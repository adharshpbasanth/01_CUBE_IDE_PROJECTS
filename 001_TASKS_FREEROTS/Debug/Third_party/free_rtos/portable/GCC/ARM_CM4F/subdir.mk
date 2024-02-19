################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Third_party/free_rtos/portable/GCC/ARM_CM4F/port.c 

OBJS += \
./Third_party/free_rtos/portable/GCC/ARM_CM4F/port.o 

C_DEPS += \
./Third_party/free_rtos/portable/GCC/ARM_CM4F/port.d 


# Each subdirectory must supply rules for building sources it contributes
Third_party/free_rtos/portable/GCC/ARM_CM4F/%.o Third_party/free_rtos/portable/GCC/ARM_CM4F/%.su Third_party/free_rtos/portable/GCC/ARM_CM4F/%.cyclo: ../Third_party/free_rtos/portable/GCC/ARM_CM4F/%.c Third_party/free_rtos/portable/GCC/ARM_CM4F/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I"C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/001_TASKS_FREEROTS/Third_party/SEGGER/Config" -I"C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/001_TASKS_FREEROTS/Third_party/SEGGER/OS" -I"C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/001_TASKS_FREEROTS/Third_party/SEGGER/SEGGER" -I"C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/001_TASKS_FREEROTS/Third_party/free_rtos" -I"C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/001_TASKS_FREEROTS/Third_party/free_rtos/include" -I"C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/001_TASKS_FREEROTS/Third_party/free_rtos/portable/GCC/ARM_CM4F" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Third_party-2f-free_rtos-2f-portable-2f-GCC-2f-ARM_CM4F

clean-Third_party-2f-free_rtos-2f-portable-2f-GCC-2f-ARM_CM4F:
	-$(RM) ./Third_party/free_rtos/portable/GCC/ARM_CM4F/port.cyclo ./Third_party/free_rtos/portable/GCC/ARM_CM4F/port.d ./Third_party/free_rtos/portable/GCC/ARM_CM4F/port.o ./Third_party/free_rtos/portable/GCC/ARM_CM4F/port.su

.PHONY: clean-Third_party-2f-free_rtos-2f-portable-2f-GCC-2f-ARM_CM4F

