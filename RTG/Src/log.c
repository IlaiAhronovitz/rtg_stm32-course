/*
 * log.c
 *
 *  Created on: Oct 14, 2025
 *      Author: amirt
 */
#include <FreeRTOS.h>
#include <task.h>
#include "log.h"

log_entry_t log_buffer[LOG_MAX_SIZE];
unsigned long log_index;
unsigned char log_mode;
unsigned char log_running = 1;

void log_init_function(void)
{
	log_index = 0;
	log_mode = LOG_MODE_ONESHOT;
	log_running = 1;
}
int log_trace_function(char *fmt,unsigned char key,unsigned long payload)
{

    uint32_t primask = __get_PRIMASK();  // Save current interrupt state
    __disable_irq();                     // Globally disable interrupts

	if(log_running) {
		log_buffer[log_index].key = key;
		log_buffer[log_index].payload = payload;
		if (portCHECK_IF_IN_ISR()) {
			log_buffer[log_index].who = LOG_IN_ISR;
			log_buffer[log_index].tick = xTaskGetTickCountFromISR();

		} else {
			log_buffer[log_index].who = *(unsigned char*)pvTaskGetThreadLocalStoragePointer(NULL, 0);
;
			log_buffer[log_index].tick = xTaskGetTickCount();

		}
			log_index++;
		if(log_index >= LOG_MAX_SIZE-1){
			if(log_mode == LOG_MODE_ONESHOT) {
				log_running = 0;
			} else {
				log_index = 0;
			}
		}
	}
	__set_PRIMASK(primask);             // Restore previous interrupt state
	return 0;
}
void vApplicationTickHook(void)
{
   log_trace_function("tick", LOG_KRRNEL_TICK_ISR,xTaskGetTickCount() );  // Or define a new key like LOG_TICK
}

