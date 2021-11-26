#define RELAY 6

int light;

void setup() {
  pinMode(RELAY, OUTPUT);       // setup Relay
  Serial.begin(9600);
}

void loop() {
  photoresistor();
  relayTest();
}

void relayTest() {
  if (light < 200) {
    digitalWrite(RELAY, LOW);             // activate relay
  }
  else {
    digitalWrite(RELAY, HIGH);            // deactivate relay
  }
}

void photoresistor() {
  light = analogRead(A0);                   // 10-bit, 0-1023

  Serial.println(light);
  delay(100);
}
