int optiune = 0;
unsigned long tPrevBlink = 0;
bool stareBlink = LOW;
const unsigned long intervalBlink = 10000;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    char c = Serial.read();
    if (c == '1' || c == '2' || c == '3') {
      optiune = c - '0';
      
      if (optiune == 1) {
        Serial.println("pornit");
        digitalWrite(13, HIGH);
      } else if (optiune == 2) {
        Serial.println("oprit");
        digitalWrite(13, LOW);
      } else if (optiune == 3) {
        Serial.println("blink");
        tPrevBlink = millis();
        stareBlink = HIGH;
        digitalWrite(13, stareBlink);
      }
    }
  }

  if (optiune == 3) {
    unsigned long tCurent = millis();
    if (tCurent - tPrevBlink >= intervalBlink) {
      tPrevBlink = tCurent;
      stareBlink = !stareBlink;
      digitalWrite(13, stareBlink);
    }
  }
}