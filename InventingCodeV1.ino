#include <LiquidCrystal.h>

const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

bool but1 = False
bool but2 = False
bool but3 = False
bool but4 = False

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  for(int pin = 1; pin <= 4; pin++){
    pinMode(pin, INPUT_PULLUP);
  }
}

void loop() {
  int buttonStates[4] = {0,0,0,0};
  for(int pin = 1; pin <= 4; pin++){
    pinMode(pin, INPUT_PULLUP);
    buttonStates[pin] = digitalRead(pin);
  }
  for(int pin = 1; pin <= 4; pin++){
    if(buttonStates[pin] == HIGH){
      if pin == 1{
        but1 = True
      }
      else if pin == 2{
        but2 = True
      }
      else if pin == 3{
        but3 = True
      }
      else{
        but4 = True
      }
      Serial.println(pin, "High");
    }
    else{
      if pin == 1{
        but1 = False
      }
      else if pin == 2{
        but2 = False
      }
      else if pin == 3{
        but3 = False
      }
      else{
        but4 = False
      }
      Serial.println(pin, "Low");
    }
    lcd.begin(16, 2);
    lcd.print("1",but1,"2",but2,"3",but3,"4",but4);
  }
}
