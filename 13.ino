/* 
 Reading analog voltage in arduino UNO
*/

const int analogPin = A0;

// Values that change in the loop
int analogValue;
float voltage; 

void setup() {

  // Serial communication is 9600 bits / sec
  Serial.begin(9600);
}

void loop() {
  // Read the analog pin connected to the component
  analogValue = analogRead(analogPin);

  // Convert analog reading (0 - 1023) to voltage (0 - 5)
  voltage = analogValue * (5.0 / 1023.0);

  // Print voltage in serial monitor
  Serial.println(voltage);
  
  // For readablitiy 
  // delay(1000);
}
