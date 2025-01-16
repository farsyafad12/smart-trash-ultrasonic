#include <Servo.h>

const int trigPin = 2;
const int echoPin = 3;
const int buzzerPin = 4;
const int servoPin = 5;
const int redPin = 6;
const int greenPin = 7;

long duration;
int distance;
Servo servo;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  servo.attach(servoPin);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  Serial.begin(9600);

  servo.write(180);
  digitalWrite(buzzerPin, LOW);
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, HIGH);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Jarak : ");
  Serial.print(distance);
  Serial.println(" cm");

  // ------------------------

  if (distance < 7.5) {
    digitalWrite(buzzerPin, HIGH);
    servo.write(0);
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    delay(5000);
  } else {
    digitalWrite(buzzerPin, LOW);
    servo.write(180);
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
  }

  delay(250);
}
