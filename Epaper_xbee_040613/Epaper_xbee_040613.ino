#include <inttypes.h>
#include <ctype.h>
#include <avr/pgmspace.h>
#include <SPI.h>
#include <Wire.h>
#include <EPD.h>
#include <LM75A.h>
#include <avr/power.h>
#include <avr/sleep.h>
 
 
const int XBee_wake = 9;         // Arduino pin used to sleep the XBee 
int sleepStatus = 0;             // variable to store a request for sleep
int count = 0;                   // counter
 

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



const int ledPin = 13;
static int state = 0;
uint8_t incomingByte;

static int nDataCounter = 0;
const int BUFSIZE = 256;         // max message size is BUFSIZE - 1 to leave room for the end-of-string NULL character (i.e. 0x00)
const char EOM = '*';            // marks the end of the message
const char SOM = '$';  // marks the end of the message
char buffer[BUFSIZE] ;          //;    // here we store the message as we receive it char by char
int  bufPos = 0;                // where to store the next received char in buffer



// I/O setup
void setup() 
{
  // pinMode(Pin_RED_LED, OUTPUT);
    pinMode(Pin_PWM, OUTPUT);
    pinMode(Pin_BUSY, INPUT);
    pinMode(Pin_RESET, OUTPUT);
    pinMode(Pin_PANEL_ON, OUTPUT);
    pinMode(Pin_DISCHARGE, OUTPUT);
    pinMode(Pin_BORDER, OUTPUT);
    pinMode(Pin_EPD_CS, OUTPUT);
  
   // digitalWrite(Pin_RED_LED, LOW);
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
 /*===================================================================================*/
void sleepNow()
{
    
  set_sleep_mode(SLEEP_MODE_IDLE);   // sleep mode is set here
  
  // put the XBee to sleep
  pinMode(XBee_wake, INPUT); // put pin in a high impedence state
  digitalWrite(XBee_wake, HIGH);
  sleep_enable();          // enables the sleep bit in the mcucr register
                             // so sleep is possible. just a safety pin 
  
  power_adc_disable();
  power_spi_disable();
  power_timer0_disable();
  power_timer1_disable();
  power_timer2_disable();
  power_twi_disable();
  
  
  sleep_mode();            // here the device is actually put to sleep!!
 
                             // THE PROGRAM CONTINUES FROM HERE AFTER WAKING UP
  sleep_disable();         // first thing after waking from sleep:
  // wake up the XBee
  pinMode(XBee_wake, OUTPUT);
  digitalWrite(XBee_wake, LOW);
                            // disable sleep...

  power_all_enable();

   
}
 /*===================================================================================*/



// this function will have to analyze the message's contents and
// take appropriate action
void EDisplay(const char *msg) 
{
    Serial.print("Received: ");
    Serial.println(msg);   // print out the message
    int PositionOfLine = 0; // track the position of the line            
    EPD.begin(); // power up the EPD panel   
    EPD.clear();     
    //String inputText = "How are you?    I have got my   text to be quitebig, is it too  big now? Please let me know.    From Watanya.                   ";
      

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
                	    lineBuffer[BytePosition] = pgm_read_byte_near(font_bits + Lookup(msg[CharPosition]) +(row*2) );
                            BytePosition++;
                            lineBuffer[BytePosition] = pgm_read_byte_near(font_bits + Lookup(msg[CharPosition]) + (row*2) + 1 );
              		    BytePosition++;	      // move to next byte [position]				
                            CharPosition++;           // move to next charector [position]
              	    }
                      lineBuffer[32] = 0x00;
                              
                      //Now push a line
                      EPD.line(PositionOfLine + row, &lineBuffer[0], 0, false, EPD_inverse);
                      
                 }
              PositionOfLine = PositionOfLine + 22;
          }

          PositionOfLine = 0;
          
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
                	    lineBuffer[BytePosition] = pgm_read_byte_near(font_bits + Lookup(msg[CharPosition]) +(row*2) );
                            BytePosition++;
                            lineBuffer[BytePosition] = pgm_read_byte_near(font_bits + Lookup(msg[CharPosition]) + (row*2) + 1 );
              		    BytePosition++;	      // move to next byte [position]				
                            CharPosition++;           // move to next charector [position]
              	    }
                      lineBuffer[32] = 0x00;
                              
                      //Now push a line
                      EPD.line(PositionOfLine + row, &lineBuffer[0], 0, false, EPD_normal);
                 }
              PositionOfLine = PositionOfLine + 22;
          }    
}

 /*===================================================================================*/
void clear()
{
    EPD.begin(); // power up the EPD panel   
    EPD.clear();
}
 /*===================================================================================*/

// main loop
void loop() 
{  

//  delay(100);               // wait for a second
//  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
//  delay(100);
    //Serial.println("loop"); 
    char ch;
    
    while (Serial.available() > 0) 
    {
         
      ch = Serial.read();
      //Serial.print(ch);
        //Serial.println("read");  
        if (ch == EOM) 
        {            // end-of-message

            buffer[bufPos] = 0;     // string terminator
            while (bufPos<200)
            {
               buffer[bufPos] = ' '; 
               bufPos++;
            }
            EDisplay(buffer);        // do something with the received message
            if (bufPos>255)
            bufPos = 0;             // restart for next messages
 
        }
        else if (ch == '%')
        {
           clear();
           Serial.print("clear");
        }
        else if (ch == '!')
        {
          
           Serial.print('!');
           bufPos = 0;
           delay(200);
        }
        else 
        {
            if (bufPos < (BUFSIZE - 1)) //take in data
            { // if there's still room in the buffer
                buffer[bufPos] = ch;             // store the received char
                bufPos++;                        // forward 1 position in buffer
            }
            else // too much data
            {
                Serial.println("Lost byte!");    // no more room, have to throw away the received char
            }
        }
    }
   
sleepNow();
}

