#include <EPD.h>


#include <inttypes.h>
#include <ctype.h>

#include <SPI.h>
#include <Wire.h>

#include <LM75A.h>



#define EPD_SIZE EPD_2_7

// configure images for display size
// change these to match display size above

#define TEXT_IMAGE "clarke_2_7.xbm"
#define TEXT_BITS clarke_2_7_bits

#define PICTURE "cat_2_7.xbm"
#define PICTURE_BITS cat_2_7_bits

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
//const int Pin_RED_LED = 13;
const int ledPin = 13; 
int incomingByte;
String incoming;
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
  
  randomSeed(analogRead(3));   
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // pinMode(Pin_RED_LED, OUTPUT);
  pinMode(Pin_PWM, OUTPUT);
  pinMode(Pin_BUSY, INPUT);
  pinMode(Pin_RESET, OUTPUT);
  pinMode(Pin_PANEL_ON, OUTPUT);
  pinMode(Pin_DISCHARGE, OUTPUT);
  pinMode(Pin_BORDER, OUTPUT);
  pinMode(Pin_EPD_CS, OUTPUT);

  //digitalWrite(Pin_RED_LED, LOW);
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
  
  Serial1.begin(9600);
  Serial.begin(9600);
#if !defined(__MSP430_CPU__)
  // wait for USB CDC serial port to connect.  Arduino Leonardo only
  while (!Serial) {
  }
#endif

}


static int state = 0;


// main loop
void loop() {          
  int temperature = LM75A.read();
  EPD.begin(); // power up the EPD panel
  EPD.setFactor(temperature); // adjust for current temperature
  

    // clear the screen
   // EPD.clear();
  while (Serial1.available() > 0) {
  incomingByte = Serial1.read();
 
    if (incomingByte == 'H') {
      digitalWrite(ledPin, HIGH);
      Serial.print('H');
     // text -> picture
    EPD.image(PICTURE_BITS);
    
//    EPD.frame_fixed_repeat(0xaa, (EPD_stage) 0);
//    EPD.frame_fixed_repeat(0xaa, (EPD_stage) 1);
//    EPD.frame_data_repeat(PICTURE_BITS, (EPD_stage) 2);
//    EPD.frame_data_repeat(PICTURE_BITS, (EPD_stage) 3);
    
  }
 
  if (incomingByte == 'L') {
      digitalWrite(ledPin, LOW);
      Serial.print('L');
      // picture -> text
    //EPD.image(TEXT_BITS);
    EPD.frame_fixed_repeat(0xaa, (EPD_stage) 0);
    EPD.frame_fixed_repeat(0xaa, (EPD_stage) 1);
    EPD.frame_data_repeat(TEXT_BITS, (EPD_stage) 2);
    EPD.frame_data_repeat(TEXT_BITS, (EPD_stage) 3);
   delay (3000);
  
//      for (uint8_t i = 0; i < 176; i++) 
//      {
//        uint8_t y = random(2); 
//        //Serial.print("Y is equal to: ");
//        //Serial.print(y);
//        uint8_t x[33];
//        for ( uint8_t z = 0; z < 33; z++) 
//        {
//          if (y == 0) 
//          {x[z] = 0x00;
//            //Serial.print("y 0\n");  
//          } 
//          else if (y == 1) 
//          {x[z] = 0xff;
//          //Serial.print("y 1\n");
//          }
//         }
//      EPD.line(i, &x[0], 0, false, (EPD_stage) 3);
//      //delay(10);
//      
//      }
   
}
  incomingByte= 0;
  }
  EPD.end();   // power down the EPD panel


}

