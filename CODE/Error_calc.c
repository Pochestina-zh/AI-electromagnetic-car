#include "Error_calc.h"

//--------------------------------------------------------------------//
//-----------------------------------ת�򻷼���-----------------------//
/*
extern int real_angle_rudder;
//extern uint16 peak_max[15];
int angle_error_rudder;
int angle_error_rudder_last;
int final_angle;
float anglepid_para[3]={0,0,0}; //p,i,d

int angle_pid_rudder(int targetangle)   //����delta_rudder
{
    angle_error_rudder = targetangle - real_angle_rudder;       //E(n)
    final_angle = anglepid_para[0]*angle_error_rudder + anglepid_para[2]*(angle_error_rudder - angle_error_rudder_last);
    angle_error_rudder_last = angle_error_rudder;
    return final_angle;
}
*/

int dir_error;  //��ǰƫ��
int final_dir;
int dir_pid(void)
{
    dir_error=dir_e;
    final_dir=5.5*dir_e+15*(dir_error-dir_e);
    return final_dir;
}
/*
extern int real_angle_motor;
int angle_error_motor;
int angle_error_motor_last;
int final_angle_motor;
float anglepid_para_motor[3] = {2, 0, 0.5};   // p,i,d

int angle_pid_motor(int targetangle_m)  //����delta_motor
{
    angle_error_motor = targetangle_m - real_angle_motor;		//E(n)
    final_angle_motor = anglepid_para_motor[0]*angle_error_motor + anglepid_para_motor[2]*(angle_error_motor - angle_error_motor_last);
	angle_error_motor_last = angle_error_motor;
    return final_angle_motor;
}
*/
//extern float rudder_error;
//extern floatmotor_error;

int delta_rudder;
//int delta_motor;
void angle_calc(void)  //���ת�򻷣��ֱ�õ��˿���ת�����
{
    delta_rudder = dir_pid();
    //delta_motor = angle_pid_motor(motor_error);
}



//--------------------------------------------------------------------//
//-----------------------------------����������-----------------------//


//-------����������ļ���------//
void rudder_calc(void)
{
    angle_calc();
    rudder_pwm=middle_rudder+delta_rudder;
}




//-------����������ļ���------//
int pwm_error=0;  //��ǰƫ��
int pwm_error_last=0; //��һ�ε�ƫ��
int pwm_error_lastlast=0; //���ϴε�ƫ��
int delta_pwm;  //pid�������������
int final_pwm;
float kp=8;
float ki=6;
float kd=0;

int pwm_pid(int target_pwm)//����ʽPID�Ӻ���//-350
{
    pwm_error_last = pwm_error;//-350
    pwm_error_lastlast = pwm_error_last;    //�������ֵ
    pwm_error = target_pwm - real_pwm;  //E(n)//-350
    delta_pwm = kp*(pwm_error - pwm_error_last) + ki*pwm_error + kd*(pwm_error - 2*pwm_error_last + pwm_error_lastlast);
    final_pwm -= delta_pwm;
    return final_pwm;//-4000//-3.5
}
int target=-350;//�����ٶ�
int target_pwm;//����������ֵ
//int basic_motor;

void motor_calc(void)
{
//   basic_motor=2000;
   motor_pwm=pwm_pid(target_pwm);
}

//------------------------------//


//------------------------------//
extern int forced_stop; //ǿ��ͣ����־

void error_calc(void)
{
    if(forced_stop)//ǿ��ͣ����pwm=0
    {
        //rudder_calc();
        rudder_pwm=middle_rudder;
        motor_pwm=0;
    }
    else
    {
        rudder_calc();
        motor_calc();
    }
}

