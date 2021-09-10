int buzz = 9;

void setup() {
  pinMode(buzz, OUTPUT);
}

void loop() {
  tone(buzz, 262, 500);
  delay(500);
  tone(buzz, 294, 500);
  delay(500);
  tone(buzz, 330, 500);
  delay(500);
  tone(buzz, 349, 500);
  delay(500);
  tone(buzz, 392, 500);
  delay(500);
  tone(buzz, 440, 500);
  delay(500);
}
