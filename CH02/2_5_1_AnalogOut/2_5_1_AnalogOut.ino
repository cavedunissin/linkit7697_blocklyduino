/*
 * Generated using BlocklyDuino:
 *
 * https://github.com/MediaTek-Labs/BlocklyDuino-for-LinkIt
 *
 * Date: Sun, 24 Mar 2019 06:27:59 GMT
 */



void setup()
{

  pinMode(7, OUTPUT);
}


void loop()
{
  analogWrite(7, 0);
  delay(1000);
  analogWrite(7, 50);
  delay(1000);
  analogWrite(7, 100);
  delay(1000);
  analogWrite(7, 150);
  delay(1000);
  analogWrite(7, 200);
  delay(1000);
  analogWrite(7, 250);
  delay(1000);
}