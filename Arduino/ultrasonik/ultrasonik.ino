#include <Servo.h>
const int trigPin = 9;
const int echoPin = 10;
int buzz= 5;
// defines variables
long duration;
int distance;
Servo servo1;
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
  servo1.attach(3);
}

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
// Calculating the distance
  distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);

int position;
  if(distance<=7){
   tone(buzz, 500, 3000);
   servo1.write(45);    // Tell servo to go to 90 degrees

  delay(1000);         // Pause to get it time to move

  servo1.write(90);   // Tell servo to go to 180 degrees

  delay(1000);         // Pause to get it time to move

  servo1.write(360);     // Tell servo to go to 0 degrees

  delay(1000);         // Pause to get it time to move

    
  }
}
