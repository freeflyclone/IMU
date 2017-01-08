#include "main.h"
#include "stm32f4xx_hal.h"

extern I2C_HandleTypeDef hi2c1;

uint16_t gyroWrite = 0xD6;
uint16_t gyroRead = 0xD7;
uint8_t gyroData[16];
uint8_t gyroIdReg;
uint8_t subAddr = 0x20;
HAL_StatusTypeDef status;

void MyBlink() {
	  HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);
	  HAL_Delay(2);
}

uint8_t GyroInit() {
	MyBlink();

	while ( (status = HAL_I2C_Master_Transmit(&hi2c1, gyroWrite, &subAddr, 1, 20)) != HAL_OK)
		HAL_Delay(1);

	while ( (status = HAL_I2C_Master_Receive(&hi2c1, gyroRead, gyroData, 1, 20)) != HAL_OK)
		HAL_Delay(1);

	gyroIdReg = gyroData[0];
	if (gyroIdReg == 0xD4)
		return gyroIdReg;
	else
		return 0;
}
