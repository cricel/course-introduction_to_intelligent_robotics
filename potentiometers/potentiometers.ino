int potentiometersPin = 27;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(potentiometersPin);
  Serial.println(value);
}