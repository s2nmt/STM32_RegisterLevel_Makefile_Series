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

// Định nghĩa các địa chỉ của thanh ghi RCC và GPIO
#define RCC_APB2ENR     (*((volatile unsigned long *)0x40021018)) // Địa chỉ của RCC APB2ENR
#define GPIOC_CRH       (*((volatile unsigned long *)0x40011004)) // Địa chỉ của GPIOC CRH
#define GPIOC_ODR       (*((volatile unsigned long *)0x4001100C)) // Địa chỉ của GPIOC ODR

// Định nghĩa cho các bit trong thanh ghi
#define RCC_IOPCEN      (1 << 4)   // Bit 4 cho phép clock GPIOC
#define GPIO_MODE13_0   (1 << 20)  // MODE13[1:0] = 01 (Output mode, max speed 10 MHz)
#define GPIO_MODE13_1   (1 << 21)  // MODE13[1:0] = 10 (Output mode, max speed 2 MHz)
#define GPIO_CNF13_0    (1 << 22)  // CNF13[1:0] = 00 (General purpose output push-pull)

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
