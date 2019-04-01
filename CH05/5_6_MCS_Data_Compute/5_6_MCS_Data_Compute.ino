/*
 * Generated using BlocklyDuino:
 *
 * https://github.com/MediaTek-Labs/BlocklyDuino-for-LinkIt
 *
 * Date: Tue, 01 Jan 2019 05:34:37 GMT
 */

#include <LWiFi.h>
#include "MCS.h"

int RandomNo;

char _lwifi_ssid[] = "jackjean";
char _lwifi_pass[] = "0226852016";
MCSDevice mcs("DBpkpYRm", "v8A0gHePSnc3wyO5");

MCSDisplayInteger classifier("classifier");

void setup()
{
  Serial.begin(9600);

  mcs.addChannel(classifier);
  Serial.println("WIFI連線開始");
  while (WiFi.begin(_lwifi_ssid, _lwifi_pass) != WL_CONNECTED) { delay(1000); }
  Serial.println("WIFI連線成功");
  Serial.println(String() + "IP是" + WiFi.localIP().toString());
  delay(1000);
  while(!mcs.connected()) { mcs.connect(); }
  Serial.println("MCS連線成功");
  Serial.begin(9600);
}


void loop()
{
  while (!mcs.connected()) {
    mcs.connect();
    if (mcs.connected()) { Serial.println("MCS Reconnected."); }
  }
  mcs.process(100);
  RandomNo = (random(1, 100));
  Serial.println(RandomNo);
  classifier.set(RandomNo);
  delay(1000);
}