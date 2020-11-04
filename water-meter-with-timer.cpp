#include <Arduino.h>

int adc_id = 0;
const  int threshold = 200;
char printBuffer[128];


ISR(TIMER0_COMPA_vect) //ISR for Timer0 compare match
{
  int currentValue = analogRead(adc_id);
  if(currentValue < threshold) {
    PORTB |= 0x20;  // 0b00100000 turn on red
    PORTB &= 0xBF;  // 0b10111111 turn off green
  } else {
    PORTB &= 0xDF; // 0b11011111 turn off red
    PORTB |= 0x40;  // 0b01000000 turn on the green
  }
}

void setup()
{
  //Serial.begin(9600);
  OCR0A = 100;
  TCCR0A = (1 << WGM01); //CTC mode, internal clk, no prescaler
  TCCR0B = 0x01;
  TIMSK0 = (1 << OCIE0A); //enable Timer0 compare match int.
  sei();                  //enable interrupts
}

void loop()
{
  //int value = analogRead(adc_id); // get adc value
    //Serial.print(".");
    // unsigned char x = 0;
    // int val = analogRead(adc_id);
    // sprintf(printBuffer,"%d\n",val);
    // Serial.print(printBuffer);

}
