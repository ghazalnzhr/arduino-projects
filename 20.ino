// LCD1602 to Arduino Uno scroll text without using built-in AutoScroll() methods

#include <LiquidCrystal.h>

const int lcdWidth = 16;
const int lcdHeight = 2;
const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
String message;

void setup() {
  lcd.begin(lcdWidth, lcdHeight);
  // you can now interact with the LCD, e.g.:
}

void loop() {
  message = "h";
    // Goes through the columns and rows in the LCD
    
    for (int r=0; r<lcdHeight; r++){
      for (int c=0; c<lcdWidth; c++) {
      // Clear the welcome message
      lcd.clear();

      // Set the cursor to the right place on the led
      lcd.setCursor(c, r);

      // Display the character
      lcd.print(message);

      // To prevent high blinking rates -which is annoying-
      delay(200);
      }
    }
}
