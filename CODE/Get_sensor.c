#include "Get_sensor.h"
/*
对传感器的值进行采集，包括：
1.电感值（get_adc）;
2.编码器（get_speed）;
3.陀螺仪（get_angle）;
*/

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////电磁采集//////////////////////////////////////////////////

int sensor[AdcNum][SampleNum] = {0}; //由于电感采集的信号为交流信号，所以可以多次采值覆盖一个信号周期(sensor[][SampleNum],其中SampleNum为采集次数，可自行设定)
int peak[AdcNum] = {0};  //提取其中最大值和最小值并作差，得到峰峰值(peak[])
int peak_min[15]= {0};
int count;
int CalcMaxToMin(int data[SampleNum]) //计算50个采样值的最大值和最小值并求差
{
    int Max = 0;
    int Min = 0;
    Max = data[0];
    Min = data[0];
    
    for(int i = 0; i < SampleNum; i++)
		{
         if(data[i] > Max)   Max = data[i];
         if(data[i] < Min)   Min = data[i];
    }
    return Max-Min;
} 
int CalcMin(int data[SampleNum])
{
    int Min = 0;
    Min = data[0];
    for(int i=0; i < SampleNum; i++)
    {
        if(data[i] < Min)   Min = data[i];
    }
    return Min;
}
void get_adc(void) 
{
   for(int i=0;i < SampleNum;i++)
	 {
       sensor[0][i] = 100*adc_convert(ADC_0,ADC0_CH0_A0,ADC_8BIT)/90;    //AD1横右
       sensor[1][i] = 100*adc_convert(ADC_0,ADC0_CH1_A1,ADC_8BIT)/104;    //AD2竖右
       sensor[2][i] = 100*adc_convert(ADC_0,ADC0_CH2_A2,ADC_8BIT)/94;    //AD3 中
       sensor[3][i] = 100*adc_convert(ADC_0,ADC0_CH3_A3,ADC_8BIT)/90;    //AD4竖左
       sensor[4][i] = 100*adc_convert(ADC_0,ADC0_CH4_A4,ADC_8BIT)/91;    //AD5横左
//       sensor[5][i] = adc_convert(ADC_0,ADC0_CH5_A5,ADC_8BIT);    //AD6
       sensor[6][i] = 100*adc_convert(ADC_0,ADC0_CH6_A6,ADC_8BIT)/85;     //AD7二排右边
//       sensor[7][i] = adc_convert(ADC_0,ADC0_CH7_A7,ADC_8BIT);     //AD8
//      sensor[8][i] = adc_convert(ADC_1,ADC1_CH0_A8,ADC_8BIT);     //AD9
       sensor[9][i] = 100*adc_convert(ADC_1,ADC1_CH2_A10,ADC_8BIT)/125;     //AD10二排左边
/*       sensor[10][i] = adc_convert(ADC_1,ADC1_CH3_A11,ADC_8BIT);    //AD11
       sensor[11][i] = adc_convert(ADC_1,ADC1_CH4_A12,ADC_8BIT);    //AD12
       sensor[12][i] = adc_convert(ADC_1,ADC1_CH5_A13,ADC_8BIT);    //AD13
       sensor[13][i] = adc_convert(ADC_2,ADC2_CH0_A16,ADC_8BIT);    //AD14
       sensor[14][i] = adc_convert(ADC_2,ADC2_CH1_A17,ADC_8BIT);    //AD15
*/
    }
   for(int i=0;i<AdcNum; i++)
   {
       peak[i]=CalcMaxToMin(sensor[i]);
   }
    //归一化
//    for(int i=0; i<AdcNum; i++)
//    {
//        peak_min[i]=CalcMin(sensor[i]);
//        peak[i]=CalcMaxToMin(sensor[i]);
//    }
//    for(int i=0;i<AdcNum; i++)
//    {
//        for(int j=0;j<SampleNum;i++)
//        {
//            sensor[i][j]=100*((sensor[i][j]-peak_min[i])/(peak[i]+1));
//        }
//        peak[i]=CalcMaxToMin(sensor[i]);
//    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////编码器采集/////////////////////////////////////////////////

extern int real_pwm;
/*
int total_distance;
int distance_count;
extern int init_flag;
extern int out_flag;
*/
void get_speed(void)
{
    //读取编码器计数值
    real_pwm=gpt12_get(GPT12_T6);
    gpt12_clear(GPT12_T6);
    /*
    if(out_flag)    //车动时记路程
    {
        distance_count+=real_pwm;
    }
    total_distance=distance_count;
    */
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////陀螺仪采集/////////////////////////////////////////////////


int real_angle;  //由陀螺仪获取的车模的转角
int real_angle_rudder;
//int real_angle_motor;
void get_angle(void)
{
    get_icm20602_gyro();
    real_angle_rudder = icm_gyro_z / 50;
    //real_angle_motor = (icm_gyro_z / 10) * 25;
}
