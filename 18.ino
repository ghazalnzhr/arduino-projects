/*
  LiquidCrystal Library - Moving text
  The code allows for printing two lines of longer text on the LCD
*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to

const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int lcdWidth = 16;
const int lcdHeight = 2;

void setup() {
  // LCD dimensions (w, h)
  lcd.begin(lcdWidth, lcdHeight);
  Serial.begin(9600);  // Prints on LCD's first row                       
                       // Goes to the next line
}

void loop()  // used to run the code repeatedly
{
  for (int col = 0; col <= lcdWidth; col++) {
    for (int row = 0; row <= lcdHeight; row++) {
      lcd.scrollDisplayRight();
      delay(150);  // delay of 150 msec
      Serial.println(col);
      if (col < lcdWidth / 4) {
        lcd.setCursor(0, 0);
        lcd.print("H");
      } else if (col == lcdWidth / 4) {
        // turn off automatic scrolling
        lcd.noAutoscroll();
        // clear screen for the next loop:
        lcd.clear();

        lcd.setCursor(0, 1);
        lcd.print("H");
      } else if (col == lcdWidth / 2 + 1) {
        // turn off automatic scrolling
        lcd.noAutoscroll();
        // clear screen for the next loop:
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("H");
      }
    }
  }
  Serial.println("loop done");
  lcd.clear();
}
