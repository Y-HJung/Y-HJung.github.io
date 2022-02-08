int pin_SLIDE = A5;
int pin_FND[8]={5, 6, 8, 9, 10, 11, 12, 13};

uint8_t FND_Data[16]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};

void setup() {
  Serial.begin(115200);
  pinMode(pin_SLIDE, INPUT);

  for(int i=0; i<8; i++){
    pinMode(pin_FND[i], OUTPUT);
  }

}

void loop() {
  uint16_t ADC_data = 0;
  ADC_data=analogRead(pin_SLIDE);
  if(ADC_data>=0 && ADC_data<=64){
    Serial.print("ADC Data: ");
    Serial.println(ADC_data);
    FND_Ctrl(FND_Data[0]);

    Serial.println("7-Segment : 0");
    delay(800);
  }
  else if(ADC_data>=65 && ADC_data<=128){
    Serial.print("ADC Data: ");
    Serial.println(ADC_data);
    FND_Ctrl(FND_Data[1]);

    Serial.println("7-Segment : 1");
    delay(800);
  }
  else if(ADC_data>=129 && ADC_data<=192){
    Serial.print("ADC Data: ");
    Serial.println(ADC_data);
    FND_Ctrl(FND_Data[2]);

    Serial.println("7-Segment : 2");
    delay(800);
  }
  else if(ADC_data>=193 && ADC_data<=256){
    Serial.print("ADC Data: ");
    Serial.println(ADC_data);
    FND_Ctrl(FND_Data[3]);

    Serial.println("7-Segment : 3");
    delay(800);
  }
  else if(ADC_data>=257 && ADC_data<=320){
    Serial.print("ADC Data: ");
    Serial.println(ADC_data);
    FND_Ctrl(FND_Data[4]);

    Serial.println("7-Segment : 4");
    delay(800);
  }
  else if(ADC_data>=321 && ADC_data<=384){
    Serial.print("ADC Data: ");
    Serial.println(ADC_data);
    FND_Ctrl(FND_Data[5]);

    Serial.println("7-Segment : 5");
    delay(800);
  }
  else if(ADC_data>=385 && ADC_data<=448){
    Serial.print("ADC Data: ");
    Serial.println(ADC_data);
    FND_Ctrl(FND_Data[6]);

    Serial.println("7-Segment : 6");
    delay(800);
  }
  else if(ADC_data>=449 && ADC_data<=512){
    Serial.print("ADC Data: ");
    Serial.println(ADC_data);
    FND_Ctrl(FND_Data[7]);
    
    Serial.println("7-Segment : 7");
    delay(800);
  }
  else if(ADC_data>=513 && ADC_data<=576){
    Serial.print("ADC Data: ");
    Serial.println(ADC_data);
    FND_Ctrl(FND_Data[8]);

    Serial.println("7-Segment : 8");
    delay(800);
  }
  else if(ADC_data>=577 && ADC_data<=640){
    Serial.print("ADC Data: ");
    Serial.println(ADC_data);
    FND_Ctrl(FND_Data[9]);

    Serial.println("7-Segment : 9");
    delay(800);
  }
  else if(ADC_data>=641 && ADC_data<=704){
    Serial.print("ADC Data: ");
    Serial.println(ADC_data);
    FND_Ctrl(FND_Data[10]);

    Serial.println("7-Segment : A");
    delay(800);
  }
  else if(ADC_data>=705 && ADC_data<=768){
    Serial.print("ADC Data: ");
    Serial.println(ADC_data);
    FND_Ctrl(FND_Data[11]);

    Serial.println("7-Segment : b");
    delay(800);
  }
  else if(ADC_data>=769 && ADC_data<=832){
    Serial.print("ADC Data: ");
    Serial.println(ADC_data);
    FND_Ctrl(FND_Data[12]);

    Serial.println("7-Segment : C");
    delay(800);
  }
  else if(ADC_data>=833 && ADC_data<=896){
    Serial.print("ADC Data: ");
    Serial.println(ADC_data);
    FND_Ctrl(FND_Data[13]);

    Serial.println("7-Segment : d");
    delay(800);
  }
  else if(ADC_data>=897 && ADC_data<=960){
    Serial.print("ADC Data: ");
    Serial.println(ADC_data);
    FND_Ctrl(FND_Data[14]);

    Serial.println("7-Segment : E");
    delay(800);
  }
  else if(ADC_data>=961 && ADC_data<=1023){
    Serial.print("ADC Data: ");
    Serial.println(ADC_data);
    FND_Ctrl(FND_Data[15]);

    Serial.println("7-Segment : F");
    delay(800);
  }
}

void FND_Ctrl(uint8_t Ctrl_data){
  for(int j=0; j<8; j++){
    digitalWrite(pin_FND[j], (Ctrl_data>>j) & 0x01);
  }
}
