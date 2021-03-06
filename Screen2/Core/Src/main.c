/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "lcd.h"
#include "keypad.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
  /*
  keypad_init();

  HAL_Delay(10); //Estabilizacion
  uint32_t num_entero=9;
  char str_num_entero[7]; //Guardar como string
  sprintf(str_num_entero, "val=%3d", num_entero); //Conversion de flotante a string
  float num_f=3.7,temporal_frac;
  uint8_t p_entera,p_frac;
  char str_entera[2];
  char str_frac[2];
  p_entera=(uint8_t)num_f; //Parte entera
  temporal_frac=(num_f-p_entera)*100; //.7*100=70
  p_frac=(uint8_t)temporal_frac;
  sprintf(str_entera, "%2d",p_entera);
  sprintf(str_frac, "%2d",p_frac); //Conversion de flotante a string

  lcd_init(); //Inicializa LCD
  lcd_command(DISPLAY_ON_D_OFF_C_ON_B);
  lcd_gotoxy(1,1);
  lcd_puts("Hello World!",12);
  lcd_gotoxy(1,2); //Segunda fila
  lcd_puts(str_num_entero,7);
  lcd_putc(' ');
  lcd_puts(str_entera,2);
  lcd_putc('.');
  lcd_puts(str_frac,2);
  lcd_putc(0xe0); //Beta
  HAL_Delay(5000);
  lcd_clear(); //Borra pantalla */

  keypad_init();
  HAL_Delay(10);
  lcd_init();

  float num_f = 547.801,temporal_frac;
  uint32_t p_entera,p_frac;
  char str_entera[3];
  char str_frac[3];
  p_entera=(uint32_t)num_f; //Parte entera
  temporal_frac=(num_f-p_entera)*1000;
  p_frac=(uint32_t)temporal_frac;
  sprintf(str_entera, "%3d",p_entera);
  sprintf(str_frac, "%3d",p_frac);

  char tecla;

  uint32_t cursor_blink = 1; // 1 = on | 0 = off
  uint32_t cursor = 1;
  lcd_command(CURSOR_ON);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  /*
	  if (tecla=='#')
	  lcd_gotoxy(1,2); //Brinca a segunda linea
	  tecla=keypad_read();
	  if ((tecla!=0) && (tecla!='#')&& (tecla!='*'))
	  lcd_putc(tecla);
	  if (tecla=='*')
	  lcd_command(CURSOR_MOVE_LEFT); */

	  tecla = keypad_read();

	  if (tecla != 0 && tecla != '#' && tecla != '*' && tecla != 'A' && tecla != 'B' && tecla != 'C'
			  && tecla != 'D' && cursor == 1) lcd_putc(tecla);

	  if (tecla == 'B' && cursor == 1) {
		  if (cursor_blink == 1) {
			  lcd_command(CURSOR_BLINK_OFF);
			  cursor_blink = 0;
		  } else {
			  lcd_command(CURSOR_BLINK_ON);
			  cursor_blink = 1;
		  }
	  }

	  if (tecla == 'D') {
		  if (cursor == 1) {
			  lcd_command(CURSOR_OFF);
			  cursor = 0;
		  } else {
			  lcd_command(CURSOR_ON);
			  cursor = 1;
		  }
	  }

	  if (tecla == '*') lcd_command(CURSOR_MOVE_LEFT);

	  if (tecla == '#') lcd_command(CURSOR_MOVE_RIGHT);

	  if (tecla == 'C') lcd_clear();

	  if (tecla == 'A') {
		  lcd_clear();
		  lcd_puts("Hello World :D",14);

		  lcd_gotoxy(1,2);
		  lcd_puts(str_entera,3);
		  lcd_putc('.');
		  lcd_puts(str_frac,3);

		  lcd_putc(' ');
		  lcd_putc(0xc0);
	  }

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSE;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
