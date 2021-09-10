/* 15. LCD screen I2C
      https://lastminuteengineers.com/i2c-lcd-arduino-tutorial
*/
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);     // addr, chars, rows

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.print("Hello, world!");
}

void loop() {
  lcd.setCursor(0, 1);
  lcd.print(millis());
  delay(100);
}
