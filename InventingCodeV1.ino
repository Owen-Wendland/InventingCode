#include <LiquidCrystal.h>

const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

bool but1 = false;
bool but2 = false;
bool but3 = false;
bool but4 = false;
String output = String("");
String a = "1:";
String b = "2:";
String c = "3:";
String d = "4:";

int aa[4] = {0,0,0,0};
int ab[4] = {1,0,0,0};
int ac[4] = {0,1,0,0};
int ad[4] = {0,0,1,0};
int ae[4] = {0,0,0,1};

int rerate = 60;

int currentVal = 1;
int vals[4] = {0,0,0,0};
int oldVals[4] = {0,0,0,0};

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  for(int pin = 2; pin <= 5; pin++){
    pinMode(pin, INPUT_PULLUP);
  }
  
}

void loop() {
  vals[0] = !digitalRead(2);
  vals[1] = !digitalRead(3);
  vals[2] = !digitalRead(4);
  vals[3] = !digitalRead(5);

  if (vals != aa){
    if (oldVals[0] != vals[0]){
      oldVals[0] = ab[0];
      oldVals[1] = ab[1];
      oldVals[2] = ab[2];
      oldVals[3] = ab[3];
    }
    if (oldVals[1] != vals[1]){
      oldVals[0] = ac[0];
      oldVals[1] = ac[1];
      oldVals[2] = ac[2];
      oldVals[3] = ac[3];
    }
    if (oldVals[2] != vals[2]){
      oldVals[0] = ad[0];
      oldVals[1] = ad[1];
      oldVals[2] = ad[2];
      oldVals[3] = ad[3];
    }
    if (oldVals[3] != vals[3]){
      oldVals[0] = ae[0];
      oldVals[1] = ae[1];
      oldVals[2] = ae[2];
      oldVals[3] = ae[3];
    }
  }

  //*oldVals = changed(vals, oldVals);

  a = "1:"+String(oldVals[0]);
  b = "2:"+String(oldVals[1]);
  c = "3:"+String(oldVals[2]);
  d = "4:"+String(oldVals[3]);

  lcd.setCursor(0, 0);
  lcd.print(a);
  lcd.setCursor(0, 1);
  lcd.print(b);
  lcd.setCursor(13, 0);
  lcd.print(c);
  lcd.setCursor(13, 1);
  lcd.print(d);

  delay(1000/rerate);
}
/*
int *changed(int currentList[], int oldList[]){
  int output[4] = {0,0,0,0};
  Serial.println(oldList[1]);
  if(currentList == oldList){
    return oldList;
  }
  else{
    if (currentList[0] != oldList[0]){
      int a[] = {1,0,0,0};
      return a;
    }
    else if (currentList[1] != oldList[1]){
      int a[] = {0,1,0,0};
      return a;
    }
    else if (currentList[2] != oldList[2]){
      int a[] = {0,0,1,0};
      return a;
    }
    else{
      int a[] = {0,0,0,1};
      return a;
    }
  }
}*/
