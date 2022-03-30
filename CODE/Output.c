#include "Output.h"

//////////////////////////////
///////////舵机/////////////
int rudder_pwm;
void rudder_output(void)
{
    //舵机限幅
    if(rudder_pwm < left_rudder_edge)rudder_pwm = left_rudder_edge;
    if(rudder_pwm > right_rudder_edge)rudder_pwm = right_rudder_edge;
    //舵机输出
    pwm_duty(ATOM0_CH1_P33_9,rudder_pwm);
}

//////////////////////////////
///////////电机/////////////
int motor_pwm;   //电机输出，0为左，1为右

void motor_output(void)
{
    //电机限幅
    if(motor_pwm<motor_pwm_min)motor_pwm=motor_pwm_min;
    if(motor_pwm>motor_pwm_max)motor_pwm=motor_pwm_max;
    //电机输出

    if(motor_pwm>0)
    {
        pwm_duty(ATOM0_CH0_P21_2,0);
        pwm_duty(ATOM0_CH2_P21_4,motor_pwm);
    }
    else if(motor_pwm<=0)
    {
        pwm_duty(ATOM0_CH0_P21_2,-motor_pwm);
        pwm_duty(ATOM0_CH2_P21_4,0);
    }
}
//////////////////////////////
///////////合并输出///////////

void output(void)
{
		rudder_output();
        motor_output();

}

