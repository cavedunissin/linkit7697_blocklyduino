/*
 * Generated using BlocklyDuino:
 *
 * https://github.com/MediaTek-Labs/BlocklyDuino-for-LinkIt
 *
 * Date: Sun, 31 Mar 2019 13:11:02 GMT
 */



int VR;

int Map;

void setup()
{
  Serial.begin(9600);

  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  analogWrite(7, 0);
  analogWrite(8, 0);
  analogWrite(9, 0);
}


void loop()
{
  VR = analogRead(A0);
  Map = ((float) VR / 4096) * 255;
  analogWrite(7, Map);
  Serial.println(Map);
}