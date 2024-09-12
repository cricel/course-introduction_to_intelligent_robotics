// Define the pin number where the potentiometer is connected
int potentiometersPin = 26;

void setup() {
  // Initialize serial communication at a baud rate of 9600
  Serial.begin(9600);
}

void loop() {
  // Read the analog input from the potentiometer (range 0-1023)
  int value = analogRead(potentiometersPin);
  // Print the potentiometer value to the serial monitor
  Serial.println(value);
  // Add a small delay to prevent spamming the serial monitor (optional)
  delay(100);  // Adjust delay if needed
}