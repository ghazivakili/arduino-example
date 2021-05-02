

/*
 * created by Mohammad
 * 
 * Complete Guide for Ultrasonic Sensor HC-SR04
 *
    Ultrasonic sensor Pins:
        VCC: +5VDC
        Trig : Trigger (INPUT) - Pin11
        Echo: Echo (OUTPUT) - Pin 12
        GND: GND
 */
 
int trigPin = 4;    // Trigger
int echoPin = 3;    // Echo
long duration, cm, inches;
unsigned long currentMillis;//
int ledState = LOW;
unsigned long previousMillis = 0;
unsigned long interval = 1000;
const int ledPin =  13;
 
void setup() {
  //Serial Port begin
  Serial.begin (9600);
  pinMode(ledPin, OUTPUT);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
 
void loop() {
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  currentMillis = millis();
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // Convert the time into a distance
  cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  inches = (duration/2) / 74;   // Divide by 74 or multiply by 0.0135
  
  if(cm<100){
  if (currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;
    
    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;
    digitalWrite(ledPin, ledState);
     }
  }else{
  digitalWrite(ledPin, LOW);
  }
  
  Serial.print(inches);
  Serial.print(" in, ");
  Serial.print(cm);
  Serial.print(" cm");
  Serial.println();
  
    // turn the LED on (HIGH is the voltage level)
 // digitalWrite(13, HIGH);
 // delay(1000); // Wait for 1000 millisecond(s)
  // turn the LED off by making the voltage LOW
//  digitalWrite(13, LOW);
//  delay(1000); // Wait for 1000 millisecond(s)
  
  
  //delay(250);
}
