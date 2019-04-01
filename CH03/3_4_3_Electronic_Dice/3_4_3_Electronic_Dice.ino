/*
 * Generated using BlocklyDuino:
 *
 * https://github.com/MediaTek-Labs/BlocklyDuino-for-LinkIt
 *
 * Date: Sun, 06 Jan 2019 13:08:00 GMT
 */

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd_i2c(0x3F);

#include <Wire.h>
#include <adxl345_blockly.h>

ADXL345Block adxl345;

void setup()
{
  lcd_i2c.begin(16, 2);
  lcd_i2c.clear();
  lcd_i2c.setCursor(0,0);
  lcd_i2c.print("Welcome to");
  lcd_i2c.setCursor(0,1);
  lcd_i2c.print("Electronic Dice");
  delay(3000);
  lcd_i2c.clear();
  adxl345.begin();
}


void loop()
{
  lcd_i2c.setCursor(0,0);
  adxl345.detectGesture();
  if (adxl345.isActivityDetected()) {
    lcd_i2c.print((random(1, 6)));

  }
}