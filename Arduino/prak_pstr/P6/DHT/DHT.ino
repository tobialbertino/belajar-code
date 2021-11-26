/*  18. ESP8266 DHT11

    WemosD1   DHT11   LCD
    -------   -----   ---
    3V3       Vcc
    5V                Vcc
    Gnd       Gnd     Gnd
    D1                SCL
    D2                SDA
    D3        Out
 */

#include <DHT.h>                      // DHT sensor library (Adafruit)
#include <LiquidCrystal_I2C.h>        // LiquidCrystal I2C  (Marco Schwartz)

DHT dht(D3, DHT11);
LiquidCrystal_I2C lcd(0x27, 16, 2);
int Tc, RH;

void setup() {
  dht.begin();
  lcd.init();
  lcd.backlight();
}

void loop() {
  Tc = dht.readTemperature();
  RH = dht.readHumidity();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Tc     RH");
  lcd.setCursor(0, 1);
  lcd.print(Tc);
  lcd.print(char(223));
  lcd.print("    ");
  lcd.print(RH);
  lcd.print("%");

  delay(5000);
}
