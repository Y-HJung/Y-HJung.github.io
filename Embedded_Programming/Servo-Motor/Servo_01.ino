#include <Servo.h>
int pin_SERVO = 13;

int pin_SW1 = 3;
int pin_SW2 = 4;
int16_t pos = 0;
int16_t a;

Servo SERVO;

void setup() {
  Serial.begin(9600);
  SERVO.attach(pin_SERVO);

  pinMode(pin_SW1, INPUT);
  pinMode(pin_SW2, INPUT);

}

void loop() {
  uint8_t SW1_data, SW2_data;

  SW1_data = digitalRead(pin_SW1);
  SW2_data = digitalRead(pin_SW2);

  if((SW1_data==1) && (SW2_data==0)){
    a = pos;
    Serial.print("목표 각도: ");
    Serial.println(pos);
    pos = pos + 15;
    a = pos;
    delay(200);
    if(pos>180){
      pos = 0;
      delay(200);
    }
  }

  if((SW2_data==1)&&(SW1_data==0)){
    Serial.print("목표 각도로 회전 : ");
    a = a - 15;
    Serial.println((a));
    SERVO.write(a);
    a = a + 15;
    delay(200);
  }

}
