int pin_LED0 = 5;
int pin_LED1 = 6;
int pin_LED2 = 8;
int pin_LED3 = 9;
int pin_LED4 = 10;
int pin_LED5 = 11;
int pin_LED6 = 12;
int pin_LED7 = 13;

int pin_SW1 = 3;
int pin_SW2 = 4;

int state = 0;
uint8_t SW1_data, SW2_data;
int count = 0;

void setup(){
  pinMode(pin_SW1, INPUT);
  pinMode(pin_SW2, INPUT);

  pinMode(pin_LED0, OUTPUT);
  pinMode(pin_LED1, OUTPUT);
  pinMode(pin_LED2, OUTPUT);
  pinMode(pin_LED3, OUTPUT);
  pinMode(pin_LED4, OUTPUT);
  pinMode(pin_LED5, OUTPUT);
  pinMode(pin_LED6, OUTPUT);
  pinMode(pin_LED7, OUTPUT);

}

void loop(){
  SW1_data = digitalRead(pin_SW1);
  SW2_data = digitalRead(pin_SW2);

  if(SW1_data==0){
    if(state==0){
      delay(10);
      state = 1;
    }
  }
  if(SW1_data==1){
    if(state==1){
      count=count+1;
      delay(10);
      state=0;
    }
  }
  if(count==1){
    digitalWrite(pin_LED0, SW1_data);
  } else if(count==2){
    digitalWrite(pin_LED1, SW1_data);
  }else if(count==3){
    digitalWrite(pin_LED0, SW1_data);
    digitalWrite(pin_LED1, SW1_data);
  }else if(count==4){
    digitalWrite(pin_LED2, SW1_data);
  }else if(count==5){
    digitalWrite(pin_LED2, SW1_data);
    digitalWrite(pin_LED0, SW1_data);
  }else if(count==6){
    digitalWrite(pin_LED2, SW1_data);
    digitalWrite(pin_LED1, SW1_data);
  }else if(count==7){
    digitalWrite(pin_LED3, SW1_data);
    digitalWrite(pin_LED2, SW1_data);
    digitalWrite(pin_LED1, SW1_data);
  }else if(count==8){
    digitalWrite(pin_LED3, SW1_data);
  }else if(count==9){
    digitalWrite(pin_LED3, SW1_data);
    digitalWrite(pin_LED0, SW1_data);
  }else if(count==10){
    digitalWrite(pin_LED3, SW1_data);
    digitalWrite(pin_LED1, SW1_data);
  }

  if(SW2_data==1) count=0;

}
