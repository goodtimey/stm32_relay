/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   ����led
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:Ұ�� ָ���� STM32 ������ 
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :http://fire-stm32.taobao.com
  *
  ******************************************************************************
  */ 
	
#include "stm32f10x.h"
#include "./beep/bsp_beep.h"
#include "sys.h"
#include "usart.h"
#include "delay.h"
#include "bsp_led.h"   
#include "./key/bsp_key.h"  
#include "oled0561.h"
#include "dht11.h"
#include "iwdg.h"
#include "wwdg.h"
#include "relay.h"
/**
  * @brief  ������
  * @param  ��  
  * @retval ��
  */
int main(void)
{	
	
   
	//��ʼ������
	delay_ms(500); //�ϵ�ʱ�ȴ�������������
	RCC_Configuration(); //ʱ������
	LED_GPIO_Config();
	Key_GPIO_Config();
	
	I2C_Configuration();//I2C��ʼ��
	
	RELAY_Init();//�̵�����ʼ��
	
	
	
//	delay_ms(1000);//DHT11��ʼ�����Ҫ����ʱ������С��1�룩

//	delay_ms(1000); //��ʱ
//	OLED_DISPLAY_CLEAR();
//	OLED_DISPLAY_8x16_BUFFER(0,"   I LOVE YOU"); //��ʾ�ַ���
	//OLED_DISPLAY_8x16_BUFFER(6,"  Temp:"); //��ʾ�ַ���

//    LED_GPIO_Config();	
//	BEEP_GPIO_Config();
//	Key_GPIO_Config();
//	USART1_Init(115200); //���ڳ�ʼ���������ǲ����ʣ�
	while(1)
	{	
//      if(GPIO_ReadInputDataBit(KEY1_GPIO_PORT,KEY1_GPIO_PIN))RELAY_1(1); //������key1����ʱ�̵���1��־��λ	
//		
//		if(GPIO_ReadInputDataBit(KEY2_GPIO_PORT,KEY2_GPIO_PIN))RELAY_1(0); //������key2����ʱ�̵���1��־��λ		
		
		if(GPIO_ReadInputDataBit(KEY1_GPIO_PORT,KEY1_GPIO_PIN))
		{
			
		  RELAY_1(1); //������key1����ʱ�̵���1��־��λ	
			
			
		}
		if(GPIO_ReadInputDataBit(KEY2_GPIO_PORT,KEY2_GPIO_PIN))
		{
			
		  RELAY_1(0); //������key2����ʱ�̵���1��־��λ		
			
			
			
		}
//		if(GPIO_ReadInputDataBit(KEY1_GPIO_PORT,KEY1_GPIO_PIN)){
//			delay_s(2);	//��ʱ2�룬ʹ������ι�������¸���
//		}	


 //       delay_ms(1000);//��ʱ
	}
}