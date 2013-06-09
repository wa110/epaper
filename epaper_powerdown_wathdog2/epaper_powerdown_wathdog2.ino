#include <avr/sleep.h>

#include <inttypes.h>
#include <ctype.h>

#include <SPI.h>
#include <Wire.h>
#include <EPD.h>
#include <LM75A.h>

#include <avr/power.h>
#include <avr/sleep.h>
 

#define EPD_SIZE EPD_2_7

// configure images for display size
// change these to match display size above

#define TEXT_IMAGE "text_image_2_7.xbm"
#define TEXT_BITS text_image_2_7_bits

#define PICTURE "ea_2_7.xbm"
#define PICTURE_BITS ea_2_7_bits

// no futher changed below this point

// current version number
#define DEMO_VERSION "1"


// Add Images library to compiler path
#include <Images.h>  // this is just an empty file

// images
PROGMEM const
#define unsigned
#define char uint8_t
#include TEXT_IMAGE
#undef char
#undef unsigned

PROGMEM const
#define unsigned
#define char uint8_t
#include PICTURE
#undef char
#undef unsigned



// Arduino IO layout
const int Pin_PANEL_ON = 2;
const int Pin_BORDER = 3;
const int Pin_DISCHARGE = 4;
const int Pin_PWM = 5;
const int Pin_RESET = 6;
const int Pin_BUSY = 7;
const int Pin_EPD_CS = 8;
const int Pin_RED_LED = 13;


// LED anode through resistor to I/O pin
// LED cathode to Ground
#define LED_ON  HIGH
#define LED_OFF LOW


// pre-processor convert to string
#define MAKE_STRING1(X) #X
#define MAKE_STRING(X) MAKE_STRING1(X)


// define the E-Ink display
EPD_Class EPD(EPD_SIZE, Pin_PANEL_ON, Pin_BORDER, Pin_DISCHARGE, Pin_PWM, Pin_RESET, Pin_BUSY, Pin_EPD_CS, SPI);
LM75A_Class LM75A;

/*=======================================================================*/

// I/O setup
void setup() {
  watchdogOn(); // Turn on the watch dog timer.
 //The following saves some extra power by disabling some 
// peripherals I am not using.
// Disable the ADC by setting the ADEN bit (bit 7) to zero.
ADCSRA = ADCSRA & B01111111;

// Disable the analog comparator by setting the ACD bit
// (bit 7) to one.
ACSR = B10000000;

// Disable digital input buffers on all analog input pins
// by setting bits 0-5 to one.
DIDR0 = DIDR0 | B00111111;
  
  
  pinMode(Pin_RED_LED, OUTPUT);
  pinMode(Pin_PWM, OUTPUT);
  pinMode(Pin_BUSY, INPUT);
  pinMode(Pin_RESET, OUTPUT);
  pinMode(Pin_PANEL_ON, OUTPUT);
  pinMode(Pin_DISCHARGE, OUTPUT);
  pinMode(Pin_BORDER, OUTPUT);
  pinMode(Pin_EPD_CS, OUTPUT);

  digitalWrite(Pin_RED_LED, LOW);
  digitalWrite(Pin_PWM, LOW);
  digitalWrite(Pin_RESET, LOW);
  digitalWrite(Pin_PANEL_ON, LOW);
  digitalWrite(Pin_DISCHARGE, LOW);
  digitalWrite(Pin_BORDER, LOW);
  digitalWrite(Pin_EPD_CS, LOW);

  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  SPI.setDataMode(SPI_MODE0);
  SPI.setClockDivider(SPI_CLOCK_DIV4);

  Serial.begin(9600);
#if !defined(__MSP430_CPU__)
  // wait for USB CDC serial port to connect.  Arduino Leonardo only
  while (!Serial) {
  }
#endif

}

/*=======================================================================*/
volatile int sleep_count = 0; // Keep track of how many sleep
static int state = 0;

/*=======================================================================*/
// main loop
void loop() {          

  int temperature = LM75A.read();
  
  EPD.begin(); // power up the EPD panel
  EPD.setFactor(temperature); // adjust for current temperature

    switch(state) {
  default:
  case 0:         // clear the screen
    EPD.clear();
    state = 1;
    break;

  case 1:         // clear -> text
    EPD.image(PICTURE_BITS);
    ++state;
    break;

  case 2:         // text -> picture
    EPD.image(PICTURE_BITS, TEXT_BITS);
    ++state;
    break;

  case 3:        // picture -> text
    EPD.image(TEXT_BITS, PICTURE_BITS);
    state = 2;  // backe to picture nex time
    break;
  }
  EPD.end();   // power down the EPD panel


  goToSleep();
}

/*===================================================================================*/

void goToSleep()   
{
// The ATmega328 has five different sleep states.
// See the ATmega 328 datasheet for more information.
// SLEEP_MODE_IDLE -the least power savings 
// SLEEP_MODE_ADC
// SLEEP_MODE_PWR_SAVE
// SLEEP_MODE_STANDBY
// SLEEP_MODE_PWR_DOWN -the most power savings
// I am using the deepest sleep mode from which a
// watchdog timer interrupt can wake the ATMega328

set_sleep_mode(SLEEP_MODE_PWR_DOWN); // Set sleep mode.
sleep_enable(); // Enable sleep mode.
sleep_mode(); // Enter sleep mode.
// After waking from watchdog interrupt the code continues
// to execute from this point.

sleep_disable(); // Disable sleep mode after waking.
                     
}

/*===================================================================================*/

void watchdogOn() {
  
// Clear the reset flag, the WDRF bit (bit 3) of MCUSR.
MCUSR = MCUSR & B11110111;
  
// Set the WDCE bit (bit 4) and the WDE bit (bit 3) 
// of WDTCSR. The WDCE bit must be set in order to 
// change WDE or the watchdog prescalers. Setting the 
// WDCE bit will allow updtaes to the prescalers and 
// WDE for 4 clock cycles then it will be reset by 
// hardware.
WDTCSR = WDTCSR | B00011000; 

// Set the watchdog timeout prescaler value to 1024 K 
// which will yeild a time-out interval of about 8.0 s.
WDTCSR = B00100001;

// Enable the watchdog timer interupt.
WDTCSR = WDTCSR | B01000000;
MCUSR = MCUSR & B11110111;

}
/*===================================================================================*/

ISR(WDT_vect)
{
sleep_count ++; // keep track of how many sleep cycles
// have been completed.
}

 /*===================================================================================*/


