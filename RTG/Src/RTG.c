#include "RTG.h"
#include "log.h"
#include <semphr.h>

void TaskA(void *params);
void TaskB(void *params);
SemaphoreHandle_t xBinSem;


void rtg_init()
{
	log_init_function();
	xBinSem = xSemaphoreCreateBinary();

	xTaskCreate(TaskB, "TaskB", 128, (void*)1, 2,NULL);  // Higher priority

	xTaskCreate(TaskA, "TaskA", 128, (void*)2, 1,NULL);

}


unsigned int taskIDs[] = {1,2};
void TaskA(void *argument)
{
	unsigned int value;
	unsigned int count = 0;

	value = (unsigned int )argument;
	vTaskSetThreadLocalStoragePointer(NULL, 0, (void*)&taskIDs[value]);
    while(1) {
		log_trace_function("task loop start",LOG_TASK_START,count);
        vTaskDelay(pdMS_TO_TICKS(5));
        if (count %5 ==0) {
               NVIC_SetPendingIRQ(EXTI15_10_IRQn);  // Simulate button press
        }

    	log_trace_function("task loop end",LOG_TASK_END,count++);

    }
}
void TaskB(void *argument) {
	unsigned int value;
	unsigned int count = 0;

	value = (unsigned int )argument;
	vTaskSetThreadLocalStoragePointer(NULL, 0, (void*)&taskIDs[value]);
    while(1) {
    	log_trace_function("task loop start",LOG_TASK_START,count);
    	xSemaphoreTake(xBinSem, portMAX_DELAY);
    	log_trace_function("task loop end",LOG_TASK_END,count++);
    }
}
void EXTI15_10_IRQHandler(void) {
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    log_trace_function("ISR Entry", LOG_ISR_ENTRY, 0);

    xSemaphoreGiveFromISR(xBinSem, &xHigherPriorityTaskWoken);

    if (xHigherPriorityTaskWoken) {
       // portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
    }
    HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_13);  // Clear interrupt
    log_trace_function("ISR EXIT", LOG_ISR_EXIT, 0);

}


