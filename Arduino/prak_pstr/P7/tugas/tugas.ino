/*  19. Motor driver
        https://electropeak.com/learn/interfacing-drv8833-dual-motor-driver-module-with-arduino/

    Uno/Nano  DRV8833   MotorR  MotorL
    --------  -------   ------  ------
    5V        VM
    Gnd       Gnd
    D4        AIN2
    D5        AIN1
    D6        STBY
    D7        BIN1
    D8        BIN2
              AO1       Pin1
              AO2       Pin2
              BO2               Pin2
              BO1               Pin1
Note: AIN-> right
      BIN-> left
*/

#define AIN2 4
#define AIN1 5
#define STBY 6
#define BIN1 7
#define BIN2 8

void setup() {
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(STBY, OUTPUT);
}

void loop() {
  forward(1000);
  delay(1000);

  back(1000);
  delay(1000);
}

void forward(int t) {
  digitalWrite(AIN1, HIGH); digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, HIGH); digitalWrite(BIN2, LOW);
  digitalWrite(STBY, HIGH);
  delay(t);
  digitalWrite(STBY, LOW);
}

void back(int t) {
  digitalWrite(AIN1, LOW); digitalWrite(AIN2, HIGH);
  digitalWrite(BIN1, LOW); digitalWrite(BIN2, HIGH);
  digitalWrite(STBY, HIGH);
  delay(t);
  digitalWrite(STBY, LOW);
}

void right(int t) {
  digitalWrite(AIN1, HIGH); digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW); digitalWrite(BIN2, HIGH);
  digitalWrite(STBY, HIGH);
  delay(t);
  digitalWrite(STBY, LOW);
}

void left(int t) {
  digitalWrite(AIN1, LOW); digitalWrite(AIN2, HIGH);
  digitalWrite(BIN1, HIGH); digitalWrite(BIN2, LOW);
  digitalWrite(STBY, HIGH);
  delay(t);
  digitalWrite(STBY, LOW);
}