#include "main.h"
#include "stm32f4xx_hal.h"

extern I2C_HandleTypeDef hi2c1;
uint16_t addr = 0xD6;
uint8_t subAddr = 0x20;
uint8_t data[16];
uint8_t id;
HAL_StatusTypeDef status;

void MyBlink() {
	  HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);
	  HAL_Delay(2);
}

uint8_t MyI2CWrite() {
	MyBlink();

	while ( (status = HAL_I2C_Master_Transmit(&hi2c1, addr, &subAddr, 1, 20)) != HAL_OK)
		HAL_Delay(1);

	status = HAL_I2C_Master_Receive(&hi2c1, addr+1, data, 1, 20);

	id = data[0];
	if (id == 0xD4)
		return id;
	else
		return 0;
}
