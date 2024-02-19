################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/Common_Thirdparty/Third_party/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.c 

OBJS += \
./Common_Thirdparty/Third_party/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.o 

C_DEPS += \
./Common_Thirdparty/Third_party/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.d 


# Each subdirectory must supply rules for building sources it contributes
Common_Thirdparty/Third_party/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.o: C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/Common_Thirdparty/Third_party/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.c Common_Thirdparty/Third_party/SEGGER/OS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../USB_HOST/App -I"C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/Common_Thirdparty/Third_party/SEGGER/SEGGER" -I"C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/Common_Thirdparty/Third_party/FreeRTOS/include" -I"C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/Common_Thirdparty/Third_party/FreeRTOS/portable/GCC/ARM_CM4F" -I../USB_HOST/Target -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/Common_Thirdparty/Third_party/SEGGER/Config" -I"C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/Common_Thirdparty/Third_party/SEGGER/OS" -I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Common_Thirdparty-2f-Third_party-2f-SEGGER-2f-OS

clean-Common_Thirdparty-2f-Third_party-2f-SEGGER-2f-OS:
	-$(RM) ./Common_Thirdparty/Third_party/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.cyclo ./Common_Thirdparty/Third_party/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.d ./Common_Thirdparty/Third_party/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.o ./Common_Thirdparty/Third_party/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.su

.PHONY: clean-Common_Thirdparty-2f-Third_party-2f-SEGGER-2f-OS

