int pin_TEMP = A4;

void setup() {
  Serial.begin(115200);

  pinMode(pin_TEMP, INPUT);
}

void loop() {
  uint16_t ADC_data = 0;
  float Temp;
  ADC_data = analogRead(pin_TEMP);

  Temp = (float)ADC_data*5*100/1023;

  Serial.print("Temp : ");
  Serial.print(Temp);
  Serial.println("[C]");
  delay(500);

}
