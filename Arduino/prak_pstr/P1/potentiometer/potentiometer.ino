/*  02. Blinking LED fast/slow according to potentiometer
        https://www.arduino.cc/reference
*/
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  int val = analogRead(A0);             // potentiometer value

  digitalWrite(LED_BUILTIN, HIGH);
  delay(val);
  digitalWrite(LED_BUILTIN, LOW);
  delay(val);
}
