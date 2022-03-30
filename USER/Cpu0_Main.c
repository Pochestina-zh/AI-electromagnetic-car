/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2020,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ����Ⱥ��824575535
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		main
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ3184284598)
 * @version    		�鿴doc��version�ļ� �汾˵��
 * @Software 		ADS v1.2.2
 * @Target core		TC364DP
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2020-11-23
 ********************************************************************************************************************/

#include "Cpu0_Main.h"
#include "headfile.h"
#pragma section all "cpu0_dsram"
//���������#pragma section all restore���֮���ȫ�ֱ���������CPU0��RAM��

//���̵��뵽���֮��Ӧ��ѡ�й���Ȼ����refreshˢ��һ��֮���ٱ���

//����Ĭ������Ϊ�ر��Ż��������Լ��һ�����ѡ��properties->C/C++ Build->Setting
//Ȼ�����Ҳ�Ĵ������ҵ�C/C++ Compiler->Optimization->Optimization level�������Ż��ȼ�
//һ��Ĭ���½����Ĺ��̶���Ĭ�Ͽ�2���Ż�����˴��Ҳ��������Ϊ2���Ż�

//����TCϵ��Ĭ���ǲ�֧���ж�Ƕ�׵ģ�ϣ��֧���ж�Ƕ����Ҫ���ж���ʹ��enableInterrupts();�������ж�Ƕ��
//�򵥵�˵ʵ���Ͻ����жϺ�TCϵ�е�Ӳ���Զ�������disableInterrupts();���ܾ���Ӧ�κε��жϣ���Ϊ��Ҫ�����Լ��ֶ�����enableInterrupts();�������жϵ���Ӧ��

int flag_1,flag_2,flag_3,flag_4;
int real_pwm;
int stop_flag;
int out_flag;
int init_flag=0;
extern int curve,normal_track_flag;
int core0_main (void)
{
    get_clk(); //��ȡʱ��Ƶ��  ��ر���
    //�û��ڴ˴����ø��ֳ�ʼ��������

    /***********************************�����ʼ��*****************************/
    //�����
    gtm_pwm_init(ATOM0_CH0_P21_2, 1500, 0);
    gtm_pwm_init(ATOM0_CH2_P21_4, 1500, 5000);    //���ң�

    /***********************************�����ʼ��*****************************/
    gtm_pwm_init(ATOM0_CH1_P33_9, 150, 2200);   //left_edge=1800, middle=2300, right_edge=2800

    /***********************************��ų�ʼ��*****************************/
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

    /**********************************��������ʼ��****************************/
    gpt12_init(GPT12_T6, GPT12_T6INA_P20_3, GPT12_T6EUDA_P20_0);
    //��ʱ��T6���������š���������

    /*********************************��ʼ����ʱ���ж�*************************/
    pit_interrupt_ms(CCU6_0, PIT_CH0, 5); //ʹ��CCU6_0ģ���ͨ��0 ����һ�� 5ms�������ж�
    //��Ҫ�ر�ע�����  �����������ȼ���ͬ���жϺ��� ÿ���жϵ����ȼ��������ǲ�һ����

    /*************************************���ڳ�ʼ��***************************/

    /*************************************TFT��ʼ��*******************************************/
    lcd_init();


    //�ȴ����к��ĳ�ʼ�����
    IfxCpu_emitEvent(&g_cpuSyncEvent);
    IfxCpu_waitEvent(&g_cpuSyncEvent, 0xFFFF);
    enableInterrupts();
    while (TRUE)
    {
        //�û��ڴ˴���д�������

        lcd_showstr(0,0,"right1");//����
        lcd_showint16(50,0,peak[0]);
        lcd_showstr(0,1,"right2");//����
        lcd_showint16(50,1,peak[1]);
        lcd_showstr(0,2,"middle");//��
        lcd_showint16(50,2,peak[2]);
        lcd_showstr(0,3,"left1");//���ҵ�һ��
        lcd_showint16(50,3,peak[3]);//����
        lcd_showstr(0,4,"left2");
        lcd_showint16(50,4,peak[4]);//����
        lcd_showint16(50,5,peak[9]);//������
        lcd_showint16(50,6,peak[6]);//������
        lcd_showint16(0,5,motor_pwm);
        lcd_showint16(0,6,real_pwm);//��������ֵ
        lcd_showint16(0,7,dir_e);
        lcd_showint16(50,7,rudder_pwm);//������
        lcd_showint8(100,6,curve);
        lcd_showint8(100,7,normal_track_flag);
    }
}

#pragma section all restore
