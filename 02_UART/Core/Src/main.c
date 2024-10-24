#include "main.h"
#include "stdio.h"
void uart1_init(void) {
    // Bước 1: Bật clock cho GPIOA và USART1
    RCC_APB2ENR |= (RCC_APB2ENR_IOPAEN | RCC_APB2ENR_USART1EN);

    // Bước 2: Cấu hình chân PA9 là TX (AF push-pull) và PA10 là RX (input floating)
    GPIOA_CRH &= ~(0xFF << 4);  // Clear bits for PA9 and PA10
    GPIOA_CRH |= (GPIO_CRH_MODE9_0 | GPIO_CRH_MODE9_1 | GPIO_CRH_CNF9_1);  // PA9 (TX)
    GPIOA_CRH |= (GPIO_CRH_CNF10_0);  // PA10 (RX)

    // Bước 3: Cấu hình baudrate cho USART1
    // Ví dụ: Với clock 72 MHz và baudrate 9600, ta cần cấu hình BRR (Baud Rate Register)
    // Công thức: BRR = Fclk / Baudrate
    // 72,000,000 / 9600 = 7500, tương ứng với giá trị 0x1D4C
    USART1_BRR = 0x0341;

    // Bước 4: Kích hoạt UART và cho phép truyền
    USART1_CR1 |= (USART_CR1_UE | USART_CR1_TE | USART_CR1_RE);
}
void uart1_send_char(char c) {
    // Chờ cho đến khi thanh ghi truyền trống (TXE = 1)
    while (!(USART1_SR & USART_SR_TXE));
    
    // Ghi dữ liệu vào thanh ghi dữ liệu (DR) để truyền
    USART1_DR = c;
}

void uart1_send_string(char *str, int len) {
    for (int i = 0; i < len; i++) {
        uart1_send_char(str[i]); // Gửi từng ký tự đến khi hết độ dài
    }
}

int _write(int file, char *ptr, int len)
{
    uart1_send_string( ptr,len);
    return len;
}


int main(void) {
    uart1_init();  // Khởi tạo UART1

    while (1) {
        printf("hello world %.2f\r\n",1.02);
        for (volatile int i = 0; i < 1000000; i++);  // Đợi một lúc để tránh truyền quá nhanh
    }
}