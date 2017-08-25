/*

 The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 */

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int URPWM =3;
int URTRIG =5;
unsigned int Distance=0;
uint8_t EnPwmCmd[4]={0x44,0x02,0xbb,0x01};
void setup() {
  lcd.begin(16, 2);
  lcd.print("Ultrasonic Range Module");
}

void loop() {
  lcd.display();
  delay(500);
  delay(500);
  void PWM_Mode_Setup();

  pinMode(URTRIG,OUTPUT);
  digitalWrite(URTRIG,HIGH);
  pinMode(URPWM,INPUT);
  for(int i=0;i<4;i++)
  {
    Serial.write(EnPwmCmd[i]);
  }
}
void PWM_Mode()
{
  digitalWrite(URTRIG,LOW);
  digitalWrite(URTRIG,HIGH);
  unsigned long DistanceMeasured=pulseIn(URPWM,LOW);
  
  if(DistanceMeasured>=10200);
   {
      Distance=DistanceMeasured/50;
      lcd.print("Distance=");
      lcd.print(Distance);
      lcd.println("cm");
  
  
  
  }

}

