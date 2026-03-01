#include <WiFi.h>
#include <WebServer.h>
#include "DHT.h"
#define DHTTYPE DHT11
#define DHTPin 27
const char* ssid = "SabaSameko"; //wifi name here
const char* pass = "SukaBumi"; //pass wifi here
WebServer server(80);
DHT dht(DHTPin, DHTTYPE);
float temp;
float hum;

void setup()
{
  Serial.begin(115200);
  dht.begin();
  delay(100);
  Serial.println("Connecting -->");
  Serial.println(ssid);
  WiFi.begin(ssid,pass);
  while (WiFi.status()!= WL_CONNECTED)
  {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println(WiFi.localIP());
  server.on("/", handle_onconnect);
  server.onNotFound(handle_notfound);
  server.begin();
  Serial.println("HTTP server started.");
}

void loop() 
{
  server.handleClient();
}

void handle_onconnect()
{
  temp = dht.readTemperature();
  hum = dht.readHumidity();
  server.send(200, "text/html", SendHTML(temp,hum));
}

void handle_notfound()
{
  server.send(404, "text/plain", "not found.");
}

String SendHTML(float tempstat,float humstat)
{
  String ptr = "<!DOCTYPE html><html>\n";
  ptr += "<head><meta name =\"viewport\" content=\"width-device-width,initial-scale=1.0, user-scalable=no\">\n";
  ptr += "<link rel=\"stylesheet\" href=\"https://use.fontawesome.com/releases/v5.7.2/css/all.css\"integrity=\"sha384-fnmOCqbTlWIlj8LyTjo7mOUStjsKC4pOpQbqyi7RrhN7udi9RwhKkMHpvLbHG9Sr\"crossorigin=\"anonymous\">\n";
  ptr += "<title>Monitoring Temperature via Webserver </title>\n";
  ptr += "<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr += "body{margin-top: 50px;} h1 {color: #444444; margin-bottom: 10px;} units {font-size: 1.2rem;}\n";
  ptr += "dht-labels{font-size: 1.5rem; vertical-align:middle;padding-bottom: 15px;}\n";
  ptr += "</style>\n";
  ptr += "</head>\n";
  ptr += "<body>\n";
  ptr += "<div id=\"webpage\">\n";
  ptr += "<h1>Monitoring Temperature via Webserver</h1>\n";
  ptr += "<p>\n";
  ptr += "<i class =\"fas fa-thermometer-half\"style=\"color:#059e8a;\"></i>\n";
  ptr += "Temperature :";
  ptr += tempstat;
  ptr += "<sup class= \"units\">&deg;C</sup>\n";
  ptr += "</p>\n";
  ptr += "<p>\n";
  ptr += "<i class=\"fas fa-tint\"style=\"color:#00add6;\"></i>\n";
  ptr += "Humidity :";
  ptr += humstat;
  ptr += "<sup class=\"units\">&percnt;</sup>\n";
  ptr += "</p>\n";
  ptr += "</div>\n";
  ptr += "</body>\n";
  ptr += "</html>\n";
  return ptr;
}