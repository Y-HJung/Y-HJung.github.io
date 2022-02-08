#include <TimerOne.h>
volatile int pin_LED[8] = {5, 6, 8, 9, 10, 11, 12, 13};
int pin_SW1 = 3;

boolean flag = false;

int i;
int count = 0, count2 = 0;


unsigned long previousMillis = 0; 
const long delayTime = 1001; 

void setup() {
  pinMode(pin_SW1, INPUT);
  
  for(int b=0; b<8; b++){
    pinMode(pin_LED[b], OUTPUT);
  }
  Timer1.initialize(500000);
  Timer1.attachInterrupt(interrupt);

}

void loop() {
  uint8_t SW1_data;
  SW1_data = digitalRead(pin_SW1);

  unsigned long currentMillis = millis(); 

  if(flag == false){
    if(SW1_data == HIGH){
      flag = true;
      delay(10);
    }
  }else if(flag == true){
    if(SW1_data == HIGH){
      flag = false;
      delay(10);
    }
  }

  if((currentMillis - previousMillis >= delayTime)&&(flag==false)){
    previousMillis = currentMillis;
    if(count2>0) i=count2;
    count2=0;
    i++;
    count = i;
    if(i>7) i=0;
  }

  if((currentMillis - previousMillis >= delayTime)&&(flag==true)){
    previousMillis = currentMillis;
    if(count<7) i=count;
    count=7;
    i--;
    count2 = i;
    if(i<0) i=7;
  }

  
}

void interrupt(){ 
    digitalWrite(pin_LED[i], !digitalRead(pin_LED[i]));
}
