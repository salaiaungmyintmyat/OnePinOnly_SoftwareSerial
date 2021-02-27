/*
  OnePinOnly Example
  ------------------
  SoftwareSerial object now only create Rx or Tx pin only mode.
  This method is handy when there is only needed one pin (Tx or Rx) and
  not much pin available for both pins in the project.

  Only need to declare as "DISABLED_PIN" for unused pin.

  Notes: This is update to original Arduino SoftwareSerial library that based on
         Mikal Hart.

  Date: 27-Feb-2021
  Author: Salai Aung Myint Myat
*/

#include "SoftwareSerialOnePinOnly.h"

#define RX_PIN   2
#define TX_PIN   3

SoftwareSerial RxSoftOnly(RX_PIN, DISABLED_PIN);   // Only used Rx pin
SoftwareSerial TxSoftOnly(DISABLED_PIN, TX_PIN);   // Only used Tx pin

void setup() {
  // Open serial communications for ports
  Serial.begin(9600);

  // Open software serial communication channels
  RxSoftOnly.begin(9600);
  TxSoftOnly.begin(9600);

  Serial.println("Start");
}

void loop() {
  // Continuously listen from SoftwareSerial RxOnlyPin
  // And write on Serial Monitor
  if (RxSoftOnly.available()) {
    Serial.write(RxSoftOnly.read());
  }

  // Continuously listen from Serial Monitor
  // And write on TxOnlyPin SoftwareSerial Channel
  if (Serial.available()) {
    TxSoftOnly.write(Serial.read());
  }

}
