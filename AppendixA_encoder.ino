// ---------------------------------------------------------------- //
// Arduino Ultrasoninc Sensor HC-SR04
// Re-writed by Arbi Abdul Jabbaar
// Using Arduino IDE 1.8.7
// Using HC-SR04 Module
// Tested on 17 September 2019
// ---------------------------------------------------------------- //

//takes input from a 6 cycle (4 positions per cycle) quadrature encoder


// includes the encoder library
#include <Encoder.h>

// Initializes the encoder using interrupt-enabled pins 2 and 11
Encoder myEnc(2, 11);

// Creates variables to track old position and distance traveled
long oldPosition = -999;
float distance;

// Creates constansts for pi, diameter of the wheel, and number of encoder counts per revolution.
const float pi = 3.14;
const float D = 5.9;
const int N = 26;

void setup()
// Begins serial communcation with baud rate of 9600
{
  Serial.begin(9600);
  Serial.println("ENCODER DISTANCE MEASUREMENT");
}

void loop() {
  long newPosition = myEnc.read();

  // check if encoder has moved
  if (newPosition != oldPosition) {
    // updates oldPosition
    oldPosition = newPosition;

    // Calculates the distance moved
    distance += (newPosition * (D * pi / N))
                // ***

                // output distance to the serial monitor
                Serial.print("Distance(m): ");
    Serial.println(distance);
  }
}
