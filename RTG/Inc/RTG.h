/*
 * RTG.h
 *
 *  Created on: Oct 2, 2022
 *      Author: RTG
 *
 */
#ifndef INC_RTG_H_
#define INC_RTG_H_
#include "main.h"
#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"

#include "stm32f7xx_hal.h"
#include <stdio.h>
#include <stdlib.h>

extern UART_HandleTypeDef huart3;
#define UART_DEBUG &huart3


#define TASK1_PRIO   2
#define TASK2_PRIO   1

extern TaskHandle_t xTask1_handle;
extern TaskHandle_t xTask2_handle;

extern void rtgTask(void *);
extern void rtg_init(void);


#endif /* INC_RTG_H_ */
