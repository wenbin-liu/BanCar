#ifndef __BANLANCE_H
#define __BANLANCE_H

void getAngle(float *angle,float *gyro);
void pwmOutputR(int pwm);
void pwmOutputL(int pwm);
int banlanceControl(float angle ,float gyro);

#endif