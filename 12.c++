/* const int ledPin1 = 2;
const int ledPin2 = 3;
const int ledPin3 = 4;
const int ledPin4 = 5; */

int leds[4] = {2, 3, 4, 5};
// The length of the led array
int arrayLen;

// Stores the random number generated by random()
long randomPin;

void setup() {
  Serial.begin(9600);

  /* pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT); */


  // WARNING: less readable but more efficient for longer arrays
  for (int led; led < sizeof(leds); led++ ) {
    pinMode(leds[led], OUTPUT);
    delay(1000);
  } 

  // Generates a new list of random numbers everytime
  randomSeed(analogRead(A0));

  // Caculate the array length
  arrayLen = sizeof(leds) / sizeof(int);
}

void loop() {

  // Serial.println("loop has began");
  
  // Generates a random number between x to y-1
  // Because we start from pin2, we have to increment the start 
  // and end by 2
  // The code below generates a random number between 2 and 5
  // WARN: HAS A BUG
  // randomPin = random(leds[random(0, arrayLen+1)]);
  randomPin = random(leds[random(0 + 2, 4 + 2)]);

  // Serial.println(randomPin);

  // Get a random index from the list
  digitalWrite(randomPin, HIGH);
  
  // delay for a random period
  delay(random(10, 45));

  // Turn of the same random led
  digitalWrite(randomPin, LOW);

}
