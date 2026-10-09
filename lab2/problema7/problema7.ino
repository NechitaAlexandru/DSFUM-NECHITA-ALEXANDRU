const int nrLeduri = 6;
int pini[nrLeduri] = {8, 9, 10, 11, 12, 13};

int luminozitate[nrLeduri] = {0, 0, 0, 0, 0, 0};
int pas[nrLeduri] = {2, 4, 1, 5, 3, 6};
unsigned long intervalFade[nrLeduri] = {40, 20, 60, 15, 30, 25};
unsigned long tPrevFade[nrLeduri] = {0, 0, 0, 0, 0, 0};

unsigned long perioada = 20;
unsigned long tPrevPWM = 0;
unsigned long timpHigh[nrLeduri] = {0, 0, 0, 0, 0, 0};

void setup() {
  for(int i = 0; i < nrLeduri; i++) {
    pinMode(pini[i], OUTPUT);
  }
}

void loop() {
  unsigned long tCurent = millis();

  for(int i = 0; i < nrLeduri; i++) {
    if(tCurent - tPrevFade[i] >= intervalFade[i]) {
      tPrevFade[i] = tCurent;
      luminozitate[i] += pas[i];
      if(luminozitate[i] <= 0 || luminozitate[i] >= 255) {
        pas[i] = -pas[i];
      }
      timpHigh[i] = (unsigned long)((luminozitate[i] * perioada) / 255);
    }
  }

  if(tCurent - tPrevPWM >= perioada) {
    tPrevPWM = tCurent;
  }

  for(int i = 0; i < nrLeduri; i++) {
    if((tCurent - tPrevPWM) < timpHigh[i]) {
      digitalWrite(pini[i], HIGH);
    } else {
      digitalWrite(pini[i], LOW);
    }
  }
}