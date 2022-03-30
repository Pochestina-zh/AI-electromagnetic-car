#include "Get_line.h"
#include  <math.h>
/*
    电磁提线部分
    根据采集到的电感值进行结算，对赛道信息进行分析。
        1.通过普通方法进行提线
        2.根据神经网络方法进行提线
*/
//extern uint16 peak_max[15];
extern int peak[AdcNum];
//extern uint8 flag_1, flag_2;

//------------------------------------//


//--------------保护程序--------------//
int forced_stop;  //强制停车标志

void protect(void)  //停车识别
{
        if(peak[0] < 40 && peak[4] < 40 && peak[6]<40 && peak[9]<30)//当电感值都小于一定值时触发保护程序
        {
            forced_stop = 1;    //强制停车
        }
}

//------------------------------------//


//--------------提线程序--------------//
float rudder_error,motor_error;
int right_island_flag ,left_island_flag;//左右环岛
int normal_track_flag;//正常赛道
int cross_flagcross_in_flag , cross_count , cross_out_flag;//十字路口
int curve,left_curve,right_curve;//急弯

//1.通过普通方法进行提线

int peak_mid;
float peak_across_add,peak_across_sub;//add加，sub减
float peak_vertical_add,peak_vertical_sub;
float error_across,error_vertical;
float error_2mid;
int dir_e;//舵机转向偏差


//******************************特殊赛道识别***********************//
//void right_curve(void)
//{
//    if(peak[0]-peak[4])>25||peak[6]-peak[9]>15)//急弯
//       {
//           right_curve=1;
//
//       }
//}
//void left_curve(void)
//{
//
//}
void element_judge(void)
{
    ///////////////////////////急弯/直角弯//////////////////////////
   if(abs(peak[0]-peak[4])>30||abs(peak[6]-peak[9])>20)//急弯
   {
       curve=1;
   }
   ////////////////////////////////环岛////////////////////////////////
   /*右环岛*/
   if(peak[4]-peak[0]>30 && peak[2]>30)
   {
       right_island_flag=1;

   }
   ////////////////////////////正常赛道//////////////////////////////
   else
   {
       normal_track_flag=1;
   }
}
    ////////////////////////////十字//////////////////////////////////


//***********************************提线处理（对不同元素）***************************//
void getline_control(void)
{
    //电感和、差
    peak_across_add=0.8*(peak[0]+peak[4]+peak[3])+0.2*(peak[6]+peak[9]);      //横电感
    peak_across_sub=0.8*(peak[0]-peak[4])+0.2*(peak[6]-peak[9]);
    peak_vertical_add=peak[1]+peak[3];    //竖电感
    peak_vertical_sub=peak[1]-peak[3];

    //横竖电感差比和
    error_across=peak_across_sub*300/peak_across_add;
    error_vertical=peak_vertical_sub*300/peak_vertical_add;

    //现有差比和
    dir_e=error_across*0.7+error_vertical*0.3;

    ////////////////////正常赛道////////////////////
    if(normal_track_flag==1)
    {
        //期望速度
        target_pwm=target;
    }
    /////////////////急弯/直角弯////////////////////
    else if(curve==1)
    {
        //期望速度
        target_pwm=0.5*target;
    }
}



//提线总函数
void get_line(void)
{
    element_judge();//特殊赛道元素识别
    protect();//停车保护
    getline_control();//提线处理函数（针对不同赛道元素）
}
