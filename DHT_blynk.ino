#define BLYNK_TEMPLATE_ID "TMPL35YNilCc3"
#define BLYNK_TEMPLATE_NAME "abc"
#define BLYNK_AUTH_TOKEN "ss7_8bKpXVC2YWdbk6BCeVp783qvOJxS"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

#define DHTPIN 14 // DHT11 sensor pin D5

#define DHTTYPE DHT11 // DHT11 sensor type
DHT dht(DHTPIN, DHTTYPE);

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "chandan";
char pass[] = "chandans";

void setup()
{
 Serial.begin(9600);
 dht.begin();
 Blynk.begin(auth, ssid, pass);
}

void loop()
{
 Blynk.run();
 float temp = dht.readTemperature();
 float hum = dht.readHumidity();
 if (isnan(temp) || isnan(hum)) {
 Serial.println("Failed to read from DHT sensor!");
 return;
 }

Blynk.virtualWrite(V5, temp);
 Blynk.virtualWrite(V6, hum);
 delay(2000);
}