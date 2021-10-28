#include "stm32f407xx.h"
#include "SysTick.h"
#include "Led.h"

int main(void)
{
	configureLEDpins();
	Init_SysTick();
	
	while(1)
	{
		Toggle_Red_LED();
		Toggle_Blue_LED();
		
		Delay_ms(1000);
		
		Toggle_Red_LED();
		Toggle_Blue_LED();
		
		Delay_ms(1000);
	}
	
}
