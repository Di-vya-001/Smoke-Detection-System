#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define MQ2_PIN 34       // Analog pin connected to MQ-2
#define BUZZER_PIN 25    // Buzzer
#define LED_RED 26       // Red LED
#define LED_GREEN 27     // Green LED

int smokeValue = 0;

// Thresholds 
int smokeThreshold = 1500;   // For smoke alert
int fireThreshold  = 2300;   // For fire alert

// LCD object
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);

  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Smoke Detector");
  delay(2000);
  lcd.clear();
}

void loop() {
  smokeValue = analogRead(MQ2_PIN);
  Serial.print("Smoke Value: ");
  Serial.println(smokeValue);

  if (smokeValue > fireThreshold) {
    // 🚨 FIRE ALERT: Fast beep + fast LED blink
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("FIRE ALERT!!!");
    lcd.setCursor(0, 1);
    lcd.print("Value: ");
    lcd.print(smokeValue);

    Serial.println("🔥 FIRE DETECTED!");

    // Buzzer - fast beep
    tone(BUZZER_PIN, 3000);
    delay(100);
    noTone(BUZZER_PIN);
    delay(100);

    // LED - fast blink
    digitalWrite(LED_RED, HIGH);
    delay(100);
    digitalWrite(LED_RED, LOW);
    delay(100);

    digitalWrite(LED_GREEN, LOW);

  } else if (smokeValue > smokeThreshold) {
    // ⚠️ SMOKE ALERT: Slow beep + slow LED blink
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("SMOKE ALERT!");
    lcd.setCursor(0, 1);
    lcd.print("Value: ");
    lcd.print(smokeValue);

    Serial.println("⚠️ Smoke Detected!");

    // Buzzer - slow beep
    tone(BUZZER_PIN, 800);
    delay(200);
    noTone(BUZZER_PIN);
    delay(800);

    // LED - slow blink
    digitalWrite(LED_RED, HIGH);
    delay(500);
    digitalWrite(LED_RED, LOW);
    delay(500);

    digitalWrite(LED_GREEN, LOW);

  } else {
    // ✅ Safe condition
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
    delay(1000);
  }
}
