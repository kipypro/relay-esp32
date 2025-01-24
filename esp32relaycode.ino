#include <WiFi.h>
#include <WebServer.h>
#include <ESPmDNS.h>  // For mDNS

// Replace with your own WiFi SSID and password
const char* ssid = "ssid";
const char* password = "password";

// Define the pins for the relays
const int relayPin1 = 23;
const int relayPin2 = 22;
const int relayPin3 = 21;
const int relayPin4 = 19;

// Keep track of the relay states
bool relay1State = LOW;
bool relay2State = LOW;
bool relay3State = LOW;
bool relay4State = LOW;

WebServer server(80);

void setup() {
  // Start serial communication
  Serial.begin(115200);

  // Set the relay pins as output
  pinMode(relayPin1, OUTPUT);
  pinMode(relayPin2, OUTPUT);
  pinMode(relayPin3, OUTPUT);
  pinMode(relayPin4, OUTPUT);
  
  // Turn the relays off
  digitalWrite(relayPin1, relay1State);
  digitalWrite(relayPin2, relay2State);
  digitalWrite(relayPin3, relay3State);
  digitalWrite(relayPin4, relay4State);

  // Connect to WiFi network
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);

  // Wait until the connection is established
  int retries = 0;
  const int maxRetries = 20;
  while (WiFi.status() != WL_CONNECTED && retries < maxRetries) {
    delay(500);
    Serial.print(".");
    retries++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println();
    Serial.println("Connected to WiFi!");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    // Start the mDNS responder
    if (!MDNS.begin("esp32")) {
      Serial.println("Error setting up MDNS responder!");
    } else {
      Serial.println("mDNS responder started! Access via http://esp32.local");
    }

    // Define the web server routes
    server.on("/", handleRoot);
    server.on("/toggle1", handleToggle1);
    server.on("/toggle2", handleToggle2);
    server.on("/toggle3", handleToggle3);
    server.on("/toggle4", handleToggle4);
    
    // Start the web server
    server.begin();
    Serial.println("Web server started!");
  } else {
    Serial.println();
    Serial.println("Failed to connect to WiFi.");
    Serial.println("Check the SSID and password and try again.");
  }
}

void loop() {
  server.handleClient();
}

void handleRoot() {
  // HTML page with buttons to toggle the relays
  String html = "<h1>Control Relays</h1>";
  html += "<p><a href=\"/toggle1\"><button>" + String(relay1State ? "Turn Relay 1 Off" : "Turn Relay 1 On") + "</button></a></p>";
  html += "<p><a href=\"/toggle2\"><button>" + String(relay2State ? "Turn Relay 2 Off" : "Turn Relay 2 On") + "</button></a></p>";
  html += "<p><a href=\"/toggle3\"><button>" + String(relay3State ? "Turn Relay 3 Off" : "Turn Relay 3 On") + "</button></a></p>";
  html += "<p><a href=\"/toggle4\"><button>" + String(relay4State ? "Turn Relay 4 Off" : "Turn Relay 4 On") + "</button></a></p>";
  server.send(200, "text/html", html);
}

void handleToggle1() {
  relay1State = !relay1State;
  digitalWrite(relayPin1, relay1State ? HIGH : LOW);  // Turn the relay on or off
  Serial.print("Relay 1 is now: ");
  Serial.println(relay1State ? "On" : "Off");
  Serial.print("RelayPin1 (GPIO 23) is: ");
  Serial.println(digitalRead(relayPin1));
  handleRoot(); // Update the page after toggling
}

void handleToggle2() {
  relay2State = !relay2State;
  digitalWrite(relayPin2, relay2State ? HIGH : LOW);  // Turn the relay on or off
  Serial.print("Relay 2 is now: ");
  Serial.println(relay2State ? "On" : "Off");
  Serial.print("RelayPin2 (GPIO 22) is: ");
  Serial.println(digitalRead(relayPin2));
  handleRoot(); // Update the page after toggling
}

void handleToggle3() {
  relay3State = !relay3State;
  digitalWrite(relayPin3, relay3State ? HIGH : LOW);  // Turn the relay on or off
  Serial.print("Relay 3 is now: ");
  Serial.println(relay3State ? "On" : "Off");
  Serial.print("RelayPin3 (GPIO 21) is: ");
  Serial.println(digitalRead(relayPin3));
  handleRoot(); // Update the page after toggling
}

void handleToggle4() {
  relay4State = !relay4State;
  digitalWrite(relayPin4, relay4State ? HIGH : LOW);  // Turn the relay on or off
  Serial.print("Relay 4 is now: ");
  Serial.println(relay4State ? "On" : "Off");
  Serial.print("RelayPin4 (GPIO 19) is: ");
  Serial.println(digitalRead(relayPin4));
  handleRoot(); // Update the page after toggling
}
