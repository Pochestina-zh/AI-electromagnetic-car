#ifndef Error_calc_H
#define Error_calc_H

#include "headfile.h"
#include "Config.h"

void error_calc(void);   
int angle_pid_rudder(int targetangle);
int angle_pid_motor(int targetangle_m);
void angle_calc(void);
void rudder_calc(void);
int pwm_pid(int target_pwm);
void motor_calc(void);


#endif
