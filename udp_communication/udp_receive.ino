#include <WiFi.h>     // Include the WiFi library to connect to WiFi
#include <WiFiUdp.h>  // Include the WiFiUDP library to handle UDP communication

// Replace these with your WiFi network SSID and password
const char* ssid = "MY_WIFI_NAME";          // WiFi network name (SSID)
const char* password = "MY_WIFI_PASSWORD";    // WiFi network password

WiFiUDP udp;                         // Create a UDP instance
const unsigned int localPort = 8888;  // Define the local port to listen on for incoming UDP packets

void setup() {
  Serial.begin(115200);  // Start serial communication at a baud rate of 115200

  // Attempt to connect to the specified WiFi network
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    // Wait for connection, print dots to indicate progress
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");   // Print confirmation when WiFi is connected
  
  // Display the local IP address assigned to the device
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Start UDP listening on the specified port
  udp.begin(localPort);
  Serial.print("UDP server started on port ");
  Serial.println(localPort);
}

void loop() {
  // Check if a UDP packet is available
  int packetSize = udp.parsePacket();
  if (packetSize) {
    // If a packet is received, print its size
    Serial.print("Received packet of size ");
    Serial.println(packetSize);

    // Retrieve and print the sender's IP address
    Serial.print("From ");
    IPAddress remoteIp = udp.remoteIP();
    for (int i = 0; i < 4; i++) {
      Serial.print(remoteIp[i], DEC);
      if (i < 3) {
        Serial.print(".");  // Format IP address with dots
      }
    }

    // Retrieve and print the sender's port number
    Serial.print(", port ");
    Serial.println(udp.remotePort());

    // Initialize a string to store the incoming packet content
    String incomingPacket = "";
    
    // Read the packet's content into the string as long as data is available
    while (udp.available()) {
      incomingPacket += (char)udp.read();
    }

    // Display the contents of the received packet
    Serial.print("Contents: ");
    Serial.println(incomingPacket);
  }
}