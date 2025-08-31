#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define MQ2_PIN 34       // Analog pin connected to MQ-2
#define BUZZER_PIN 25    // Buzzer
#define LED_RED 26       // Red LED
#define LED_GREEN 27     // Green LED

int smokeValue = 0;
int threshold = 3000;    // Adjust after calibration

// Create LCD object (address 0x27 or 0x3F depending on module)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);

  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Smoke Detector");
  delay(2000);
  lcd.clear();
}

void loop() {
  smokeValue = analogRead(MQ2_PIN);
  Serial.print("Smoke Value: ");
  Serial.println(smokeValue);

  if (smokeValue > threshold) {
    

    // For PASSIVE buzzer (needs tone):
    tone(BUZZER_PIN, 1000);   // 1kHz sound

    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_GREEN, LOW);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("ALERT: SMOKE!!");
    lcd.setCursor(0, 1);
    lcd.print("Value: ");
    lcd.print(smokeValue);

    Serial.println("⚠️ Smoke Detected!");
  } else {
    
    // For PASSIVE buzzer:
    noTone(BUZZER_PIN);

    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_GREEN, HIGH);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Air is Clean");
    lcd.setCursor(0, 1);
    lcd.print("Value: ");
    lcd.print(smokeValue);

    Serial.println("✅ Air is Clean");
  }

  delay(1000);
}
