# Arduino Autonomous Obstacle Avoiding Car

An autonomous robot car built with Arduino that continuously moves forward, detects obstacles, and intelligently avoids them using a proximity sensor, servo-based scanning, and motor control.

---

##  Features
- Automatic forward movement on power-up
- Obstacle detection using IR proximity sensor
- Smart avoidance logic:
  - Stops when obstacle is detected
  - Reverses slightly
  - Scans left and right using a servo motor
  - Chooses the free direction automatically
- Fully autonomous (no remote or Bluetooth needed)
- Simple and efficient Arduino code

---

##  How It Works
1. The car moves forward continuously.
2. When an obstacle is detected:
   - Motors stop immediately.
   - Car reverses slightly.
   - Servo rotates to the left and checks for obstacles.
   - Servo rotates to the right and checks again.
3. Decision logic:
   - If left is free → turn left
   - Else if right is free → turn right
   - Else → reverse and retry
4. The car continues moving forward and repeats the process automatically.

---

## Hardware Components
- Arduino Nano
- L298N Motor Driver
- 2 DC Motors + Robot chassis
- IR Proximity Sensor (3-pin)
- Servo Motor (SG90 or similar)
- Battery / Power supply
- Jumper wires

---

##  Pin Connections

### Motor Driver (L298N → Arduino Nano)
| L298N Pin | Arduino Pin |
|---------|-------------|
| IN1 | D12 |
| IN2 | D13 |
| IN3 | D10 |
| IN4 | D11 |

### Sensors & Servo
| Component | Arduino Pin |
|---------|-------------|
| IR Proximity OUT | D2 |
| Servo Signal | D9 |

---

## Code Overview
- `moveForward()` → Drives the car forward
- `moveBackward()` → Reverses the car
- `turnLeft()` / `turnRight()` → Direction control
- `obstacleDetected()` → Reads proximity sensor
- Servo scans left (150°) and right (30°) for obstacle detection

---

##  How to Run
1. Connect all components as shown above.
2. Upload the code using Arduino IDE.
3. Power the Arduino and motors.
4. The car will start moving automatically and avoid obstacles.

---

## Author
**Mansur Isah Madaki**  
IoT & Embedded Systems Developer  
Powered by **SmartSense**

---

## ⭐ Support
If you like this project, give it a ⭐ on GitHub!
