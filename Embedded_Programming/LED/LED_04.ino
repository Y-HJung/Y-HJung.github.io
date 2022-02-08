int pin_LED_R=9;
int pin_LED_G=10;
int pin_LED_B=11;

void setup() {
  // put your setup code here, to run once:
pinMode(pin_LED_R,OUTPUT);
pinMode(pin_LED_G,OUTPUT);
pinMode(pin_LED_B,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
analogWrite(pin_LED_R, 255);
analogWrite(pin_LED_G, 0);
analogWrite(pin_LED_B, 0);
delay(1000);

analogWrite(pin_LED_R, 255);
analogWrite(pin_LED_G, 50);
analogWrite(pin_LED_B, 0);
delay(1000);

analogWrite(pin_LED_R, 255);
analogWrite(pin_LED_G, 228);
analogWrite(pin_LED_B, 0);
delay(1000);

analogWrite(pin_LED_R, 29);
analogWrite(pin_LED_G, 219);
analogWrite(pin_LED_B, 22);
delay(1000);

analogWrite(pin_LED_R, 0);
analogWrite(pin_LED_G, 84);
analogWrite(pin_LED_B, 255);
delay(1000);

analogWrite(pin_LED_R, 1);
analogWrite(pin_LED_G, 0);
analogWrite(pin_LED_B, 139);
delay(1000);

analogWrite(pin_LED_R, 95);
analogWrite(pin_LED_G, 0);
analogWrite(pin_LED_B, 255);
delay(1000);

analogWrite(pin_LED_R, 0);
analogWrite(pin_LED_G, 0);
analogWrite(pin_LED_B, 0);

}
