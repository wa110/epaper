#include <avr/power.h>
#include <avr/sleep.h>


void setup(void)
{
  
  Serial.begin(9600);
  
}

void loop(void)
{
   //Serial.print("hello");
   delay(1000);
  if (Serial.available() > 0) 
    {
      char ch;
      ch = Serial.read();
      Serial.print(ch);
      char P = ch;
        Serial.print(P);
      if (ch == '!')
        {
            
           Serial.print('A');
           
           delay(200);
        }
        if (ch == '*')
        {
           delay(200);
           goToSleep();
        }
    }
    else{goToSleep();}
 
}

void goToSleep()
{
    byte adcsra, mcucr1, mcucr2;

    sleep_enable();
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    PCICR = _BV(PCIE1);            //enable pin change interrupts 8-14
    PCMSK1 = _BV(PCINT8) | _BV(PCINT11) | _BV(PCINT12) | _BV(PCINT13);    //enable PCINT8,11,12,13 (PC0,3,4,5)
    adcsra = ADCSRA;               //save the ADC Control and Status Register A
    ADCSRA = 0;                    //disable ADC
    cli();
    mcucr1 = MCUCR | _BV(BODS) | _BV(BODSE);  //turn off the brown-out detector
    mcucr2 = mcucr1 & ~_BV(BODSE);
    MCUCR = mcucr1;                //timed sequence
    MCUCR = mcucr2;                //BODS stays active for 3 cycles, sleep instruction must be executed while it's active
    sei();                         //ensure interrupts enabled so we can wake up again
    sleep_cpu();                   //go to sleep
                                   //wake up here
    PCICR = 0x00;                  //disable pin change interrupts 8-14
    PCMSK1 = 0x00;
    sleep_disable();
    ADCSRA = adcsra;               //restore ADCSRA
}

ISR(PCINT1_vect)
{
    PCICR = 0x00;                  //disable pin change interrupts 8-14
    PCMSK1 = 0x00;
}
 

 
  
 

