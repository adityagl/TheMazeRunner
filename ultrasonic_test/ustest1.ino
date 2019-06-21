
// ultrasonic pins
const int trigPinF = 44;
const int echoPinF = 42;

const int trigPinL = 40;
const int echoPinL = 38;

const int trigPinR = 34;
const int echoPinR = 36;

const int trigPinDL = 30;
const int echoPinDL = 32;

const int trigPinDR = 26;
const int echoPinDR = 28;

// defines variables for ultrasonic

long durationF;
float distanceF;

long durationL;
float distanceL;

long durationR;
float distanceR;

long durationDL;
float distanceDL;

long durationDR;
float distanceDR;

void ultrasonic (char d)
{
  if (d== 'f')
  {
    // Clears the trigPin
    digitalWrite(trigPinF, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPinF, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPinF, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    durationF = pulseIn(echoPinF, HIGH);
    // Calculating the distance
    distanceF= durationF*0.034/2;
    // Prints the distance on the Serial Monitor
    Serial.print("DistanceF: ");
    Serial.println(distanceF);
  } 
  
 else if (d== 'r')
{
// Clears the trigPin
digitalWrite(trigPinR, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPinR, HIGH);
delayMicroseconds(10);
digitalWrite(trigPinR, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
durationR = pulseIn(echoPinR, HIGH);
// Calculating the distance
distanceR= durationR*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("DistanceR: ");
Serial.println(distanceR);
}

 if (d== 'l')
{
// Clears the trigPin
digitalWrite(trigPinL, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPinL, HIGH);
delayMicroseconds(10);
digitalWrite(trigPinL, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
durationL = pulseIn(echoPinL, HIGH);
// Calculating the distance
distanceL= durationL*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("DistanceL: ");
Serial.println(distanceL);
}

 if (d== 'd')
{
// Clears the trigPin
digitalWrite(trigPinDL, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPinDL, HIGH);
delayMicroseconds(10);
digitalWrite(trigPinDL, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
durationDL = pulseIn(echoPinDL, HIGH);
// Calculating the distance
distanceDL= durationDL*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("DistanceDL: ");
Serial.println(distanceDL);
}

 if (d== 'e')
{
// Clears the trigPin
digitalWrite(trigPinDR, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPinDR, HIGH);
delayMicroseconds(10);
digitalWrite(trigPinDR, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
durationDR = pulseIn(echoPinDR, HIGH);
// Calculating the distance
distanceDR= durationDR*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("DistanceDR: ");
Serial.println(distanceDR);
}

}

void setup() {
  // put your setup code here, to run once:
//    ultrasonic setup
  
pinMode(trigPinL, OUTPUT);
pinMode(echoPinL, INPUT); 

pinMode(trigPinDL, OUTPUT);
pinMode(echoPinDL, INPUT);

pinMode(trigPinR, OUTPUT);
pinMode(echoPinR, INPUT);

pinMode(trigPinF, OUTPUT);
pinMode(echoPinF, INPUT);

pinMode(trigPinDR, OUTPUT);
pinMode(echoPinDR, INPUT);

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //ultrasonic test
//  ultrasonic ('f');
//  ultrasonic ('r');
//  ultrasonic ('l');
//  ultrasonic ('d');
  ultrasonic ('e');

//  delay(1000);
}
