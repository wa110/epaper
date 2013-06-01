void setup()
{
  Serial.begin(9600);
   Serial1.begin(9600);
}
int i = 0;
char Data[128];// = "How are you?    I have got my   text to be quitebig, is it too  big now? Please let me know.    From Watanya.         *";
static int state = 0;
void loop()
{
  //Serial.println("Wake the end device up.");
  Serial1.print('!');
  delay(3000);
  char ch,  ch0 ;
  
 
   switch(state) {
   case 0:
   while (Serial.available() > 0) 
   {
       ch0 = Serial.read();
        if (ch0 == '$')  // if recieve reply start senting data
        {
        Serial.println('#');
        digitalWrite(13, HIGH);
        state = 1;
        } 
   }
   ch0 = 0;
  // Serial.println(state);
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
       
       // Serial.println(state);
        break;
        
  case 2:       
  while (Serial1.available() > 0) 
  {      
    ch = Serial1.read();
    if (ch == '!')  // if recieve reply start senting data
    {  
      Serial.println("The end device woke up");
      Serial.println("Sent data: ");
      for (int i = 0; i < 128; i++)
      {
        Serial.print(Data[i]); //print data to serial monitor
        Serial1.print(Data[i]); // sent data to the end device
      }
      Serial.println(" Data end");
      delay(6000);
      delay(4000);
    
    }
  }
  state = 0;
 // Serial.println(state);
  break; 
}
}
