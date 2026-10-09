void setup() {

  for(byte i=8; i<=13; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  for (byte cnt = 0; cnt < 64; cnt++) {
    for (byte pin = 8; pin <= 13; pin++) {
       digitalWrite(pin, bitRead(cnt, pin - 8));
    }
    
    delay(500); 
  }
  
  while (true) {
      
  }
}