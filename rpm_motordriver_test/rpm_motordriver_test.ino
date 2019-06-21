// Endoder pins

const int leftC1 = 18;
const int leftC2 = 46;

const int rightC1 = 19;
const int rightC2 = 48;

volatile long encoderLPos=0;
long newpositionL;
long oldpositionL = 0;
unsigned long newtimeL;
unsigned long oldtimeL = 0;
long velL;

volatile long encoderRPos=0;
long newpositionR;
long oldpositionR = 0;
unsigned long newtimeR;
unsigned long oldtimeR = 0;
long velR;

const int en_right=7, en_left=2, rightPin_1 = 5,rightPin_2 = 6,leftPin_1 = 3,leftPin_2 = 4;

int vL = 200, vR = 200;

void setup()
{
  pinMode(leftC1, INPUT);
  digitalWrite(leftC1, HIGH);       // turn on pullup resistor
  pinMode(leftC2, INPUT);
  digitalWrite(leftC2, HIGH);       // turn on pullup resistor
  attachInterrupt(digitalPinToInterrupt(leftC1), doEncoderL, RISING);  // encoDER ON leftC1 (Whenever the pin in first argument goes high, doEncoder function is implemented)
  
  pinMode(rightC1, INPUT);
  digitalWrite(rightC1, HIGH);       // turn on pullup resistor
  pinMode(rightC2, INPUT);
  digitalWrite(rightC2, HIGH);       // turn on pullup resistor
  attachInterrupt(digitalPinToInterrupt(rightC1), doEncoderR, RISING);  // encoDER ON rightC1 (Whenever the pin in first argument goes high, doEncoder function is implemented)

  Serial.begin (9600);
  Serial.println("start");                // a personal quirk

  analogWrite(en_right , vR);
  digitalWrite(rightPin_2 , HIGH);
  digitalWrite(rightPin_1 , LOW);

  analogWrite(en_left , vL);
  digitalWrite(leftPin_2 , LOW);
  digitalWrite(leftPin_1 , HIGH);
}

void loop()
{
newpositionL = encoderLPos;
newtimeL = millis();
velL = (newpositionL-oldpositionL) * 1000 /(newtimeL-oldtimeL);
Serial.print ("speedL = ");
Serial.println (velL);
oldpositionL = newpositionL;
oldtimeL = newtimeL;

newpositionR = encoderRPos;
newtimeR = millis();
velR = (newpositionR - oldpositionR) * 1000 /(newtimeR - oldtimeR);
Serial.print ("speedR = ");
Serial.println (velR);
oldpositionR = newpositionR;
oldtimeR = newtimeR;

if(velR > 500)
  vR = vR-5;
else 
  vR = vR+5;
    
if(velL > 500)
  vL=vL-5;
else 
  vL=vL+5;
  
delay(250);
}

void doEncoderL()
{
  if (digitalRead(leftC1) == digitalRead(leftC2)) {
    encoderLPos++;
  } else {
    encoderLPos--;
  }
}
void doEncoderR()
{
  if (digitalRead(rightC1) == digitalRead(rightC2)) {
    encoderRPos++;
  } else {
    encoderRPos--;
  }
}
