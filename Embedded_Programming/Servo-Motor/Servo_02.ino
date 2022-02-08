#include <Servo.h>
int pin_SERVO = 13;

Servo SERVO;

void setup() {
  Serial.begin(9600);
  SERVO.attach(pin_SERVO);

}

void loop() {
  int16_t pos;

  if(Serial.available()>0){
    Serial.print("목표 각도 : ");
    pos = Serial.parseInt();
    if(pos>180){
    Serial.println("180도 초과!!");
    } else if(pos<0){
      Serial.println("값은 0~180도 범위로 입력해주세요");
    }
    Serial.println(pos);
    SERVO.write(pos);
    delay(1000);
  }

}
