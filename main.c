/*****************************************************
*   ʵ�ֵ�����һ����ˮ��
******************************************************/
#if 0
#include"stm32f10x.h"

int main(void)
{
	
		//��gpiobʱ��
	*(unsigned int *)0x40021018 |= (1<<3);
	
		//����ioΪ���ģʽ
	*(unsigned int *)0x40010c00 |= (1<<(4*0));
	
		//����pb0����͵�ƽ
	*(unsigned int *)0x40010c0c &= ~(1<<0);
}

#endif

/*****************************************************
*   ��ͬ��ɫ��˸
******************************************************/

#include "stm32f10x.h"

void Delay(unsigned int TIME)
{
	while(TIME--);
}

void LED_ON_G()
{
		//��gpiobʱ��
	*(unsigned int *)0x40021018 |= (1<<3);
	
		//����ioΪ���ģʽ
	*(unsigned int *)0x40010c00 |= (1<<(4*0));
	
		//����pb0����͵�ƽ
	*(unsigned int *)0x40010c0c &= ~(1<<0);
}

void LED_ON_B()
{
	//��ʼ��ʱ��
	*(unsigned int *)0x40021018 |= (1<<3);
	
	//����ioģʽ
	*(unsigned int *)0X40010C00 |= (1<<(4*1));
	
	//��������
	*(unsigned int *)0X40010C0c  &= ~(1<<1);
}

void LED_ON_R()
{
	//��ʼ��ʱ��
	*(unsigned int *)0x40021018 |= (1<<3);
	
	//����ioģʽ
	*(unsigned int *)0X40010C00 |= (1<<(4*5));
	
	//��������
	*(unsigned int *)0X40010C0c  &= ~(1<<5);
}

void LED_OFF()
{
	//��ʼ��ʱ��
	*(unsigned int *)0x40021018 |= (1<<3);
	
	//����ioģʽ
	*(unsigned int *)0X40010C00 |= (1<<(4*5));
	
	//��������
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
