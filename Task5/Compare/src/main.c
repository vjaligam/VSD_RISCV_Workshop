#include <ch32v00x.h>
#include <debug.h>

#define CMP_GPIO_PORT GPIOD
// This is L1-GPIO LED on the board which is PD6
#define CMP_GPIO_PIN GPIO_Pin_6
#define CMP_CLOCK_ENABLE RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE)

void NMI_Handler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void HardFault_Handler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void Delay_Init(void);
void Delay_Ms(uint32_t n);

void compare(uint8_t a, uint8_t b) {
    
    GPIO_ResetBits(CMP_GPIO_PORT, CMP_GPIO_PIN);

    if (a > b) {
        GPIO_SetBits(CMP_GPIO_PORT, CMP_GPIO_PIN);
    } else if (a == b) {
        GPIO_ResetBits(CMP_GPIO_PORT, CMP_GPIO_PIN);
    } else {
        GPIO_SetBits(CMP_GPIO_PORT, CMP_GPIO_PIN);
    }  
    
} 
int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	SystemCoreClockUpdate();
	Delay_Init();

	GPIO_InitTypeDef GPIO_InitStructure = {0};

	CMP_CLOCK_ENABLE;
	GPIO_InitStructure.GPIO_Pin = CMP_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(CMP_GPIO_PORT, &GPIO_InitStructure);

	// Loop for both A and B 
     for (uint8_t a = 0; a <= 10; a++) {
        for (uint8_t b = 0; b <= 10; b++) {
            compare(a, b);
            Delay_Ms(1000);
        }
    }

void NMI_Handler(void) {}
void HardFault_Handler(void)
{
	while (1)
	{
	}
}
