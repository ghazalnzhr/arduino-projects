/*
  LiquidCrystal Library - Walking character
  This is the code for a walking costum character
*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to

const int lcdWidth = 16;
const int lcdHeight = 2;
const int rs = 12,
	en = 11,
	d4 = 10,
	d5 = 9,
	d6 = 8,
	d7 = 7;
const int buttonPin = 2;

// Keep track of button state
int buttonState = 0;

// Character bytes
byte Character[8] = { 0b00000, 0b01110, 0b01110, 0b00100,
	0b01110, 0b00100, 0b00100, 0b01010
};

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup()
{
	// Steup button as input
	pinMode(buttonPin, INPUT);

	// LCD dimensions (w, h)
	lcd.begin(lcdWidth, lcdHeight);

	// Create charactar                  
	lcd.createChar(0, Character);
}

void loop()
{

	// read the state of the button
	buttonState = digitalRead(buttonPin);

	if (buttonState == HIGH)
	{
		// If the user has pushed the button

		// Set state
		bool isButtonPushed = true;
		if (isButtonPushed)
		{
			// Only if the button is pushed, call the utility method
			buttonPushed();
		}
	}
	else
	{
		// The user has not pushed the button yet

		// Set cursor to top left
		lcd.setCursor(0, 0);

		// Print a welcome message on the LED
		lcd.write("Hello &Welcome!");

		// Set cursor to bottom left
		lcd.setCursor(0, 1);

		// Tell the user to push the button
		lcd.write("Push the button");
	}
}

// Handles the change in buttons state
// Method for putting layers of abstraction on the code
void buttonPushed()
{
	// Goes through the rows and columns in the LCD
	for (int r = 0; r < lcdHeight; r++)
	{
		for (int c = 0; c < lcdWidth; c++)
		{
			// Clear the welcome message
			lcd.clear();

			// Set the cursor to the right place on the led
			lcd.setCursor(c, r);

			// Display the charactar
			lcd.write(byte(0));

			// To prevent high blinking rates -which is annoying-
			delay(1000);
		}
	}
}
