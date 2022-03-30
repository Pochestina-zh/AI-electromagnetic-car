/*
此文件为配置文件，主要包含主程序中所使用的一些宏定义参数
*/
/*
//--------------------------------------------//
//------------------模型相关------------------//
#define SHIFT 3  //数值由这个决定（inf.quantBits - pOM->fracBits - 1）
*/
//--------------------------------------------//
//------------------舵机相关------------------//
#define left_rudder_edge 1500   //舵机左打角极限值
#define middle_rudder 2200   //舵机中值
#define right_rudder_edge 2900   //舵机右打角极限值

//--------------------------------------------//
//------------------电机相关------------------//
#define motor_pwm_max 7000
#define motor_pwm_min -7000

//--------------------------------------------//
//------------------电感相关------------------//
#define AdcNum 15  //电感数量
#define SampleNum 50  //电感采集样本量



//定义全局变量
//电机
extern int motor_pwm;//电机输出值
extern int real_pwm;//电机真实值
extern int target_pwm;
extern int target;
extern int pwm_error;//电机差比和
//电感
extern int sensor[AdcNum][SampleNum];//电感采集值
extern int peak[AdcNum];//电感峰值
//舵机
extern int dir_e;//差比和
extern int rudder_pwm;//舵机输出值
//停车
extern int forced_stop;
extern int output_flag;
//丢线
extern int out_flag;
extern int init_flag;


