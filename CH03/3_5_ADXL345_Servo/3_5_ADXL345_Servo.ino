/*
 * Generated using BlocklyDuino:
 *
 * https://github.com/MediaTek-Labs/BlocklyDuino-for-LinkIt
 *
 * Date: Sun, 20 Jan 2019 15:02:22 GMT
 */

#include <Servo.h>
#include <Wire.h>
#include <adxl345_blockly.h>

int X_Position;

int Y_Position;

Servo __myservo2;
Servo __myservo5;
ADXL345Block adxl345;

void setup()
{
  Serial.begin(115200);

  __myservo2.attach(2);
  __myservo5.attach(5);
  X_Position = 90;
  Y_Position = 90;
  __myservo2.write(X_Position);
  __myservo5.write(Y_Position);
  Serial.print("X軸:");
  Serial.println(__myservo2.read());
  Serial.print("Y軸:");
  Serial.println(__myservo5.read());
  delay(1000);
  adxl345.begin();
}


void loop()
{
  X_Position = ((adxl345.getX() + 1) / 2) * 170;
  Y_Position = ((adxl345.getY() + 1) / 2) * 170;
  __myservo2.write(X_Position);
  delay(50);
  __myservo5.write(Y_Position);
  delay(50);
  Serial.print("X軸:");
  Serial.println(X_Position);
  Serial.print("Y軸:");
  Serial.println(Y_Position);
}