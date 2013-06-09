#include <avr/power.h>
#include <avr/sleep.h>

void setup()
{                
  byte i;
  
  // Ensure no floating pins
  for(i=0; i<20 ; i++)
  {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
  
  // Power-down board
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  
  sleep_enable();
  
  // Disable ADC
  ADCSRA &= ~(1 << ADEN);

  // Power down functions
  PRR = 0xFF;
  
  // Enter sleep mode
  sleep_mode();
}

void loop()
{
}

