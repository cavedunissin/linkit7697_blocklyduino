/*
 * Generated using BlocklyDuino:
 *
 * https://github.com/MediaTek-Labs/BlocklyDuino-for-LinkIt
 *
 * Date: Sun, 24 Mar 2019 12:05:10 GMT
 */



int Counter;

void setup()
{
  Serial.begin(9600);


  pinMode(7, OUTPUT);
}


void loop()
{
  Counter = 0;
  while (Counter <= 255) {
    analogWrite(7, Counter);
    Serial.println(Counter);
    Counter = Counter + 5;
    delay(400);
  }
}