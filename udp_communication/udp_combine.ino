#include <WiFi.h>
#include <WiFiUdp.h>
// Replace these with your WiFi network settings
const char* ssid = "SHIELD";
const char* password = "AVENGERS";
WiFiUDP udp;
const unsigned int localPort = 8888; // Local port to listen on

void setup() {
  Serial.begin(115200);
  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
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
  }
}

