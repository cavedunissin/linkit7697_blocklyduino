/*
 * Generated using BlocklyDuino:
 *
 * https://github.com/MediaTek-Labs/BlocklyDuino-for-LinkIt
 *
 * Date: Sat, 23 Mar 2019 23:09:31 GMT
 */



void setup()
{
  Serial.begin(9600);


  pinMode(2, INPUT);
}


void loop()
{
  Serial.println(digitalRead(2));
  delay(1000);
}