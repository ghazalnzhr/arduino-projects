// Simple lcd print

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

void setup() {
  // Dimemsions (w, h)
  lcd.begin(16, 2);

  // Print statement
  lcd.print("Qazal");
}

void loop() {}
