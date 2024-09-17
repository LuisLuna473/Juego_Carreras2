/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BTN_Pin GPIO_PIN_13
#define BTN_GPIO_Port GPIOC
#define L1_Pin GPIO_PIN_1
#define L1_GPIO_Port GPIOH
#define N1_Pin GPIO_PIN_0
#define N1_GPIO_Port GPIOC
#define N2_Pin GPIO_PIN_1
#define N2_GPIO_Port GPIOC
#define N3_Pin GPIO_PIN_2
#define N3_GPIO_Port GPIOC
#define N4_Pin GPIO_PIN_3
#define N4_GPIO_Port GPIOC
#define red_Pin GPIO_PIN_0
#define red_GPIO_Port GPIOA
#define yellow_Pin GPIO_PIN_1
#define yellow_GPIO_Port GPIOA
#define green_Pin GPIO_PIN_4
#define green_GPIO_Port GPIOA
#define LED_Pin GPIO_PIN_5
#define LED_GPIO_Port GPIOA
#define win1_Pin GPIO_PIN_5
#define win1_GPIO_Port GPIOC
#define N5_Pin GPIO_PIN_0
#define N5_GPIO_Port GPIOB
#define L3_Pin GPIO_PIN_10
#define L3_GPIO_Port GPIOB
#define N7_Pin GPIO_PIN_6
#define N7_GPIO_Port GPIOC
#define N6_Pin GPIO_PIN_8
#define N6_GPIO_Port GPIOC
#define L2_Pin GPIO_PIN_8
#define L2_GPIO_Port GPIOA
#define L7_Pin GPIO_PIN_15
#define L7_GPIO_Port GPIOA
#define Jug1_Pin GPIO_PIN_10
#define Jug1_GPIO_Port GPIOC
#define L5_Pin GPIO_PIN_11
#define L5_GPIO_Port GPIOC
#define Jug2_Pin GPIO_PIN_12
#define Jug2_GPIO_Port GPIOC
#define win2_Pin GPIO_PIN_2
#define win2_GPIO_Port GPIOD
#define L4_Pin GPIO_PIN_4
#define L4_GPIO_Port GPIOB
#define L6_Pin GPIO_PIN_7
#define L6_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
