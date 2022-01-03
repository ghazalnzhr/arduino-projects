int LEDPin = 3;
int buttonPin = 13;
int buttonRead;
int dt = 250;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LEDPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  buttonRead = digitalRead(buttonPin);
  // For debuging
  // Serial.println(buttonRead);
  if (buttonRead == 1)
  {
    digitalWrite(LEDPin, HIGH);
  }
  else
  {
    digitalWrite(LEDPin, LOW);
  }
  delay(dt);
}