int pin_PSD = A0;

void setup() {
  Serial.begin(115200);

  pinMode(pin_PSD, INPUT);
}

void loop() {
  uint16_t ADC_data = 0;
  int dist = 0;
  
  ADC_data = analogRead(pin_PSD);
  dist = 6230/ADC_data-1.4;
  Serial.print("Dist : ");
  Serial.print(dist);
  Serial.println(" [cm]");
  
  delay(1000);
  
}
