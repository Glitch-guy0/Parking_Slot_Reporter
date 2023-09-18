/**
 * This code sets up an array of infrared sensors and corresponding red and green LEDs, and
 * continuously checks the sensors to determine if all slots are filled, lighting up the red LED if
 * they are.
 */
 int ir[4] = {6,14,8,15};
 int ledr[4] = {2,3,4,5};
 int ledg[4] = {10, 11, 12, 13};
 int masterRedLedPin = 1;

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(ir[i], INPUT);
  }

  for (int i = 0; i < 4; i++) {
    pinMode(ledr[i], OUTPUT);
    pinMode(ledg[i], OUTPUT);
  }
  pinMode(masterRedLedPin, OUTPUT);
}

void loop() {
  int filledSlots = 0;

  for (int i = 0; i < 4; i++) {
    if (digitalRead(ir[i]) == HIGH) {
      digitalWrite(ledr[i], HIGH);
      digitalWrite(ledg[i], LOW);
      filledSlots++;
    } else {
      digitalWrite(ledr[i], LOW);
      digitalWrite(ledg[i], HIGH);
    }
  }

  if (filledSlots == 4) {
    digitalWrite(masterRedLedPin, HIGH);
  } else {
    digitalWrite(masterRedLedPin, LOW);
  }
}
#include <Servo.h>

// declaring servo object
Servo gateServo;


//* servo motor
const int servoPin = 9;
int angle = 0;

// initial gate position 
bool gateOpen = false;

// servo function
void checkGate(bool isCar)
{
    if(isCar && !gateOpen)
    {
        while(angle < 90)
        {
            angle += 15;
            gateServo.write(angle);
            delay(15);
        }
        gateOpen = true;
    }
    if(!isCar && gateOpen)
    {
        while(angle > 0)
        {
            angle -= 15;
            gateServo.write(angle);
            delay(15);
        }
        gateOpen = false;
    }
}

//* sonar at entrance detection
const int ultrasoundSignalPin = 7;


//* ultrasound sensor class
class UltrasoundSensor{
    private:
        int signalPin;
        const int thresholdDistance = 30;  //todo: important to initialize this value (in cms)
        long readDistanceCms()
            {
                pinMode(this->signalPin, OUTPUT);  // Clear the trigger
                digitalWrite(this->signalPin, LOW);
                delayMicroseconds(2);
                // Sets the trigger pin to HIGH state for 10 microseconds
                digitalWrite(this->signalPin, HIGH);
                delayMicroseconds(10);
                digitalWrite(this->signalPin, LOW);
                pinMode(this->signalPin, INPUT);
                // Reads the echo pin, and returns the sound wave travel time in cm
                return 0.01723 * pulseIn(this->signalPin, HIGH);
            } 

    public:
        UltrasoundSensor(int signalPin)
        {
            this->signalPin = signalPin;
        }
        bool near()
        {
            if(this->thresholdDistance > int(this->readDistanceCms()))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};

//* ultrasound sensor declaration
UltrasoundSensor ultrasound(ultrasoundSignalPin); 

// ultrasound sensor declaration
//* Setup
void setup()
{
    // Attach the gate servo to pin 9
    gateServo.attach(servoPin);

}

//* loop
void loop()
{
    checkGate(ultrasound.near());
}
