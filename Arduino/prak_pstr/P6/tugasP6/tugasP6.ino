#include <DHT.h>                      // DHT sensor library (Adafruit)
#include <LiquidCrystal_I2C.h>        // LiquidCrystal I2C  (Marco Schwartz)
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

#define SSID  "Muchchal2101"
#define PASS  "NT2604D23"
#define PHOTORESISTOR A0

int light;

DHT dht(D3, DHT11);
LiquidCrystal_I2C lcd(0x27, 16, 2);
int Tc, RH;

void setup() {
  dht.begin();
  lcd.init();
  lcd.backlight();
  WiFi.begin(SSID, PASS);
  while (WiFi.status() != WL_CONNECTED) delay(500);
}

void loop() {
  Tc = dht.readTemperature();
  RH = dht.readHumidity();
  light = analogRead(PHOTORESISTOR);   //10 bit - 0-1023

  show_temp();
  if (WiFi.status() == WL_CONNECTED)
    send_data();

  delay(20000);
}

void send_data() {
  WiFiClient wifi;
  HTTPClient http;
  http.begin(wifi, "http://api.thingspeak.com/update");
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  int status = http.POST("api_key=EF34AJHEW9VCGVPL&field1=" + String(Tc) + "&field2=" + RH + "&field3=" + WiFi.RSSI() + "&field4=" +light);
  http.end();
  lcd.setCursor(13, 1);
  lcd.print(status);
}

void show_temp() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Tc     RH");
  lcd.setCursor(0, 1);
  lcd.print(Tc);
  lcd.print(char(223));
  lcd.print("    ");
  lcd.print(RH);
  lcd.print("%");
}
