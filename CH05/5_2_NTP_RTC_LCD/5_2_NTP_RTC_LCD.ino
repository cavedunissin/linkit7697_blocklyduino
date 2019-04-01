/*
 * Generated using BlocklyDuino:
 *
 * https://github.com/MediaTek-Labs/BlocklyDuino-for-LinkIt
 *
 * Date: Tue, 01 Jan 2019 03:02:43 GMT
 */

#include <LWiFi.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd_i2c(0x3F);

#include <LRTC.h>
#include <WiFiUdp.h>
#include <ctime>

String TimeString;

char _lwifi_ssid[] = "jackjean";
char _lwifi_pass[] = "0226852016";

void set_rtc_from_time_string(const String& time_str) {
  // field_index [0,1,2,3,4,5] = [Year,Month,Day,Hour,Minute,Sec]
  int fields[6] = {0};
  sscanf(time_str.c_str(), "%d-%d-%dT%d:%d:%d+08",
          &fields[0], &fields[1], &fields[2],
          &fields[3], &fields[4], &fields[5]);
  LRTC.set(fields[0], fields[1], fields[2],
           fields[3], fields[4], fields[5]);
}

const char *NTP_server = "time.stdtime.gov.tw";
const int NTP_PACKET_SIZE = 48;                   // NTP time stamp is in the first 48 bytes of the message
static byte packetBuffer[NTP_PACKET_SIZE] = {0};  //buffer to hold incoming and outgoing packets
const unsigned int localPort = 2390;              // local port to listen for UDP packets
static WiFiUDP Udp;                               // A UDP instance to let us send and receive packets over UDP

String getNetworkTime() {
  Udp.begin(localPort);
  sendNTPpacket(NTP_server); // send an NTP packet to a time server
  // wait to see if a reply is available
  delay(1000);
  if (Udp.parsePacket()) {
    // We've received a packet, read the data from it
    Udp.read(packetBuffer, NTP_PACKET_SIZE); // read the packet into the buffer

    //the timestamp starts at byte 40 of the received packet and is four bytes,
    // or two words, long. First, esxtract the two words:
    const unsigned long highWord = word(packetBuffer[40], packetBuffer[41]);
    const unsigned long lowWord = word(packetBuffer[42], packetBuffer[43]);
    // combine the four bytes (two words) into a long integer
    // this is NTP time (seconds since Jan 1 1900):
    const unsigned long secsSince1900 = highWord << 16 | lowWord;
    // Unix time starts on Jan 1 1970. In seconds, that's 2208988800:
    const unsigned long seventyYears = 2208988800UL;
    // subtract seventy years:
    const unsigned long epoch = secsSince1900 - seventyYears;
    // Taiwan is UTC+8 = 8 * 60 * 60 seconds
    const time_t taiwan_time = epoch + (8 * 60 * 60);
    // const tm* pTime = gmtime(&taiwan_time);
    static char time_text[] = "YYYY-MM-DDTHH:MM:SS+08";
    strftime(time_text, sizeof(time_text), "%Y-%m-%dT%H:%M:%S+08", gmtime(&taiwan_time));
    return String((const char*)time_text);
  }

  return String("Connection error");
}

// send an NTP request to the time server at the given address
unsigned long sendNTPpacket(const char* host) {
	//Serial.println("1");
	// set all bytes in the buffer to 0
	memset(packetBuffer, 0, NTP_PACKET_SIZE);
	// Initialize values needed to form NTP request
	// (see URL above for details on the packets)
	//Serial.println("2");
	packetBuffer[0] = 0b11100011;   // LI, Version, Mode
	packetBuffer[1] = 0;     // Stratum, or type of clock
	packetBuffer[2] = 6;     // Polling Interval
	packetBuffer[3] = 0xEC;  // Peer Clock Precision
	// 8 bytes of zero for Root Delay & Root Dispersion
	packetBuffer[12]  = 49;
	packetBuffer[13]  = 0x4E;
	packetBuffer[14]  = 49;
	packetBuffer[15]  = 52;

	//Serial.println("3");

	// all NTP fields have been given values, now
	// you can send a packet requesting a timestamp:
	Udp.beginPacket(host, 123); //NTP requests are to port 123
	//Serial.println("4");
	Udp.write(packetBuffer, NTP_PACKET_SIZE);
	//Serial.println("5");
	Udp.endPacket();
	//Serial.println("6");

	return 0;
}

String get_time_from_RTC() {
  // get time from the RTC module
  LRTC.get();

  // format to time string
  static char buffer[] = "YYYY-MM-DDTHH:MM:SS+08";
  sprintf(buffer, "%04ld-%02ld-%02ldT%02ld:%02ld:%02ld+08",
    LRTC.year(),
    LRTC.month(),
    LRTC.day(),
    LRTC.hour(),
    LRTC.minute(),
    LRTC.second());

  return String(buffer);
}

int get_field_from_time_string(const String& time_str, int field_index) {
  // field_index [0,1,2,3,4,5] = [Year,Month,Day,Hour,Minute,Sec]
  int fields[6] = {0};
  sscanf(time_str.c_str(), "%d-%d-%dT%d:%d:%d+08",
          &fields[0], &fields[1], &fields[2],
          &fields[3], &fields[4], &fields[5]);
  if(field_index < 0 || field_index > 5) {
    return 0;
  } else {
    return fields[field_index];
  }
}

void setup()
{
  Serial.begin(9600);

  lcd_i2c.begin(16, 2);
  LRTC.begin();
  Serial.println("WiFi開始連線!");
  while (WiFi.begin(_lwifi_ssid, _lwifi_pass) != WL_CONNECTED) { delay(1000); }
  Serial.println("WiFi連線成功!");
  Serial.println(String() + "IP is " + WiFi.localIP().toString());
  set_rtc_from_time_string(getNetworkTime());
}


void loop()
{
  TimeString = get_time_from_RTC();
  lcd_i2c.clear();
  lcd_i2c.setCursor(0,0);
  lcd_i2c.print(String() + get_field_from_time_string(TimeString, 0) + "/" + get_field_from_time_string(TimeString, 1) + "/" + get_field_from_time_string(TimeString, 2));
  lcd_i2c.setCursor(0,1);
  lcd_i2c.print(String() + get_field_from_time_string(TimeString, 3) + ":" + get_field_from_time_string(TimeString, 4) + ":" + get_field_from_time_string(TimeString, 5));
  delay(1000);
}