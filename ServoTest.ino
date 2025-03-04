#include <Servo.h>

Servo testservo;

uint32_t next;
int i = -180;
void setup() {
  //7 pin for white
  testservo.attach(7, 1000, 2000);
  Serial.begin(9600);
}

void loop() {
  i = analogRead(2)/5.68333333;
  testservo.write(i);
  Serial.println(testservo.read());
  delay(10);
}
