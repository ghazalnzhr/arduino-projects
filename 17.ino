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

void setup() {
  // LCD dimensions (w, h)
  lcd.begin(16, 2);

  // Displayed text
  lcd.print("Hello human!");                    // Prints on LCD's first row
  lcd.setCursor(0, 1);                          // Goes to the next line
  lcd.print("I'm a robot and I have sensors");  // Prints on LCD's second row
  delay(1000);  // delay of 1 second
}

void loop()  // used to run the code repeatedly
{
  // Scroll the text to the left
  lcd.scrollDisplayLeft();  // builtin command to scroll left the text
  delay(150);  // delay of 150 msec
}
