/*
 * Generated using BlocklyDuino:
 *
 * https://github.com/MediaTek-Labs/BlocklyDuino-for-LinkIt
 *
 * Date: Tue, 01 Jan 2019 05:33:45 GMT
 */

#include <LWiFi.h>
#include "MCS.h"

#include <DHT.h>

int Temp;

int Humi;

char _lwifi_ssid[] = "你的WiFi熱點帳號";
char _lwifi_pass[] = "密碼";
MCSDevice mcs("MCS測試裝置的DeviceID", "MCS測試裝置的DeviceKey");

MCSDisplayInteger Temperature("Temperature");
MCSDisplayInteger Humidity("Humidity");
DHT dht11_p2(2, DHT11);

void setup()
{
  Serial.begin(9600);

  mcs.addChannel(Temperature);
  mcs.addChannel(Humidity);
  Serial.println("WIFI連線開始");
  while (WiFi.begin(_lwifi_ssid, _lwifi_pass) != WL_CONNECTED) { delay(1000); }
  Serial.println("WIFI連線成功");
  Serial.println(String() + "IP是" + WiFi.localIP().toString());
  delay(1000);
  while(!mcs.connected()) { mcs.connect(); }
  Serial.println("MCS連線成功");
  Serial.begin(9600);
  dht11_p2.begin();
}


void loop()
{
  while (!mcs.connected()) {
    mcs.connect();
    if (mcs.connected()) { Serial.println("MCS Reconnected."); }
  }
  mcs.process(100);
  Temp = dht11_p2.readTemperature();
  Humi = dht11_p2.readHumidity();
  Serial.println(String() + "溫度為" + Temp);
  Serial.println(String() + "相對濕度為" + Humi);
  Temperature.set(Temp);
  Humidity.set(Humi);
  delay(1000);
}