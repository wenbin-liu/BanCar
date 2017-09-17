#include "mpu6050.h"
static HAL_StatusTypeDef MPU_WriteReg(uint8_t regAddr,uint8_t data)
{
    uint8_t buffer[2]={regAddr,data};
    return HAL_I2C_Master_Transmit(&hi2c1,MPU_ADDR,buffer,2,5);
}
static HAL_StatusTypeDef MPU_ReadReg(uint8_t regAddr,uint8_t *data)
{
    HAL_I2C_Master_Transmit(&hi2c1,MPU_ADDR,&regAddr,1,5);
    return HAL_I2C_Master_Receive(&hi2c1,MPU_ADDR,data,1,5);
}
HAL_StatusTypeDef MPU_WakeUp()
{
    return MPU_WriteReg(MPU_PWR_MGMT1_ADDR,MPU_PWR_MGMT1_WAKEUP);
}

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
    MPU_ReadReg(ACC_X_ADDR+1,(uint8_t *)pax);
    return MPU_ReadReg(ACC_X_ADDR,(uint8_t *) pax + 1);
}
HAL_StatusTypeDef MPU_ReadAy(int16_t * pay)
{
    MPU_ReadReg(ACC_Y_ADDR+1,(uint8_t *)pay);
    return MPU_ReadReg(ACC_Y_ADDR,(uint8_t *) pay + 1);
}
HAL_StatusTypeDef MPU_ReadAz(int16_t * paz)
{
    MPU_ReadReg(ACC_Z_ADDR+1,(uint8_t *)paz);
    return MPU_ReadReg(ACC_Z_ADDR,(uint8_t *) paz + 1);
}
HAL_StatusTypeDef MPU_ReadGx(int16_t * pgx)
{
    MPU_ReadReg(GYRO_X_ADDR+1,(uint8_t *)pgx);
    return MPU_ReadReg(GYRO_X_ADDR,(uint8_t *) pgx + 1);
}
HAL_StatusTypeDef MPU_ReadGy(int16_t * pgy)
{
    MPU_ReadReg(GYRO_Y_ADDR+1,(uint8_t *)pgy);
    return MPU_ReadReg(GYRO_Y_ADDR,(uint8_t *) pgy + 1);
}
HAL_StatusTypeDef MPU_ReadGz(int16_t * pgz)
{
    MPU_ReadReg(GYRO_Z_ADDR+1,(uint8_t *)pgz);
    return MPU_ReadReg(GYRO_Z_ADDR,(uint8_t *) pgz + 1);
}
