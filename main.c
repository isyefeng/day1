/*****************************************************
*   实现点亮第一颗流水灯
******************************************************/
#if 0
#include"stm32f10x.h"

int main(void)
{
	
		//开gpiob时钟
	*(unsigned int *)0x40021018 |= (1<<3);
	
		//配置io为输出模式
	*(unsigned int *)0x40010c00 |= (1<<(4*0));
	
		//控制pb0输出低电平
	*(unsigned int *)0x40010c0c &= ~(1<<0);
}

#endif

/*****************************************************
*   不同颜色闪烁
******************************************************/

#include "stm32f10x.h"

void Delay(unsigned int TIME)
{
	while(TIME--);
}

void LED_ON_G()
{
		//开gpiob时钟
	*(unsigned int *)0x40021018 |= (1<<3);
	
		//配置io为输出模式
	*(unsigned int *)0x40010c00 |= (1<<(4*0));
	
		//控制pb0输出低电平
	*(unsigned int *)0x40010c0c &= ~(1<<0);
}

void LED_ON_B()
{
	//初始化时钟
	*(unsigned int *)0x40021018 |= (1<<3);
	
	//配置io模式
	*(unsigned int *)0X40010C00 |= (1<<(4*1));
	
	//设置引脚
	*(unsigned int *)0X40010C0c  &= ~(1<<1);
}

void LED_ON_R()
{
	//初始化时钟
	*(unsigned int *)0x40021018 |= (1<<3);
	
	//配置io模式
	*(unsigned int *)0X40010C00 |= (1<<(4*5));
	
	//设置引脚
	*(unsigned int *)0X40010C0c  &= ~(1<<5);
}

void LED_OFF()
{
	//初始化时钟
	*(unsigned int *)0x40021018 |= (1<<3);
	
	//配置io模式
	*(unsigned int *)0X40010C00 |= (1<<(4*5));
	
	//设置引脚
	*(unsigned int *)0X40010C0c |=0xffff; 
}

int main(void)
{
	while(1)
	{
		LED_OFF();
		LED_ON_G();
		Delay(0xffff);
		LED_OFF();
		LED_ON_R();
		Delay(0xffff);
		LED_OFF();
		LED_ON_B();
		Delay(0xffff);
	}
}

void SystemInit(void)
{
	
}
