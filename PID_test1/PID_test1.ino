// ultrasonic pins
const int trigPinL = 40;
const int echoPinL = 38;

const int trigPinR = 34;
const int echoPinR = 36;

long durationL;
float distanceL;

long durationR;
float distanceR;

//PID constants
double kp = 50;
double ki = 0;
double kd = 0;

const int en_right=7, en_left=2, rightPin_1 = 5,rightPin_2 = 6,leftPin_1 = 3,leftPin_2 = 4;
float vL = 100, vR = 100;

void ultrasonic (char d)
{
 if (d== 'r')
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

 else if (d== 'l')
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
}

 
unsigned long currentTime, previousTime;
double elapsedTime;
double error;
double lastError;
double input, output, setPoint;
double cumError, rateError;
 
void setup(){
  setPoint = 0;                          //set point at zero degrees
  pinMode(trigPinL, OUTPUT);
  pinMode(echoPinL, INPUT); 

  pinMode(trigPinR, OUTPUT);
  pinMode(echoPinR, INPUT);

  digitalWrite(rightPin_2 , HIGH);
  digitalWrite(rightPin_1 , LOW);

  digitalWrite(leftPin_2 , LOW);
  digitalWrite(leftPin_1 , HIGH);

  Serial.begin(9600);
}    
 
void loop(){

  ultrasonic ('r');
  ultrasonic ('l');
  
//  input = analogRead(A0);                //read from rotary encoder connected to A0
  output = computePID(input);
  Serial.print("Output:");
  Serial.println(output);
  
  delay(100);
//  analogWrite(3, output);                //control the motor based on PID value
  vL = 100 - output*100/255;
  Serial.print("leftV:");
  Serial.println(vL);
  Serial.print("rightV:");
  Serial.println(vR);
  vR = 100 + output*100/255;

  analogWrite(en_left , vL);
  analogWrite(en_right , vR); 

  Serial.print("\n");
  delay(1000);
}
 
double computePID(double inp){     
        currentTime = millis();                //get current time
        elapsedTime = (double)(currentTime - previousTime);        //compute time elapsed from previous computation
        
        error = distanceL - distanceR;                                // determine error
        cumError += error * elapsedTime;                // compute integral
        rateError = (error - lastError)/elapsedTime;   // compute derivative
 
        double out = kp*error + ki*cumError + kd*rateError;                //PID output               
 
        lastError = error;                                //remember current error
        previousTime = currentTime;                        //remember current time
 
        return out;                                        //have function return the PID output
}
