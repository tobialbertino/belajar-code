#include <DHT.h>                      // DHT sensor library (Adafruit)

#define DHT_PIN 1
#define DHT_TYPE DHT11

DHT dht(DHT_PIN, DHT_TYPE);
float Humidity, TemperatureC;

void setup() {
  Serial.begin(9600);
  dht.begin();
}
void loop() {
  Humidity = dht.readHumidity();
  TemperatureC = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit
  Serial.println(Humidity);
  Serial.println(TemperatureC);
  delay(1000);
}
