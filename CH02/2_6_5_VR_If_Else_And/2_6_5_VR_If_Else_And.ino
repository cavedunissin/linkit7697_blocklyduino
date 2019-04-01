/*
 * Generated using BlocklyDuino:
 *
 * https://github.com/MediaTek-Labs/BlocklyDuino-for-LinkIt
 *
 * Date: Sun, 31 Mar 2019 15:07:28 GMT
 */



int VR;

void setup()
{
  Serial.begin(9600);

  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
}


void loop()
{
  VR = analogRead(A0);
  Serial.println(VR);
  if (VR >= 0 && VR <= 1000) {
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);

  }
  if (VR > 1000 && VR <= 2000) {
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);

  }
  if (VR > 2000) {
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);

  }
}