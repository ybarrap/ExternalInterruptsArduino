uint8_t led_pin = PB5;7
//const uint16_t t1_load=0;
const uint16_t t1_comp=64;
uint16_t last,now;

void setup() {
//Serial.begin(9600);
//Setup LED Pin as output
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
DDRB |= (1 << led_pin);

//Reset timer 1 Control Register A
TCCR1A=0;
TCCR1B=0;

//Set CTC Mode
TCCR1A |= (1<<WGM10) | (1<<COM1A1)|(1<<COM1B1); //non-inverting PWM
TCCR1B |= (1<<CS10) | (1 <<WGM12); //prescaler 1, FastPWM 8-Bit

//Set Prescaler 1024
//TCCR1B |=  (1 << CS12);
//TCCR1B &= ~(1 << CS11);
//TCCR1B |=  (1 << CS10);

//Preset Time1 and set compare value
//TCNT1 = t1_load;
OCR1A=t1_comp;

//Enable Timer 1 Compare Interrupt
//TIMSK1 = (1 << OCIE1A);
//last=0;
//now=0;

//sei();
}

void loop() {
 delay(500);
}

ISR(TIMER1_COMPA_vect) {
  PORTB ^= (1 << led_pin);
//  now=millis();
//  Serial.println(now-last);
//  last=now;
}

