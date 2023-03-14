#include <Arduino.h>

#define HIGH 1
#define LOW 0
#define OUTPUT 1
#define INPUT 0

unsigned char * configureDDRxPointer(uint8_t x){
  switch(x){
    //DDRx registers start from B to F
    //DDRB
    case 0:
      return (unsigned char *) 0x24;
      break;
    //DDRC
    case 1:
      return (unsigned char *) 0x27;
      break;
    //DDRD
    case 2:
      return (unsigned char *) 0x2A;
      break;
    //DDRE
    case 3:
      return (unsigned char *) 0x2D;
      break;
    //DDRF
    case 4:
      return (unsigned char *) 0x30;
      break;
    default:
      return NULL;
      break;
  }
}

unsigned char * configurePORTxPointer(uint8_t x){
   switch(x){
    //PORTx registers start from B to F
    //PORTB
    case 0:
      return (unsigned char *) 0x25;
      break;
    //PORTC
    case 1:
      return (unsigned char *) 0x28;
      break;
    //PORTD
    case 2:
      return (unsigned char *) 0x2B;
      break;
    //PORTE
    case 3:
      return (unsigned char *) 0x2E;
      break;
    //PORTF
    case 4:
      return (unsigned char *) 0x31;
      break;
    default:
      return NULL;
      break;
  }
}

unsigned char * configurePINxPointer(uint8_t x){
   switch(x){
    //PINx registers start from B to F
    //PINB
    case 0:
      return (unsigned char *) 0x23;
      break;
    //PINC
    case 1:
      return (unsigned char *) 0x26;
      break;
    //PIND
    case 2:
      return (unsigned char *) 0x29;
      break;
    //PINE
    case 3:
      return (unsigned char *) 0x2C;
      break;
    //PINF
    case 4:
      return (unsigned char *) 0x2F;
      break;
    default:
      return NULL;
      break;
  }
}

// Configures the specified pin to behave either as an input or an output -> would control DDRx registers
void _pinMode(uint8_t port, uint8_t pin, uint8_t value){
  volatile unsigned char* DDRxPtr = (unsigned char*)configureDDRxPointer(port);

  if(value == 1){
    *DDRxPtr |= (1 << pin);
  }
  else if(value == 0){
    *DDRxPtr &= ~(1 << pin);
  }
}

// Configures the specified pin to high or low -> would control PORTx registers
void _digitalWrite(uint8_t port, uint8_t pin, uint8_t value){
  volatile unsigned char* PORTxPtr = (unsigned char*)configurePORTxPointer(port);

  if(value == 1){
    *PORTxPtr |= (1 << pin);
  }
  else if(value == 0){
    *PORTxPtr &= ~(1 << pin);
  }
}

int _digitalRead(uint8_t port, uint8_t pin){
  volatile unsigned char* PINxPtr = (unsigned char*)configurePINxPointer(port);

  if(*PINxPtr & (1 << pin)){
    return HIGH;
  }
  else{
    return LOW;
  }
}

void setup() {
  // put your setup code here, to run once:
  //TESTING PREVIOUS CODE BY TURNING ON LED ON PIN #13 or C7
  _pinMode(1, 7, OUTPUT);
  _digitalWrite(1, 7, HIGH);
  //Testing DigitalRead() by turning the LED off if button on pin #4 is clicked & turned on if button on #19 is clicked
  _pinMode(2, 4, INPUT);
  _digitalWrite(2, 4, HIGH);
  _pinMode(4, 6, INPUT);
  _digitalWrite(4, 6, HIGH);
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(_digitalRead(2, 4)){
    _digitalWrite(1, 7, LOW);
  }
  else if(_digitalRead(4, 6)){
    _digitalWrite(1, 7, HIGH);
  }
}
