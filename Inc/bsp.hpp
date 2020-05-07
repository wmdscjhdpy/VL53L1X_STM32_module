#ifndef __BSP_HPP
#define __BSP_HPP
#include "string.h"
#include "cmsis_os.h"
#include "oled.h"
#include "gfx.h"
#include "adc.h"
#include "menu.h"
#include "fivesw.h"
#include "vl53l1.h"
#include "apps.hpp"
#include "W25Q.h"
//#include "fatfs.h"
//#include "user_diskio.h"
//#include "usbd_cdc_if.h"

#define BAT_BUFFER_NUM 10
//简单的宏定义驱动
#define Set_Fric(x,y)  __HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_##x,y)
#define SWFIFONUM 10

typedef struct
{
    uint16_t Battery[BAT_BUFFER_NUM];
    uint8_t BatIndex;
    float BatValue;
    uint8_t SWFifo[SWFIFONUM];//12345分别代表上下左右中
    uint8_t SWindexSave;//队列存储索引
    uint8_t SWindexRead;//队列读取索引
}device_t;
extern  device_t Device;
extern char charbuf[128];


extern osMutexId laserlock;//激光传感器的锁


void bspInit(void);
void Config_Flash(void);
void sort(uint16_t *a, uint16_t end);//对uint16_t的快速排序法
#endif
