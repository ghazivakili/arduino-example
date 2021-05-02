#include <SoftwareSerial.h>
SoftwareSerial BTserial(2, 3); // RX | TX

int incoming;
int LED_BUILTIN = 2;

void setup() {
  Serial.begin(9600); //Start Serial monitor in 9600
  BTserial.begin(9600); //Name of your Bluetooth Signal
  Serial.println("Bluetooth Device is Ready to Pair");

  pinMode (LED_BUILTIN, OUTPUT);//Specify that LED pin is output
}

void loop() {
  
  if (BTserial.available()) //Check if we receive anything from Bluetooth
  {
    incoming = BTserial.read(); //Read what we recevive 
    Serial.print("Received:"); Serial.println(incoming);

    if (incoming == 49) //1 ASCI code
        {
        digitalWrite(LED_BUILTIN, HIGH);
        BTserial.println("LED turned ON");
        Serial.println("LED turned ON");
        }
        
    if (incoming == 48) //0 ASCI code
        {
        digitalWrite(LED_BUILTIN, LOW);
        BTserial.println("LED turned OFF");
        Serial.println("LED turned OFF");
        }     
  }
  delay(20);
}
