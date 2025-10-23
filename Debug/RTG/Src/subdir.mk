################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../RTG/Src/RTG.c \
../RTG/Src/log.c 

OBJS += \
./RTG/Src/RTG.o \
./RTG/Src/log.o 

C_DEPS += \
./RTG/Src/RTG.d \
./RTG/Src/log.d 


# Each subdirectory must supply rules for building sources it contributes
RTG/Src/%.o RTG/Src/%.su RTG/Src/%.cyclo: ../RTG/Src/%.c RTG/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I"C:/Users/ghkh1/Downloads/freertos-yield (1)/freertos-yield/RTG/Inc" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-RTG-2f-Src

clean-RTG-2f-Src:
	-$(RM) ./RTG/Src/RTG.cyclo ./RTG/Src/RTG.d ./RTG/Src/RTG.o ./RTG/Src/RTG.su ./RTG/Src/log.cyclo ./RTG/Src/log.d ./RTG/Src/log.o ./RTG/Src/log.su

.PHONY: clean-RTG-2f-Src

