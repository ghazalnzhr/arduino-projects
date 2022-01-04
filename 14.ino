/* By pushing the buttons once and then letting go of it,
the buzzer will make noise until the melody
is finished, then it'll automatically stop
if we don't pick up our finger, the alarm will keep on repeating
 */

const int buttonPin = 2;
const int buzzerPin = 8;

// Sounds 
int melody[] = {500, 800, 500, 800, 500, 800, 500, 800, 
700, 700}; //  frequencies
int noteDurations[] = {300, 300, 300, 300, 300, 300, 300, 300,
800, 800};
int noteDuration;

// Keep track of state
int buttonState;
int prevButtonState;

void setup() {
  pinMode(buttonPin, INPUT);
}
void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    for (int thisNote = 0; thisNote < 10; thisNote++) {
    
    noteDuration = noteDurations[thisNote];
    // args: pin, freq, dur
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.

    // the note's duration + 30% seems to work well:

    int pauseBetweenNotes = noteDuration * 1.30;

    delay(pauseBetweenNotes);

    prevButtonState = LOW;
  } 
  } else if (buttonState != prevButtonState) {
        // stop the tone playing:
      noTone(8);
  } 
  
}
