const int SWPin = 19;     // Joystick switch pin connected to pin 19

const int VRxPin = 26;    // Joystick VRx (horizontal) connected to pin 26
const int VRyPin = 27;    // Joystick VRy (vertical) connected to pin 27

int SW = 0;  // Variable to store the value read from the joystick switch

void setup() {
  Serial.begin(9600);  // Start serial communication at a baud rate of 9600

  // Set the joystick switch pin as input with an internal pull-up resistor enabled
  pinMode(SWPin, INPUT_PULLUP); 

  // Set the joystick analog pins as inputs (no pull-up needed for analog)
  pinMode(VRxPin, INPUT_PULLUP);  
  pinMode(VRyPin, INPUT_PULLUP);
}

void loop() {
  // Read the digital state of the joystick switch (pressed or not pressed)
  SW = digitalRead(SWPin);

  // Read the analog values of the joystick's VRx (horizontal) and VRy (vertical) axes
  int VRxValue = analogRead(VRxPin);  // Read horizontal position
  int VRyValue = analogRead(VRyPin);  // Read vertical position

  // Print the joystick switch state to the serial monitor
  Serial.print("\tSW = ");
  Serial.println(SW);

  // Print the analog values of the VRx and VRy axes to the serial monitor
  Serial.print(VRxValue);   // Horizontal axis value
  Serial.print(" | ");      // Separator for clarity
  Serial.println(VRyValue); // Vertical axis value

  delay(200);  // Delay for 200ms to avoid overwhelming the serial monitor with data
}
