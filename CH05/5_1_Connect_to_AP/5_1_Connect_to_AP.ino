/*
 * Generated using BlocklyDuino:
 *
 * https://github.com/MediaTek-Labs/BlocklyDuino-for-LinkIt
 *
 * Date: Tue, 01 Jan 2019 03:01:28 GMT
 */

#include <LWiFi.h>

char _lwifi_ssid[] = "jackjean";
char _lwifi_pass[] = "0226852016";

void setup()
{
  Serial.begin(9600);

  Serial.println("開始Wi-Fi連線");
  while (WiFi.begin(_lwifi_ssid, _lwifi_pass) != WL_CONNECTED) { delay(1000); }
  Serial.println("Wi-Fi連線成功!!");
  Serial.print("linkit7697的IP：");
  Serial.println(WiFi.localIP().toString());
}


void loop()
{

}