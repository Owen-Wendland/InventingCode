#include <LiquidCrystal.h>

const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

bool but1 = false;
bool but2 = false;
bool but3 = false;
bool but4 = false;

int rerate = 60;

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
      if(pin == 1){
        but1 = true;
      }
      else if (pin == 2){
        but2 = true;
      }
      else if (pin == 3){
        but3 = true;
      }
      else{
        but4 = true;
      }
      //Serial.println(pin, "High");
    }
    else{
      if (pin == 1){
        but1 = false;
      }
      else if (pin == 2){
        but2 = false;
      }
      else if (pin == 3){
        but3 = false;
      }
      else{
        but4 = false;
      }
      //Serial.println(pin, "Low");
    }
    Serial.println(String(("1",but1,"2",but2,"3",but3,"4",but4)));
    //Serial.println(analogRead(4));
    lcd.begin(16, 2);
    lcd.print(String(("1",but1,"2",but2,"3",but3,"4",but4)));
    delay(1000/rerate);
  }
}
