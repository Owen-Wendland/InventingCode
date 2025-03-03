#include <Servo.h>

Servo testservo;

uint32_t next;

void setup()
{
  //7 pin for white
  testservo.attach(7, 1000, 2000);

  next = millis() + 500;
}

void loop()
{
  static bool rising = true;

  if(millis() > next)
  {
    if(rising)
    {
      testservo.write(180);
      rising = false;
    }
    else
    {
      testservo.write(0);
      rising = true;
    }

    next += 3000;
  }

}
