#include <WiFi.h>     // Include WiFi library to manage WiFi connections
#include <WiFiUdp.h>  // Include WiFiUDP library to handle UDP communication

// WiFi network settings
const char* ssid = "MY_WIFI_NAME";          // WiFi network name (SSID)
const char* password = "MY_WIFI_PASSWORD"; // WiFi password

WiFiUDP udp;                        // Create a UDP instance
const unsigned int localPort = 8888; // Local port to listen for incoming UDP packets
const unsigned int remotePort = 8889; // Remote port to send outgoing UDP messages
IPAddress remoteIp(192, 168, 1, 176);  // IP address of the Python client to send UDP messages to

// Button and LED pin configurations
const int buttonPin = 17;  // GPIO pin connected to the button
const int ledPin = 16;     // GPIO pin connected to an LED
bool lastButtonState = LOW; // Store the last button state for edge detection

void setup() {
  Serial.begin(115200);  // Start serial communication at 115200 baud

  // Setup button pin as input with an internal pull-up resistor
  pinMode(buttonPin, INPUT_PULLUP);
  
  // Setup the LED pin as output
  pinMode(ledPin, OUTPUT);

  // Connect to WiFi using the provided credentials
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    // Wait until the device connects to WiFi, print progress
    delay(500);
    Serial.println("waiting to be connected...");
  }
  Serial.println("WiFi connected");   // Confirm WiFi connection
  
  // Print the device's IP address once connected
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Start listening for UDP packets on the local port
  udp.begin(localPort);
  Serial.print("UDP server started on port ");
  Serial.println(localPort);
}

void loop() {
  // Check if there is an incoming UDP packet
  int packetSize = udp.parsePacket();
  if (packetSize) {
    // If a packet is received, print its size
    Serial.print("Received packet of size ");
    Serial.println(packetSize);

    // Retrieve the sender's IP address
    Serial.print("From ");
    IPAddress remoteIp = udp.remoteIP();
    for (int i = 0; i < 4; i++) {
      Serial.print(remoteIp[i], DEC);
      if (i < 3) {
        Serial.print(".");
      }
    }

    // Retrieve the sender's port
    Serial.print(", port ");
    Serial.println(udp.remotePort());

    // Read the packet's content into a string
    String incomingPacket = "";
    while (udp.available()) {
      incomingPacket += (char)udp.read();
    }

    // Display the packet contents
    Serial.print("Contents: ");
    Serial.println(incomingPacket);

    // Control the LED based on the received message
    if (incomingPacket == "1") {
      digitalWrite(ledPin, HIGH);  // Turn the LED on if the packet contains "1"
    } else if (incomingPacket == "a") {
      digitalWrite(ledPin, LOW);   // Turn the LED off if the packet contains "a"
    }
  }

  // Check if the button is pressed (detect rising edge)
  bool buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH && lastButtonState == LOW) {
    Serial.println("Button pressed, sending message to Python...");

    // Send a message to the Python client when the button is pressed
    String message = "Button Pressed!";
    udp.beginPacket(remoteIp, remotePort);   // Begin the UDP packet to the Python client
    udp.write(message.c_str());              // Write the message content
    udp.endPacket();                         // Send the packet
  }

  // Save the current button state for edge detection in the next loop
  lastButtonState = buttonState;
}