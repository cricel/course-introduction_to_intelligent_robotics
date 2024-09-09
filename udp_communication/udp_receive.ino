#include <WiFi.h>
#include <WiFiUdp.h>
// Replace these with your WiFi network settings
const char* ssid = "atom";
const char* password = "test123456";
WiFiUDP udp;
const unsigned int localPort = 8888; // Local port to listen on
const unsigned int remotePort = 8889;  // Remote port to send the message to
IPAddress remoteIp(10, 42, 0, 172);  // Replace with the IP address of your Python client

const int buttonPin = 27;   // Pin where the button is connected
const int ledPin = 16;
bool lastButtonState = LOW;

void setup(){
  Serial.begin(115200);

  // Setup Button & LED
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("waiting to be connected...");
  }
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  // Start UDP
  udp.begin(localPort);
  Serial.print("UDP server started on port ");
  Serial.println(localPort);
}
void loop() {
  int packetSize = udp.parsePacket();
  if (packetSize) {
    // Received a packet
    Serial.print("Received packet of size ");
    Serial.println(packetSize);
    Serial.print("From ");
    IPAddress remoteIp = udp.remoteIP();
    for (int i = 0; i < 4; i++) {
      Serial.print(remoteIp[i], DEC);
      if (i < 3) {
        Serial.print(".");
      }
    }
    Serial.print(", port ");
    Serial.println(udp.remotePort());
    // Read the packet into a string
    String incomingPacket = "";
    while (udp.available()) {
      incomingPacket += (char)udp.read();
    }
    Serial.print("Contents: ");
    Serial.println(incomingPacket);
    if (incomingPacket == "1"){
      digitalWrite(ledPin, HIGH);
    }
    else if (incomingPacket == "a"){
      digitalWrite(ledPin, LOW);
    }
  }

  // Check if the button is pressed
  bool buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH && lastButtonState == LOW) {
    Serial.println("Button pressed, sending message to Python...");

    // Send UDP message to Python client
    String message = "Button Pressed!";
    udp.beginPacket(remoteIp, remotePort);
    udp.write(message.c_str());
    udp.endPacket();
  }
  lastButtonState = buttonState;  // Save the current button state
}

