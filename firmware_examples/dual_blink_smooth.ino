#define RED_LED_PIN 24
#define GREEN_LED_PIN 25

#define EMERGENCY_BOOT_PIN 15 

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

  setupEmergencyBoot(EMERGENCY_BOOT_PIN);
}

void loop() { 
  // Smoothly fade RED up while fading GREEN down
  for (int brightness = 0; brightness <= 255; brightness++) {
    analogWrite(RED_LED_PIN, brightness);
    analogWrite(GREEN_LED_PIN, 255 - brightness);
    delay(4);
  }

  // Smoothly fade RED down while fading GREEN up
  for (int brightness = 255; brightness >= 0; brightness--) {
    analogWrite(RED_LED_PIN, brightness);
    analogWrite(GREEN_LED_PIN, 255 - brightness);
    delay(4);
  }
}
