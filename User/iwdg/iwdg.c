

/*
//杜洋工作室出品
//洋桃系列开发板应用程序
//关注微信公众号：洋桃电子
//洋桃开发板资料下载 www.DoYoung.net/YT 
//即可免费看所有教学视频，下载技术资料，技术疑难提问
//更多内容尽在 杜洋工作室主页 www.doyoung.net
*/

/*
《修改日志》
1-201708202309 创建。


*/



#include "iwdg.h"


void IWDG_Init(void){ //初始化独立看门狗
    IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable); //使能对寄存器IWDG_PR和IWDG_RLR的写操作
    IWDG_SetPrescaler(pre); //设置IWDG预分频值
    IWDG_SetReload(rlr); //设置IWDG重装载值
    IWDG_ReloadCounter(); //按照IWDG重装载寄存器的值重装载IWDG计数器
    IWDG_Enable(); //使能IWDG
}

void IWDG_Feed(void){ //喂狗程序
    IWDG_ReloadCounter();//固件库的喂狗函数
}


 
/*********************************************************************************************
 * 杜洋工作室 www.DoYoung.net
 * 洋桃电子 www.DoYoung.net/YT 
*********************************************************************************************/


/*
选择IO接口工作方式：
GPIO_Mode_AIN 模拟输入
GPIO_Mode_IN_FLOATING 浮空输入
GPIO_Mode_IPD 下拉输入
GPIO_Mode_IPU 上拉输入
GPIO_Mode_Out_PP 推挽输出
GPIO_Mode_Out_OD 开漏输出
GPIO_Mode_AF_PP 复用推挽输出
GPIO_Mode_AF_OD 复用开漏输出
*/
