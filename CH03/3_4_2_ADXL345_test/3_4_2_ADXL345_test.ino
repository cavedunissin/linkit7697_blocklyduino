/*
 * Generated using BlocklyDuino:
 *
 * https://github.com/MediaTek-Labs/BlocklyDuino-for-LinkIt
 *
 * Date: Sun, 06 Jan 2019 13:03:33 GMT
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
  adxl345.detectGesture();
  if (adxl345.isTapDetected()) {
    Serial.println("偵測到點一下!");

  }
  if (adxl345.isDoubleTapDetected()) {
    Serial.println("偵測到點二下!!");

  }
  if (adxl345.isActivityDetected()) {
    Serial.println("偵測到移動!");

  }
  delay(200);
}