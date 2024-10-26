#include <ch32v00x.h>
#include <debug.h>

#define BLINKY_GPIO_PORT GPIOD
#define BLINKY_GPIO_PIN GPIO_Pin_6
#define BLINKY_CLOCK_ENABLE RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE)

void NMI_Handler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void HardFault_Handler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void Delay_Init(void);
void Delay_Ms(uint32_t n);

void compare_2bit(uint8_t a, uint8_t b) {
    // Clear all LEDs
    GPIO_ResetBits(BLINKY_GPIO_PORT, BLINKY_GPIO_PIN);

    if (a > b) {
      // Light up LED1 if a > b
        GPIO_SetBits(BLINKY_GPIO_PORT, BLINKY_GPIO_PIN);
    //} else if (a == b) {
        // Light up LED2 if a == b
    //    GPIO_SetBits(BLINKY_GPIO_PORT, BLINKY_GPIO_PIN);
    } else {
        // Light up LED3 if a < b
        GPIO_ResetBits(BLINKY_GPIO_PORT, BLINKY_GPIO_PIN);
    }  
    
} 


int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	SystemCoreClockUpdate();
	Delay_Init();

	GPIO_InitTypeDef GPIO_InitStructure = {0};

	BLINKY_CLOCK_ENABLE;
	GPIO_InitStructure.GPIO_Pin = BLINKY_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(BLINKY_GPIO_PORT, &GPIO_InitStructure);

	// Main loop to iterate over all possible 2-bit numbers  
     for (uint8_t a = 0; a <= 3; a++) {
        for (uint8_t b = 0; b <= 3; b++) {
            compare_2bit(a, b);
            Delay_Ms(5000); // Delay for visualization
        }
    }
//uint8_t ledState = 0;
//	#while (1)
//	{
//		GPIO_WriteBit(BLINKY_GPIO_PORT, BLINKY_GPIO_PIN, ledState);
//		ledState ^= 1; // invert for the next run
//		Delay_Ms(5000);
//	}
}

void NMI_Handler(void) {}
void HardFault_Handler(void)
{
	while (1)
	{
	}
}
