#include <Servo.h>

int pin_SERVO = 13;
int pin_SLIDE = A5;

Servo SERVO;

void setup() {
  Serial.begin(115200);
  SERVO.attach(pin_SERVO);
  pinMode(pin_SLIDE, INPUT);

}

void loop() {
  uint16_t ADC_data = 0;
  ADC_data =analogRead(pin_SLIDE);
  Serial.print("ADC Data : ");
  Serial.println(ADC_data);
  delay(1000);
  
  uint16_t SERVO_data = map(ADC_data, 0, 1023, 0, 180);
  Serial.print("SERVO Data : ");
  Serial.println(SERVO_data);

  SERVO.write(SERVO_data);
  delay(1000);

}
