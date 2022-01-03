// C++ code
int leds[17] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
                16, 17};

// Analog inputs 0 - 5 can be used as digital pins 14 - 19.

void setup()
{
  for (int jj; jj < sizeof(leds) / sizeof(int); jj++)
  {
    pinMode(leds[jj], OUTPUT);
  }
}

void loop()
{
  for (int i = 0; i <= sizeof(leds); i++)
  {
    digitalWrite(i, HIGH);
    delay(100);
    digitalWrite(i, LOW);
  }
}