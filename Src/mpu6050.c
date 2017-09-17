#include "mpu6050.h"

HAL_StatusTypeDef MPU_isReady()
{
    return HAL_I2C_IsDeviceReady(&hi2c1, MPU_ADDR, 3, 1000);
}

HAL_StatusTypeDef MPU_SetScale(enum GYRO_SCALE gyroscale, enum ACC_SCALE accscale)
{
    uint8_t buffer[4] = {GYRO_SCALE_ADDR, gyroscale, ACC_SCALE_ADDR, accscale};
    return HAL_I2C_Master_Transmit(&hi2c1, MPU_ADDR, buffer, 4, 5);
}
HAL_StatusTypeDef MPU_ReadAx(int16_t * pax)
{
    uint8_t buffer = ACC_X_ADDR + 1;
    HAL_I2C_Master_Transmit(&hi2c1, MPU_ADDR, &buffer, 1, 5);
    HAL_I2C_Master_Receive(&hi2c1, MPU_ADDR,(uint8_t *) pax, 1, 5);
    buffer--;
    HAL_I2C_Master_Transmit(&hi2c1, MPU_ADDR, &buffer, 1, 5);
    return HAL_I2C_Master_Receive(&hi2c1, MPU_ADDR, 1 + (uint8_t *) pax, 1, 5);
}