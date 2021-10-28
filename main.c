
#include "stm32f407xx.h"

//1: Configure LED pins
void configureLEDpins(void);
//2: Configure Button
void configureButton(void);
//3: Define a delay function
void msDelay(uint32_t msTime);

int main(void)
{
	configureLEDpins();
	configureButton();
	uint8_t count = 0;
	
	while (1)
	{
		while((GPIOA->IDR & 0x01U) == 0);
		msDelay(10);
		count++;
		count = count % 5; // Resets count when it reaches 5
		
		switch(count)
		{
			case(0):
				GPIOD->ODR &= ~(0x0FU << 12U);
				break;
			case(1):
				GPIOD->ODR |= (0x01U << 12U);
				break;
			case(2):
				GPIOD->ODR &= ~ (0x01U << 12U);
				GPIOD->ODR |= (0x01U << 13U);
				break;
			case(3):
				GPIOD->ODR &= ~ (0x01U << 13U);
				GPIOD->ODR |= (0x01U << 14U);
				break;
			case(4):
				GPIOD->ODR &= ~ (0x01U << 14U);
				GPIOD->ODR |= (0x01U << 15U);
				break;
			default:
				GPIOD->ODR &= ~ (0x0FU << 12U);
		}
		
		while((GPIOD->IDR & 0x01U) == 1);
		msDelay(10);
	}				
}

void configureLEDpins(void)
{
	// RCC AHB1 peripheral clock register Page 180 of Reference manual
	RCC->AHB1ENR |= (0x1U << 3U);
	
	// GPIO port mode Register Page 281 of Reference manual
	GPIOD->MODER |= (0x55U << 12*2);
	
	// GPIO output type mode Register Page 281 of Referance manual
	GPIOD->OTYPER &= ~ (0xFU << 12U);
}

void configureButton(void)
{
	// RCC AHB1 peripheral clock register Page 180 of Reference manual
	RCC->AHB1ENR |= (0x1U << 0U);
	
	// GPIO port mode Register Page 281 of Referance manual
	GPIOA->MODER |= (0x0U << 0*2);
}

void msDelay(uint32_t msTime)
{
	for(uint32_t i=0; i<msTime*4000; i++);
}