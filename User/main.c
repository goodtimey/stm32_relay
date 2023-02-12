/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   测试led
  ******************************************************************************
  * @attention
  *
  * 实验平台:野火 指南者 STM32 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :http://fire-stm32.taobao.com
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
  * @brief  主函数
  * @param  无  
  * @retval 无
  */
int main(void)
{	
	
   
	//初始化程序
	delay_ms(500); //上电时等待其他器件就绪
	RCC_Configuration(); //时钟设置
	LED_GPIO_Config();
	Key_GPIO_Config();
	
	I2C_Configuration();//I2C初始化
	
	RELAY_Init();//继电器初始化
	
	
	
//	delay_ms(1000);//DHT11初始化后必要的延时（不得小于1秒）

//	delay_ms(1000); //延时
//	OLED_DISPLAY_CLEAR();
//	OLED_DISPLAY_8x16_BUFFER(0,"   I LOVE YOU"); //显示字符串
	//OLED_DISPLAY_8x16_BUFFER(6,"  Temp:"); //显示字符串

//    LED_GPIO_Config();	
//	BEEP_GPIO_Config();
//	Key_GPIO_Config();
//	USART1_Init(115200); //串口初始化（参数是波特率）
	while(1)
	{	
//      if(GPIO_ReadInputDataBit(KEY1_GPIO_PORT,KEY1_GPIO_PIN))RELAY_1(1); //当按键key1按下时继电器1标志置位	
//		
//		if(GPIO_ReadInputDataBit(KEY2_GPIO_PORT,KEY2_GPIO_PIN))RELAY_1(0); //当按键key2按下时继电器1标志置位		
		
		if(GPIO_ReadInputDataBit(KEY1_GPIO_PORT,KEY1_GPIO_PIN))
		{
			
		  RELAY_1(1); //当按键key1按下时继电器1标志置位	
			
			
		}
		if(GPIO_ReadInputDataBit(KEY2_GPIO_PORT,KEY2_GPIO_PIN))
		{
			
		  RELAY_1(0); //当按键key2按下时继电器1标志置位		
			
			
			
		}
//		if(GPIO_ReadInputDataBit(KEY1_GPIO_PORT,KEY1_GPIO_PIN)){
//			delay_s(2);	//延时2秒，使程序不能喂狗而导致复制
//		}	


 //       delay_ms(1000);//延时
	}
}