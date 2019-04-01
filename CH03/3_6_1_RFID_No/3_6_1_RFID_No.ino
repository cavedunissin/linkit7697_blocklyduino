/*
 * Generated using BlocklyDuino:
 *
 * https://github.com/MediaTek-Labs/BlocklyDuino-for-LinkIt
 *
 * Date: Tue, 01 Jan 2019 09:18:42 GMT
 */

#include <SPI.h>

#include <MFRC522.h>

String RfidNo;

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

void setup()
{
  Serial.begin(9600);


  SPI.begin();
  rfid.PCD_Init();

}


void loop()
{
  RfidNo = mfrc522_readID();
  if (RfidNo != "") {
    Serial.println("偵測到Mifare S50卡片");
    Serial.print("卡片卡號為：");
    Serial.println(RfidNo);
    Serial.println("");

  }
  delay(1000);
}