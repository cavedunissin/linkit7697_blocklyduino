/*
 * Generated using BlocklyDuino:
 *
 * https://github.com/MediaTek-Labs/BlocklyDuino-for-LinkIt
 *
 * Date: Tue, 01 Jan 2019 05:31:44 GMT
 */

#include <LWiFi.h>
#include "MCS.h"

int LED;

char _lwifi_ssid[] = "你的WiFi熱點帳號";
char _lwifi_pass[] = "密碼";
MCSDevice mcs("MCS測試裝置的DeviceID", "MCS測試裝置的DeviceKey");

MCSControllerOnOff LED_Control("LED_Control");
MCSDisplayOnOff LED_Status("LED_Status");

void setup()
{
  Serial.begin(9600);

  mcs.addChannel(LED_Control);
  mcs.addChannel(LED_Status);
  Serial.println("WIFI連線開始");
  LED = 0;
  while (WiFi.begin(_lwifi_ssid, _lwifi_pass) != WL_CONNECTED) { delay(1000); }
  Serial.println("WIFI連線成功");
  Serial.println(String() + "IP是" + WiFi.localIP().toString());
  delay(1000);
  while(!mcs.connected()) { mcs.connect(); }
  Serial.println("MCS連線成功");
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}


void loop()
{
  while (!mcs.connected()) {
    mcs.connect();
    if (mcs.connected()) { Serial.println("MCS Reconnected."); }
  }
  mcs.process(100);
  if (LED_Control.updated()) {
    Serial.print("LED 控制信號更新:");
    Serial.println(LED_Control.value());
    if (LED_Control.value()) {
      digitalWrite(LED_BUILTIN, HIGH);
      LED = 1;

    } else {
      digitalWrite(LED_BUILTIN, LOW);
      LED = 0;

    }

  }
  LED_Status.set(LED);
}