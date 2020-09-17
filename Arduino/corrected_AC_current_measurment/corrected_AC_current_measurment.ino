#include<LiquidCrystal.h>
LiquidCrystal LCD(8,9,10,11,12,13);
const int sensorIn = A0;
int mVperAmp = 185; 
double Voltage = 0;
double VRMS = 0;
double AmpsRMS = 0;

void setup(){ 
  LCD.begin(20,4);
}

void loop(){

 
 Voltage = getVPP();
VRMS = (Voltage/2.0) *0.707; 
 AmpsRMS = (VRMS * 1000)/mVperAmp;
LCD.setCursor(0,0);
LCD.print("current=");
  LCD.print(AmpsRMS);
  LCD.print("Amp");
  delay(500);
  }

  float getVPP()
{
  float result;
  
  int readValue;             
  int maxValue = 0;         
  int minValue = 1024;          
   uint32_t start_time = millis();
   while((millis()-start_time) < 250) 
   {
       readValue = analogRead(sensorIn);
       
       if (readValue > maxValue) 
       {
           
           maxValue = readValue;
       }
       if (readValue < minValue) 
       {
           
           minValue = readValue;
       }
   }
   
   
   result = ((maxValue - minValue) * 5.0)/1024.0;
      
   return result;
} 
