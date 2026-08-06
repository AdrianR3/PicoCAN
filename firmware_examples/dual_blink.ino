#define RED_LED_PIN 24
#define GREEN_LED_PIN 25

// Sets up an interrupt to enter BOOTSEL mode when a pin is pulled low
void setupEmergencyBoot(uint8_t pin) {
  pinMode(pin, INPUT_PULLUP);
  
  attachInterrupt(digitalPinToInterrupt(pin), []() {
    reset_usb_boot(0, 0); 
  }, FALLING);
}

void setup() {
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);

  setupEmergencyBoot(15);
}

void loop() { // Alternates between red and green onboard LEDs
  digitalWrite(RED_LED_PIN, HIGH);
  digitalWrite(GREEN_LED_PIN, LOW);

  delay(500);

  digitalWrite(RED_LED_PIN, LOW);
  digitalWrite(GREEN_LED_PIN, HIGH);

  delay(500);
}