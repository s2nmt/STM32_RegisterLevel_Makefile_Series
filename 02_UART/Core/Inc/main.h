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

#define RCC_APB2ENR     (*((volatile unsigned long *)0x40021018))
#define GPIOA_CRH       (*((volatile unsigned long *)0x40010804))
#define USART1_SR       (*((volatile unsigned long *)0x40013800))
#define USART1_DR       (*((volatile unsigned long *)0x40013804))
#define USART1_BRR      (*((volatile unsigned long *)0x40013808))
#define USART1_CR1      (*((volatile unsigned long *)0x4001380C))
#define USART1_CR2      (*((volatile unsigned long *)0x40013810))

#define RCC_APB2ENR_USART1EN (1 << 14)   // Enable clock for USART1
#define RCC_APB2ENR_IOPAEN    (1 << 2)    // Enable clock for GPIOA

// Set PA9 (TX) as Alternate function push-pull, PA10 (RX) as input floating
#define GPIO_CRH_MODE9_0  (1 << 4)
#define GPIO_CRH_MODE9_1  (1 << 5)
#define GPIO_CRH_CNF9_1   (1 << 7)
#define GPIO_CRH_CNF10_0  (1 << 8)
#define GPIO_CRH_CNF10_1  (0 << 9)  // Floating input (reset state)

// USART_SR Register bits
#define USART_SR_TXE      (1 << 7)   // Transmit data register empty

// USART_CR1 Register bits
#define USART_CR1_UE      (1 << 13)  // USART enable
#define USART_CR1_TE      (1 << 3)   // Transmitter enable
#define USART_CR1_RE      (1 << 2)   // Receiver enable#define RCC_APB2ENR     (*((volatile unsigned long *)0x40021018))
#define GPIOA_CRH       (*((volatile unsigned long *)0x40010804))
#define USART1_SR       (*((volatile unsigned long *)0x40013800))
#define USART1_DR       (*((volatile unsigned long *)0x40013804))
#define USART1_BRR      (*((volatile unsigned long *)0x40013808))
#define USART1_CR1      (*((volatile unsigned long *)0x4001380C))
#define USART1_CR2      (*((volatile unsigned long *)0x40013810))

#define RCC_APB2ENR_USART1EN (1 << 14)   // Enable clock for USART1
#define RCC_APB2ENR_IOPAEN    (1 << 2)    // Enable clock for GPIOA

// Set PA9 (TX) as Alternate function push-pull, PA10 (RX) as input floating
#define GPIO_CRH_MODE9_0  (1 << 4)
#define GPIO_CRH_MODE9_1  (1 << 5)
#define GPIO_CRH_CNF9_1   (1 << 7)
#define GPIO_CRH_CNF10_0  (1 << 8)
#define GPIO_CRH_CNF10_1  (0 << 9)  // Floating input (reset state)

// USART_SR Register bits
#define USART_SR_TXE      (1 << 7)   // Transmit data register empty

// USART_CR1 Register bits
#define USART_CR1_UE      (1 << 13)  // USART enable
#define USART_CR1_TE      (1 << 3)   // Transmitter enable
#define USART_CR1_RE      (1 << 2)   // Receiver enable
#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
