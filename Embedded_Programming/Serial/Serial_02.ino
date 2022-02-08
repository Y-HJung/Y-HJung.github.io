int pin_SW1 = 3;
int pin_SW2 = 4;
int count = 0;

void setup() { 
pinMode(pin_SW1, INPUT);
pinMode(pin_SW2, INPUT);
}


void loop() {
   uint8_t SW1_data, SW2_data;
 
   SW1_data = digitalRead(pin_SW1); 
   SW2_data = digitalRead(pin_SW2);
   
 
  if(SW1_data == 1){ 
    count++;
    delay(200);
    Serial.println(count);
  }     
   if (SW2_data == 1){
     count--;
     delay(200);
     Serial.println(count);
   }
}
  
