#include <LiquidCrystal.h>
  LiquidCrystal lcd(8,9,10,11,12,13);
float a;
int b;
int c;
float analog=A0;
float current=0;
float cal=0;
float voltage=0;
float offset=2.5;
float sensitivity=0.185;


void setup() {
Serial.begin(9600);
pinMode(3 , INPUT);
}

void loop() {
  cal=analogRead(analog);
  voltage=(cal*5)/1023;
  current=(voltage-offset)/sensitivity;
a = pulseIn(3 , HIGH)/539.90;

lcd.print(" Phase is ");
lcd.print(a);
Serial.println("current");
Serial.println(current,4);
delay(70);
lcd.clear();


}
