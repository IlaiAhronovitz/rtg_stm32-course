/*
 * log.h
 *
 *  Created on: Oct 14, 2025
 *      Author: amirt
 */

#ifndef INC_LOG_H_
#define INC_LOG_H_

#include <log.h>
#include "cmsis_gcc.h"

#define portCHECK_IF_IN_ISR() (__get_IPSR() != 0)


typedef struct
{
	unsigned char key;
	unsigned char who;
	unsigned short tick;
	unsigned long payload;
} log_entry_t ;





#define LOG_MAX_SIZE      256
#define LOG_MODE_ONESHOT  0
#define LOG_MODE_CYCLIC   1
#define LOG_IN_ISR        0xFF

#define LOG_TASK_CREATE				0
#define LOG_TASK_START				1
#define LOG_TASK_END				2

#define LOG_KERNEL_TASK_CREATE	    3
#define LOG_KERNEL_TASK_SWITCH_IN	4
#define LOG_KERNEL_TASK_SWITCH_OUT	5
#define LOG_KERNEL_TASK_DELAY   	6
#define LOG_KERNEL_MOVED_TO_READY   7
#define LOG_KRRNEL_TICK_ISR         8
#define LOG_ISR_ENTRY               9
#define LOG_ISR_EXIT                10

int log_trace_function(char *fmt,unsigned char key,unsigned long payload);
void log_init_function(void);



#endif /* INC_LOG_H_ */
