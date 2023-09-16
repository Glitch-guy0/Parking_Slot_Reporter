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