//* Initialization
// todo: declare pins for each components
//* led's

//* servo motor
const byte servoPin = A0;

//* IRs at entrance detection
const int triggerPin = 5;
const int echoPin = 6;


//* ulterasound hos sleep for 100ms

class UltrasoundSensor{
    private:
        int signalPin;
        const int thresholdDistance = 5;
        long readDistanceCms(int signalPin)
            {
                pinMode(signalPin, OUTPUT);  // Clear the trigger
                digitalWrite(signalPin, LOW);
                delayMicroseconds(2);
                // Sets the trigger pin to HIGH state for 10 microseconds
                digitalWrite(signalPin, HIGH);
                delayMicroseconds(10);
                digitalWrite(signalPin, LOW);
                pinMode(signalPin, INPUT);
                // Reads the echo pin, and returns the sound wave travel time in cm
                return 0.01723 * pulseIn(signalPin, HIGH);
            } 

    public:
        void UltrasoundSensor(int signalPin)
        {
            this.signalPin = signalPin;
        }
        bool near()
        {
            if(this.thresholdDistance > this.readDistanceCms())
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        bool far()
        {
            if(this.thresholdDistance <= this.readDistanceCms())
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};
//* Setup
void setup()
{
    // todo: declaring pin mode
}

//* loop
void loop()
{

}