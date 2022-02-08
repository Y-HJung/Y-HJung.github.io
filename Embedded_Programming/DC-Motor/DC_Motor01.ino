int pin_DC_A = 5;
int pin_DC_B = 6;

int pin_LED_R = 9;
int pin_LED_G = 10;
int pin_LED_B = 11;

int pin_SW1 = 3;
int pin_SW2 = 4;

int count1 = 0;
int count2 = 0;

void setup() {
  pinMode(pin_DC_A, OUTPUT);
  pinMode(pin_DC_B, OUTPUT);

  pinMode(pin_LED_R, OUTPUT);
  pinMode(pin_LED_G, OUTPUT);
  pinMode(pin_LED_B, OUTPUT);

  pinMode(pin_SW1, INPUT);
  pinMode(pin_SW2, INPUT);

}

void loop() {
  uint8_t SW1_data, SW2_data;
  uint16_t Speed;
  uint16_t Speed2;

  int brightness1;
  int brightness2;
  
  SW1_data = digitalRead(pin_SW1);
  SW2_data = digitalRead(pin_SW2);

  if(SW1_data == 1)
  {
    Stop();
    count2=0;
    count1++;
    brightness2=0;
    analogWrite(pin_LED_B, brightness2);
    delay(200);
  }

  if(count1==1)
  {
    Speed=52;
    forwardRotation(Speed);
    delay(20);
    brightness1=10;
    analogWrite(pin_LED_R, brightness1);
    delay(20);
  }else if(count1==2)
  {
    Speed=102;
    forwardRotation(Speed);
    delay(20);
    brightness1=70;
    analogWrite(pin_LED_R, brightness1);
    delay(20);
  }else if(count1==3)
  {
    Speed=153;
    forwardRotation(Speed);
    delay(20);
    brightness1=120;
    analogWrite(pin_LED_R, brightness1);
    delay(20);
  }else if(count1==4)
  {
    Speed=204;
    forwardRotation(Speed);
    delay(20);
    brightness1=180;
    analogWrite(pin_LED_R, brightness1);
    delay(20);
  }else if(count1==5)
  {
    Speed=255;
    forwardRotation(Speed);
    delay(20);
    brightness1=255;
    analogWrite(pin_LED_R, brightness1);
    delay(20);
  }else{
    Stop();
    analogWrite(pin_LED_R, 0);
    delay(200);
    count1 = 0;
  }

  if(SW2_data == 1)
  {
    Stop();
    count1 = 0;
    count2++;
    brightness1=0;
    analogWrite(pin_LED_R, brightness1);
    delay(200);
  }
  
  if(count2 == 1)
  {
    Speed2=51;
    reverseRotation(Speed2);
    delay(20);
    brightness2=10;
    analogWrite(pin_LED_B, brightness2);
    delay(20);
  } else if(count2 == 2)
  {
    Speed2=102;
    reverseRotation(Speed2);
    delay(20);
    brightness2=70;
    analogWrite(pin_LED_B, brightness2);
    delay(20);
  } else if(count2 == 3)
  {
    Speed2=153;
    reverseRotation(Speed2);
    delay(20);
    brightness2=120;
    analogWrite(pin_LED_B, brightness2);
    delay(20);
  } else if(count2 == 4)
  {
    Speed2=204;
    reverseRotation(Speed2);
    delay(20);
    brightness2=180;
    analogWrite(pin_LED_B, brightness2);
    delay(20);
  } else if(count2 == 5)
  {
    Speed2=255;
    reverseRotation(Speed2);
    delay(20);
    brightness2=255;
    analogWrite(pin_LED_B, brightness2);
    delay(20);
  } else{
    Stop();
    analogWrite(pin_LED_B, 0);
    delay(200);
    count2 = 0;
  }
}

void forwardRotation(uint8_t Speed)
{
  digitalWrite(pin_DC_A, LOW);
  analogWrite(pin_DC_B, Speed);
}

void reverseRotation(uint8_t Speed2)
{
  digitalWrite(pin_DC_B, LOW);
  analogWrite(pin_DC_A, Speed2);
}

void Stop()
{
  digitalWrite(pin_DC_A, LOW);
  digitalWrite(pin_DC_B, LOW);
}
