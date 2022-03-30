#include "Output.h"

//////////////////////////////
///////////���/////////////
int rudder_pwm;
void rudder_output(void)
{
    //����޷�
    if(rudder_pwm < left_rudder_edge)rudder_pwm = left_rudder_edge;
    if(rudder_pwm > right_rudder_edge)rudder_pwm = right_rudder_edge;
    //������
    pwm_duty(ATOM0_CH1_P33_9,rudder_pwm);
}

//////////////////////////////
///////////���/////////////
int motor_pwm;   //��������0Ϊ��1Ϊ��

void motor_output(void)
{
    //����޷�
    if(motor_pwm<motor_pwm_min)motor_pwm=motor_pwm_min;
    if(motor_pwm>motor_pwm_max)motor_pwm=motor_pwm_max;
    //������

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
///////////�ϲ����///////////

void output(void)
{
		rudder_output();
        motor_output();

}

