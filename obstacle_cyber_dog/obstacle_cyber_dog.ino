#include <Servo.h>

// ===== Motor Pins (L298N) =====
#define IN1 12
#define IN2 13
#define IN3 10
#define IN4 11

// ===== Sensors & Servo =====
#define PROX_PIN 2     // IR proximity sensor OUT
#define SERVO_PIN 9

Servo scanServo;

// ===== Motor Functions =====
void stopMotors() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
}

void moveForward() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
}

void moveBackward() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
}

void turnLeft() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
}

void turnRight() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
}

// ===== Obstacle Detection =====
bool obstacleDetected() {
  return digitalRead(PROX_PIN) == LOW;  // LOW = obstacle
}

void setup() {
  Serial.begin(9600);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(PROX_PIN, INPUT);

  scanServo.attach(SERVO_PIN);
  scanServo.write(90); // center position

  stopMotors();
  delay(1000);

  Serial.println("Autonomous Obstacle Avoiding Car Started");
}

void loop() {

  // Move forward continuously
  moveForward();

  // Check for obstacle
  if (obstacleDetected()) {

    Serial.println("Obstacle detected!");

    // Stop
    stopMotors();
    delay(300);

    // Move back a little
    moveBackward();
    delay(400);

    stopMotors();
    delay(300);

    // Scan LEFT
    scanServo.write(150);
    delay(400);
    bool leftBlocked = obstacleDetected();

    // Scan RIGHT
    scanServo.write(30);
    delay(400);
    bool rightBlocked = obstacleDetected();

    // Center servo again
    scanServo.write(90);
    delay(200);

    // Decide direction
    if (!leftBlocked) {
      Serial.println("Turning LEFT");
      turnLeft();
      delay(500);
    }
    else if (!rightBlocked) {
      Serial.println("Turning RIGHT");
      turnRight();
      delay(500);
    }
    else {
      Serial.println("Both sides blocked, reversing");
      moveBackward();
      delay(500);
    }

    stopMotors();
    delay(200);
  }
}
