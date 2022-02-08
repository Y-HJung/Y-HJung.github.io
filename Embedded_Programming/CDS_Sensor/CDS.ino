int pin_CDS = A1;
int pin_LED[8] = {5, 6, 8, 9, 10, 11, 12, 13};
int binary[10];

int n;

void setup() {
  Serial.begin(115200);
  
  pinMode(pin_CDS, INPUT);
  
  for(int i=0; i<8; i++){
    pinMode(pin_LED[i], OUTPUT);
  }

}
void loop() {
  uint16_t ADC_data = 0;
  ADC_data = analogRead(pin_CDS);
  Serial.print("ADC Data : ");
  Serial.println(ADC_data);

  for(int i=0; i<10; i++){
    binary[i] = 0;
  }
  
  Conversion(ADC_data);

  Serial.print("상위 8비트 : ");
  
  for(int i=7, j=9; i>=0; i--){
    Serial.print(binary[j]);
    digitalWrite(pin_LED[i], binary[j]);
    j--;
  }
  Serial.println(" ");

  Serial.print("10비트 : ");
  for(int a=9; a>=0; a--){
    Serial.print(binary[a]); 
  }
  Serial.println(" ");
  Serial.println(" ");
  n = 0;

  delay(5000);
}

int Conversion(uint16_t num) {
  for(n=0; num>0; n++){
    binary[n] = num % 2;
    num = num / 2;
  }
}
