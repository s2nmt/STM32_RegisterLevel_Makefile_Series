#include "main.h"

// Hàm tạo độ trễ đơn giản
void delay_ms(unsigned long ms) {
    for (unsigned long i = 0; i < ms*1000; i++) {
        __asm("nop"); 
    }
}

int main(void) {
    // Bước 1: Bật clock cho GPIOC (bit IOPCEN trong thanh ghi RCC_APB2ENR)
    RCC_APB2ENR |= RCC_IOPCEN;

    // Bước 2: Cấu hình chân PC13 làm output (push-pull) tốc độ 2 MHz
    GPIOC_CRH &= ~(GPIO_MODE13_0 | GPIO_MODE13_1 | GPIO_CNF13_0); // Xóa các bit MODE và CNF cho chân 13
    GPIOC_CRH |= GPIO_MODE13_1; // Đặt MODE13 thành output với tốc độ 2 MHz

    // Bước 3: Vòng lặp chính - nhấp nháy LED
    while (1) {
        GPIOC_ODR &= ~(1 << 13); 
        delay_ms(1000);           
        GPIOC_ODR |= (1 << 13); 
        delay_ms(1000);          
    }
}
