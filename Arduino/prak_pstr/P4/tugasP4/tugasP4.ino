#include <Servo.h>
#define analogPIN A0  // potentiometer connected to analog pin A0

int val = 0;         // variable to store the read value
int angle = 0;       // variable to store angle 0 -- 180 degree
Servo myServo;

void setup() {
  // Serial.begin(9600);  // read serial monitor
  myServo.attach(9);  // Servo in pin 9(PWM)
}

void loop() {
  readPotentiometer();
  // printSerial(); // perintah monitor serial dapat menyebabkan memory penuh! (?)
}

void readPotentiometer() {
  val = analogRead(analogPIN);  // read the input pin, analogRead values go from 0 to 1023
  angle = map(val, 0, 1023, 0, 180);  // 0-1023 to 0-180
  myServo.write(angle);           // move servo
  delay(10);
}

void printSerial() {
  Serial.print("Val Potentiometer: ");
  Serial.print(val); 
  Serial.print(", angel: "); 
  Serial.println(angle); 
}
