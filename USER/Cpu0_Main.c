/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2020,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：三群：824575535
 *
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 *
 * @file       		main
 * @company	   		成都逐飞科技有限公司
 * @author     		逐飞科技(QQ3184284598)
 * @version    		查看doc内version文件 版本说明
 * @Software 		ADS v1.2.2
 * @Target core		TC364DP
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2020-11-23
 ********************************************************************************************************************/

#include "Cpu0_Main.h"
#include "headfile.h"
#pragma section all "cpu0_dsram"
//将本语句与#pragma section all restore语句之间的全局变量都放在CPU0的RAM中

//工程导入到软件之后，应该选中工程然后点击refresh刷新一下之后再编译

//工程默认设置为关闭优化，可以自己右击工程选择properties->C/C++ Build->Setting
//然后在右侧的窗口中找到C/C++ Compiler->Optimization->Optimization level处设置优化等级
//一般默认新建立的工程都会默认开2级优化，因此大家也可以设置为2级优化

//对于TC系列默认是不支持中断嵌套的，希望支持中断嵌套需要在中断内使用enableInterrupts();来开启中断嵌套
//简单点说实际上进入中断后TC系列的硬件自动调用了disableInterrupts();来拒绝响应任何的中断，因为需要我们自己手动调用enableInterrupts();来开启中断的响应。

int flag_1,flag_2,flag_3,flag_4;
int real_pwm;
int stop_flag;
int out_flag;
int init_flag=0;
extern int curve,normal_track_flag;
int core0_main (void)
{
    get_clk(); //获取时钟频率  务必保留
    //用户在此处调用各种初始化函数等

    /***********************************电机初始化*****************************/
    //单电机
    gtm_pwm_init(ATOM0_CH0_P21_2, 1500, 0);
    gtm_pwm_init(ATOM0_CH2_P21_4, 1500, 5000);    //左右？

    /***********************************舵机初始化*****************************/
    gtm_pwm_init(ATOM0_CH1_P33_9, 150, 2200);   //left_edge=1800, middle=2300, right_edge=2800

    /***********************************电磁初始化*****************************/
    adc_init(ADC_0, ADC0_CH0_A0);   //AD1
    adc_init(ADC_0, ADC0_CH1_A1);   //AD2
    adc_init(ADC_0, ADC0_CH2_A2);   //AD3
    adc_init(ADC_0, ADC0_CH3_A3);   //AD4
    adc_init(ADC_0, ADC0_CH4_A4);   //AD5
//    adc_init(ADC_0, ADC0_CH5_A5);   //AD6
    adc_init(ADC_0, ADC0_CH6_A6);   //AD7
//    adc_init(ADC_0, ADC0_CH7_A7);   //AD8
//    adc_init(ADC_1, ADC1_CH0_A8);   //AD9
    adc_init(ADC_1, ADC1_CH2_A10);   //AD10
/*    adc_init(ADC_1, ADC1_CH3_A11);   //AD11
    adc_init(ADC_1, ADC1_CH4_A12);   //AD12
    adc_init(ADC_1, ADC1_CH5_A13);   //AD13
    adc_init(ADC_2, ADC2_CH0_A16);   //AD14
    adc_init(ADC_2, ADC2_CH1_A17);   //AD15  */

    /**********************************编码器初始化****************************/
    gpt12_init(GPT12_T6, GPT12_T6INA_P20_3, GPT12_T6EUDA_P20_0);
    //定时器T6、计数引脚、方向引脚

    /*********************************初始化定时器中断*************************/
    pit_interrupt_ms(CCU6_0, PIT_CH0, 5); //使用CCU6_0模块的通道0 产生一个 5ms的周期中断
    //需要特备注意的是  不可以有优先级相同的中断函数 每个中断的优先级都必须是不一样的

    /*************************************串口初始化***************************/

    /*************************************TFT初始化*******************************************/
    lcd_init();


    //等待所有核心初始化完毕
    IfxCpu_emitEvent(&g_cpuSyncEvent);
    IfxCpu_waitEvent(&g_cpuSyncEvent, 0xFFFF);
    enableInterrupts();
    while (TRUE)
    {
        //用户在此处编写任务代码

        lcd_showstr(0,0,"right1");//横右
        lcd_showint16(50,0,peak[0]);
        lcd_showstr(0,1,"right2");//竖右
        lcd_showint16(50,1,peak[1]);
        lcd_showstr(0,2,"middle");//中
        lcd_showint16(50,2,peak[2]);
        lcd_showstr(0,3,"left1");//靠右的一个
        lcd_showint16(50,3,peak[3]);//竖左
        lcd_showstr(0,4,"left2");
        lcd_showint16(50,4,peak[4]);//横左
        lcd_showint16(50,5,peak[9]);//二排左
        lcd_showint16(50,6,peak[6]);//二排右
        lcd_showint16(0,5,motor_pwm);
        lcd_showint16(0,6,real_pwm);//编码器读值
        lcd_showint16(0,7,dir_e);
        lcd_showint16(50,7,rudder_pwm);//舵机输出
        lcd_showint8(100,6,curve);
        lcd_showint8(100,7,normal_track_flag);
    }
}

#pragma section all restore
