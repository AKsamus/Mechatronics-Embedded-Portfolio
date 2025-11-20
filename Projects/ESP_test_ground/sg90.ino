#include <ESP32Servo.h>  // Include the ESP32 Servo library

Servo myservo;  // Create a servo object

int servoPin = 13;  // Define the pin where the servo is connected

void setup() {
  Serial.begin(115200);  // Start serial communication at 115200 baud rate
  myservo.attach(servoPin);  // Attach the servo to the pin
  Serial.println("Servo control started");
}

void loop() {
  Serial.println("Moving servo to 0 degrees...");
  for (int pos = 0; pos <= 90; pos++) {
    myservo.write(pos);              // Tell servo to go to position 'pos'
    Serial.print("Servo position: ");
    Serial.println(pos);             // Print the current position to Serial Monitor
    delay(50);                        // Wait for the servo to reach the position
  }
  delay(5000);  // Wait a bit at the end of the sweep

  Serial.println("Moving servo back to 0 degrees...");
  for (int pos = 90; pos >= 0; pos--) {
    myservo.write(pos);              // Tell servo to go to position 'pos'
    Serial.print("Servo position: ");
    Serial.println(pos);             // Print the current position to Serial Monitor
    delay(50);                        // Wait for the servo to reach the position
  }
  delay(5000);  // Wait a bit at the end of the sweep
}
