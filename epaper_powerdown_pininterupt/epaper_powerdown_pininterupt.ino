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
//  watchdogOn(); // Turn on the watch dog timer.
  // The following saves some extra power by disabling some 
// peripherals I am not using.

// Disable the ADC by setting the ADEN bit (bit 7) to zero.
//ADCSRA = ADCSRA & B01111111;
//
//// Disable the analog comparator by setting the ACD bit
//// (bit 7) to one.
//ACSR = B10000000;
//
//// Disable digital input buffers on all analog input pins
//// by setting bits 0-5 to one.
//DIDR0 = DIDR0 | B00111111;
  
  
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

void goToSleep()
{
    byte adcsra, mcucr1, mcucr2;

    sleep_enable();
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    PCICR = _BV(PCIE1);            //enable pin change interrupts 8-14
    PCMSK1 = _BV(PCINT8) | _BV(PCINT11) ;    //enable PCINT8,11,12,13 (PC0,3,4,5)
    adcsra = ADCSRA;               //save the ADC Control and Status Register A
    ADCSRA = 0;                    //disable ADC
    cli();
    mcucr1 = MCUCR | _BV(BODS) | _BV(BODSE);  //turn off the brown-out detector
    mcucr2 = mcucr1 & ~_BV(BODSE);
    MCUCR = mcucr1;                //timed sequence
    MCUCR = mcucr2;                //BODS stays active for 3 cycles, sleep instruction must be executed while it's active
    sei();                         //ensure interrupts enabled so we can wake up again
    sleep_cpu();                   //go to sleep
    

                                   //wake up here
    PCICR = 0x00;                  //disable pin change interrupts 8-14
    PCMSK1 = 0x00;
       
    sleep_disable();
    ADCSRA = adcsra;               //restore ADCSRA
}

ISR(PCINT1_vect)
{
    PCICR = 0x00;                  //disable pin change interrupts 8-14
    PCMSK1 = 0x00;
}
