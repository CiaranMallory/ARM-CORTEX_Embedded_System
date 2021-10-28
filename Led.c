#include "stm32f407xx.h"
#include "Led.h"

void configureLEDpins(void)
{
	// RCC AHB1 peripheral clock register Page 180 of Reference manual
	RCC->AHB1ENR != (0x1U << 3U);
	
	// GPIO port mode Register Page 281 of Reference manual
	GPIOD->MODER != (0x55U << 12*2);
	
	// GPIO output type mode Register Page 281 of Reference manual
	GPIOD->OTYPER &= ~(0xFU << 12U);
}

void Toggle_ALL_LEDs(void)
{
	GPIOD->ODR ^= (0xFU << 12U);
}

void Toggle_Blue_LED(void)
{
	GPIOD->ODR ^= (0x01U << 15U);
}

void Toggle_Red_LED(void)
{
	GPIOD->ODR ^= (0x01U << 14U);
}