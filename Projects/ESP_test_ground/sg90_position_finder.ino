#include <ESP32Servo.h>  // Include the ESP32 Servo library

Servo myservo;  // Create a servo object

int servoPin = 13;  // Define the pin where the servo is connected

void setup() {
  Serial.begin(115200);  // Start serial communication at 115200 baud rate
  myservo.attach(servoPin);  // Attach the servo to the pin
  Serial.println("Servo control started");
}

void loop() {
  //Serial.println("Moving servo to 0 degrees...");
  //myservo.write(90);
  //delay(5000);
  Serial.println("ON");
  myservo.write(38);
  delay(250);
  myservo.write(100);
  delay(5000);
  Serial.println("OFF");
  myservo.write(130);
  delay(250);
  myservo.write(100);
  delay(5000);
  //Serial.println("Moving servo to 0 degrees...");
 // myservo.write(0);
 // delay(5000);
  //Serial.println("Moving servo to 45 degrees...");
  //myservo.write(65);
  //delay(5000);
  //Serial.println("Moving servo to 135 degrees...");
 // myservo.write(155);
 // delay(5000);
  //delay(5000);
  
  
                     // Wait for the servo to reach the position
  
 
}
