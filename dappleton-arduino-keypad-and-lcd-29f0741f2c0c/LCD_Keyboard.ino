#include <LiquidCrystal.h>

#include <Keypad.h>

LiquidCrystal  lcd (11,10,6,7,8,9);


const byte rows = 4;
const byte cols = 4;
const char keys [rows][cols] =
{
  {'1','2','3','F'},
  {'4','5','6','E'},
  {'7','8','9','D'},
  {'A','0','B','C'}
};

byte rowPins[rows] = {6,7,8,9}; //connect to the row pinouts of the keypad
byte colPins[cols] = {2,3,4,5}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols );

void setup(){
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.noAutoscroll();
  lcd.print("IOBLOCKS 2012");
  lcd.setCursor(0,1);
  lcd.print("Enter>");
  delay(2000);
  keypad.setDebounceTime(20);
}

void initLCDKeys()
{
  for (int i = 0; i < sizeof(rowPins); i++)
    pinMode(rowPins[i],OUTPUT);
  for (int i = 0; i < sizeof(colPins); i++)
  {
    pinMode(colPins[i],INPUT);
    digitalWrite(colPins[i],LOW);
  }
}

void loop(){

  char key = keypad.getKey();
  initLCDKeys();
  delay(50);
  if (key != NO_KEY){
    Serial.println(key);
    if (key == 'F')
    {
      lcd.setCursor(6,1);
      lcd.write("          ");
      lcd.setCursor(6,1);
    } else
      lcd.print(key);
  }

  
}

