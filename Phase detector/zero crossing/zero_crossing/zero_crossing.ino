#include <LiquidCrystal.h>
  LiquidCrystal lcd(8,9,10,11,12,13);
float a;
int b;
int c;

void setup() {
Serial.begin(9600);
pinMode(3 , INPUT);
}

void loop() {
  
a = pulseIn(3 , HIGH)/539.90;

lcd.print(" Phase is ");
lcd.print(a);
delay(70);
lcd.clear();


}
