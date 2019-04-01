/*
 * Generated using BlocklyDuino:
 *
 * https://github.com/MediaTek-Labs/BlocklyDuino-for-LinkIt
 *
 * Date: Mon, 25 Mar 2019 08:26:20 GMT
 */



int i;

void setup()
{
  Serial.begin(9600);


  pinMode(7, OUTPUT);
}


void loop()
{
  for (i = 0; i <= 255; i++) {
    analogWrite(7, i);
    Serial.println(i);
    delay(400);
  }
}