int pin = 8;

unsigned long perioada = 20;
unsigned long timpHigh = 0;
unsigned long tPrevPWM = 0;
unsigned long tPrevFade = 0;
unsigned long intervalFade = 30;

int luminozitate = 0;
int pas = 5;
bool stare = LOW;

void setup() {
  pinMode(pin, OUTPUT);
}

void loop() {
  unsigned long tCurent = millis();

  if (tCurent - tPrevFade >= intervalFade) {
    tPrevFade = tCurent;

    luminozitate += pas;
    if (luminozitate <= 0 || luminozitate >= 255) {
      pas = -pas;
    }

    timpHigh = (unsigned long)((luminozitate * perioada) / 255);
  }

  unsigned long deltaPWM = tCurent - tPrevPWM;

  if (stare == HIGH) {
    if (deltaPWM >= timpHigh) {
      digitalWrite(pin, LOW);
      stare = LOW;
    }
  } else {
    if (deltaPWM >= perioada) {
      tPrevPWM = tCurent; 
      if (timpHigh > 0) {
        digitalWrite(pin, HIGH);
        stare = HIGH;
      }
    }
  }
}