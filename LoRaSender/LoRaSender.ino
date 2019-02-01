#include <Time.h>
#include <TimeLib.h>
#include <SPI.h>
#include <LoRa.h>
#include <ArduinoJson.h>

#define NODEID 1;
const int pinAdc = A0;
void setup() {
  int h = 6;
  int m = 02;
  int s = 00;
  int d = 28;
  int mh = 1;
  int y = 2019;
  setTime(h, m, s, d, mh, y);

  Serial.println("LoRa Sender");

  if (!LoRa.begin(915E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}//end steup

char data[100];

//initialize json object
StaticJsonBuffer<200> jsonBuffer;
JsonObject& jsonObj = jsonBuffer.createObject();

void loop() {
  Serial.print("Sending packet: ");

  time_t t = now();

  long sum = 0;
  for (int i = 0; i < 32; i++)
  {
    sum += analogRead(pinAdc);
  }

  sum >>= 5;


  // Send a message to rf95_server

  //You have to convert from uint8_t to char
  //Because it does not accept to send an array with buffer uin8_t
  jsonObj["NodeID"] = NODEID;
  jsonObj["Microphone"] = int(sum);
  jsonObj["Time"] = hour(t);
  jsonObj["Date"] = year(t);

  // send packet
  LoRa.beginPacket();
  Serial.print("Sending Packets");
  jsonObj.printTo(LoRa);
  LoRa.endPacket();

  delay(100);
}
