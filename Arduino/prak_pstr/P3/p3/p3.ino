#include <dht.h>                        // DHTlib
#include <LiquidCrystal_I2C.h>
#define DHTPIN 8

dht dht11;
LiquidCrystal_I2C lcd(0x27, 16, 2);     // addr, chars, rows

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop() {
  dht11Function();
}

void dht11Function() {
  dht11.read11(DHTPIN);

  Serial.print("Temp: ");
  Serial.print(dht11.temperature);
  Serial.print(", humidity: ");
  Serial.println(dht11.humidity);

  delay(2000);
}

void showLCD() {
  lcd.print('Tc----RH');
  lcd.setCursor(0, 1);
  lcd.print(dht11.temperature);
  delay(100);
}
