#include "math.h"
#include "stdint.h"
#include "mpu6050.h"
#define GYRO_SCALE 500
#define GYRO_BIASE (-67)
#define BANLANCE_KP 500
#define BANLANCE_KD 0

extern TIM_HandleTypeDef htim3;
void getAngle(float *angle,float *gyro)
{
    int16_t ax,az,gy;
    MPU_ReadAx(&ax);
    MPU_ReadAz(&az);
    MPU_ReadGy(&gy);
    *gyro=-(gy-GYRO_BIASE)*GYRO_SCALE/32767.0;
    *angle=57.296*atan((float)ax/az);
    return;
}

void pwmOutputR(int pwm)
{
    if(pwm>0)
    {
        if(pwm>7200)
            pwm=7200;
        __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,pwm);
        __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,0);
    }

    else
    {
        if(pwm<-7200)
            pwm=-7200;
        __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,-pwm);
        __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,0);
    }
}
void pwmOutputL(int pwm)
{
    if(pwm>0)
    {
        if(pwm>7200)
            pwm=7200;
        __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_3,pwm);
        __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_4,0);
    }

    else
    {
        if(pwm<-7200)
            pwm=-7200;
        __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_4,-pwm);
        __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_3,0);
    }
}
int banlanceControl(float angle ,float gyro)
{
    return (int)BANLANCE_KP*angle+BANLANCE_KD*gyro;
}
