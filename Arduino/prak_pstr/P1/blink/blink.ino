/*  01. Blinking LED
        https://www.arduino.cc/reference
*/
void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);   // turn on
  delay(1000);              // wait 1 sec
  digitalWrite(13, LOW);    // turn off
  delay(1000);              // wait 1 sec
}
