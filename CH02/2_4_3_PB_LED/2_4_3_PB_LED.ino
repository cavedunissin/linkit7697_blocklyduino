/*
 * Generated using BlocklyDuino:
 *
 * https://github.com/MediaTek-Labs/BlocklyDuino-for-LinkIt
 *
 * Date: Sun, 31 Mar 2019 12:10:05 GMT
 */



void setup()
{
  pinMode(7, OUTPUT);
  digitalWrite(7, LOW);
  pinMode(2, INPUT);
}


void loop()
{
  if (digitalRead(2)) {
    digitalWrite(7, HIGH);

  } else {
    digitalWrite(7, LOW);

  }
}