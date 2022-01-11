// LCD1602 to Arduino Uno scroll text without using AutoScroll()

#include <LiquidCrystal.h>

const int lcdWidth = 16;
const int lcdHeight = 2;
const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;

// Prevent message overflow in an lcd's row
int threshold;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
String message;

void setup() {
  Serial.begin(9600);
  lcd.begin(lcdWidth, lcdHeight);
  // you can now interact with the LCD, e.g.:
}

void loop() {
  message = "hello";
    // Goes through the columns and rows in the LCD
    
    for (int r=0; r<lcdHeight; r++){
      for (int c=0; c<lcdWidth; c++) {
      // Clear the welcome message

      // The text gets to the end of the LCD in that row when:
      // c = lcdWidth - message.length() => This is when we need to change rows
      lcd.clear();

      // Set threshold
      threshold = lcdWidth - message.length();
      // Check if we're on the threshold
      if (c == threshold) {
        Serial.println("hiii");
        for (int l=message.length(); l > 0; l--) {
          Serial.println(l);
          lcd.clear();
          lcd.setCursor(c, r);
          lcd.print(message.length());
        }
      } else {

      // Set the cursor to the right place on the led
      lcd.setCursor(c, r);

      // Display the character
      lcd.print(message);

      // To prevent high blinking rates -which is annoying-
      delay(200);
      } }
    }
}
