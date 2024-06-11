#include <Servo.h>

Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;

void setup() {
  // put your setup code here, to run once:
  myservo1.attach(2);
  myservo2.attach(3);
  myservo3.attach(4);
  myservo4.attach(5);
  myservo5.attach(6);

}

void loop() {
  // put your main code here, to run repeatedly:
  myservo1.write(180);
  myservo2.write(180);
  myservo3.write(180);
  myservo4.write(180);
  myservo5.write(180);

  delay(1000);

  myservo1.write(0);
  myservo2.write(0);
  myservo3.write(0);
  myservo4.write(0);
  myservo5.write(0);

  delay(1000);
}
