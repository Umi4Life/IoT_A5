#include <Servo.h>
Servo yAxisServo;  // create servo object to control a servo
Servo xAxisServo;
// twelve servo objects can be created on most boards

int minDiff =200;
int yServoValue = 120;
int xServoValue = 90;

void setup() {
  yAxisServo.attach(8);  // attaches the servo on pin 9 to the servo object
  xAxisServo.attach(9);
  Serial.begin(9600);
  yAxisServo.write(yServoValue);
  xAxisServo.write(xServoValue);
}

void loop() {
  // put your main code here, to run repeatedly:
  int upLdr = analogRead(A0);
  int downLdr = analogRead(A1);
  int leftLdr = analogRead(A2);
  int rightLdr = analogRead(A3);
//  Serial.println(leftLdr);
//  Serial.println(rightLdr);
  Serial.println();
  moveMotorY(upLdr, downLdr);
  moveMotorX(leftLdr, rightLdr);
  delay(20);
}

void moveMotorX(int value1, int value2) {
  if (abs(value1 - value2) > minDiff) {
    if (value1 > value2) {
      xServoValue++;
    }
    else if (value1 < value2) {
      xServoValue--;
    }
    xAxisServo.write(xServoValue);
  }
}

void moveMotorY(int value1, int value2) {
  Serial.println(yServoValue);
  if (abs(value1 - value2) > minDiff) {
    if (value1 > value2 and yServoValue < 155) {
      yServoValue++;
      if(yServoValue > 155){
        yServoValue--;
      }
      Serial.println("up");
    }
    else if (value1 < value2 and yServoValue > 50) {
      yServoValue--;
      if(yServoValue < 50){
        yServoValue++;
      }
      Serial.println("down");
    }
    yAxisServo.write(yServoValue);
  }
}
