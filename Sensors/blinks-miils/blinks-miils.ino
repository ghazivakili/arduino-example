//Example: Blink sample with mills()

const int ledPin =  13;
const int ledPin2 =  12;
int ledState = LOW;
unsigned long previousMillis = 0;
unsigned long interval = 1000;

void setup() {
  pinMode(ledPin, OUTPUT);
    pinMode(ledPin2, OUTPUT);

}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;
    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;
    digitalWrite(ledPin, ledState);
    digitalWrite(ledPin2, !ledState);
  }
}
