#include <LiquidCrystal.h>

LiquidCrystal lcd(11, 12, 5,4,3,2);

#define MQPin A0
#define buzzer 6

void setup() {
  digitalWrite(buzzer, LOW);
   lcd.begin(16, 2);
   Serial.begin(9600);
   pinMode(MQPin, INPUT_PULLUP);
   pinMode(buzzer, OUTPUT);
   int i=20;
   while(i>=1){
    if(i>=10){
     lcd.setCursor(2, 0);
     lcd.print("GAS DETECTOR");
     lcd.setCursor(1, 1);
     lcd.print("Please Wait");
     lcd.setCursor(13,1);
     lcd.print(i);
     lcd.setCursor(15,1);
     lcd.print("s");
     delay(1000);
     if(i==10){
      lcd.clear();
     }
     i-=1;
    }
    else{
     lcd.setCursor(2, 0);
     lcd.print("GAS DETECTOR");
     lcd.setCursor(1, 1);
     lcd.print("Please Wait");
     lcd.setCursor(14,1);
     lcd.print(i);
     lcd.setCursor(15,1);
     lcd.print("s");
     delay(1000);
     i-=1;
    }
    
   }
   lcd.clear();

}

void loop() {

int gas_value = digitalRead(MQPin);
if(analogRead(A1)>=500)
{


  digitalWrite(buzzer, HIGH);
  Serial.println(analogRead(A1));
  lcd.setCursor(3, 0);
  lcd.print("GAS DETECTED");
  lcd.setCursor(4, 1);
  lcd.print(analogRead(A1));
  lcd.setCursor(8, 1);
  lcd.print("PPM");
  delay(2000);
  lcd.clear();
  delay(2000);
  digitalWrite(buzzer, LOW);
  delay(2000);
  
}
else
{  
  Serial.println("Not detecting");
  Serial.println(analogRead(A1)); 
}
  

}
