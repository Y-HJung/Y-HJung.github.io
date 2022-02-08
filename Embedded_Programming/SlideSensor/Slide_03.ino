int pin_SLIDE = A5;
int pin_LED_R = 9;
int pin_LED_G = 10;
int pin_LED_B = 11;
void setup() {
  Serial.begin(115200);
  pinMode(pin_SLIDE, INPUT);
  pinMode(pin_LED_R, OUTPUT);
  pinMode(pin_LED_G, OUTPUT);
  pinMode(pin_LED_B, OUTPUT);

}

void loop() {
  uint16_t ADC_data = 0;
  ADC_data = analogRead(pin_SLIDE);
  Serial.print("ADC Data : ");
  Serial.println(ADC_data);
  delay(50);
  if (ADC_data < 341) {
    analogWrite(pin_LED_R, 255 - ADC_data );
    analogWrite(pin_LED_G, ADC_data );
    analogWrite(pin_LED_B, 0 );
  } else if (ADC_data >= 341 && ADC_data < 682) {
    ADC_data - 341;
    analogWrite(pin_LED_G, 255 - ADC_data );
    analogWrite(pin_LED_B, ADC_data );
    analogWrite(pin_LED_R, 0);
  } else if (ADC_data >= 682 && ADC_data < 1023) {
    ADC_data - 682;
    analogWrite(pin_LED_B, 255 - ADC_data  );
    analogWrite(pin_LED_R, ADC_data  );
    analogWrite(pin_LED_G, 0 );
  } else {

  }
}
