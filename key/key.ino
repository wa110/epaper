void setup() {
  pinMode(9, OUTPUT);  
  pinMode(10, OUTPUT);
  pinMode(A0, INPUT);  
  pinMode(A1, INPUT); 
  pinMode(A2, INPUT);  
  pinMode(A3, INPUT);   
  pinMode(13, OUTPUT);  
  Serial.begin(9600);
}


char charMap[4][4][3] = 
{'A', 'D', 'G', 'U'} , 
{'J', 'M', 'P', 'D'} ,
{'S', 'V', 'Y', 'L'} ,
{' ', '-', '*', 'R'};
{'B', 'E', 'H', 'U'} , 
{'K', 'N', 'Q', 'D'} ,
{'T', 'W', 'Z', 'L'} ,
{' ', '-', '*', 'R'};
{'C', 'F', 'I', 'U'} , 
{'L', 'O', 'R', 'D'} ,
{'U', 'X', '.', 'L'} ,
{' ', '-', '*', 'R'};
int Col=0;
int Row=0;
int Val = 0;
void loop() {
 char r = getKeyPressed();
 
 if ( r== 'U') {
   digitalWrite(13, HIGH);
 } else if ( r== 'D') {
   digitalWrite(13, LOW);
 }
}


char getKeyPressed() {
 
 
  for (int i =0; i<4; i++)
  {

     int a0, a1;
     switch(i)
     {  
       
       case 0 :
         a0=0;
         a1=0;
         break;
      
       case 1 :
         a0=1;
         a1=0;
         break; 
        
        case 2 :
         a0=0;
         a1=1;
         break; 
        
        case 3 :
         a0=1;
         a1=1;
         break; 
     }
     
     digitalWrite(9, a0);
     digitalWrite(10, a1);

     
     for (int j = 0; j<4; j++)
     {
        switch(j)
         {  
           case 0 :
           Val = digitalRead(A0);
           break;
           case 1 :
           Val = digitalRead(A1);
           break;
           case 2 :
           Val = digitalRead(A2);
           break;
           case 3 :
           Val = digitalRead(A3);
           break;   
          }          //Serial.print("test"); 

          if (Val == LOW )
          {
            delay(20);
            Col = i;
            Row = j;
              if (Col == 1 && Row == 1)
              {

                    return 'U';
  

              }
              else if (Col == 1 && Row == 2) {

                   return  'D';
              }
          }

     }
 } 
  
}

