/*
���ļ�Ϊ�����ļ�����Ҫ��������������ʹ�õ�һЩ�궨�����
*/
/*
//--------------------------------------------//
//------------------ģ�����------------------//
#define SHIFT 3  //��ֵ�����������inf.quantBits - pOM->fracBits - 1��
*/
//--------------------------------------------//
//------------------������------------------//
#define left_rudder_edge 1500   //������Ǽ���ֵ
#define middle_rudder 2200   //�����ֵ
#define right_rudder_edge 2900   //����Ҵ�Ǽ���ֵ

//--------------------------------------------//
//------------------������------------------//
#define motor_pwm_max 7000
#define motor_pwm_min -7000

//--------------------------------------------//
//------------------������------------------//
#define AdcNum 15  //�������
#define SampleNum 50  //��вɼ�������



//����ȫ�ֱ���
//���
extern int motor_pwm;//������ֵ
extern int real_pwm;//�����ʵֵ
extern int target_pwm;
extern int target;
extern int pwm_error;//�����Ⱥ�
//���
extern int sensor[AdcNum][SampleNum];//��вɼ�ֵ
extern int peak[AdcNum];//��з�ֵ
//���
extern int dir_e;//��Ⱥ�
extern int rudder_pwm;//������ֵ
//ͣ��
extern int forced_stop;
extern int output_flag;
//����
extern int out_flag;
extern int init_flag;


