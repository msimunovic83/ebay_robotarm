#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Create servo driver object
Adafruit_PWMServoDriver servoShield = Adafruit_PWMServoDriver();

// Servo channel assignments
const int servo1Channel = 0;
const int servo2Channel = 1;
const int servo3Channel = 2;
const int servo4Channel = 3;
const int servo5Channel = 4;

// Servo minimum and maximum pulse length in microseconds
const int servoMin = 150;
const int servoMax = 600;

void setup() {
  // Start the shield with the default I2C address (0x40)
  servoShield.begin();
  // Set PWM frequency to 60 Hz
  servoShield.setPWMFreq(60);

  // Start serial communication at 9600 bps
  Serial.begin(9600);
}






// Function prototypes
void moveServo(int servoChannel, int startPos, int endPos, int step, int delayTime);

void loop() {
  // Move each servo with custom settings
  moveServo(servo1Channel, 0, 90, 1, 40);
  moveServo(servo2Channel, 100, 130, 1, 40);
  moveServo(servo3Channel, 70, 150, 1, 40);
  moveServo(servo4Channel, 50, 100, 1, 40);
  moveServo(servo5Channel, 50, 100, 1, 40);

  // Add a delay between forward and backward movements
  delay(10);

  moveServo(servo1Channel, 90, 0, -1, 40);
  moveServo(servo2Channel, 130, 100, -1, 40);
  moveServo(servo3Channel, 150, 70, -1, 40);
  moveServo(servo4Channel, 100, 50, -1, 40);
  moveServo(servo5Channel, 100, 50, -1, 40);
}

// Function to move a servo with custom settings
void moveServo(int servoChannel, int startPos, int endPos, int step, int delayTime) {
  for (int pos = startPos; (step > 0) ? pos <= endPos : pos >= endPos; pos += step) {
    setServoPosition(servoChannel, pos);
    delay(delayTime);
  }
}













void setServoPosition(int channel, int angle) {
  int pulse = map(angle, 0, 180, servoMin, servoMax);
  servoShield.setPWM(channel, 0, pulse);
}

void printServoValues(int pos1, int pos2, int pos3, int pos4, int pos5) {
  Serial.print("Servo1: ");
  Serial.print(pos1);
  Serial.print(" | Servo2: ");
  Serial.print(pos2);
  Serial.print(" | Servo3: ");
  Serial.print(pos3);
  Serial.print(" | Servo4: ");
  Serial.print(pos4);
  Serial.print(" | Servo5: ");
  Serial.println(pos5);
}

