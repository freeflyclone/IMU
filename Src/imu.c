#include "main.h"
#include "stm32f4xx_hal.h"

void MyBlink() {
	  HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);
	  HAL_Delay(2);
}

