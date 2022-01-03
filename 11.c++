const int ledPin = 5;

int brightness = 0; // Init
int fadeAmount = 5; // Step count

void setup()
{
    pinMode(ledPin, OUTPUT);
}

void loop()
{
    // Gradual increase of PWM from 0 to 255
    analogWrite(ledPin, brightness);

    // Change the brightness in the next loop
    brightness += fadeAmount;

    // reverse the direction of the fading at the ends of the fade:
    if (brightness <= 0 || brightness >= 255)
    {
        fadeAmount = -fadeAmount;
    }

    // wait for 30 milliseconds to see the dimming effect
    delay(30);
}