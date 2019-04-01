/*
 * Generated using BlocklyDuino:
 *
 * https://github.com/MediaTek-Labs/BlocklyDuino-for-LinkIt
 *
 * Date: Sun, 06 Jan 2019 11:30:34 GMT
 */

#include <Wire.h>
#include <adxl345_blockly.h>

ADXL345Block adxl345;

void setup()
{
  Serial.begin(115200);


  adxl345.begin();
}


void loop()
{
  Serial.println(String() + "X軸:" + adxl345.getX());
  Serial.println(String() + "Y軸:" + adxl345.getY());
  Serial.println(String() + "Z軸:" + adxl345.getZ());
  Serial.println(String() + "俯仰角度:" + adxl345.getPitch());
  Serial.println(String() + "翻滾角度:" + adxl345.getRoll());
  delay(200);
}