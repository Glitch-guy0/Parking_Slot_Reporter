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
