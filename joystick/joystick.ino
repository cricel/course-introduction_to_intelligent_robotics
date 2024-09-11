const int SWPin = 19;

const int VRxPin = 26; // Joystick VRx connected to pin 27
const int VRyPin = 27; // Joystick VRy connected to pin 26

int SW = 0; // value read from the switch

void setup() {
  Serial.begin(9600);
  pinMode(SWPin, INPUT_PULLUP); // Using INPUT_PULLUP to enable internal pull-up resistor
  pinMode(VRxPin, INPUT_PULLUP);
  pinMode(VRyPin, INPUT_PULLUP);
}

void loop() {
  SW = digitalRead(SWPin);

  // Read the analog values of joystick VRx and VRy
  int VRxValue = analogRead(VRxPin);
  int VRyValue = analogRead(VRyPin);

  // Print the switch state, LED state, and brightness to the Serial Monitor
  Serial.print("\tSW = ");
  Serial.println(SW);
  Serial.print(VRxValue);
  Serial.print(" | ");
  Serial.println(VRyValue);

  delay(200);
}