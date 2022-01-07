/*
  LiquidCrystal Library - Moving text
  The code allows for printing two lines of longer text on the LCD
*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to

const int lcdWidth = 16;
const int lcdHeight = 2;
const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;
const int buttonPin = 4;

int buttonState = 0;

byte Character[8] = {0b00000, 0b01110, 0b01110, 0b00100,
                     0b01110, 0b00100, 0b00100, 0b01010};

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // LCD dimensions (w, h)
  pinMode(buttonPin, INPUT);
  lcd.begin(lcdWidth, lcdHeight);
  Serial.begin(9600);  // Prints on LCD's first row                      
  lcd.createChar(0, Character);
}

void loop()  // used to run the code repeatedly
{
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    bool isButtonPushed = true;
    if (isButtonPushed) {
      lcd.clear();
      // display the charactar
      lcd.setCursor(0, 0);
      lcd.write(byte(0));
      delay(1000);

      // TODO: make it move
    }
  } else {
    lcd.setCursor(0, 0);
    lcd.write("Hello & Welcome!");
    lcd.setCursor(0, 1);
    lcd.write("Push the button");
  }
}
