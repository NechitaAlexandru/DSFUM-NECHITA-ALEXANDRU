const int targetPin = 8; 

unsigned long period = 20;     
unsigned long highTime = 0;   
unsigned long previousMillis = 0;
bool pinState = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(targetPin, OUTPUT);
}

void loop() {

  if (Serial.available() > 0) {
    float tensiuneDorita = Serial.parseFloat();
    while (Serial.read() >= 0); 

    if (tensiuneDorita < 0.0) tensiuneDorita = 0.0;
    if (tensiuneDorita > 5.0) tensiuneDorita = 5.0;

    
    highTime = (tensiuneDorita / 5.0) * period;
  }

  
  unsigned long currentMillis = millis();
  unsigned long elapsed = currentMillis - previousMillis;

  if (pinState == HIGH) {
   
    if (elapsed >= highTime) {
      digitalWrite(targetPin, LOW);
      pinState = LOW;
    }
  } else {
    
    if (elapsed >= period) {
      previousMillis = currentMillis; 
      if (highTime > 0) {
        digitalWrite(targetPin, HIGH);
        pinState = HIGH;
      }
    }
  }
}