
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
double Setpoint, Input, Output;
double val_output;//Power supplied to the motor PWM value.
//double Kp=0.6, Ki=5, Kd=0;  
double Kp=0.6, Ki=5, Kd=0; 
PID myPID(&Input, &val_output, &Setpoint, Kp, Ki, Kd, DIRECT); 


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
  
  Setpoint = 150*5;

  //turn the PID on
  myPID.SetMode(AUTOMATIC);
}

void loop()
{

newposition = encoder0Pos;
newtime = millis();
vel = ((newposition-oldposition) * 1000 /(newtime-oldtime)); // N=1 

oldposition = newposition;
oldtime = newtime;
  Input = vel;
  myPID.Compute();

  if(i>10){
  analogWrite(basePin,val_output); 
  Serial.print (vel);
  Serial.print("\t");
  Serial.print(Setpoint);
  Serial.print("\t");
  Serial.println (val_output);
   // Serial.print("\t");
 // Serial.println((i%500));
  }

  if((i%500)==0)
    {
      
      amplitude=-amplitude;
      Setpoint=Setpoint +(amplitude*2);
      myPID.Compute();
      
      }
  i++;
delay(60);

}

void doEncoder()
{
  if (digitalRead(encoder0PinA) == digitalRead(encoder0PinB)) {
    encoder0Pos++;
  } else {
    encoder0Pos--;
  }
}
