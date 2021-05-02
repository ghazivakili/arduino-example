// include the library code:
#include <LiquidCrystal.h>
int sensorPin = 1;
int motor = 9;
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(20, 4);
  Serial.begin(9600);  //Start the serial connection with the computer

  // Print a message to the LCD.
  lcd.setCursor(6, 0);
  lcd.print("LCD 20*4");
  lcd.setCursor(3,1);
  lcd.print("Temperature is!");
  lcd.setCursor(0, 2);
  lcd.print("C:");
  lcd.setCursor(0, 3);
  lcd.print("F:");

}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  
      //getting the voltage reading from the temperature sensor
     int reading = analogRead(sensorPin);  
     
     // converting that reading to voltage, for 3.3v arduino use 3.3
     float voltage = reading * 5.0;
     voltage /= 1024.0; 
     
     // print out the voltage
     Serial.print(voltage); Serial.println(" volts");
     
     // now print out the temperature
     float temperatureC = (voltage) * 100 ;  //converting from 10 mv per degree wit 500 mV offset
                                                   //to degrees ((voltage) times 100)
     float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
     Serial.print(temperatureC); Serial.println(" degrees C");
  
  lcd.setCursor(2, 2);
  // print the number of seconds since reset:
  lcd.print(temperatureC);
  lcd.setCursor(2, 3);
  // print the number of seconds since reset:
  lcd.print(temperatureF);
  digitalWrite(motor,1);
  delay(1000);
  analogWrite(motor,50);
  delay(1000);
  delay(500);
  
}
 
