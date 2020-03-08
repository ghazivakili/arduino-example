#include <WiFi.h>
#include <HTTPClient.h>
 
const char* ssid = "Vodafone-spring";
const char* password =  "****";
long randNumber;
String getlink;
void setup() {
 
  Serial.begin(115200);
  delay(4000);   //Delay needed before calling the WiFi.begin
 
  WiFi.begin(ssid, password); 
 
  while (WiFi.status() != WL_CONNECTED) { //Check for the connection
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println("Connected to the WiFi network");
 
}


void loop() {
  // put your main code here, to run repeatedly:
  if ((WiFi.status() == WL_CONNECTED)) { //Check the current connection status
    randNumber = random(10, 300);
    HTTPClient http;

    getlink = String("http://192.168.1.5:5000/value/1/1/"+String(randNumber));
    Serial.println(getlink);
    http.begin(getlink); //Specify the URL
    int httpCode = http.GET();                                        //Make the request
 
    if (httpCode > 0) { //Check for the returning code
 
        String payload = http.getString();
        Serial.println(httpCode);
        Serial.println(payload);
      }
 
    else {
      Serial.println("Error on HTTP request");
    }
 
    http.end(); //Free the resources
  }
 
  delay(10000);
}
