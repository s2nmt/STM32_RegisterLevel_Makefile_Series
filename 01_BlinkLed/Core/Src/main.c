// Định nghĩa các địa chỉ của thanh ghi RCC và GPIO
#define RCC_APB2ENR     (*((volatile unsigned long *)0x40021018)) // Địa chỉ của RCC APB2ENR
#define GPIOC_CRH       (*((volatile unsigned long *)0x40011004)) // Địa chỉ của GPIOC CRH
#define GPIOC_ODR       (*((volatile unsigned long *)0x4001100C)) // Địa chỉ của GPIOC ODR

// Định nghĩa cho các bit trong thanh ghi
#define RCC_IOPCEN      (1 << 4)   // Bit 4 cho phép clock GPIOC
#define GPIO_MODE13_0   (1 << 20)  // MODE13[1:0] = 01 (Output mode, max speed 10 MHz)
#define GPIO_MODE13_1   (1 << 21)  // MODE13[1:0] = 10 (Output mode, max speed 2 MHz)
#define GPIO_CNF13_0    (1 << 22)  // CNF13[1:0] = 00 (General purpose output push-pull)

// Hàm tạo độ trễ đơn giản
void delay_ms(unsigned long ms) {
    for (unsigned long i = 0; i < ms * 1000; i++) {
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
        GPIOC_ODR &= ~(1 << 13); // Bật LED (PC13 = 0, LED sáng vì mạch đảo chiều)
        delay_ms(500);           // Đợi 500ms
        GPIOC_ODR |= (1 << 13);  // Tắt LED (PC13 = 1, LED tắt)
        delay_ms(500);           // Đợi 500ms
    }
}
