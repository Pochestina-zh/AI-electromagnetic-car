#include "Get_line.h"
#include  <math.h>
/*
    ������߲���
    ���ݲɼ����ĵ��ֵ���н��㣬��������Ϣ���з�����
        1.ͨ����ͨ������������
        2.���������緽����������
*/
//extern uint16 peak_max[15];
extern int peak[AdcNum];
//extern uint8 flag_1, flag_2;

//------------------------------------//


//--------------��������--------------//
int forced_stop;  //ǿ��ͣ����־

void protect(void)  //ͣ��ʶ��
{
        if(peak[0] < 40 && peak[4] < 40 && peak[6]<40 && peak[9]<30)//�����ֵ��С��һ��ֵʱ������������
        {
            forced_stop = 1;    //ǿ��ͣ��
        }
}

//------------------------------------//


//--------------���߳���--------------//
float rudder_error,motor_error;
int right_island_flag ,left_island_flag;//���һ���
int normal_track_flag;//��������
int cross_flagcross_in_flag , cross_count , cross_out_flag;//ʮ��·��
int curve,left_curve,right_curve;//����

//1.ͨ����ͨ������������

int peak_mid;
float peak_across_add,peak_across_sub;//add�ӣ�sub��
float peak_vertical_add,peak_vertical_sub;
float error_across,error_vertical;
float error_2mid;
int dir_e;//���ת��ƫ��


//******************************��������ʶ��***********************//
//void right_curve(void)
//{
//    if(peak[0]-peak[4])>25||peak[6]-peak[9]>15)//����
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
    ///////////////////////////����/ֱ����//////////////////////////
   if(abs(peak[0]-peak[4])>30||abs(peak[6]-peak[9])>20)//����
   {
       curve=1;
   }
   ////////////////////////////////����////////////////////////////////
   /*�һ���*/
   if(peak[4]-peak[0]>30 && peak[2]>30)
   {
       right_island_flag=1;

   }
   ////////////////////////////��������//////////////////////////////
   else
   {
       normal_track_flag=1;
   }
}
    ////////////////////////////ʮ��//////////////////////////////////


//***********************************���ߴ����Բ�ͬԪ�أ�***************************//
void getline_control(void)
{
    //��к͡���
    peak_across_add=0.8*(peak[0]+peak[4]+peak[3])+0.2*(peak[6]+peak[9]);      //����
    peak_across_sub=0.8*(peak[0]-peak[4])+0.2*(peak[6]-peak[9]);
    peak_vertical_add=peak[1]+peak[3];    //�����
    peak_vertical_sub=peak[1]-peak[3];

    //������в�Ⱥ�
    error_across=peak_across_sub*300/peak_across_add;
    error_vertical=peak_vertical_sub*300/peak_vertical_add;

    //���в�Ⱥ�
    dir_e=error_across*0.7+error_vertical*0.3;

    ////////////////////��������////////////////////
    if(normal_track_flag==1)
    {
        //�����ٶ�
        target_pwm=target;
    }
    /////////////////����/ֱ����////////////////////
    else if(curve==1)
    {
        //�����ٶ�
        target_pwm=0.5*target;
    }
}



//�����ܺ���
void get_line(void)
{
    element_judge();//��������Ԫ��ʶ��
    protect();//ͣ������
    getline_control();//���ߴ���������Բ�ͬ����Ԫ�أ�
}
