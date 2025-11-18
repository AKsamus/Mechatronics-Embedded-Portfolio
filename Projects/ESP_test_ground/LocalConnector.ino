#include <WiFi.h>
#include <WebServer.h>

// Replace with your network credentials
const char *ssid = "TuBhiLele";
const char *password = "TuBhiLele2";

// Create a web server object
WebServer server(80);

// LED connected to GPIO 32
const int ledPin = 32;  

// HTML content for the switch page
const char* htmlPage = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>On/Off Switch</title>
  <style>
    .switch {
      position: relative;
      display: inline-block;
      width: 60px;
      height: 34px;
    }
    .switch input {
      opacity: 0;
      width: 0;
      height: 0;
    }
    .slider {
      position: absolute;
      cursor: pointer;
      top: 0;
      left: 0;
      right: 0;
      bottom: 0;
      background-color: #ccc;
      transition: 0.4s;
      border-radius: 34px;
    }
    .slider:before {
      position: absolute;
      content: "";
      height: 26px;
      width: 26px;
      border-radius: 50%;
      left: 4px;
      bottom: 4px;
      background-color: white;
      transition: 0.4s;
    }
    input:checked + .slider {
      background-color: #4CAF50;
    }
    input:checked + .slider:before {
      transform: translateX(26px);
    }
  </style>
</head>
<body>
<h2>HTML On/Off Switch</h2>
<label class="switch">
  <input type="checkbox" id="switch" onchange="toggleSwitch()">
  <span class="slider"></span>
</label>
<script>
  function toggleSwitch() {
    var switchState = document.getElementById('switch').checked ? 'on' : 'off';
    fetch(`/toggle?state=${switchState}`)
      .then(response => response.text())
      .then(data => console.log(data));
  }
</script>
</body>
</html>
)rawliteral";

// Set up the web server routes
void handleRoot() {
  server.send(200, "text/html", htmlPage);
}

void handleToggle() {
  String state = server.arg("state");
  if (state == "on") {
    // Do something when switch is ON
    digitalWrite(ledPin, HIGH);  // Turn the LED on
    Serial.println("Switch is ON");
  } else {
    // Do something when switch is OFF
    digitalWrite(ledPin, LOW);   // Turn the LED off
    Serial.println("Switch is OFF");
  }
  server.send(200, "text/plain", "Switch state updated to: " + state);
}

void setup() {
  // Start serial communication
  Serial.begin(115200);

  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);
  
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  
  // Start the web server
  server.on("/", handleRoot);
  server.on("/toggle", handleToggle);
  server.begin();
}

void loop() {
  // Handle incoming client requests
  server.handleClient();
}
