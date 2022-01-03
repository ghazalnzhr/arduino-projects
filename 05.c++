void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

void dnc()
{
  digitalWrite(2, !digitalRead(2));
  delay(random(15, 55));
  digitalWrite(3, !digitalRead(3));
  delay(random(15, 55));
}

void loop()
{
  dnc();
}