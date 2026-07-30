#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int ledPins[] = {0, 1, 6, 7, 8, 9, 10, 13, A5, A4, A3, A2};

void setup() {
  lcd.begin(16, 2);
  lcd.print("HAPPY BIRTHDAY");

  for (int i = 0; i < 12; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  lcd.scrollDisplayLeft();

  // Turn all LEDs ON
  for (int i = 0; i < 12; i++) {
    digitalWrite(ledPins[i], HIGH);
  }

  delay(300);

  // Turn all LEDs OFF
  for (int i = 0; i < 12; i++) {
    digitalWrite(ledPins[i], LOW);
  }

  delay(300);
}