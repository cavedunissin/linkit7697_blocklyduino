/*
 * Generated using BlocklyDuino:
 *
 * https://github.com/MediaTek-Labs/BlocklyDuino-for-LinkIt
 *
 * Date: Tue, 01 Jan 2019 06:30:35 GMT
 */

#include <LRemote.h>

LRemoteLabel label1;
LRemoteSwitch switch1;
LRemoteButton button1;
LRemoteSlider slider1;
LRemoteCircleButton circle1;

void setup()
{
  LRemote.setName("jackjean");
  LRemote.setOrientation(RC_PORTRAIT);
  LRemote.setGrid(5, 6);
    label1.setPos(0, 0);
    label1.setText("曾希哲測試");
    label1.setSize(5, 1);
    label1.setColor(RC_GREY);
    LRemote.addControl(label1);

    switch1.setPos(0, 1);
    switch1.setSize(2, 1);
    switch1.setText("USR LED");
    switch1.setColor(RC_GREY);
    LRemote.addControl(switch1);

    button1.setPos(2, 1);
    button1.setText("PRESS ME");
    button1.setSize(3, 1);
    button1.setColor(RC_PINK);
    LRemote.addControl(button1);

    slider1.setPos(0, 2);
    slider1.setSize(5, 1);
    slider1.setText("Value Slider");
    slider1.setValueRange((-100), 1024, 1);
    slider1.setColor(RC_ORANGE);
    LRemote.addControl(slider1);

    circle1.setPos(1, 3);
    circle1.setSize(3, 3);
    circle1.setText("!BIG!");
    circle1.setColor(RC_GREEN);
    LRemote.addControl(circle1);
  LRemote.begin();
}


void loop()
{

}