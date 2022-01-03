// C++ code
//
const int buttonPin = 2;
const int ledPin1 = 3;
const int ledPin2 = 4;

int pressCount = 0;
int buttonState = 0;
int val;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop()
{
  val = digitalRead(buttonPin);
  if (val != buttonState)
  {
    if (val == 1)
    { //if the button is pressed
      pressCount += val;
      Serial.println(pressCount);
      switch (pressCount)
      {
      case 6:
        digitalWrite(ledPin2, HIGH);
        delay(1000);
        digitalWrite(ledPin2, LOW);
        pressCount = 0;
        break;
      case 4:
        digitalWrite(ledPin1, HIGH);
        delay(1000);
        digitalWrite(ledPin1, LOW);
        break;
      default:
        digitalWrite(ledPin1, LOW);
        digitalWrite(ledPin2, LOW);
        break;
      }
    }
  }
  buttonState = val;
}
