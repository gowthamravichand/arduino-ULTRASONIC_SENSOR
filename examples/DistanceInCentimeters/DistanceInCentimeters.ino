#define TRIG_PIN 23 // ESP32 pin GPIO23 connected to Ultrasonic Sensor's TRIG pin
#define ECHO_PIN 22 // ESP32 pin GPIO22 connected to Ultrasonic Sensor's ECHO pin

float duration_us, distance_cm;

void setup() {
  // Begin serial communication at a baud rate of 9600
  Serial.begin(9600);
  
  // Configure the trigger pin to output mode
  pinMode(TRIG_PIN, OUTPUT);
  
  // Configure the echo pin to input mode
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  // Generate a 10-microsecond pulse to TRIG pin
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure the duration of pulse from ECHO pin
  duration_us = pulseIn(ECHO_PIN, HIGH);

  // Calculate the distance
  distance_cm = 0.017 * duration_us;

  // Print the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  delay(500);
}
