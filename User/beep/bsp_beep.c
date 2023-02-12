/**
  ******************************************************************************
  * @file    bsp_beep.c
  * @author  fire
  * @version V3.0
  * @date    2015-xx-xx
  * @brief   ������Ӧ�ú����ӿ�
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:Ұ�� ָ���� STM32 ������ 
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :http://fire-stm32.taobao.com
  *
  ******************************************************************************
  */
  
#include "./beep/bsp_beep.h"   








 /**
  * @brief  ��ʼ�����Ʒ�������IO
  * @param  ��
  * @retval ��
  */
void BEEP_GPIO_Config(void)
{		
		/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
		GPIO_InitTypeDef GPIO_InitStructure;

		/*�������Ʒ�������GPIO�Ķ˿�ʱ��*/
		RCC_APB2PeriphClockCmd( BEEP_GPIO_CLK, ENABLE); 

		/*ѡ��Ҫ���Ʒ�������GPIO*/															   
		GPIO_InitStructure.GPIO_Pin = BEEP_GPIO_PIN;	

		/*����GPIOģʽΪͨ���������*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

		/*����GPIO����Ϊ50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

		/*���ÿ⺯������ʼ�����Ʒ�������GPIO*/
		GPIO_Init(BEEP_GPIO_PORT, &GPIO_InitStructure);			 
    
    /* �رշ�����*/
		GPIO_ResetBits(BEEP_GPIO_PORT, BEEP_GPIO_PIN);	 
}
/*********************************************END OF FILE**********************/

uc16 music1[78]={ //����1�����ݱ�������������ż���ǳ��ȣ�
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

void MIDI_PLAY(void){ //MIDI����
	u16 i,e;
	for(i=0;i<39;i++)     //39������ѭ��39��
	{
		for(e=0;e<music1[i*2]*music1[i*2+1]/1000;e++)//ѭ����ͬ�Ĵ�������һ�������ﵽʱ�䳤�ȣ����ģ���1s330�Σ�750ms�𶯶��ٴ�
		{
//			GPIO_WriteBit(BEEP_GPIO_PORT,BUZZER,(BitAction)(0)); //�������ӿ����0
			
			BEEP( ON );
			delay_us(500000/music1[i*2]); //��ʱ		���������ĸߵͣ���һ����330��0.5s���ڰ�����Ҫ��330��ÿһ�ε�ʱ�䳤��
//			GPIO_WriteBit(BEEP_GPIO_PORT,BUZZER,(BitAction)(1)); //�������ӿ�����ߵ�ƽ1
			
			BEEP( OFF );
			delay_us(500000/music1[i*2]); //��ʱ	
		}	
	}
}