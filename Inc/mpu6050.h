#ifndef MPU6050_H_
#define MPU6050_H_

#include "stm32f1xx_hal.h"
#define GYRO_SCALE_ADDR 0x1B
#define ACC_SCALE_ADDR 0x1C
#define MPU_ADDR 0x68
#define ACC_X_ADDR 0x3B
#define ACC_Y_ADDR 0x3D
#define ACC_Z_ADDR 0x3F
#define GYRO_X_ADDR 0x43
#define GYRO_Y_ADDR 0x45
#define GYRO_Z_ADDR 0x47
enum GYRO_SCALE
{
    GYRO_SCALE_250 = 0,
    GYRO_SCALE_500 = 8,
    GYRO_SCALE_1000 = 16,
    GYRO_SCALE_2000 = 24
};
enum ACC_SCALE
{
    ACC_SCALE_2G = 0,
    ACC_SCALE_4G = 8,
    ACC_SCALE_8G = 16,
    ACC_SCALE_16G = 24
};
struct SensorData
{
    int16_t ax, ay, az, gx, gy, gz;
};

extern I2C_HandleTypeDef hi2c1;
HAL_StatusTypeDef MPU_isReady(void);
HAL_StatusTypeDef MPU_SetScale(enum GYRO_SCALE gyroscale, enum ACC_SCALE accscale);
HAL_StatusTypeDef MPU_ReadAx(int16_t * pax);

#endif