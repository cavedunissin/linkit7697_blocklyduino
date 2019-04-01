/*
 * Generated using BlocklyDuino:
 *
 * https://github.com/MediaTek-Labs/BlocklyDuino-for-LinkIt
 *
 * Date: Tue, 01 Jan 2019 05:30:47 GMT
 */

#include <LWiFi.h>
#include <SPI.h>

#include <MFRC522.h>

String item;

char _lwifi_ssid[] = "你的WiFi熱點帳號";
char _lwifi_pass[] = "密碼";
MFRC522 rfid(/*SS_PIN*/ 10, /*RST_PIN*/ UINT8_MAX);

String mfrc522_readID()
{
  String ret;
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial())
  {
    MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);

    for (byte i = 0; i < rfid.uid.size; i++) {
      ret += (rfid.uid.uidByte[i] < 0x10 ? "0" : "");
      ret += String(rfid.uid.uidByte[i], HEX);
    }
  }

  // Halt PICC
  rfid.PICC_HaltA();

  // Stop encryption on PCD
  rfid.PCD_StopCrypto1();
  return ret;
}

void invokeIFTTT(const String& key, const String& event, const String& p1, const String& p2, const String& p3)
{
  // Initialize the Ethernet client library
  // with the IP address and port of the server
  // that you want to connect to (port 80 is default for HTTP):
  static TLSClient client;

  // This is the root certificate(CA) for https://maker.ifttt.com/
  // Different host server may use different root CA.
  static const char rootCA[] = "-----BEGIN CERTIFICATE-----\r\n"
  "MIIFJjCCBA6gAwIBAgIIRJxbLJxAihkwDQYJKoZIhvcNAQELBQAwgbQxCzAJBgNV\r\n"
  "BAYTAlVTMRAwDgYDVQQIEwdBcml6b25hMRMwEQYDVQQHEwpTY290dHNkYWxlMRow\r\n"
  "GAYDVQQKExFHb0RhZGR5LmNvbSwgSW5jLjEtMCsGA1UECxMkaHR0cDovL2NlcnRz\r\n"
  "LmdvZGFkZHkuY29tL3JlcG9zaXRvcnkvMTMwMQYDVQQDEypHbyBEYWRkeSBTZWN1\r\n"
  "cmUgQ2VydGlmaWNhdGUgQXV0aG9yaXR5IC0gRzIwHhcNMTYwNzI1MTc0NTM4WhcN\r\n"
  "MTgwOTI4MjIxMzU0WjA5MSEwHwYDVQQLExhEb21haW4gQ29udHJvbCBWYWxpZGF0\r\n"
  "ZWQxFDASBgNVBAMMCyouaWZ0dHQuY29tMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8A\r\n"
  "MIIBCgKCAQEA8c1HRaRBFWER/SG2eXN++ykWLSoCyJ1xcxOXy15Bk57WXGLIBZHn\r\n"
  "Y8/SN+H1KuUcN40KC35NuGhaQP43cELcBSG/BiYTlFPIAizauX2K9VZh+zWhwkgq\r\n"
  "y8bJ5+yvZKH5gwqNL248Y4gjwaPeU8o2K1xrFYWSfM/7kFQFul2goWOA3HIn5qE3\r\n"
  "NUsgxF8uLh2BSuJKQF73WDvM1zE86MIU20M9+PEo/pV5orIPZX/54cAZgXnr+59t\r\n"
  "KPL14Rl9qqTiptMJC8y2CIqKC9zHBwIwX4uYPOquom1oqAuItWgqAJwtC3z5a20r\r\n"
  "wbI2eNbDPdbeweT/4RtCjTwKlQuHmzeLbwIDAQABo4IBtDCCAbAwDAYDVR0TAQH/\r\n"
  "BAIwADAdBgNVHSUEFjAUBggrBgEFBQcDAQYIKwYBBQUHAwIwDgYDVR0PAQH/BAQD\r\n"
  "AgWgMDcGA1UdHwQwMC4wLKAqoCiGJmh0dHA6Ly9jcmwuZ29kYWRkeS5jb20vZ2Rp\r\n"
  "ZzJzMS0yNzMuY3JsMF0GA1UdIARWMFQwSAYLYIZIAYb9bQEHFwEwOTA3BggrBgEF\r\n"
  "BQcCARYraHR0cDovL2NlcnRpZmljYXRlcy5nb2RhZGR5LmNvbS9yZXBvc2l0b3J5\r\n"
  "LzAIBgZngQwBAgEwdgYIKwYBBQUHAQEEajBoMCQGCCsGAQUFBzABhhhodHRwOi8v\r\n"
  "b2NzcC5nb2RhZGR5LmNvbS8wQAYIKwYBBQUHMAKGNGh0dHA6Ly9jZXJ0aWZpY2F0\r\n"
  "ZXMuZ29kYWRkeS5jb20vcmVwb3NpdG9yeS9nZGlnMi5jcnQwHwYDVR0jBBgwFoAU\r\n"
  "QMK9J47MNIMwojPX+2yz8LQsgM4wIQYDVR0RBBowGIILKi5pZnR0dC5jb22CCWlm\r\n"
  "dHR0LmNvbTAdBgNVHQ4EFgQUTv/uQ1GFjIW3WdcM3sn8fwtzoKQwDQYJKoZIhvcN\r\n"
  "AQELBQADggEBAA0L5s4DXdeyx2rsVKljSq7CsDUbl1w8AgyxO0o1JAdYoPwZOlUT\r\n"
  "Yl6xL+jYtlgdINAOi/SDsEXtTQSMNb6xrGN0AfPgCRlKEBSEIluiRQc97H/AOmwp\r\n"
  "6HVeMQm/BVdQtp+i9MauwKJclB7ljReS0vlqMfk5FnlD3AT9eT61HUGcBVuyR37p\r\n"
  "vbHP2yRg+5uZnw5BqUOL1Y0asuK0vqlizllpRxikq9kMKsR8KaesRyHkVX/FAC9u\r\n"
  "uxxYke0T3f+dGlGzxm/ly6g5gQVbjdZGeoNma8qXjJ9o5BhZuAll7SajSLiXWERu\r\n"
  "n4PtYxVA4KsvJNDabHea1zF3pGyKzv7HAUc=\r\n"
  "-----END CERTIFICATE-----\r\n";

  // We must set root CA before connecting to host
  // Note that the lenght includes the terminating NULL,
  // so use sizeof() instead of strlen().
  client.setRootCA(rootCA, sizeof(rootCA));
  if (client.connect("maker.ifttt.com", 443)) {
      // Make a HTTP request over SSL (HTTPS)

      const String payload = String() + "{\"value1\":\"" + p1
                        + "\",\"value2\":\"" + p2
                        + "\",\"value3\":\"" + p3
                        + "\"}";

      const String url = String() + "https://maker.ifttt.com/trigger/" + event + "/with/key/" + key;

      client.println(String() + "POST " + url + " HTTP/1.1");
      client.println("Host: maker.ifttt.com");
      client.println("User-Agent: BlocklyDuino/1.0");
      client.println("Content-Type: application/json;charset=utf-8");
      client.print("Content-Length: ");
      client.println(payload.length());
      client.println("User-Agent: BlocklyDuino/1.0");
      client.println("Accept: */*");
      client.println("Connection: close");

      client.println();
      client.print(payload);

      client.println();
      delay(300);
  }

  // wait for server response
  // if there are incoming bytes available
  // from the server, read them and print them:
  while (client.available()) {
      char c = client.read();
      // Serial.print(c);
      delay(1);
  }

  // if the server's disconnected, stop the client:
  if (!client.connected()) {
      //Serial.println();
      //Serial.println("disconnecting from server.");
      client.stop();
  }
}

void setup()
{
  Serial.begin(9600);

  while (WiFi.begin(_lwifi_ssid, _lwifi_pass) != WL_CONNECTED) { delay(1000); }
  Serial.println(String() + "IP 是" + WiFi.localIP().toString());
  SPI.begin();
  rfid.PCD_Init();

}


void loop()
{
  item = mfrc522_readID();
  if (item != "") {
    Serial.print("Card No is ");
    Serial.println(item);
    tone(2, 1000, 500);
    if (item == "你的FRID卡號") {
      invokeIFTTT("觸發密碼", "你設定的觸發事件", String("你的姓名"), String(0), String(0));
      Serial.println("觸發IFTTTevent");

    }

  }
}