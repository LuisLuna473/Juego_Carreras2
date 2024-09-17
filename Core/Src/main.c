/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
uint8_t contador = 0;
uint8_t start = 0;
uint8_t jug1 = 0;
uint8_t jug2 = 0;
uint8_t winner1 = 0;
uint8_t winner2 = 0;
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

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  if(HAL_GPIO_ReadPin(BTN_GPIO_Port, BTN_Pin)== 0){
		  contador = contador + 1;

	  }


	  if(contador == 1){
		  HAL_GPIO_WritePin(red_GPIO_Port, red_Pin, GPIO_PIN_SET);
		  HAL_Delay(1000);
		  HAL_GPIO_WritePin(yellow_GPIO_Port, yellow_Pin, GPIO_PIN_SET);
		  HAL_Delay(1000);
		  HAL_GPIO_WritePin(green_GPIO_Port, green_Pin, GPIO_PIN_SET);
		  HAL_Delay(1000);
		  contador = 0;
		  start = 1;
		  jug1 = 0;
		  jug2 = 0;
		  winner1 = 0;
		  winner2 = 0;
	  }else if (contador == 0){
		  HAL_GPIO_WritePin(red_GPIO_Port, red_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(yellow_GPIO_Port, yellow_Pin, GPIO_PIN_RESET);

	  }
	  if(start == 1){
		  if(HAL_GPIO_ReadPin(Jug1_GPIO_Port, Jug1_Pin)== 0){
			  jug1++;
		  }
		  if(HAL_GPIO_ReadPin(Jug2_GPIO_Port, Jug2_Pin)== 0){
			  //jug2 = jug2 + 1;
			  jug2++;
		  }
	  }

	  switch(jug1){
	  	  case (0): //0
	  			  HAL_GPIO_WritePin(N1_GPIO_Port, N1_Pin, GPIO_PIN_RESET);
	  	  	  	  HAL_GPIO_WritePin(N2_GPIO_Port, N2_Pin, GPIO_PIN_RESET);
	  	  	  	  HAL_GPIO_WritePin(N3_GPIO_Port, N3_Pin, GPIO_PIN_RESET);
	  	  	  	  HAL_GPIO_WritePin(N4_GPIO_Port, N4_Pin, GPIO_PIN_RESET);
	  	  	      HAL_GPIO_WritePin(N5_GPIO_Port, N5_Pin, GPIO_PIN_RESET);
	  	  	      HAL_GPIO_WritePin(N6_GPIO_Port, N6_Pin, GPIO_PIN_RESET);
	  	  	  	  HAL_GPIO_WritePin(win1_GPIO_Port, win1_Pin, GPIO_PIN_RESET);
	  	  	  	  HAL_GPIO_WritePin(N7_GPIO_Port, N7_Pin, GPIO_PIN_RESET);
				  break;
		  case(1): //1
		  	  	  HAL_GPIO_WritePin(N1_GPIO_Port, N1_Pin, GPIO_PIN_SET);
		  	  	  HAL_Delay(120);
		  	  	  break;
		  case(2): //2
				  HAL_GPIO_WritePin(N1_GPIO_Port, N1_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(N2_GPIO_Port, N2_Pin, GPIO_PIN_SET);
				  HAL_Delay(120);
				  break;
		  case(3): //4
		    	  HAL_GPIO_WritePin(N2_GPIO_Port, N2_Pin, GPIO_PIN_RESET);
		          HAL_GPIO_WritePin(N3_GPIO_Port, N3_Pin, GPIO_PIN_SET);
		          HAL_Delay(120);
				  break;
		  case(4): //8
				  HAL_GPIO_WritePin(N3_GPIO_Port, N3_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(N4_GPIO_Port, N4_Pin, GPIO_PIN_SET);
				  HAL_Delay(120);
				  break;
		  case(5): //16
				  HAL_GPIO_WritePin(N4_GPIO_Port, N4_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(N5_GPIO_Port, N5_Pin, GPIO_PIN_SET);
				  HAL_Delay(120);
				  break;
		  case(6): //32
		          HAL_GPIO_WritePin(N5_GPIO_Port, N5_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(N6_GPIO_Port, N6_Pin, GPIO_PIN_SET);
				  HAL_Delay(120);
				  break;
		  case(7): //64
				  HAL_GPIO_WritePin(N6_GPIO_Port, N6_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(N7_GPIO_Port, N7_Pin, GPIO_PIN_SET);
				  HAL_Delay(120);
				  break;
		  case(8): //128
				  HAL_GPIO_WritePin(N6_GPIO_Port, N6_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(N7_GPIO_Port, N7_Pin, GPIO_PIN_SET);
				  winner1 = 1;
				  HAL_Delay(120);
				  break;
		  default:
			  break;
	  }
	  switch(jug2){
	  	  	  case (0): //0
	  	  			  HAL_GPIO_WritePin(L1_GPIO_Port, L1_Pin, GPIO_PIN_RESET);
	  	  	  	  	  HAL_GPIO_WritePin(L2_GPIO_Port, L2_Pin, GPIO_PIN_RESET);
	  	  	  	  	  HAL_GPIO_WritePin(L3_GPIO_Port, L3_Pin, GPIO_PIN_RESET);
	  	  	  	  	  HAL_GPIO_WritePin(L4_GPIO_Port, L4_Pin, GPIO_PIN_RESET);
	  	  	  	      HAL_GPIO_WritePin(L5_GPIO_Port, L5_Pin, GPIO_PIN_RESET);
	  	  	  	      HAL_GPIO_WritePin(L6_GPIO_Port, L6_Pin, GPIO_PIN_RESET);
	  	  	  	  	  HAL_GPIO_WritePin(win2_GPIO_Port, win2_Pin, GPIO_PIN_RESET);
	  	  	  	  	  HAL_GPIO_WritePin(L7_GPIO_Port, L7_Pin, GPIO_PIN_RESET);
	  				  break;
	  		  case(1): //1
	  		  	  	  HAL_GPIO_WritePin(L1_GPIO_Port, L1_Pin, GPIO_PIN_SET);
	  		  	  	  HAL_Delay(100);
	  		  	  	  break;
	  		  case(2): //2
	  				  HAL_GPIO_WritePin(L1_GPIO_Port, L1_Pin, GPIO_PIN_RESET);
	  				  HAL_GPIO_WritePin(L2_GPIO_Port, L2_Pin, GPIO_PIN_SET);
	  				  HAL_Delay(100);
	  				  break;
	  		  case(3): //4
	  		    	  HAL_GPIO_WritePin(L2_GPIO_Port, L2_Pin, GPIO_PIN_RESET);
	  		          HAL_GPIO_WritePin(L3_GPIO_Port, L3_Pin, GPIO_PIN_SET);
	  		          HAL_Delay(100);
	  				  break;
	  		  case(4): //8
	  				  HAL_GPIO_WritePin(L3_GPIO_Port, L3_Pin, GPIO_PIN_RESET);
	  				  HAL_GPIO_WritePin(L4_GPIO_Port, L4_Pin, GPIO_PIN_SET);
	  				  HAL_Delay(100);
	  				  break;
	  		  case(5): //16
	  				  HAL_GPIO_WritePin(L4_GPIO_Port, L4_Pin, GPIO_PIN_RESET);
	  				  HAL_GPIO_WritePin(L5_GPIO_Port, L5_Pin, GPIO_PIN_SET);
	  				  HAL_Delay(100);
	  				  break;
	  		  case(6): //32
	  		          HAL_GPIO_WritePin(L5_GPIO_Port, L5_Pin, GPIO_PIN_RESET);
	  				  HAL_GPIO_WritePin(L6_GPIO_Port, L6_Pin, GPIO_PIN_SET);
	  				  HAL_Delay(100);
	  				  break;
	  		  case(7): //64
	  				  HAL_GPIO_WritePin(L6_GPIO_Port, L6_Pin, GPIO_PIN_RESET);
	  				  HAL_GPIO_WritePin(L7_GPIO_Port, L7_Pin, GPIO_PIN_SET);
	  				  HAL_Delay(100);
	  				  break;
	  		  case(8): //128
	  				  HAL_GPIO_WritePin(L6_GPIO_Port, L6_Pin, GPIO_PIN_RESET);
	  				  HAL_GPIO_WritePin(L7_GPIO_Port, L7_Pin, GPIO_PIN_SET);
	  				  winner2 = 1;
	  				  HAL_Delay(100);
	  				  break;
	  		  default:
	  			  break;
	  	  }
	  if(winner2 == 1){
		  HAL_GPIO_WritePin(win2_GPIO_Port, win2_Pin, GPIO_PIN_SET);
		  start = 0;
	  }
	  if(winner1 == 1){
		  HAL_GPIO_WritePin(win1_GPIO_Port, win1_Pin, GPIO_PIN_SET);
		  start = 0;
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

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
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
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(L1_GPIO_Port, L1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, N1_Pin|N2_Pin|N3_Pin|N4_Pin
                          |win1_Pin|N7_Pin|N6_Pin|L5_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, red_Pin|yellow_Pin|green_Pin|LED_Pin
                          |L2_Pin|L7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, N5_Pin|L3_Pin|L4_Pin|L6_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(win2_GPIO_Port, win2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : BTN_Pin */
  GPIO_InitStruct.Pin = BTN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(BTN_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : L1_Pin */
  GPIO_InitStruct.Pin = L1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(L1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : N1_Pin N2_Pin N3_Pin N4_Pin
                           win1_Pin N7_Pin N6_Pin L5_Pin */
  GPIO_InitStruct.Pin = N1_Pin|N2_Pin|N3_Pin|N4_Pin
                          |win1_Pin|N7_Pin|N6_Pin|L5_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : red_Pin yellow_Pin green_Pin LED_Pin
                           L2_Pin L7_Pin */
  GPIO_InitStruct.Pin = red_Pin|yellow_Pin|green_Pin|LED_Pin
                          |L2_Pin|L7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : N5_Pin L3_Pin L4_Pin L6_Pin */
  GPIO_InitStruct.Pin = N5_Pin|L3_Pin|L4_Pin|L6_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : Jug1_Pin Jug2_Pin */
  GPIO_InitStruct.Pin = Jug1_Pin|Jug2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : win2_Pin */
  GPIO_InitStruct.Pin = win2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(win2_GPIO_Port, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
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
