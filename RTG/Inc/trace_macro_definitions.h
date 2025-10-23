/*
 * trace_macro_definitions.h
 *
 *  Created on: Oct 15, 2025
 *      Author: amirt
 */

#ifndef INC_TRACE_MACRO_DEFINITIONS_H_
#define INC_TRACE_MACRO_DEFINITIONS_H_

#include <log.h>

#define traceTASK_DELAY() \
    log_trace_function("delay", LOG_KERNEL_TASK_DELAY, 0)

#define traceTASK_CREATE(pxNewTCB) \
    log_trace_function("create", LOG_KERNEL_TASK_CREATE, *(unsigned long*)pvTaskGetThreadLocalStoragePointer(pxNewTCB,0))

#define traceTASK_SWITCHED_OUT() \
	  log_trace_function("switch out", LOG_KERNEL_TASK_SWITCH_OUT, *(unsigned long*)pvTaskGetThreadLocalStoragePointer(pxCurrentTCB,0))

#define traceTASK_SWITCHED_IN() \
    log_trace_function("switch in", LOG_KERNEL_TASK_SWITCH_IN, *(unsigned long*)pvTaskGetThreadLocalStoragePointer(pxCurrentTCB,0))

#define tracePOST_MOVED_TASK_TO_READY_STATE( pxTCB )\
	  log_trace_function("ready queue", LOG_KERNEL_MOVED_TO_READY, *(unsigned long*)pvTaskGetThreadLocalStoragePointer(pxTCB,0))


#endif /* INC_TRACE_MACRO_DEFINITIONS_H_ */
