/*

  for manual connection and working

*/
// Define the Trigger and Echo pins
//* Digital pins
const int triggerPin = 7;
const int echoPin = 8;

void setup() {
  // Set the Trigger pin as output
  pinMode(triggerPin, OUTPUT);

  // Set the Echo pin as input
  //* Which listens to the echo sound
  pinMode(echoPin, INPUT);

  // Serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Send a pulse to the Trigger pin
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  // Measure the pulse length on the Echo pin
  long pulseLength = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters
  float distance = pulseLength * 0.034 / 2;

  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);

  // Wait for 1 second
  delay(1000);
}