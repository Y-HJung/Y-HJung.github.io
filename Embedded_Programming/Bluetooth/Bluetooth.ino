int pin_LED_R = 9;
int pin_LED_G = 10;
int pin_LED_B = 11;

int pin_DC_A = 5;
int pin_DC_B = 6;

void setup() {
  Serial1.begin(9600);

  pinMode(pin_LED_R, OUTPUT);
  pinMode(pin_LED_G, OUTPUT);
  pinMode(pin_LED_B, OUTPUT);

  pinMode(pin_DC_A, OUTPUT);
  pinMode(pin_DC_B, OUTPUT);
}

void loop() {
  if(Serial1.available()>0){
    int Choice = Select();

    if(Choice == 1){
      Serial1.println("1 : RGB");
      char r[4]={0,}, g[4]={0,}, b[4]={0,};
      int Red = 0, Green = 0, Blue = 0;
      delay(300);

      Serial1.println("Red : ");
      delay(300);
      byte a = Serial1.readBytes(r, 4);
      Red = atoi(r);
      delay(500);

      Serial1.println("Green : ");
      delay(300);
      byte c = Serial1.readBytes(g, 4);
      Green = atoi(g);
      delay(500);

      Serial1.println("Blue : ");
      delay(300);
      byte d = Serial1.readBytes(b, 4);
      Blue = atoi(b);
      
      analogWrite(pin_LED_R, Red);
      analogWrite(pin_LED_G, Green);
      analogWrite(pin_LED_B, Blue);

      delay(3000);

      Choice = Select();
      
    }else if(Choice == 2){
      Serial1.println("2 : DC Moter");
      int Speed = 0;
      char sp[6] = {0,};
      delay(200);

      Serial1.print("Speed : ");
      delay(600);
      byte e = Serial1.readBytes(sp, 6);
      Speed = atoi(sp);
      delay(200);

      if(Speed>=0){
        forwardRotation(Speed);
        delay(20);
      }else if(Speed<0){
        reverseRotation(Speed);
        delay(20);
      }
      delay(3000);

      Choice = Select();
      
    }else{
      Serial1.println("Invalid Select");

      Choice = Select();
    }
    delay(20);
  }

}

int Select(){
  digitalWrite(pin_LED_R, 0);
  digitalWrite(pin_LED_G, 0);
  digitalWrite(pin_LED_B, 0);

  Stop();
  
  int result = 0;
  char temp[2] = {0,};

  Serial1.println("Choice 1 or 2");
  byte a = Serial1.readBytes(temp, 2);
  result = atoi(temp);
  Serial1.print("Choice : ");
  Serial1.println(result);
  return result;
}

void forwardRotation(int8_t Speed)
{
  digitalWrite(pin_DC_A, LOW);
  analogWrite(pin_DC_B, Speed);
}

void reverseRotation(int8_t Speed)
{
  digitalWrite(pin_DC_B, LOW);
  analogWrite(pin_DC_A, Speed);
}

void Stop(void)
{
  digitalWrite(pin_DC_A, LOW);
  digitalWrite(pin_DC_B, LOW);
}
