/*  
  Set PJO Lamp case
*/
// set PIN
#define GREEN 4
#define YELLOW 3
#define RED 2
#define BUTTON1 8

void setup() {
  pinMode(BUTTON1, INPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);
}

void loop() {
  int s1 = digitalRead(BUTTON1); // set digitalRead button
  
  green(); // green function

  if (s1 == LOW) {  // if button push, execute stop_light()
    stop_light();
  }
}

void green() {                  // Green always ON
  digitalWrite(GREEN, HIGH);     
}

void stop_light() {             // stop_ligh function
  digitalWrite(GREEN, LOW);     // Green OFF
  digitalWrite(RED, HIGH);      // RED & Yellow ON
  digitalWrite(YELLOW, HIGH);
  delay(2000);                  // delay 2 second
    for (int i=0; i < 10; i++) {  // Loop Yellow LIght
      digitalWrite(YELLOW, HIGH);
      delay(500);
      digitalWrite(YELLOW, LOW);
      delay(500);
    }
  digitalWrite(RED, LOW);         // Turn OFF RED & Yellow
  digitalWrite(YELLOW, LOW);

  return green();     // return and back to green function
}
