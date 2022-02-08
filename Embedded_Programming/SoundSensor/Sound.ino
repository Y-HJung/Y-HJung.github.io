int pin_SOUND = A2;
int pin_LED[8] = {5, 6, 8, 9, 10, 11, 12, 13};

void setup() {
  Serial.begin(115200);
  
  pinMode(pin_SOUND, INPUT);
  
  for(int i=0; i<8; i++){
    pinMode(pin_LED[i], OUTPUT);
  }
}

void loop() {
  uint16_t i, ADC_data = 0;
  ADC_data = analogRead(pin_SOUND);

  Serial.print("ADC data : ");
  Serial.println(ADC_data);

  if(ADC_data>=0 && ADC_data<128){
    digitalWrite(pin_LED[7], 1);
    digitalWrite(pin_LED[6], 0);
    digitalWrite(pin_LED[5], 0);
    digitalWrite(pin_LED[4], 0);
    digitalWrite(pin_LED[3], 0);
    digitalWrite(pin_LED[2], 0);
    digitalWrite(pin_LED[1], 0);
    digitalWrite(pin_LED[0], 0);
    Serial.println("1000 0000");
  } else if(ADC_data>=128 && ADC_data<256){
    digitalWrite(pin_LED[7], 1);
    digitalWrite(pin_LED[6], 1);
    digitalWrite(pin_LED[5], 0);
    digitalWrite(pin_LED[4], 0);
    digitalWrite(pin_LED[3], 0);
    digitalWrite(pin_LED[2], 0);
    digitalWrite(pin_LED[1], 0);
    digitalWrite(pin_LED[0], 0);
    Serial.println("1100 0000");
  } else if(ADC_data>=256 && ADC_data<384){
    digitalWrite(pin_LED[7], 1);
    digitalWrite(pin_LED[6], 1);
    digitalWrite(pin_LED[5], 1);
    digitalWrite(pin_LED[4], 0);
    digitalWrite(pin_LED[3], 0);
    digitalWrite(pin_LED[2], 0);
    digitalWrite(pin_LED[1], 0);
    digitalWrite(pin_LED[0], 0);
    Serial.println("1110 0000");
  } else if(ADC_data>=384 && ADC_data<512){
    digitalWrite(pin_LED[7], 1);
    digitalWrite(pin_LED[6], 1);
    digitalWrite(pin_LED[5], 1);
    digitalWrite(pin_LED[4], 1);
    digitalWrite(pin_LED[3], 0);
    digitalWrite(pin_LED[2], 0);
    digitalWrite(pin_LED[1], 0);
    digitalWrite(pin_LED[0], 0);
    Serial.println("1111 0000");
  } else if(ADC_data>=512 && ADC_data<640){
    digitalWrite(pin_LED[7], 1);
    digitalWrite(pin_LED[6], 1);
    digitalWrite(pin_LED[5], 1);
    digitalWrite(pin_LED[4], 1);
    digitalWrite(pin_LED[3], 1);
    digitalWrite(pin_LED[2], 0);
    digitalWrite(pin_LED[1], 0);
    digitalWrite(pin_LED[0], 0);
    Serial.println("1111 1000");
  } else if(ADC_data>=640 && ADC_data<768){
    digitalWrite(pin_LED[7], 1);
    digitalWrite(pin_LED[6], 1);
    digitalWrite(pin_LED[5], 1);
    digitalWrite(pin_LED[4], 1);
    digitalWrite(pin_LED[3], 1);
    digitalWrite(pin_LED[2], 1);
    digitalWrite(pin_LED[1], 0);
    digitalWrite(pin_LED[0], 0);
    Serial.println("1111 1100");
  } else if(ADC_data>=768 && ADC_data<896){
    digitalWrite(pin_LED[7], 1);
    digitalWrite(pin_LED[6], 1);
    digitalWrite(pin_LED[5], 1);
    digitalWrite(pin_LED[4], 1);
    digitalWrite(pin_LED[3], 1);
    digitalWrite(pin_LED[2], 1);
    digitalWrite(pin_LED[1], 1);
    digitalWrite(pin_LED[0], 0);
    Serial.println("1111 1110");
  } else if(ADC_data>=896 && ADC_data<1024){
    digitalWrite(pin_LED[7], 1);
    digitalWrite(pin_LED[6], 1);
    digitalWrite(pin_LED[5], 1);
    digitalWrite(pin_LED[4], 1);
    digitalWrite(pin_LED[3], 1);
    digitalWrite(pin_LED[2], 1);
    digitalWrite(pin_LED[1], 1);
    digitalWrite(pin_LED[0], 1);
    Serial.println("1111 1111");
  }

  delay(100);

}
