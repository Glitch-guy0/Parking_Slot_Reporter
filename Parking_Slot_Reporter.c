#include <Servo.h>

/******* Test Code ******************************************************************************/

class Ultrasound
{
  public:
    bool near()
    {
        return true;
    }
};
Ultrasound ultrasound;
/*********Test Code end **************************************************************************/

//* Initialization

// creating objects
Servo gateServo;

// todo: declare pins for each components
//* led's

//* servo motor
const int servoPin = 9;

//* IRs at entrance detection
const int triggerPin = 5;
const int echoPin = 6;

// initial gate position 
bool gateOpen = false;

// servo function
void checkGate(bool isCar)
{
    if(isCar && !gateOpen)
    {
        int angle = 0;
        while(angle < 90)
        {
            angle += 15;
            gateServo.write(angle);
            delay(15);
            Serial.println(angle); //***** Debug code *****************************************
        }
        gateOpen = true;
    }
    if(!isCar && gateOpen)
    {
        int angle = 90;
        while(angle < 0)
        {
            angle -= 15;
            gateServo.write(angle);
            delay(15);
            Serial.println(angle); //************ Debug code ************************************
        }
        gateOpen = false;
    }
}
//* Setup
void setup()
{
    // todo: declaring pin mode

/*****  Temporary  ********************************************************************************/
    // Set the servo pin mode to output
    pinMode(servoPin, OUTPUT);

    // Set the IR sensor pin modes to input
    pinMode(triggerPin, INPUT);
    pinMode(echoPin, INPUT);

    Serial.begin(9600);
/*****  Temporary  ***********************************************************************************/
    // * servo pin declaration
    // Attach the gate servo to pin 9
    gateServo.attach(servoPin);

}

//* loop
void loop()
{
    checkGate(ultrasound.near());
}