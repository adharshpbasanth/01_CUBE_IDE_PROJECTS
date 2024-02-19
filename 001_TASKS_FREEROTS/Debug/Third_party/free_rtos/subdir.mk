################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Third_party/free_rtos/croutine.c \
../Third_party/free_rtos/event_groups.c \
../Third_party/free_rtos/list.c \
../Third_party/free_rtos/queue.c \
../Third_party/free_rtos/stream_buffer.c \
../Third_party/free_rtos/tasks.c \
../Third_party/free_rtos/timers.c 

OBJS += \
./Third_party/free_rtos/croutine.o \
./Third_party/free_rtos/event_groups.o \
./Third_party/free_rtos/list.o \
./Third_party/free_rtos/queue.o \
./Third_party/free_rtos/stream_buffer.o \
./Third_party/free_rtos/tasks.o \
./Third_party/free_rtos/timers.o 

C_DEPS += \
./Third_party/free_rtos/croutine.d \
./Third_party/free_rtos/event_groups.d \
./Third_party/free_rtos/list.d \
./Third_party/free_rtos/queue.d \
./Third_party/free_rtos/stream_buffer.d \
./Third_party/free_rtos/tasks.d \
./Third_party/free_rtos/timers.d 


# Each subdirectory must supply rules for building sources it contributes
Third_party/free_rtos/%.o Third_party/free_rtos/%.su Third_party/free_rtos/%.cyclo: ../Third_party/free_rtos/%.c Third_party/free_rtos/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I"C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/001_TASKS_FREEROTS/Third_party/SEGGER/Config" -I"C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/001_TASKS_FREEROTS/Third_party/SEGGER/OS" -I"C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/001_TASKS_FREEROTS/Third_party/SEGGER/SEGGER" -I"C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/001_TASKS_FREEROTS/Third_party/free_rtos" -I"C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/001_TASKS_FREEROTS/Third_party/free_rtos/include" -I"C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/001_TASKS_FREEROTS/Third_party/free_rtos/portable/GCC/ARM_CM4F" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Third_party-2f-free_rtos

clean-Third_party-2f-free_rtos:
	-$(RM) ./Third_party/free_rtos/croutine.cyclo ./Third_party/free_rtos/croutine.d ./Third_party/free_rtos/croutine.o ./Third_party/free_rtos/croutine.su ./Third_party/free_rtos/event_groups.cyclo ./Third_party/free_rtos/event_groups.d ./Third_party/free_rtos/event_groups.o ./Third_party/free_rtos/event_groups.su ./Third_party/free_rtos/list.cyclo ./Third_party/free_rtos/list.d ./Third_party/free_rtos/list.o ./Third_party/free_rtos/list.su ./Third_party/free_rtos/queue.cyclo ./Third_party/free_rtos/queue.d ./Third_party/free_rtos/queue.o ./Third_party/free_rtos/queue.su ./Third_party/free_rtos/stream_buffer.cyclo ./Third_party/free_rtos/stream_buffer.d ./Third_party/free_rtos/stream_buffer.o ./Third_party/free_rtos/stream_buffer.su ./Third_party/free_rtos/tasks.cyclo ./Third_party/free_rtos/tasks.d ./Third_party/free_rtos/tasks.o ./Third_party/free_rtos/tasks.su ./Third_party/free_rtos/timers.cyclo ./Third_party/free_rtos/timers.d ./Third_party/free_rtos/timers.o ./Third_party/free_rtos/timers.su

.PHONY: clean-Third_party-2f-free_rtos

