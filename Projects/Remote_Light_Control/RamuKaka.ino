#include <WiFi.h>
#include <WebServer.h>
#include <ESP32Servo.h>

// Replace with your network credentials
const char *ssid = "AK2G";
const char *password = "1234567890";

WebServer server(80);
Servo myServo;

const int servoPin = 27;
int servoState = 0;  // 0 = OFF, 1 = ON

void handleRoot() {
  String html = R"rawliteral(
    <!DOCTYPE html>
    <html lang="en">
    <head>
      <meta charset="UTF-8">
      <meta name="viewport" content="width=device-width, initial-scale=1.0">
      <title>ESP32 Servo Control</title>
      <style>
        body {
          font-family: Arial, sans-serif;
          background: #f2f2f2;
          text-align: center;
          padding: 50px;
        }
        h2 {
          color: #333;
        }
        .switch {
          position: relative;
          display: inline-block;
          width: 80px;
          height: 40px;
          margin-top: 20px;
        }
        .switch input {
          display: none;
        }
        .slider {
          position: absolute;
          cursor: pointer;
          top: 0; left: 0; right: 0; bottom: 0;
          background-color: #ccc;
          transition: 0.4s;
          border-radius: 40px;
        }
        .slider:before {
          position: absolute;
          content: "";
          height: 32px;
          width: 32px;
          left: 4px;
          bottom: 4px;
          background-color: white;
          transition: 0.4s;
          border-radius: 50%;
        }
        input:checked + .slider {
          background-color: #4CAF50;
        }
        input:checked + .slider:before {
          transform: translateX(40px);
        }
        .status {
          margin-top: 20px;
          font-size: 1.2em;
          color: #444;
        }
      </style>
    </head>
    <body>
      <h2>ESP32 Servo Control</h2>
      <label class="switch">
        <input type="checkbox" id="servoSwitch" onchange="toggleServo(this)" )rawliteral";

  if (servoState == 1) html += "checked";

  html += R"rawliteral(>
        <span class="slider"></span>
      </label>
      <div class="status" id="statusText">Servo is )rawliteral";
  html += (servoState == 1 ? "ON" : "OFF");
  html += R"rawliteral(</div>

      <script>
        function toggleServo(element) {
          var xhr = new XMLHttpRequest();
          xhr.open("GET", "/toggle?state=" + (element.checked ? "1" : "0"), true);
          xhr.send();
          document.getElementById("statusText").innerText = "Servo is " + (element.checked ? "ON" : "OFF");
        }
      </script>
    </body>
    </html>
  )rawliteral";

  server.send(200, "text/html", html);
}

void handleToggle() {
  if (server.hasArg("state")) {
    servoState = server.arg("state").toInt();
    if (servoState == 1) {
      myServo.write(38); // ON position
      delay(200);
      myServo.write(100);
    } else {
      myServo.write(130);  // OFF position
      delay(200);
      myServo.write(100);
    }
    server.send(200, "text/plain", "OK");
  }
}

void setup() {
  Serial.begin(115200);
  myServo.attach(servoPin);
  myServo.write(100); // Default position

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected. IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/toggle", handleToggle);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
