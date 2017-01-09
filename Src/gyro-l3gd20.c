#include <gyro-l3gd20.h>

extern I2C_HandleTypeDef hi2c1;

static uint16_t gyroWrite = 0xD6;
static uint16_t gyroRead = 0xD7;
static uint8_t gyroData[16];
static HAL_StatusTypeDef status;


uint8_t GyroInit() {
	gyroData[0] = CTRL_REG1;
	gyroData[1] = 0xF;

	while ( (status = HAL_I2C_Master_Transmit(&hi2c1, gyroWrite, gyroData, 2, 20)) != HAL_OK)
		HAL_Delay(1);

	while ( (status = HAL_I2C_Master_Receive(&hi2c1, gyroRead, gyroData, 1, 20)) != HAL_OK)
		HAL_Delay(1);

	if (gyroData[0] != 0xF)
		return HAL_ERROR;

	return HAL_OK;
}

void GyroRead() {
	MyBlink();

	gyroData[0] = 0x28;

	while ( (status = HAL_I2C_Master_Transmit(&hi2c1, gyroWrite, gyroData, 1, 20)) != HAL_OK)
		HAL_Delay(1);

	while ( (status = HAL_I2C_Master_Receive(&hi2c1, gyroRead, gyroData, 1, 20)) != HAL_OK)
		HAL_Delay(1);

}
