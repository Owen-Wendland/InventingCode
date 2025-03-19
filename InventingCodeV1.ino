#include <LiquidCrystal.h>
#include <EEPROM.h>

#include <Servo.h>

Servo testservo;

uint32_t next;
int servoLoc = -180;

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

int time = 0;

int rerate = 60;

int currentVal = 1;
int vals[4] = {0,0,0,0};
int oldVals[4] = {0,0,0,0};
int lastBut = 5;
int lastBut2 = 0;

void setup() {
  testservo.attach(7, 1000, 2000);
  lcd.begin(16, 2);
  Serial.begin(9600);
  for(int pin = 2; pin <= 5; pin++){
    pinMode(pin, INPUT_PULLUP);
  }
  
}

void loop() {
  servoLoc = analogRead(2)/5.68333333;
  testservo.write(servoLoc);
  vals[0] = !digitalRead(2);
  vals[1] = !digitalRead(3);
  vals[2] = !digitalRead(4);
  vals[3] = !digitalRead(5);
  
  if (vals[0]+vals[1]+vals[2]+vals[3] > 0){
    int data;
    if (oldVals[0] != vals[0]){
      data = 1;
      oldVals[0] = ab[0];
      oldVals[1] = ab[1];
      oldVals[2] = ab[2];
      oldVals[3] = ab[3];
      lastBut = 1;
    }
    else if (oldVals[1] != vals[1]){
      Serial.println("2");
      data = 2;
      oldVals[0] = ac[0];
      oldVals[1] = ac[1];
      oldVals[2] = ac[2];
      oldVals[3] = ac[3];
      lastBut = 2;
    }
    else if (oldVals[2] != vals[2]){
      data = 3;
      oldVals[0] = ad[0];
      oldVals[1] = ad[1];
      oldVals[2] = ad[2];
      oldVals[3] = ad[3];
      lastBut = 3;
    }
    else if (oldVals[3] != vals[3]){
      data = 4;
      oldVals[0] = ae[0];
      oldVals[1] = ae[1];
      oldVals[2] = ae[2];
      oldVals[3] = ae[3];
      lastBut = 4;
    }
    if(lastBut == lastBut2){
      Serial.println(lastBut);
      EEPROM.write(data, lastBut);
    }
    
    lastBut2 = lastBut;
    
    while(vals[0]+vals[1]+vals[2]+vals[3] > 0){
      delay(1000/rerate);
      vals[0] = !digitalRead(2);
      vals[1] = !digitalRead(3);
      vals[2] = !digitalRead(4);
      vals[3] = !digitalRead(5);
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

  //Serial.println(((analogRead(1)*1100)/(1024)-58));
  if(time % rerate == 0){
    int translation = int(analogRead(1)*(0.472));
    lcd.setCursor(4, 0);
    String tempere = "temp:"+String(translation);
    lcd.print(tempere);
    Serial.println("begin");
    for(int i=1; i <= 4; i++){
      int address = i;
      byte value;
      value = EEPROM.read(address);
  
      Serial.print(address);
      Serial.print("\t");
      Serial.print(value, DEC);
      Serial.println();
    }
    Serial.print(lastBut);
    Serial.print("\t");
    Serial.print(lastBut2);
    Serial.println();
  }
  delay(1000/rerate);
  time += 1;
}
