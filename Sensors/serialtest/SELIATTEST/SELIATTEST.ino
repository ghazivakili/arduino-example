//Example: print on the serial port the mills() value.

unsigned long time;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("Time: ");
  time = millis();
  Serial.println(time); //prints time since program started then goes to next line
  Serial.print(time);    //prints time since program started 
  Serial.print("\n");     // goes to next line
  int bytesSent = Serial.write("hello"); //send the string "hello" and return the length of the string.
  Serial.println(bytesSent);
  delay(1000);          // wait a second so as not to send massive amounts of data
}
