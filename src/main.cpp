#include <Arduino.h>
#include <main.h>
#include <line_follow.h>
#include <motor_control.h>


void setup() {
  pinMode(LS,INPUT);
  pinMode(MS,INPUT);
  pinMode(RS,INPUT);
  Serial.begin(9600);
}

Line_follow lineHandle(LEFT_BASE_PWM, RIGHT_BASE_PWM, KP, KI, KD);
// Motor leftMotor(LF, LB, LE);
// Motor rightMotor(RF, RB, RE);

Motor leftMotor(LF, LB);
Motor rightMotor(RF, RB);

void loop() {
  // Serial.print(digitalRead(LS));
  // Serial.print("\t");
  // Serial.print(digitalRead(MS));
  // Serial.print("\t");
  // Serial.print(digitalRead(RS));
  // Serial.print("\t");
  lineHandle.calculate_output_control(digitalRead(LS),digitalRead(MS),digitalRead(RS));
  // Serial.print(lineHandle.Err);
  // Serial.print("\t");
  // Serial.print(lineHandle.left_pwm);
  // Serial.print("\t");
  // Serial.println(lineHandle.right_pwm);
  leftMotor.Run(lineHandle.left_pwm);
  rightMotor.Run(lineHandle.right_pwm);
  Serial.println();
}