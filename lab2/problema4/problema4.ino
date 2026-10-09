const int ledPin = 9; 

int brightness = 0;    
int fadeAmount = 5;    

unsigned long previousMillis = 0;
unsigned long interval = 30; 

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    int viteza = Serial.parseInt();
    while (Serial.read() >= 0); 
    
    if (viteza > 0) {
      interval = 300 / viteza; 
      if (interval < 1) {
        interval = 1; 
      }
    }
  }

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    analogWrite(ledPin, brightness);
    brightness = brightness + fadeAmount;

    if (brightness <= 0 || brightness >= 255) {
      fadeAmount = -fadeAmount;
    }
  }
}