#include <Arduino.h>
#include "motor_control.h"

// Motor::Motor(int8_t forward_pin, int8_t backward_pin, int8_t enable_pin) {
//     forward = forward_pin;
//     backward = backward_pin;
//     enable = enable_pin;
// }

// void Motor::Run(int pwm) {
//     if (pwm>255) pwm = 255;
//     else if (pwm<-255) pwm = -255;
//     digitalWrite(forward, (pwm)>0);
//     digitalWrite(backward, (pwm)<0);
//     analogWrite(enable, abs(pwm));
// }



Motor::Motor(int8_t forward_pin, int8_t backward_pin) {
    forward = forward_pin;
    backward = backward_pin;
}

void Motor::Run(int pwm) {
    if (pwm>255) pwm = 255;
    else if (pwm<-255) pwm = -255;
    analogWrite(forward,(pwm>0)?(pwm):(0));
    analogWrite(backward,(pwm>0)?(0):(-pwm));
}