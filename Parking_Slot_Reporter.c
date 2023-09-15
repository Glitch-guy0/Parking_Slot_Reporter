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