#include "line_follow.h"

Line_follow::Line_follow(int16_t left_base_pwm, int16_t right_base_pwm, float _Kp, float _Ki, float _Kd) {
        left_base_speed = left_base_pwm;
        right_base_speed = right_base_pwm;
        Kp = _Kp;
        Ki = _Ki;
        Kd = _Kd;
}

void Line_follow::calculate_output_control(bool input1, bool input2, bool input3) {

    if      (input1==1 && input2==0 && input3==0)    Err =-2;
    else if (input1==1 && input2==1 && input3==0)    Err =-1;
    else if (input1==0 && input2==1 && input3==0)    Err =0;
    else if (input1==0 && input2==1 && input3==1)    Err =1; 
    else if (input1==0 && input2==0 && input3==1)    Err =2;
    else if (input1==0 && input2==0 && input3==0){
        if(preErr>0) Err=3;
        else if(preErr<0) Err = -3;
        else Err = 0;
    }
    P = Err;
    I = I+Err;
    D = Err-preErr;
    output = Kp*P+ Ki*I + Kd*D;
    left_pwm = left_base_speed + output;
    right_pwm = right_base_speed - output;
    if (preErr!=Err) preErr = Err;
}



