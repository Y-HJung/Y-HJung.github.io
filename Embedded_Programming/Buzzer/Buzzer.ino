int pin_BUZZER = 12;

void setup(){
  pinMode(pin_BUZZER,OUTPUT);
}

void loop(){
  digitalWrite(pin_BUZZER, HIGH);
  delay(1200);
  digitalWrite(pin_BUZZER, LOW);
  delay(800);
}
