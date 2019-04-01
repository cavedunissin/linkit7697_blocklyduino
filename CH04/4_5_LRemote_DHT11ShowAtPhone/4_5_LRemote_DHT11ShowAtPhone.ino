/*
 * Generated using BlocklyDuino:
 *
 * https://github.com/MediaTek-Labs/BlocklyDuino-for-LinkIt
 *
 * Date: Tue, 01 Jan 2019 06:51:59 GMT
 */

#include <LRemote.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd_i2c(0x3F);

#include <DHT.h>

int temp;

int humi;

LRemoteLabel label1;
LRemoteLabel label2;
LRemoteSwitch switch1;
LRemoteLabel label3;
DHT dht11_p2(2, DHT11);

void setup()
{
  lcd_i2c.begin(16, 2);
  LRemote.setName("jackjean");
  LRemote.setOrientation(RC_PORTRAIT);
  LRemote.setGrid(3, 4);
    label1.setPos(0, 0);
    label1.setText("溫溼度顯示測試");
    label1.setSize(3, 1);
    label1.setColor(RC_GREY);
    LRemote.addControl(label1);

    label2.setPos(0, 1);
    label2.setText("溫度");
    label2.setSize(3, 1);
    label2.setColor(RC_GREY);
    LRemote.addControl(label2);

    switch1.setPos(0, 2);
    switch1.setSize(3, 1);
    switch1.setText("溫溼度切換");
    switch1.setColor(RC_BLUE);
    LRemote.addControl(switch1);

    label3.setPos(0, 3);
    label3.setText("曾希哲製作");
    label3.setSize(3, 1);
    label3.setColor(RC_GREY);
    LRemote.addControl(label3);
  LRemote.begin();
  dht11_p2.begin();
}


void loop()
{
  LRemote.process();
  temp = dht11_p2.readTemperature();
  humi = dht11_p2.readHumidity();
  if (switch1.getValue() == 0) {
    label2.updateText(String(String() + "溫度 " + temp + "℃"));

  } else {
    label2.updateText(String(String() + "濕度 " + humi + "%"));

  }
  lcd_i2c.clear();
  lcd_i2c.setCursor(0,0);
  lcd_i2c.print("Temp: ");
  lcd_i2c.setCursor(6,0);
  lcd_i2c.print(temp);
  lcd_i2c.setCursor(0,1);
  lcd_i2c.print("Humidity: ");
  lcd_i2c.setCursor(10,1);
  lcd_i2c.print(humi);
  delay(50);
}