// Define the pin connected to the built-in LED
const int ledPin = 2;//2;  // On most ESP32 boards, the built-in LED is connected to pin 2

void setup() {
  // Initialize the built-in LED pin as an output
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(115200);
}

void loop() {
  // Turn the LED on
  Serial.println("LED is turning ON");
  digitalWrite(ledPin, HIGH);
  delay(1000);  // Wait for one second (1000 milliseconds)
  
  // Turn the LED off
  Serial.println("LED is turning OFF");
  digitalWrite(ledPin, LOW);
  delay(1000);  // Wait for one second
}
