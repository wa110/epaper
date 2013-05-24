
const int ledPin = 13; // the pin that the LED is attached to
u_int8 incomingByte;      // a variable to read incoming serial data into
int state = 0;
int nDataCounter = 0;
int nLineCounter = 0;
uint8_t x[33];
void setup() 
{
  // initialize serial communication:
    Serial.begin(9600);
 //  Serial1.begin(9600);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
}

void loop() 
{
  
  // see if there's incoming serial data:
  while (Serial.available() > 0) {
    // read the oldest byte in the serial buffer:

       incomingByte = Serial.read();
       //Serial.print(incomingByte);
       
       if (state == 1) {
         if (incomingByte == 69) 
           state = 0;
         //Serial.print(incomingByte);
         x[nDataCounter] = incomingByte;
         nDataCounter++;
//         if (nDataCounter == 32) {
//         nDataCounter = 0;
//         nLineCounter++;
//         Serial.println(nLineCounter);
//         }
       }
       
       if (state == 0 && incomingByte == 'H') 
       {  
           Serial.println();
           Serial.print("DATA OUT: >>> ");
         for ( uint8_t i = 0; i < 33; i++) 
         {
           uint8_t p = x[i];        
            Serial.print(p);
         }
            Serial.print(" <<< Entering state1");
            state = 1;
            nDataCounter = 0;
            nLineCounter = 0;
//         }
         
         Serial.println();
       }
       

    }
}
