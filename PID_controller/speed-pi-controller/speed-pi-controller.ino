
#include <PID_v1.h>

#define encoder0PinA  2
#define encoder0PinB  3

volatile long encoder0Pos=0;
long newposition;
long oldposition = 0;
unsigned long newtime;
unsigned long oldtime = 0;
long vel;
int basePin = 11;

int i=0;
double amplitude=50;
double Setpoint, Input, Output, errort;
double val_output;//Power supplied to the motor PWM value.
float PIDinMin = 0;
float PIDinMax = 1000;
double Kp=5, Ki=5, Kd=0;  
//double Kp=0.6, Ki=5, Kd=0; 
//PID myPID(&Input, &val_output, &Setpoint, Kp, Ki, Kd, DIRECT); 


float PIDoutMin = 0;
float PIDoutMax = 1000;

float outMin = 0;
float outMax = 255;
float outRangeFactor = outMax / PIDoutMax;


void setup()
{
  pinMode(encoder0PinA, INPUT);
  digitalWrite(encoder0PinA, HIGH);       // turn on pullup resistor
  pinMode(encoder0PinB, INPUT);
  digitalWrite(encoder0PinB, HIGH);       // turn on pullup resistor
  attachInterrupt(0, doEncoder, RISING);  // encoDER ON PIN 2
  Serial.begin (9600);
  //Serial.println("start");                // a personal quirk
  pinMode(basePin,OUTPUT);
  
  Setpoint = 250;
  analogWrite(basePin,255); 
  //turn the PID on
 //myPID.SetMode(AUTOMATIC);
}

void loop()
{

newposition = encoder0Pos;
newtime = millis();
vel = ((newposition-oldposition) * 1000/(newtime-oldtime));

oldposition = newposition;
oldtime = newtime;
  Input = vel;
  //myPID.Compute();
 PController();
  
  if(i>10){
 //analogWrite(basePin,255); 
  analogWrite(basePin,val_output); 
  Serial.print (vel);
  Serial.print("\t");
  Serial.print(Setpoint);
  Serial.print("\t");
  Serial.print(val_output);
  Serial.print("\t");
  Serial.println (errort);
   // Serial.print("\t");
 // Serial.println((i%500));
  }

  if((i%500)==0)
    {
      
      amplitude=-amplitude;
      Setpoint=(Setpoint) +(amplitude);
      //myPID.Compute();
     PController();
      
      }
  i++;
    delay(250);

}

void doEncoder()
{
  if (digitalRead(encoder0PinA) == digitalRead(encoder0PinB)) {
    encoder0Pos++;
  } else {
    encoder0Pos--;
  }
}



void PController()
{
  errort=Setpoint-Input;
  val_output=(Kp*errort);
    //Serial.print("\t");
    //Serial.print(val_output);
  if(val_output<0){
    val_output=80;
    }else if(val_output>255){
      val_output=255;
      }
   // delay(10);
  
  
  }

