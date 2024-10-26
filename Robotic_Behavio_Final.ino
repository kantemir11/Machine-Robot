// define varibales
int echoPin = 13; // attach pin D8 to pin Echo of HC-SR04
int trigPin = 12; // attach pin D7 to pin Trig of HC-SR04

int echoPin2 = 8; // attach pin D10 to pin Echo of HC-SR04
int trigPin2 = 7; // attach pin D9 to pin Trig of HC-SR04

int in1 = 4; // variable names for the L298N (first wheel)
int in2 = 5; // variable names for the L298N (first wheel)
int in3 = 10; // variable names for the L298N (second wheel)
int in4 = 11; // variable names for the L298N (second wheel)

long duration; // duration of sound wave travel
int distance; // distance measurement

long duration2; // duration of sound wave travel
int distance2; // distance measurement


void setup() {

  pinMode (trigPin, OUTPUT) ; // sonar digital pin mode for trig
  pinMode (echoPin, INPUT); // sonar digital pin mode for echo

  pinMode (trigPin2, OUTPUT) ; // sonar digital pin mode for trig
  pinMode (echoPin2, INPUT); // sonar digital pin mode for echo
  
  pinMode (in1, OUTPUT); // all L298N digital pins are outputs
  pinMode (in2, OUTPUT); // all L298N digital pins are outputs
  pinMode (in3, OUTPUT); // all L298N digital pins are outputs
  pinMode (in4, OUTPUT); // all L298N digital pins are outputs

  Serial.begin (9600) ; // use default of 9600 baud rate for serial communication
  
}


void loop() {
  
  // Clears the trigPin condition
  digitalWrite (trigPin, LOW);//starts trig pin low
  delayMicroseconds (2); //waits for hardware to respond
  digitalWrite (trigPin, HIGH); //makes trig pin high
  delayMicroseconds (10) ; //continues high trig pin state for 10 microseconds
  digitalWrite (trigPin, LOW); //after 10 microseconds trig pin is brought low
  duration = pulseIn (echoPin, HIGH); //reads echo as it receives the pulse and stores duration
  distance = duration * 0.034 / 2; // Converts the time of flight to distance to object
  
  digitalWrite (trigPin2, LOW);//starts trig pin low
  delayMicroseconds (2); //waits for hardware to respond
  digitalWrite (trigPin2, HIGH); //makes trig pin high
  delayMicroseconds (10) ; //continues high trig pin state for 10 microseconds
  digitalWrite (trigPin2, LOW); //after 10 microseconds trig pin is brought low
  duration2 = pulseIn (echoPin2, HIGH); //reads echo as it receives the pulse and stores duration
  distance2 = duration2 * 0.034 / 2; // Converts the time of flight to distance to object
  
  // Displays the distance on the serial Monitor
  Serial.print ("Distance: ");
  Serial.print (distance);
  Serial.println(" cm");

  Serial.print ("Distance2: ");
  Serial.print (distance2);
  Serial.println(" cm");
  
  if (distance <= 15) {
    // If the distance is less than 15 the robot will back up
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    delay (750);
    // Then the robot will turn left
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);  
    delay(700);
  }
  else if (distance2 >= 40) {
    // The robot will turn right when the distance2 becomes greater than 40
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    delay(420);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(500);
  }
  else {
    //The robot will move forward unless it reaches the distance that will change the function
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
  
  delay(10);
}
