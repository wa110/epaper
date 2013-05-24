

#include <inttypes.h>
#include <ctype.h>

#include <SPI.h>
#include <Wire.h>
//#include <EPD.h>
#include <LM75A.h>
//#incl



#define EPD_SIZE EPD_2_7

// configure images for display size
// change these to match display size above

#define TEXT_IMAGE "cat_2_7.xbm"
#define TEXT_BITS cat_2_7_bits

#define PICTURE "ea_2_7.xbm"
#define PICTURE_BITS ea_2_7_bits


#define FONT "font_2_7.xbm"
#define FONT_BITS font_2_7_bits
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

PROGMEM const
#define unsigned
#define char uint8_t
#include FONT
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


// I/O setup
void setup() {
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
  Serial.println();
  Serial.println();
  Serial.println("Demo version: " DEMO_VERSION);
  Serial.println("Display: " MAKE_STRING(EPD_SIZE));
  Serial.println();
}


static int state = 0;


// main loop
void loop() {          
  int temperature = LM75A.read();
  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println(" Celcius");

  EPD.begin(); // power up the EPD panel
  EPD.setFactor(temperature); // adjust for current temperature

    switch(state) {
  default:
  case 0:         // clear the screen
    EPD.clear();
    state = 1;
    break;

  case 1:         // clear -> text
    //EPD.image(PICTURE_BITS);
    ++state;
    break;

  case 2:         // text -> picture
    //EPD.image(PICTURE_BITS, FONT_BITS);
    EPD.clear();
    EPD.frame_fixed_repeat(0xaa, (EPD_stage) 0);
    EPD.frame_fixed_repeat(0xaa, (EPD_stage) 1);
    EPD.frame_data_repeat(PICTURE_BITS, (EPD_stage) 3);
    ++state;
    //delay(4000);
    break;

  case 3:        // picture -> text
    EPD.clear();
    //EPD.frame_fixed_repeat(0xaa, (EPD_stage) 0);
    //EPD.frame_fixed_repeat(0xaa, (EPD_stage) 1);
    EPD.frame_data_repeat(FONT_BITS, (EPD_stage) 3);
    //delay(4000);
    state = 2;  // backe to picture nex time
    break;
  }
  
  
  EPD.end();   // power down the EPD panel
  
  }



