/*
 * Generated using BlocklyDuino:
 *
 * https://github.com/MediaTek-Labs/BlocklyDuino-for-LinkIt
 *
 * Date: Tue, 01 Jan 2019 06:48:32 GMT
 */

#include <LRemote.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd_i2c(0x3F);

int count1;

int count2;

int count3;

int count4;

LRemoteLabel label1;
LRemoteCircleButton circle1;
LRemoteCircleButton circle2;
LRemoteCircleButton circle3;
LRemoteCircleButton circle4;
LRemoteLabel label2;

void setup()
{
  lcd_i2c.begin(16, 2);
  LRemote.setName("jackjean@HLC");
  LRemote.setOrientation(RC_PORTRAIT);
  LRemote.setGrid(4, 6);
    label1.setPos(0, 0);
    label1.setText("按鈕測試");
    label1.setSize(4, 1);
    label1.setColor(RC_GREY);
    LRemote.addControl(label1);

    circle1.setPos(0, 1);
    circle1.setSize(2, 2);
    circle1.setText("正常");
    circle1.setColor(RC_BLUE);
    LRemote.addControl(circle1);

    circle2.setPos(2, 1);
    circle2.setSize(2, 2);
    circle2.setText("累加");
    circle2.setColor(RC_GREEN);
    LRemote.addControl(circle2);

    circle3.setPos(0, 3);
    circle3.setSize(2, 2);
    circle3.setText("按下");
    circle3.setColor(RC_PINK);
    LRemote.addControl(circle3);

    circle4.setPos(2, 3);
    circle4.setSize(2, 2);
    circle4.setText("釋放");
    circle4.setColor(RC_YELLOW);
    LRemote.addControl(circle4);

    label2.setPos(0, 5);
    label2.setText("曾希哲製作");
    label2.setSize(4, 1);
    label2.setColor(RC_GREY);
    LRemote.addControl(label2);
  LRemote.begin();
  lcd_i2c.backlight();
  lcd_i2c.clear();
  count1 = 0;
  count2 = 0;
  count3 = 0;
  count4 = 0;
}


void loop()
{
  LRemote.process();
  if (circle1.isValueChanged()) {
    if (circle1.getValue() == 1) {
      count1 = count1 + 1;

    } else {
      count1 = count1 + 1;

    }

  }
  if (circle2.getValue() == 1) {
    count2 = count2 + 1;

  }
  if (circle3.isValueChanged()) {
    if (circle3.getValue() == 1) {
      count3 = count3 + 1;

    }

  }
  if (circle4.isValueChanged()) {
    if (circle4.getValue() == 0) {
      count4 = count4 + 1;

    }

  }
  lcd_i2c.setCursor(0,0);
  lcd_i2c.print("C1:");
  lcd_i2c.setCursor(3,0);
  lcd_i2c.print(count1);
  lcd_i2c.setCursor(6,0);
  lcd_i2c.print("C2:");
  lcd_i2c.setCursor(9,0);
  lcd_i2c.print(count2);
  lcd_i2c.setCursor(0,1);
  lcd_i2c.print("C3:");
  lcd_i2c.setCursor(3,1);
  lcd_i2c.print(count3);
  lcd_i2c.setCursor(6,1);
  lcd_i2c.print("C4:");
  lcd_i2c.setCursor(9,1);
  lcd_i2c.print(count4);
  delay(50);
}