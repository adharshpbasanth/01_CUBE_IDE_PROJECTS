################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Third_party/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.c 

OBJS += \
./Third_party/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.o 

C_DEPS += \
./Third_party/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.d 


# Each subdirectory must supply rules for building sources it contributes
Third_party/SEGGER/OS/%.o Third_party/SEGGER/OS/%.su Third_party/SEGGER/OS/%.cyclo: ../Third_party/SEGGER/OS/%.c Third_party/SEGGER/OS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I"C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/001_TASKS_FREEROTS/Third_party/SEGGER/Config" -I"C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/001_TASKS_FREEROTS/Third_party/SEGGER/OS" -I"C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/001_TASKS_FREEROTS/Third_party/SEGGER/SEGGER" -I"C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/001_TASKS_FREEROTS/Third_party/FreeRTOS" -I"C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/001_TASKS_FREEROTS/Third_party/FreeRTOS/portable/GCC/ARM_CM4F" -I"C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/001_TASKS_FREEROTS/Third_party/FreeRTOS/include" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Third_party-2f-SEGGER-2f-OS

clean-Third_party-2f-SEGGER-2f-OS:
	-$(RM) ./Third_party/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.cyclo ./Third_party/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.d ./Third_party/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.o ./Third_party/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.su

.PHONY: clean-Third_party-2f-SEGGER-2f-OS

