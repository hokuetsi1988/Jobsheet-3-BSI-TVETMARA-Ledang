/*
#define BLYNK_TEMPLATE_ID "" //we'll get this when we setup on blynk's end
#define BLYNK_TEMPLATE_NAME "" //same as above
#define BLYNK_AUTH_TOKEN "" //same as above lol
*/

#define BLYNK_TEMPLATE_ID "TMPL65Mx5aJie"
#define BLYNK_TEMPLATE_NAME "Monitoring Humidity and Temperature via Blynk"
#define BLYNK_AUTH_TOKEN "trrW57OlF0BGzqgKdKIBqUDf3AblZGJ8"

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "SabaSameko"; //wifi name goes here
char pass[] = "SukaBumi"; //password goes here

BlynkTimer timer;

#define DHTPIN 27
#define TYPE DHT11 //change to DHT11 if you use the other model
DHT dht(DHTPIN,TYPE);

void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t))
  {
    Serial.println("Failed to read from DHT Sensor.");
    return;
  }
  Blynk.virtualWrite(V0,t);
  Blynk.virtualWrite(V1,h);
  Serial.print("Temps :");
  Serial.print(t);
  Serial.print("   Humid :");
  Serial.println(h);
}

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  dht.begin();
  timer.setInterval(100L,sendSensor);
}

void loop() {
  Blynk.run();
  timer.run();
}
