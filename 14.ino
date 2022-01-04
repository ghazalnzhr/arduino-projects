const int buzzerPin = 8;

int melody[] = {500, 800, 500, 800, 500, 800, 500, 800, 
700, 700}; //  frequencies
int noteDurations[] = {300, 300, 300, 300, 300, 300, 300, 300,
800, 800};
int noteDuration;

void setup() {}

void loop() {
  // iterate over the notes of the melody:

  for (int thisNote = 0; thisNote < 10; thisNote++) {
    
    noteDuration = noteDurations[thisNote];
    // args: pin, freq, dur
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.

    // the note's duration + 30% seems to work well:

    int pauseBetweenNotes = noteDuration * 1.30;

    delay(pauseBetweenNotes);

    // stop the tone playing:
    noTone(8);

} 
}
