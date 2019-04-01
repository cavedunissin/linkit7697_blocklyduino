/*
 * Generated using BlocklyDuino:
 *
 * https://github.com/MediaTek-Labs/BlocklyDuino-for-LinkIt
 *
 * Date: Sun, 31 Mar 2019 04:24:44 GMT
 */

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd_i2c(0x3F);

#include <Ultrasonic.h>

float MaxDist;

Ultrasonic ultrasonic_3_2(3, 2);

void setup()
{
  lcd_i2c.begin(16, 2);
  MaxDist = 10;
  lcd_i2c.backlight();
  lcd_i2c.clear();
  lcd_i2c.setCursor(0,0);
  lcd_i2c.print("Distance Metter");
  lcd_i2c.setCursor(0,1);
  lcd_i2c.print("Start now!!");
  delay(5000);
  pinMode(6, INPUT);
}


void loop()
{
  lcd_i2c.clear();
  if (digitalRead(6) == LOW) {
    lcd_i2c.setCursor(0,0);
    lcd_i2c.print("cm:");
    lcd_i2c.setCursor(3,0);
    lcd_i2c.print(ultrasonic_3_2.convert(ultrasonic_3_2.timing(), Ultrasonic::CM));
    lcd_i2c.setCursor(0,1);
    lcd_i2c.print("inch:");
    lcd_i2c.setCursor(5,1);
    lcd_i2c.print(ultrasonic_3_2.convert(ultrasonic_3_2.timing(), Ultrasonic::IN));

  } else {
    lcd_i2c.setCursor(0,0);
    lcd_i2c.print("Max Dist:");
    lcd_i2c.setCursor(9,0);
    lcd_i2c.print(MaxDist);
    if (MaxDist <= ultrasonic_3_2.convert(ultrasonic_3_2.timing(), Ultrasonic::CM)) {
      lcd_i2c.setCursor(0,1);
      lcd_i2c.print("Normal");

    } else {
      lcd_i2c.setCursor(0,1);
      lcd_i2c.print("Alarm!!");
      for (int count = 0; count < 3; count++) {
        tone(4, 1000, 300);
        delay(500);
      }

    }

  }
  delay(500);
}