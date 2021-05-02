/*
  ReadAnalogVoltage
  Reads an analog input on pin 0, converts it to voltage, and prints the result to the serial monitor.

  OPEN THE SERIAL MONITOR TO VIEW THE OUTPUT >> 
  Attach the center pin of a potentiometer to pin A2, and the outside pins to +5V and ground.

  This example code is in the public domain.
*/


// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(9,OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A2);
  analogWrite(9,sensorValue/4);
  //digitalWrite(4,1);

  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  delay(500);
  Serial.println(voltage);
}
