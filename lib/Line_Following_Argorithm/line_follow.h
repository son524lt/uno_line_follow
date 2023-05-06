#ifndef _LINE_FOLLOW_H_
#define _LINE_FOLLOW_H_

#include "stdint.h"


class Line_follow
{
private:
    /* data */
public:
    float P,I,D, Kp, Ki, Kd;
    float output;
    float Err=0, preErr=0;
    int16_t left_pwm, right_pwm, right_base_speed, left_base_speed;
    void calculate_output_control(bool input1, bool input2, bool input3);
    Line_follow(int16_t left_base_pwm, int16_t right_base_pwm, float _Kp, float _Ki, float _Kd);
};


#endif

