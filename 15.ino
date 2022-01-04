/* By pushing the buttons once and then letting go of it,
the buzzer will make noise we push the button again
if we don't push the button, it will continue to buzz
 */
// Police 

const int buttonPin = 2;
const int buzzerPin = 8;

// Keep track of state
int buttonState; // the current reading from the input pin
bool buttonPressed; // Was the button pressed?

void setup() {
  pinMode(buttonPin, INPUT);
}
void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH && buttonPressed == false) {

    buttonPressed = true;
    // only turn on buzzer when button is pressed
    for (int i = 700; i < 800; i++) {
      tone(buzzerPin, i);
      delay(15);
    }
    for (int i = 800; i > 700; i--) {
      tone(buzzerPin, i);
      delay(15);
    }
  } else if (buttonState == HIGH && buttonPressed == true) {
    // When we press the button again to stop the buzzer
    noTone(buzzerPin);
  } else {
    // After we've stopped the buzzer, this will reset the state
    noTone(buzzerPin);
    buttonPressed = false;
  }

}
