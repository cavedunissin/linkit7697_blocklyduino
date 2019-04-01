/*
 * Generated using BlocklyDuino:
 *
 * https://github.com/MediaTek-Labs/BlocklyDuino-for-LinkIt
 *
 * Date: Mon, 25 Mar 2019 07:51:31 GMT
 */



int k;

int j;

int i;

void setup()
{
  Serial.begin(9600);


  pinMode(k, OUTPUT);
  pinMode(j, OUTPUT);
}


void loop()
{
  for (k = 7; k <= 9; k++) {
    analogWrite(k, 0);
  }
  for (j = 7; j <= 9; j++) {
    for (i = 0; i <= 255; i++) {
      analogWrite(j, i);
      Serial.println(i);
      delay(400);
    }
  }
}