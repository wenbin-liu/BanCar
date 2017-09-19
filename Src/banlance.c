#include "math.h"
#include "stdint.h"
#include "mpu6050.h"
#define GYRO_SCALE 500
#define GYRO_BIASE (-67)
void getAngle(double *angle,double *gyro)
{
    int16_t ax,az,gy;
    MPU_ReadAx(&ax);
    MPU_ReadAz(&az);
    MPU_ReadGy(&gy);
    *gyro=(gy-GYRO_BIASE)*GYRO_SCALE/32767.0;
    *angle=-57.296*atan((double)ax/az);
    return;
}
