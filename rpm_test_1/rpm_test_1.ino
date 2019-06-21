#define encoder0PinA  18
#define encoder0PinB  48  

#define encoder1PinA 19
#define encoder1PinB 46


volatile long encoder0Pos=0;
long newposition0;
long oldposition0 = 0;
unsigned long newtime0;
unsigned long oldtime0 = 0;
long vel0;

volatile long encoder1Pos=0;
long newposition1;
long oldposition1 = 0;
unsigned long newtime1;
unsigned long oldtime1 = 0;
long vel1;
void setup()
{
  pinMode(encoder0PinA, INPUT);
  digitalWrite(encoder0PinA, HIGH);       // turn on pullup resistor
  pinMode(encoder0PinB, INPUT);
  digitalWrite(encoder0PinB, HIGH);       // turn on pullup resistor
  attachInterrupt(digitalPinToInterrupt(encoder0PinA), doEncoder0, RISING);  //(Whenever the pin in first argument goes high, doEncoder function is implemented)
  
  pinMode(encoder1PinA, INPUT);
  digitalWrite(encoder1PinA, HIGH);       // turn on pullup resistor
  pinMode(encoder1PinB, INPUT);
  digitalWrite(encoder1PinB, HIGH);       // turn on pullup resistor
  attachInterrupt(digitalPinToInterrupt(encoder1PinA), doEncoder1, RISING);  //(Whenever the pin in first argument goes high, doEncoder function is implemented)

  Serial.begin (9600);
  Serial.println("start");                // a personal quirk
}

void loop()
{
newposition0 = encoder0Pos;
newtime0 = millis();
vel0 = (newposition0-oldposition0) * 1000 /(newtime0-oldtime0);
Serial.print ("speed0 = ");
Serial.println (vel0);
oldposition0 = newposition0;
oldtime0 = newtime0;

newposition1 = encoder1Pos;
newtime1 = millis();
vel1 = (newposition1 - oldposition1) * 1000 /(newtime1 - oldtime1);
Serial.print ("speed1 = ");
Serial.println (vel1);
oldposition1 = newposition1;
oldtime1 = newtime1;

delay(250);
}

void doEncoder0()
{
  if (digitalRead(encoder0PinA) == digitalRead(encoder0PinB)) {
    encoder0Pos++;
  } else {
    encoder0Pos--;
  }
}
void doEncoder1()
{
  if (digitalRead(encoder1PinA) == digitalRead(encoder1PinB)) {
    encoder1Pos++;
  } else {
    encoder1Pos--;
  }
}
