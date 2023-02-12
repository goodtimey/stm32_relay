/**
  ******************************************************************************
  * @file    bsp_beep.c
  * @author  fire
  * @version V3.0
  * @date    2015-xx-xx
  * @brief   蜂鸣器应用函数接口
  ******************************************************************************
  * @attention
  *
  * 实验平台:野火 指南者 STM32 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :http://fire-stm32.taobao.com
  *
  ******************************************************************************
  */
  
#include "./beep/bsp_beep.h"   








 /**
  * @brief  初始化控制蜂鸣器的IO
  * @param  无
  * @retval 无
  */
void BEEP_GPIO_Config(void)
{		
		/*定义一个GPIO_InitTypeDef类型的结构体*/
		GPIO_InitTypeDef GPIO_InitStructure;

		/*开启控制蜂鸣器的GPIO的端口时钟*/
		RCC_APB2PeriphClockCmd( BEEP_GPIO_CLK, ENABLE); 

		/*选择要控制蜂鸣器的GPIO*/															   
		GPIO_InitStructure.GPIO_Pin = BEEP_GPIO_PIN;	

		/*设置GPIO模式为通用推挽输出*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

		/*设置GPIO速率为50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

		/*调用库函数，初始化控制蜂鸣器的GPIO*/
		GPIO_Init(BEEP_GPIO_PORT, &GPIO_InitStructure);			 
    
    /* 关闭蜂鸣器*/
		GPIO_ResetBits(BEEP_GPIO_PORT, BEEP_GPIO_PIN);	 
}
/*********************************************END OF FILE**********************/

uc16 music1[78]={ //音乐1的数据表（奇数是音调，偶数是长度）
330,750,//750ms
440,375,
494,375,
523,750,
587,375,
659,375,
587,750,
494,375,
392,375,
440,1500,
330,750,
440,375,
494,375,
523,750,
587,375,
659,375,
587,750,
494,375,
392,375,
784,1500,
659,750,
698,375,
784,375,
880,750,
784,375,
698,375,
659,750,
587,750,
659,750,
523,375,
494,375,
440,750,
440,375,
494,375,
523,750,
523,750,
494,750,
392,750,
440,3000
};

void MIDI_PLAY(void){ //MIDI音乐
	u16 i,e;
	for(i=0;i<39;i++)     //39个音符循环39次
	{
		for(e=0;e<music1[i*2]*music1[i*2+1]/1000;e++)//循环不同的次数，让一个音符达到时间长度（节拍），1s330次，750ms震动多少次
		{
//			GPIO_WriteBit(BEEP_GPIO_PORT,BUZZER,(BitAction)(0)); //蜂鸣器接口输出0
			
			BEEP( ON );
			delay_us(500000/music1[i*2]); //延时		决定音调的高低，第一个是330，0.5s，在半秒内要震动330次每一次的时间长度
//			GPIO_WriteBit(BEEP_GPIO_PORT,BUZZER,(BitAction)(1)); //蜂鸣器接口输出高电平1
			
			BEEP( OFF );
			delay_us(500000/music1[i*2]); //延时	
		}	
	}
}