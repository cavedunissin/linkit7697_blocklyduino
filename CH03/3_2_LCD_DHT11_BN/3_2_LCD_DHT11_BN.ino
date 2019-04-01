/*
 * Generated using BlocklyDuino:
 *
 * https://github.com/MediaTek-Labs/BlocklyDuino-for-LinkIt
 *
 * Date: Tue, 01 Jan 2019 09:11:30 GMT
 */

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd_i2c(0x3F);

#include <DHT.h>

int Temp;

int Humi;

DHT dht11_p2(2, DHT11);

void setup()
{
  lcd_i2c.begin(16, 2);
  lcd_i2c.backlight();
  lcd_i2c.clear();
  lcd_i2c.setCursor(0,0);
  lcd_i2c.print("Hygrothermograph");
  lcd_i2c.setCursor(0,1);
  lcd_i2c.print("Start now!!");
  delay(5000);
  dht11_p2.begin();
  pinMode(4, INPUT);
}


void loop()
{
  Temp = dht11_p2.readTemperature();
  Humi = dht11_p2.readHumidity();
  if (digitalRead(4) == LOW) {
    lcd_i2c.clear();
    lcd_i2c.setCursor(0,0);
    lcd_i2c.print("Temp: ");
    lcd_i2c.setCursor(6,0);
    lcd_i2c.print(Temp);
    lcd_i2c.setCursor(8,0);
    lcd_i2c.print("deg");
    lcd_i2c.setCursor(0,1);
    lcd_i2c.print("Humidity: ");
    lcd_i2c.setCursor(10,1);
    lcd_i2c.print(Humi);
    lcd_i2c.setCursor(12,1);
    lcd_i2c.print("%");

  } else {
    lcd_i2c.clear();
    lcd_i2c.setCursor(0,0);
    lcd_i2c.print("comfort index :");
    lcd_i2c.setCursor(0,1);
    if (Temp < 11) {
      lcd_i2c.print("very cold");

    } else if (Temp >= 11 && Temp < 16) {
      lcd_i2c.print("cold");
    } else if (Temp >= 16 && Temp < 20) {
      lcd_i2c.print("cool");
    } else if (Temp >= 20 && Temp < 27) {
      lcd_i2c.print("comfortable");
    } else if (Temp >= 27 && Temp < 31) {
      lcd_i2c.print("sultry");
    } else {
      lcd_i2c.print("EZ2get heatstroke");

    }

  }
}