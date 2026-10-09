void setup() {
  Serial.begin(9600);
  
  for (byte i = 8; i <= 13; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  if (Serial.available() > 0) {
    int valoare = Serial.parseInt();
    
    while (Serial.read() >= 0); 
    
    if (valoare >= 0 && valoare <= 63) {
      for (byte pin = 8; pin <= 13; pin++) {
        digitalWrite(pin, bitRead(valoare, pin - 8));
      }
    }
  }
}