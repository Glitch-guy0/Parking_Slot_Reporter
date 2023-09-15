/*
 * this is only applicable if it **supports**
 much easier
*/

#include <Ultrasonic.h>

// Create an instance of the Ultrasonic class
Ultrasonic ultrasonic(triggerPin, echoPin);

// Measure the distance to an object
float distance = ultrasonic.ping();

// Print the distance to the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);