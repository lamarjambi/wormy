#include <Servo.h>

Servo leftServo;   // pin 12 - moves counter-clockwise
Servo rightServo;  // pin 11 - moves clockwise (mirrored)

int pos = 0;

const int leftOffset = 10;

void setup() {
  leftServo.attach(11);
  rightServo.attach(12);

  leftServo.write(120);
  rightServo.write(90);
  delay(1000);
}

void loop() {
  // left motor turns CCW + right motor goes opposite (CW)
  for (pos = 180; pos >= 0; pos -= 1) {
    leftServo.write(max(0, pos - leftOffset));
    rightServo.write(180 - pos); // mirror
    delay(15);
  }

  // both motors go back to neutral states
  for (pos = 0; pos <= 90; pos += 1) {
    leftServo.write(pos);
    rightServo.write(180 - pos); // mirror
    delay(15);
  }
}