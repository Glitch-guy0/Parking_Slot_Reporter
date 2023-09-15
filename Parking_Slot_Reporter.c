//* Initialization
// todo: declare pins for each components
//* led's

//* servo motor
const byte servoPin = A0;

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
    // todo: declaring pin mode
}

//* loop
void loop()
{
    
}