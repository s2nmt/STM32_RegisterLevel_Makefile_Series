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

#define RCC_APB2ENR     (*((volatile unsigned long *)0x40021018)) // Thanh ghi clock APB2
#define GPIOC_CRH       (*((volatile unsigned long *)0x40011004)) // Thanh ghi cấu hình chân PC13
#define GPIOC_ODR       (*((volatile unsigned long *)0x4001100C)) // Thanh ghi xuất dữ liệu của GPIOC
#define RCC_APB1ENR     (*((volatile unsigned long *)0x4002101C)) // Thanh ghi clock APB1
#define TIM2_PSC        (*((volatile unsigned long *)0x40000028)) // Thanh ghi Prescaler của TIM2
#define TIM2_ARR        (*((volatile unsigned long *)0x4000002C)) // Thanh ghi Auto-Reload của TIM2
#define TIM2_CNT        (*((volatile unsigned long *)0x40000024)) // Thanh ghi đếm của TIM2
#define TIM2_CR1        (*((volatile unsigned long *)0x40000000)) // Thanh ghi điều khiển của TIM2
#define TIM2_SR         (*((volatile unsigned long *)0x40000010)) // Thanh ghi trạng thái của TIM2

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
