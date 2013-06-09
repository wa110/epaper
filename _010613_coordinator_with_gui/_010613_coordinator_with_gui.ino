void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600);
}
int i = 0;
char Data[129];// = "How are you?    I have got my   text to be quitebig, is it too  big now? Please let me know.    From Watanya.         *";
static int state = 0;
void loop()
{
  //Serial.println("Wake the end device up.");
  char ch,  ch0 ;
  
 
   switch(state) {
   case 0:
     
     digitalWrite(13, LOW);
     while (Serial.available() > 0) 
     {
         ch0 = Serial.read();
          if (ch0 == '$')  // if recieve reply start senting data
          {
          Serial.println('#');
          state = 1;
          } 
     }
     ch0 = 0;
     i=0;
   break;    
   
   case 1:
      while (Serial.available() > 0) 
     {
       ch0 = Serial.read();
       
           Data[i] = ch0;
           i++;
           if (ch0 == '*')  // if recieve reply start senting data
           {
            state = 2;
           }  
        }
       digitalWrite(13, HIGH);
       // Serial.println(state);
        break;
        
  case 2:     
  //Send data state  
  Serial1.println('!');
  delay(3000);
  while (Serial1.available() > 0) 
  {      
    ch = Serial1.read();
  
    if (ch == '!')  // if recieve reply start senting data
    {  
      Serial.println("The end device woke up");
      Serial.println("Sent data: ");
      for (int i = 0; i < 130; i++)
      {
        Serial.print(Data[i]); //print data to serial monitor
        Serial1.print(Data[i]); // sent data to the end device
      }

      delay(50);
      state = 0;
       
    }
  }
 
 // Serial.println(state);
  break; 
}
}
