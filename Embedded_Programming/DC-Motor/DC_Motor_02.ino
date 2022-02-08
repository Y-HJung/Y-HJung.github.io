int pin_DC_A = 5;
int pin_DC_B = 6;
String myString;

void setup() {
  Serial.begin(9600);
  pinMode(pin_DC_A, OUTPUT);
  pinMode(pin_DC_B, OUTPUT);

  digitalWrite(pin_DC_A, LOW);
  digitalWrite(pin_DC_B, LOW);
}

void loop() {
  int16_t Speed;


  if(Serial.available()>0)
  {
    myString=Serial.readString();
    Serial.println(myString);
    Speed = myString.toInt();
    Serial.println(Speed); 
    if(Speed>=0 && Speed<=126){
      forwardRotation(Speed);
    } else if (Speed>=-127 && Speed<0){
      reverseRotation(Speed);
    } else{
      Stop();
    }
  } delay(200);
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

void Stop()
{
  digitalWrite(pin_DC_A, LOW);
  digitalWrite(pin_DC_B, LOW);
}
