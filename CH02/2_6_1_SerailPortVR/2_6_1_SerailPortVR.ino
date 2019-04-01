/*
 * Generated using BlocklyDuino:
 *
 * https://github.com/MediaTek-Labs/BlocklyDuino-for-LinkIt
 *
 * Date: Mon, 25 Mar 2019 13:54:18 GMT
 */



void setup()
{
  Serial.begin(9600);


}


void loop()
{
  Serial.println(analogRead(A0));
  delay(400);
}