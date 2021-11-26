/* 
  https://randomnerdtutorials.com/esp8266-pinout-reference-gpios/
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

    Button Input Manual mode function:
      D18(high/low) (Auto/Manual)
      D9 (high) (Manual->Fan ON)
      D9 (low) (Manual->Fan OFF)
      D10 (high) (Manual->Water pump ON)
      D10 (low) (Manual->Water Pump OFF)

Note: VCC/5v -> customize
      GND/(-)-> customize ('_')
*/

// BLYNK SET UP VIA ARDUINO USB CABLE
// BLYNK SET UP WeMosD1 ESP8266
#include <DHT.h>                      // DHT sensor library (Adafruit)
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill-in your Template ID (only if using Blynk.Cloud) */
//#define BLYNK_TEMPLATE_ID   "YourTemplateID"

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "CDLDshV_DW75l2b_df1-yyh24EzcczX-";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Nan's123";
char pass[] = "999999999";

#define DHT_PIN D7
#define RELAY_PIN D2     // Fan relay
#define RELAY_PIN2 D3    // Water pump relay
#define DHT_TYPE DHT11 
#define SOIL_MOISTURE_PIN A0  // RANGE INPUT 0 - 3.3V
// Select switch
#define MODE_SELECT D4
#define FAN_CONTROL D5
#define PUMP_CONTROL D6

DHT dht(DHT_PIN, DHT_TYPE);
BlynkTimer timer;
WidgetLED led1(V4);

float Humidity, TemperatureC;
int SoilMoistureAnalog, SoilMoisturePercent;
int S1;
int S2;
int S3;
int VS1;
int VS2;
int VS3;

// Send data from app to hardware
// test LED button
BLYNK_WRITE(V5) { //Button Widget is writing to pin V1
  int input_value = param.asInt();
  if (input_value == 1) {
    led1.on();
  } else {
    led1.off();
  }
}
BLYNK_WRITE(V6) { //Button Widget is writing to pin V1
  VS1 = param.asInt(); 
}
BLYNK_WRITE(V7) { //Button Widget is writing to pin V1
  VS2 = param.asInt(); 
}
BLYNK_WRITE(V8) { //Button Widget is writing to pin V1
  VS3 = param.asInt(); 
}

BLYNK_CONNECTED() {
    Blynk.syncAll();
}

void sendSensor() {
  Humidity = dht.readHumidity();
  TemperatureC = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit
  SoilMoistureAnalog = analogRead(SOIL_MOISTURE_PIN);
  SoilMoisturePercent = convertToPercentSoilMoisture(SoilMoistureAnalog);

  if (isnan(Humidity) || isnan(TemperatureC)) {
    Serial.println("Failed to read from DHumidityT sensor!");
    //return;
  }
  Serial.print(Humidity);
  // Serial.print("SoilMoistureAnalog: ");
  // Serial.println(SoilMoistureAnalog);
  // Serial.print("SoilMoisturePercent: ");
  // Serial.println(SoilMoisturePercent);
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V0, TemperatureC);
  Blynk.virtualWrite(V1, Humidity);
  Blynk.virtualWrite(V2, SoilMoistureAnalog);
  Blynk.virtualWrite(V3, SoilMoisturePercent);
}

void setup() {
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  dht.begin();

  // Setup a function to be called every second
  timer.setInterval(1000L, sendSensor);

  pinMode(RELAY_PIN, OUTPUT); // Fan
  pinMode(RELAY_PIN2, OUTPUT); // Water pump
  // Mode Select
  pinMode(MODE_SELECT, INPUT);
  pinMode(FAN_CONTROL, INPUT);
  pinMode(PUMP_CONTROL, INPUT);
}

void loop()
{
  S1 = digitalRead(MODE_SELECT);
  S2 = digitalRead(FAN_CONTROL);
  S3 = digitalRead(PUMP_CONTROL);
  Blynk.run();
  timer.run();
  main_implement();
}

void main_implement() {
  if (VS1 == LOW) {
    main_auto_implement();
  } else {
    main_manual_implement();
  }
}

void main_manual_implement() {
  // RelayFan
  if (VS2 == HIGH) {
    digitalWrite(RELAY_PIN, LOW);     // Active relay
  } else {
    digitalWrite(RELAY_PIN, HIGH);    // Deactivate relay
  }

  // Relay water pump
  if (VS3 == HIGH) {
    digitalWrite(RELAY_PIN2, LOW);     // Active relay
  } else {
    digitalWrite(RELAY_PIN2, HIGH);    // Deactivate relay
  }
}

void main_auto_implement() {
  // RelayFan
  relay_fan(Humidity);

  // Relay water pump
  relay_water(SoilMoistureAnalog);
}

// relay code
void relay_fan(float number) {
  if (number > 70.0) {
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

int convertToPercentSoilMoisture(int value) {
  int percentValue = 0;
  percentValue = map(value, 1023, 465, 0, 100);
  return percentValue;
}
