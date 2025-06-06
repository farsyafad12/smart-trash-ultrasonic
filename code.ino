#include <Servo.h>

const int trigPin = 2;
const int echoPin = 3;
const int buzzerPin = 4;
const int servoPin = 5;
const int redPin = 6;
const int yellowPin = 7;
const int greenPin = 8;

const int servoDefaultWrite = 180;

long duration;
int distance;
Servo servo;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(buzzerPin, OUTPUT);
  servo.attach(servoPin);

  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  Serial.begin(9600);

  servo.write(servoDefaultWrite);
  digitalWrite(buzzerPin, LOW);
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);
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

  if (distance < 7) {
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, HIGH);
    digitalWrite(greenPin, LOW);
    delay(350);
    digitalWrite(redPin, HIGH);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, LOW);
    // ------
    digitalWrite(buzzerPin, HIGH);
    servo.write(65);
    delay(4500);
  } else {
    digitalWrite(buzzerPin, LOW);
    servo.write(servoDefaultWrite);
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, HIGH);
  }

  delay(250);
}