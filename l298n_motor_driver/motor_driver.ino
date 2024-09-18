// Define motor control pins for Motor 1
int motor1en = 20;    // Enable pin for Motor 1
int motor1pin1 = 16;  // Control pin 1 for Motor 1
int motor1pin2 = 17;  // Control pin 2 for Motor 1

// Define motor control pins for Motor 2
int motor2en = 21;    // Enable pin for Motor 2
int motor2pin1 = 18;  // Control pin 1 for Motor 2
int motor2pin2 = 19;  // Control pin 2 for Motor 2

void setup() {
  // Set motor pins as outputs for Motor 1
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);

  // Set motor pins as outputs for Motor 2
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  // Set enable pins as outputs to control speed
  pinMode(motor1en, OUTPUT); 
  pinMode(motor2en, OUTPUT);
}

void loop() {
  // Controlling speed (0 = off and 255 = max speed)
  analogWrite(motor1en, 255); // Set Motor 1 to maximum speed
  analogWrite(motor2en, 200); // Set Motor 2 to slightly lower speed
  
  // Set Motor 1 to rotate in one direction
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  // Set Motor 2 to rotate in one direction
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  delay(3000); // Run motors in this direction for 3 seconds

  // Reverse the direction of Motor 1
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  // Reverse the direction of Motor 2
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  delay(3000); // Run motors in reverse direction for 3 seconds
}
