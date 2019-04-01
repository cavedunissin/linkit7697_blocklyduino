/*
 * Generated using BlocklyDuino:
 *
 * https://github.com/MediaTek-Labs/BlocklyDuino-for-LinkIt
 *
 * Date: Tue, 01 Jan 2019 06:49:03 GMT
 */

#include <LRemote.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd_i2c(0x3F);

int Count;

LRemoteLabel label1;
LRemoteCircleButton circle1;
LRemoteCircleButton circle2;
LRemoteLabel label2;

void setup()
{
  lcd_i2c.begin(16, 2);
  LRemote.setName("jackjean");
  LRemote.setOrientation(RC_PORTRAIT);
  LRemote.setGrid(4, 5);
    label1.setPos(0, 0);
    label1.setText("手機連續控制");
    label1.setSize(4, 1);
    label1.setColor(RC_GREY);
    LRemote.addControl(label1);

    circle1.setPos(0, 1);
    circle1.setSize(2, 2);
    circle1.setText("Count累增");
    circle1.setColor(RC_GREEN);
    LRemote.addControl(circle1);

    circle2.setPos(2, 1);
    circle2.setSize(2, 2);
    circle2.setText("Count遞減");
    circle2.setColor(RC_BLUE);
    LRemote.addControl(circle2);

    label2.setPos(0, 4);
    label2.setText("曾希哲製作");
    label2.setSize(4, 1);
    label2.setColor(RC_GREY);
    LRemote.addControl(label2);
  LRemote.begin();
  lcd_i2c.backlight();
  Count = 0;
}


void loop()
{
  LRemote.process();
  if (circle1.isValueChanged()) {
    if (circle1.getValue() == 1) {
      Count = Count + 1;

    }

  }
  if (circle2.isValueChanged()) {
    if (circle2.getValue() == 1) {
      Count = Count - 1;

    }

  }
  lcd_i2c.clear();
  lcd_i2c.setCursor(0,0);
  lcd_i2c.print("Count:");
  lcd_i2c.setCursor(0,1);
  lcd_i2c.print(Count);
  delay(100);
}