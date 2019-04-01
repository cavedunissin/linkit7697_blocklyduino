/*
 * Generated using BlocklyDuino:
 *
 * https://github.com/MediaTek-Labs/BlocklyDuino-for-LinkIt
 *
 * Date: Tue, 01 Jan 2019 06:32:48 GMT
 */

#include <LRemote.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd_i2c(0x3F);

LRemoteLabel label1;
LRemoteButton button1;
LRemoteSwitch switch1;
LRemoteButton button2;
LRemoteLabel label2;

void setup()
{
  lcd_i2c.begin(16, 2);
  LRemote.setName("jackjean");
  LRemote.setOrientation(RC_PORTRAIT);
  LRemote.setGrid(3, 5);
    label1.setPos(0, 0);
    label1.setText("LED&LCD控制");
    label1.setSize(3, 1);
    label1.setColor(RC_GREY);
    LRemote.addControl(label1);

    button1.setPos(0, 1);
    button1.setText("LED ON/OFF控制");
    button1.setSize(3, 1);
    button1.setColor(RC_BLUE);
    LRemote.addControl(button1);

    switch1.setPos(0, 2);
    switch1.setSize(3, 1);
    switch1.setText("LCD背燈控制");
    switch1.setColor(RC_ORANGE);
    LRemote.addControl(switch1);

    button2.setPos(0, 3);
    button2.setText("LCD顯示控制");
    button2.setSize(3, 1);
    button2.setColor(RC_GREEN);
    LRemote.addControl(button2);

    label2.setPos(0, 4);
    label2.setText("曾希哲製作");
    label2.setSize(3, 1);
    label2.setColor(RC_GREY);
    LRemote.addControl(label2);
  LRemote.begin();
  lcd_i2c.clear();
  lcd_i2c.noBacklight();
  lcd_i2c.setCursor(0,0);
  lcd_i2c.print("LCD Controller");
  pinMode(LED_BUILTIN, OUTPUT);
}


void loop()
{
  LRemote.process();
  if (button1.isValueChanged()) {
    if (button1.getValue() == 1) {
      digitalWrite(LED_BUILTIN, HIGH);

    } else {
      digitalWrite(LED_BUILTIN, LOW);

    }

  }
  if (switch1.isValueChanged()) {
    if (switch1.getValue() == 1) {
      lcd_i2c.backlight();

    } else {
      lcd_i2c.noBacklight();

    }

  }
  if (button2.isValueChanged()) {
    if (button2.getValue() == 1) {
      lcd_i2c.clear();
      lcd_i2c.setCursor(0,0);
      lcd_i2c.print("Press LCD Button!!");
      delay(3000);
      lcd_i2c.clear();

    }

  }
  delay(100);
}