
#include <avr/sleep.h>
#include <avr/power.h>
#include <avr/wdt.h>

#include <inttypes.h>
#include <ctype.h>
#include <avr/pgmspace.h>
#include <SPI.h>
#include <Wire.h>
#include <EPD.h>
#include <LM75A.h>

volatile int sleep_count = 0; // Keep track of how many sleep 

//Font table with lookup function
#include <font_table.h>
#include <text.h>
   
#define EPD_SIZE EPD_2_7


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

const int ledPin = 13;
char incomingByte;
static int nDataCounter = 0;
const int BUFSIZE = 257;         // max message size is BUFSIZE - 1 to leave room for the end-of-string NULL character (i.e. 0x00)
const char EOM = '*';            // marks the end of the message
char buffer[BUFSIZE] ;          //;    // here we store the message as we receive it char by char
int  bufPos = 0;                // where to store the next received char in buffer

/*=======================================================================*/

/***************************************************
 *  Name:        ISR(WDT_vect)
 *
 *  Returns:     Nothing.
 *
 *  Parameters:  None.
 *
 *  Description: Watchdog Interrupt Service. This
 *               is executed when watchdog timed out.
 *
 ***************************************************/
ISR(WDT_vect)
{
  sleep_count ++;
  Serial.println(sleep_count);
}


/***************************************************
 *  Name:        enterSleep
 *
 *  Returns:     Nothing.
 *
 *  Parameters:  None.
 *
 *  Description: Enters the arduino into sleep mode.
 *
 ***************************************************/
void enterSleep(void)
{
  set_sleep_mode(SLEEP_MODE_PWR_SAVE);   /* EDIT: could also use SLEEP_MODE_PWR_DOWN for lowest power consumption. */
  sleep_enable();
  
  /* Now enter sleep mode. */
  sleep_mode();
  
  /* The program will continue from here after the WDT timeout*/
  sleep_disable(); /* First thing to do is disable sleep. */
  
  /* Re-enable the peripherals. */
  power_all_enable();
}



/***************************************************
 *  Name:        setup
 *
 *  Returns:     Nothing.
 *
 *  Parameters:  None.
 *
 *  Description: Setup for the serial comms and the
 *                Watch dog timeout. 
 *
 ***************************************************/
void setup()
{
  Serial.begin(9600);
  Serial.println("Initialising...");
  delay(100); //Allow for serial print to complete.

  /*** Setup the WDT ***/
  
  /* Clear the reset flag. */
  MCUSR &= ~(1<<WDRF);
  
  /* In order to change WDE or the prescaler, we need to
   * set WDCE (This will allow updates for 4 clock cycles).
   */
  WDTCSR |= (1<<WDCE) | (1<<WDE);

  /* set new watchdog timeout prescaler value */
  WDTCSR = 1<<WDP0 | 1<<WDP3; /* 8.0 seconds */
  
  /* Enable the WD interrupt (note no reset). */
  WDTCSR |= _BV(WDIE);
  
  
  Serial.println("Initialising Epaper...");
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

  
  Serial.println("Initialisation complete.");
  delay(100); //Allow for serial print to complete.
}


/*===================================================================================*/



// this function will have to analyze the message's contents and
// take appropriate action
void EDisplay(const char *msg) 
{
    Serial.println("Received: ");
    Serial.println(msg);   // print out the message
    int PositionOfLine = 0; // track the position of the line            
    EPD.begin(); // power up the EPD panel   
    EPD.clear();     
    //String inputText = "How are you?    I have got my   text to be quitebig, is it too  big now? Please let me know.    From Watanya.                   ";
      
    Serial.println("Begin write to screen stage...");
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
          delay(100);
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
Serial.println("Exit epaper");
}

 /*===================================================================================*/
void clear()
{
    EPD.begin(); // power up the EPD panel   
    EPD.clear();
}
 /*===================================================================================*/

/***************************************************
 *  Name:        enterSleep
 *
 *  Returns:     Nothing.
 *
 *  Parameters:  None.
 *
 *  Description: Main application loop.
 *
 ***************************************************/
 volatile boolean bCheckingSerial = false;
 volatile boolean bNoSleepAllowed = false;
 volatile boolean bResponded = false; 
 

void loop()
{
  
  if (sleep_count == 2) 
  {  
     bCheckingSerial = true ;
  }
  char ch;
    if (bCheckingSerial == true) 
    {
      // wake up the XBee
      pinMode(A0, OUTPUT);
      digitalWrite(A0, LOW);
      
      if (Serial.available() > 0) 
      {
       ch = Serial.read();
       
        if (ch == EOM) 
        {            
            
            buffer[bufPos] = 0;     // string terminator
              while (bufPos<255)
              {
                 buffer[bufPos] = ' '; 
                 bufPos++;
              }
              EDisplay(buffer);        // do something with the received message
              delay(100); 
              if (bufPos==255) {bufPos = 0; }          // restart for next message
              delay(200);
              bCheckingSerial = false;                //
              bNoSleepAllowed = false;                // We want to go back to sleep
              bResponded = false;
              delay(100); 
        }
        else if (ch == '!' )
        {
            if(!bResponded) 
            {
             bResponded = true;
             Serial.print('=');
            }
             bufPos = 0;
             bNoSleepAllowed = true; //Prevent System going to sleep mode until whole message recieved 
             
        }
        else 
        {  
            if (bufPos < (BUFSIZE - 1)) //take in data
            {                                    // if there's still room in the buffer
                buffer[bufPos] = ch;             // store the received char
                bufPos++;                        // forward 1 position in buffer
               
            }  
            
        }      
    }
}
  else if (bNoSleepAllowed == false)
  {
            Serial.println("Entering gotosleep");
            delay (100);
            bCheckingSerial = false;
            // put the XBee to sleep
            pinMode(A0, INPUT); // put pin in a high impedence state
            digitalWrite(A0, HIGH);
            enterSleep();
            Serial.println("Exited goto sleep"); 
             delay (100);
    }

  if (sleep_count == 4   ) 
  {  
    sleep_count = 0; 
    //if (bNoSleepAllowed == false)
    bCheckingSerial = false;
  }
  
}
