/* 
  01. Relay module
      https://lastminuteengineers.com/one-channel-relay-module-arduino-tutorial
  02. DHT11 temperature sensor
      https://lastminuteengineers.com/dht11-module-arduino-tutorial
  03. Soil Moisture Sensor
      http://indomaker.com/index.php/2019/01/15/tutorial-mengakses-sensor-soil-moisture-pada-arduino/
      https://www.nyebarilmu.com/cara-mengakses-soil-moisture-sensor-secara-online/
  04. Mini Water Pump
      Customize ON-OFF power

    Uno/Nano  Relay   dht11 Soil  Water(relay)
    --------  -----   ----- ----  -----
    5V        -       -     -     -
    Gnd       -       -     -     -
    3         IN      
    4                 Out
    A0                      A0
    7                             IN

Note: VCC/5v -> customize
      GND/(-)-> customize ('_')
*/

#include <dht.h>                        // DHTlib

#define RELAY_PIN 3
#define RELAY_PIN2 7
#define DHT_PIN 4
#define SOIL_MOISTURE_PIN A0

dht dht11;                  // Initialize DHT11

int sensorSoilValue = 0;
int humidity = 0;

void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(RELAY_PIN2, OUTPUT);
}

void loop() {
  main_implement();
}

void main_implement() {
  dht11.read11(DHT_PIN);    // read dht
  dht_serial_print(dht11);

  // RelayFan
  relay_fan(dht11);

  // Soil Moisture
  soil_moistute_main();

  // Relay water pump
  relay_water(sensorSoilValue);

  delay(500);
}

// relay code
void relay() {
  digitalWrite(RELAY_PIN, LOW);             // activate relay
  delay(1000);
  digitalWrite(RELAY_PIN, HIGH);            // deactivate relay
  delay(3000);
}

void relay_fan(dht dht) {
  if (dht.humidity > 70) {
    digitalWrite(RELAY_PIN, LOW);     // Active relay
  } else {
    digitalWrite(RELAY_PIN, HIGH);    // Deactivate relay
  }
}

void relay_water(int number) {
  if (number > 900) {
    digitalWrite(RELAY_PIN2, LOW);     // Active relay
  } else {
    digitalWrite(RELAY_PIN2, HIGH);    // Deactivate relay
  }
}

// DHT11 code
void dht_out() {
  dht11.read11(DHT_PIN);

  Serial.print(dht11.temperature);
  Serial.print("`C, ");
  Serial.print(dht11.humidity);
  Serial.println("%");

  delay(1000);
}

void dht_serial_print(dht dht) {
  Serial.print("Suhu : ");
  Serial.print(dht.temperature);
  Serial.println("`C, ");
  Serial.print("Humidity : ");
  Serial.print(dht.humidity);
  Serial.println("%");
  // delay(1000);
}

// Soil Moisture Sensor
void soil_moistute() {
  sensorSoilValue = analogRead(SOIL_MOISTURE_PIN);
  humidity = convertToPercentSoilMoisture(sensorSoilValue);
  Serial.print("Nilai Sensor : ");
  Serial.println(sensorSoilValue);
  Serial.print("Kelembaban: ");
  Serial.print(humidity);
  Serial.println("%");
  Serial.println(" ");
  delay(1000);
}
// Soil
void soil_moistute_main() {
  sensorSoilValue = analogRead(SOIL_MOISTURE_PIN);
  humidity = convertToPercentSoilMoisture(sensorSoilValue);
  Serial.print("Nilai Sensor : ");
  Serial.println(sensorSoilValue);
  Serial.print("Kelembaban: ");
  Serial.print(humidity);
  Serial.println("%");
  Serial.println(" ");
  // delay(1000);
}

int convertToPercentSoilMoisture(int value) {
  int percentValue = 0;
  percentValue = map(value, 1023, 465, 0, 100);
  return percentValue;
}
