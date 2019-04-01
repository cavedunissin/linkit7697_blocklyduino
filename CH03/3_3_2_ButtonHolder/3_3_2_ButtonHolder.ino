/*
 * Generated using BlocklyDuino:
 *
 * https://github.com/MediaTek-Labs/BlocklyDuino-for-LinkIt
 *
 * Date: Tue, 01 Jan 2019 09:20:48 GMT
 */



int Sw;

int SwOld;

int Butten;

void setup()
{
  Sw = 0;
  SwOld = 0;
  Butten = 0;
  pinMode(6, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}


void loop()
{
  Sw = digitalRead(6);
  if (SwOld == 0 && Sw == 1) {
    Butten = 1 - Butten;
    delay(100);

  }
  SwOld = Sw;
  if (Butten == 1) {
    digitalWrite(LED_BUILTIN, HIGH);

  } else {
    digitalWrite(LED_BUILTIN, LOW);

  }
}