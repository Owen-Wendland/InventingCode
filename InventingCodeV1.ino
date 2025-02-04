void setup() {
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
      Serial.println(pin, "High");
    }
    else{
      Serial.println(pin, "Low");
    }
  }
}
