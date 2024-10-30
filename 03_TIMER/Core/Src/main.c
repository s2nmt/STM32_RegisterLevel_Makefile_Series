#include "main.h"
#include <stdint.h>
void Timer2_Init(void) {
    RCC_APB1ENR |= (1 << 0); 
    TIM2_PSC = 8000 - 1;  
    TIM2_ARR = 1000 - 1;  

    TIM2_CNT = 0;
    TIM2_CR1 |= (1 << 0); 
}
void delay(uint32_t ms) {
    for (uint32_t i = 0; i < ms; i++) {
        TIM2_CNT = 0;  
        while (!(TIM2_SR & (1 << 0)));
        TIM2_SR &= ~(1 << 0); 
    }
}
int main(void) {
    // enable clock for GPIOC
    RCC_APB2ENR |= (1 << 4); // Bit 4 of RCC_APB2ENR is IOPCEN for GPIOC

    // Config PC13 make output push-pull
    GPIOC_CRH &= ~(0xF << 20);  // clear bits old config of PC13
    GPIOC_CRH |= (0x1 << 20);   // MODE13[1:0] = 01 (output 10MHz), CNF13[1:0] = 00 (push-pull)

    // init Timer2
    Timer2_Init();

    // Bink led
    while (1) {
        GPIOC_ODR &= ~(1 << 13); 
        delay(1);          
        GPIOC_ODR |= (1 << 13);  
        delay(1);           
    }
}
