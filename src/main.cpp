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

Line_follow lineHandle(BASE_PWM, KP, KD);
Motor leftMotor(LF, LB, LE);
Motor rightMotor(RF, RB, RE);

void loop() {
  lineHandle.calculate_output_control(digitalRead(RS),digitalRead(MS),digitalRead(LS));
  Serial.print(lineHandle.Err);
  Serial.print("\t");
  Serial.print(lineHandle.left_pwm);
  Serial.print("\t");
  Serial.println(lineHandle.right_pwm);
  leftMotor.Run(lineHandle.left_pwm);
  rightMotor.Run(lineHandle.right_pwm);
}