#include <Arduino.h>
#include <main.h>
#include <line_follow.h>
#include <motor_control.h>

Line_follow lineHandle(LEFT_BASE_PWM, RIGHT_BASE_PWM, KP, KI, KD);

void setup() {
  pinMode(LS,INPUT);
  pinMode(MS,INPUT);
  pinMode(RS,INPUT);
  lineHandle.initLogging(9600);
}

// Motor leftMotor(LF, LB, LE);
// Motor rightMotor(RF, RB, RE);

Motor leftMotor(LF, LB);
Motor rightMotor(RF, RB);

void loop() {
  lineHandle.calculate_output_control(digitalRead(LS),digitalRead(MS),digitalRead(RS));
  leftMotor.Run(lineHandle.left_pwm);
  rightMotor.Run(lineHandle.right_pwm);
}