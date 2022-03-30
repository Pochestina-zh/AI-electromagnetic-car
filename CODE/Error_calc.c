#include "Error_calc.h"

//--------------------------------------------------------------------//
//-----------------------------------转向环计算-----------------------//
/*
extern int real_angle_rudder;
//extern uint16 peak_max[15];
int angle_error_rudder;
int angle_error_rudder_last;
int final_angle;
float anglepid_para[3]={0,0,0}; //p,i,d

int angle_pid_rudder(int targetangle)   //计算delta_rudder
{
    angle_error_rudder = targetangle - real_angle_rudder;       //E(n)
    final_angle = anglepid_para[0]*angle_error_rudder + anglepid_para[2]*(angle_error_rudder - angle_error_rudder_last);
    angle_error_rudder_last = angle_error_rudder;
    return final_angle;
}
*/

int dir_error;  //当前偏差
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

int angle_pid_motor(int targetangle_m)  //计算delta_motor
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
void angle_calc(void)  //设计转向环，分别得到了控制转向的量
{
    delta_rudder = dir_pid();
    //delta_motor = angle_pid_motor(motor_error);
}



//--------------------------------------------------------------------//
//-----------------------------------控制量计算-----------------------//


//-------舵机控制量的计算------//
void rudder_calc(void)
{
    angle_calc();
    rudder_pwm=middle_rudder+delta_rudder;
}




//-------电机控制量的计算------//
int pwm_error=0;  //当前偏差
int pwm_error_last=0; //上一次的偏差
int pwm_error_lastlast=0; //上上次的偏差
int delta_pwm;  //pid计算出来的增量
int final_pwm;
float kp=8;
float ki=6;
float kd=0;

int pwm_pid(int target_pwm)//增量式PID子函数//-350
{
    pwm_error_last = pwm_error;//-350
    pwm_error_lastlast = pwm_error_last;    //更新误差值
    pwm_error = target_pwm - real_pwm;  //E(n)//-350
    delta_pwm = kp*(pwm_error - pwm_error_last) + ki*pwm_error + kd*(pwm_error - 2*pwm_error_last + pwm_error_lastlast);
    final_pwm -= delta_pwm;
    return final_pwm;//-4000//-3.5
}
int target=-350;//期望速度
int target_pwm;//期望电机输出值
//int basic_motor;

void motor_calc(void)
{
//   basic_motor=2000;
   motor_pwm=pwm_pid(target_pwm);
}

//------------------------------//


//------------------------------//
extern int forced_stop; //强制停车标志

void error_calc(void)
{
    if(forced_stop)//强制停车，pwm=0
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

