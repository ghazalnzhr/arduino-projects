const int LEDPin = 3;
const int buttonPin = 13;

int buttonRead;
int totalReads;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LEDPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop()
{

  buttonRead = digitalRead(buttonPin);

  if (buttonRead == 1)
  {
    digitalWrite(LEDPin, HIGH);
    totalReads += 1;
    Serial.println(totalReads);
  }
  else
  {
    digitalWrite(LEDPin, LOW);
  }
}