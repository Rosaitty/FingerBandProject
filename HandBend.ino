int led;

int sensAdjust(int value) { // Function to calibrate sensor input to light output.
  int result = (value - 230)*3-30;
  return result;
}

int clamp(int number, int min, int max) {
    int lowerBounded = number ^ ((number ^ min) & -(number < min));
    return max ^ ((lowerBounded ^ max) & -(lowerBounded < max));
}

void setup () {
  Serial.begin(9600); // Starts serial communication for debugging purposes.
  pinMode(5, OUTPUT); // Sets and output pin for the LED.
}

void loop () {
  led = sensAdjust(analogRead(A5)); // Sets adjusted input values to led.
  led = clamp(led, 0, 255);

  Serial.println(led); // Prints the led value to serial monitor for debugging purposes.
  analogWrite(5, led); // The LED is lit as high as the final value of led.
  
  delay(100); // Adds a 100ms delay to help Arduino run smoother.
}