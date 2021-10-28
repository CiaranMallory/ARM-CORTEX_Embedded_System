#include <stdint.h>
#include "stm32f407xx.h"
#include "SysTick.h"

volatile uint32_t TimingDelay;
extern uint32_t SystemCoreClock;

void Init_SysTick(void)
{
	SysTick_Config(SystemCoreClock/1000);
}

void SysTick_Handler(void)
{
	if(TimingDelay != 0)
	{
		TimingDelay--;
	}
}

void Delay_ms(uint32_t time)
{
	TimingDelay = time;
	while(TimingDelay != 0);
}