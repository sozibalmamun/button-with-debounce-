volatile unsigned long DebounceTimer;
volatile int ButtonPressed;
volatile unsigned int delayTime = 200;
volatile unsigned int delayRepeatTime = 500;
volatile byte state = LOW;
unsigned long lastInterrupt;

#define pin 34
#define ledPin 2

void setup() {
  Serial.begin(115200);

  pinMode(ledPin, OUTPUT);
  pinMode(pin, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(pin), [] {
    if (ButtonPressed += (millis() - DebounceTimer) >= (delayTime )) {
      DebounceTimer = millis();
      if (millis() - lastInterrupt > delayRepeatTime)
      {
        state = !state;
        lastInterrupt = millis();
        digitalWrite(ledPin, state);
        Serial.println("Pressed");
        Serial.println(state);
      }
    }
  }, RISING);
}

void loop() {
}
