// ---------------------------------------------------------------- //
// Arduino Ultrasoninc Sensor HC-SR04
// Re-writed by Arbi Abdul Jabbaar
// Using Arduino IDE 1.8.7
// Using HC-SR04 Module
// Tested on 17 September 2019
// ---------------------------------------------------------------- //

#define echoPin 26 // Echo pin to GPIO 26 
#define trigPin 32// Trig pin to GPIO 32
#define led 17

// defines variables 
long time; // variable for the time of sound wave travel
int distance; // variable for the distance from obstacle

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  pinMode(led, OUTPUT);
  Serial.begin(115200); // // Serial Communication is starting with 115200 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
}


void loop() {
  // Clears the trigPin condition by setting it low.
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  if (distance < 10)// When distance is smaller, flashes more frequently 
  {
     digitalWrite(led,HIGH);
     delay(25);
     digitalWrite(led,LOW);
     delay(25);
     
     digitalWrite(led,HIGH);
     delay(25);
     digitalWrite(led,LOW);
     delay(25);
  } 
// When distance is bigger, flashes less frequently
else if ((distance >= 10) && (distance <= 20) )
{ 
digitalWrite(led,HIGH);
     delay(100);
     digitalWrite(led,LOW);
     delay(100);
     digitalWrite(led,HIGH);
     delay(100);
     digitalWrite(led,LOW);
     delay(100);
// Longer delay between flashes as distance increases
}   
else if ((distance > 20) && (distance <= 30) ) 
   { 
digitalWrite(led,HIGH);
     delay(300);
     digitalWrite(led,LOW);
     delay(300);
     digitalWrite(led,HIGH);
     delay(300);
     digitalWrite(led,LOW);
     delay(300);

 }
else 
  digitalWrite(led,LOW);

  // Calculating the distance
  distance = time * 0.034 / 2; // Speed of sound in air * time divided by 2 
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}
 
