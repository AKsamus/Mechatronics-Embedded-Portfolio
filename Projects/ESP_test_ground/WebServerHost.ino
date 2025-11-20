#include <WiFi.h>
#include <WebServer.h>

// Replace with your network credentials
const char* ssid="***";  
const char* password="***";  

WebServer server(80);  // Web server on port 80

void setup() {
  Serial.begin(115200);
  
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("Connected to WiFi. IP Address: ");
  Serial.println(WiFi.localIP());  // Print IP Address of ESP32

  // Define a route (path) for the home page ("/")
  server.on("/", HTTP_GET, handleRoot);

  // Start the server
  server.begin();
}

void loop() {
  server.handleClient();  // Listen for incoming client requests
}

void handleRoot() {
  // Create a simple HTML page
  String html = "<html><body><h1>Welcome to ESP32 Web Server!</h1>";
  html += "<p>This is a simple web server hosted on the ESP32.</p>";
  html += "<p>Click the link below to control the ESP32.</p>";
  html += "<a href='/led_on'><button>Turn LED ON</button></a>";
  html += "<a href='/led_off'><button>Turn LED OFF</button></a>";
  html += "</body></html>";

  server.send(200, "text/html", html);  // Send HTML response
}
