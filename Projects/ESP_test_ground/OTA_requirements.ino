#include <WiFi.h>
#include <ArduinoOTA.h>

// Replace with your Wi-Fi credentials
const char* ssid = "AK2G";
const char* password = "1234567890";
const int ledPin = 2;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  // Initialize the built-in LED pin as an output
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Initialize OTA service
  ArduinoOTA.onStart([]() {
    Serial.println("Start OTA update");
  });
  ArduinoOTA.onEnd([]() {
    Serial.println("\nOTA update complete");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress * 100) / total);
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("OTA Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
    else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
    else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
    else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
    else if (error == OTA_END_ERROR) Serial.println("End Failed");
  });

  ArduinoOTA.begin();
  Serial.println("OTA Ready");
}

void loop() {
  ArduinoOTA.handle();
  // Turn the LED on
  Serial.println("LED is turning ON");
  digitalWrite(ledPin, HIGH);
  delay(1000);  // Wait for one second (1000 milliseconds)
  
  // Turn the LED off
  Serial.println("LED is turning OFF");
  digitalWrite(ledPin, LOW);
  delay(1000);  // Wait for one second
}
