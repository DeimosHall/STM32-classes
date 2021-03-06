#include "Led.h"
#include "stm32f1xx.h"

void my_delay(retardo tiempo)
{
HAL_GPIO_TogglePin(LED_PORT,LED_PIN);
HAL_Delay(tiempo);
}

//Inicializa y configura el puerto y pin
void LED_init(void){
GPIO_InitTypeDef GPIO_InitStruct= {0};;
/* GPIO Ports Clock Enable */
__HAL_RCC_GPIOC_CLK_ENABLE();
HAL_GPIO_WritePin(LED_PORT, LED_PIN, GPIO_PIN_RESET);

GPIO_InitStruct.Pin = LED_PIN;
GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
GPIO_InitStruct.Pull = GPIO_NOPULL;
GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
HAL_GPIO_Init(LED_PORT, &GPIO_InitStruct);
}
