
#include <inttypes.h>
#include <ctype.h>
#include <avr/pgmspace.h>
#include <SPI.h>
#include <Wire.h>
#include <EPD.h>
#include <LM75A.h>

//Font table with lookup function
#include "C:\Users\watanya\Documents\Arduino\Paper_Text\font_table.h"
#include <text.h>
   
#define EPD_SIZE EPD_2_7

// current version number
#define DEMO_VERSION "1"

// Add Images library to compiler path
#include <Images.h>  // this is just an empty file

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
void setup() 
{
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


static int state = 0;
int incomingByte;
char inputText[257];
int nDataCounter = 0;

// main loop
void loop() {          
    int temperature = LM75A.read();
    
    EPD.begin(); // power up the EPD panel
    EPD.setFactor(temperature); // adjust for current temperature     
    EPD.clear();

    while (Serial.available() > 0) 
    {
     incomingByte = Serial.read();
     inputText[nDataCounter] = incomingByte;
     nDataCounter++;
     Serial.print("How are you? ");
    } 
    
    
      //String inputText = "How are you?    I have got my   text to be quitebig, is it too  big now? Please let me know.    From Watanya.                   ";
      int PositionOfLine = 0; // track the position of the line
    
      for (uint8_t z = 0; z < 3; z++) 
      {
        for(uint8_t CharRow = 0; CharRow<8; CharRow++)
        {
          
              for(uint8_t row = 0; row<22; row++)
              {
      		
                uint8_t CharPosition = CharRow*16;   //  position of the character (first char, secound char , .....)
        	uint8_t BytePosition = 0;           // position on the line, restart at first charector everytime when start new new row
        	        
        		//accumulate line
        	prog_uint8_t lineBuffer[33];                        
        
        	for(uint8_t col = 0; col<32; col = col + 2)
        	{	
          		lineBuffer[BytePosition] = pgm_read_byte_near(font_bits + Lookup(inputText[CharPosition]) +(row*2) );
                        BytePosition++;
                        lineBuffer[BytePosition] = pgm_read_byte_near(font_bits + Lookup(inputText[CharPosition]) + (row*2) + 1 );
        		BytePosition++;	      // move to next byte [position]				
                        CharPosition++;        // move to next charector [position]
        	}
                lineBuffer[32] = 0x00;
                        
                //Now push a line
                EPD.line(PositionOfLine + row, &lineBuffer[0], 0, false, EPD_compensate);
      	        EPD.line(PositionOfLine + row, &lineBuffer[0], 0, false, EPD_white);
                EPD.line(PositionOfLine + row, &lineBuffer[0], 0, false, EPD_inverse);
                EPD.line(PositionOfLine + row, &lineBuffer[0], 0, false, EPD_normal);
               }
            PositionOfLine = PositionOfLine + 22;
        }
        delay (3000);
      }
    
}

