#ifndef _LINE_FOLLOW_H_
#define _LINE_FOLLOW_H_

#include "stdint.h"


class Line_follow
{
private:
    /* data */
public:
    float P,D, Kp, Kd;
    float output;
    float Err=0, preErr=0;
    int16_t left_pwm, right_pwm, base_speed;
    void calculate_output_control(bool input1, bool input2, bool input3);
    Line_follow(int16_t base_pwm, float _Kp, float _Kd);
};


#endif

