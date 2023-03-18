#include "line_follow.h"

Line_follow::Line_follow(int16_t base_pwm, float _Kp, float _Kd) {
        base_speed = base_pwm;
        Kp = _Kp;
        Kd = _Kd;
}

void Line_follow::calculate_output_control(bool input1, bool input2, bool input3) {

    if      (input1==1 && input2==0 && input3==0)    Err =-2;
    else if (input1==1 && input2==1 && input3==0)    Err =-1;
    else if (input1==0 && input2==1 && input3==0)    Err =0;
    else if (input1==0 && input2==1 && input3==1)    Err =1; 
    else if (input1==0 && input2==0 && input3==1)    Err =2;
    else if (input1==0 && input2==0 && input3==0){
        if(preErr>=0) Err=3;
        else if(preErr<0) Err = -3;
    }
    P = Kp*Err;
    D = Kd*(Err-preErr)*80;
    output = P+D;
    left_pwm = base_speed + output;
    right_pwm = base_speed - output;
    preErr = Err;
}



