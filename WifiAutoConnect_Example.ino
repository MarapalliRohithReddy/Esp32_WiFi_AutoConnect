/*
 * ESP32 WiFi AutoConnection
 * @author :: MarapalliRohithReddy
 * @git page :: https://github.com/MarapalliRohithReddy
*/
#include <WiFi.h>
#include <HTTPClient.h>
#define ONBOARD_LED 2
byte mac[6];
const char* ssid = "SSID"; //Enter your SSID
const char* password = "PASSWORD"; //Enter your Password

void WiFi_Setup()
{
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("OK! IP=");
  Serial.println(WiFi.localIP());
  WiFi.macAddress(mac);
  Serial.print("MAC: ");
  Serial.print(mac[5], HEX);
  Serial.print(":");
  Serial.print(mac[4], HEX);
  Serial.print(":");
  Serial.print(mac[3], HEX);
  Serial.print(":");
  Serial.print(mac[2], HEX);
  Serial.print(":");
  Serial.print(mac[1], HEX);
  Serial.print(":");
  Serial.println(mac[0], HEX);
}

void setup() {
  Serial.begin(115200);
  pinMode(ONBOARD_LED, OUTPUT);
  digitalWrite(ONBOARD_LED, LOW);
  WiFi_Setup();
  if (WiFi.status() == WL_CONNECTED) {

    Serial.println("WiFi connected");
  }
  else {
    Serial.println("Wifi Disconnected");
  }
}
/*Main loop which runs forever*/
void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    digitalWrite(ONBOARD_LED, HIGH);
    Serial.println("looping");
    delay(100);
    digitalWrite(ONBOARD_LED, LOW);
    delay(2000);
  }
  else {
    Serial.println("Wifi Disconnected in loop");
    WiFi_Setup();
    delay(500);
  }
  
}
