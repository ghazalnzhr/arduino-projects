
const int ledPin = 2;
const int ldrPin = A0;
void setup()
{
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);
    pinMode(ldrPin, INPUT);
}

void loop()
{
    int ldrStatus = analogRead(ldrPin);
    // Serial.println(ldrStatus);
    // The analog output ranges from 54 to 974
    if (ldrStatus <= 200)
    {
        digitalWrite(ledPin, HIGH);
    }
    else
    {
        digitalWrite(ledPin, LOW);
    }
}