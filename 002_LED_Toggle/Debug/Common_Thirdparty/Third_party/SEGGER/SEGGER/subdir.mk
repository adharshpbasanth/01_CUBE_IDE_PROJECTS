################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/Common_Thirdparty/Third_party/SEGGER/SEGGER/SEGGER_RTT.c \
C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/Common_Thirdparty/Third_party/SEGGER/SEGGER/SEGGER_RTT_printf.c \
C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/Common_Thirdparty/Third_party/SEGGER/SEGGER/SEGGER_SYSVIEW.c 

S_UPPER_SRCS += \
C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/Common_Thirdparty/Third_party/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.S 

OBJS += \
./Common_Thirdparty/Third_party/SEGGER/SEGGER/SEGGER_RTT.o \
./Common_Thirdparty/Third_party/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.o \
./Common_Thirdparty/Third_party/SEGGER/SEGGER/SEGGER_RTT_printf.o \
./Common_Thirdparty/Third_party/SEGGER/SEGGER/SEGGER_SYSVIEW.o 

S_UPPER_DEPS += \
./Common_Thirdparty/Third_party/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.d 

C_DEPS += \
./Common_Thirdparty/Third_party/SEGGER/SEGGER/SEGGER_RTT.d \
./Common_Thirdparty/Third_party/SEGGER/SEGGER/SEGGER_RTT_printf.d \
./Common_Thirdparty/Third_party/SEGGER/SEGGER/SEGGER_SYSVIEW.d 


# Each subdirectory must supply rules for building sources it contributes
Common_Thirdparty/Third_party/SEGGER/SEGGER/SEGGER_RTT.o: C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/Common_Thirdparty/Third_party/SEGGER/SEGGER/SEGGER_RTT.c Common_Thirdparty/Third_party/SEGGER/SEGGER/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../USB_HOST/App -I"C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/Common_Thirdparty/Third_party/SEGGER/SEGGER" -I"C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/Common_Thirdparty/Third_party/FreeRTOS/include" -I"C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/Common_Thirdparty/Third_party/FreeRTOS/portable/GCC/ARM_CM4F" -I../USB_HOST/Target -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/Common_Thirdparty/Third_party/SEGGER/Config" -I"C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/Common_Thirdparty/Third_party/SEGGER/OS" -I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Common_Thirdparty/Third_party/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.o: C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/Common_Thirdparty/Third_party/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.S Common_Thirdparty/Third_party/SEGGER/SEGGER/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -I"C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/Common_Thirdparty/Third_party/SEGGER/Config" -I"C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/Common_Thirdparty/Third_party/SEGGER/SEGGER" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"
Common_Thirdparty/Third_party/SEGGER/SEGGER/SEGGER_RTT_printf.o: C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/Common_Thirdparty/Third_party/SEGGER/SEGGER/SEGGER_RTT_printf.c Common_Thirdparty/Third_party/SEGGER/SEGGER/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../USB_HOST/App -I"C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/Common_Thirdparty/Third_party/SEGGER/SEGGER" -I"C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/Common_Thirdparty/Third_party/FreeRTOS/include" -I"C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/Common_Thirdparty/Third_party/FreeRTOS/portable/GCC/ARM_CM4F" -I../USB_HOST/Target -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/Common_Thirdparty/Third_party/SEGGER/Config" -I"C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/Common_Thirdparty/Third_party/SEGGER/OS" -I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Common_Thirdparty/Third_party/SEGGER/SEGGER/SEGGER_SYSVIEW.o: C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/Common_Thirdparty/Third_party/SEGGER/SEGGER/SEGGER_SYSVIEW.c Common_Thirdparty/Third_party/SEGGER/SEGGER/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../USB_HOST/App -I"C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/Common_Thirdparty/Third_party/SEGGER/SEGGER" -I"C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/Common_Thirdparty/Third_party/FreeRTOS/include" -I"C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/Common_Thirdparty/Third_party/FreeRTOS/portable/GCC/ARM_CM4F" -I../USB_HOST/Target -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/Common_Thirdparty/Third_party/SEGGER/Config" -I"C:/Users/adhar/STM32Cube/01_CUBE_IDE_PROJECTS/Common_Thirdparty/Third_party/SEGGER/OS" -I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Common_Thirdparty-2f-Third_party-2f-SEGGER-2f-SEGGER

clean-Common_Thirdparty-2f-Third_party-2f-SEGGER-2f-SEGGER:
	-$(RM) ./Common_Thirdparty/Third_party/SEGGER/SEGGER/SEGGER_RTT.cyclo ./Common_Thirdparty/Third_party/SEGGER/SEGGER/SEGGER_RTT.d ./Common_Thirdparty/Third_party/SEGGER/SEGGER/SEGGER_RTT.o ./Common_Thirdparty/Third_party/SEGGER/SEGGER/SEGGER_RTT.su ./Common_Thirdparty/Third_party/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.d ./Common_Thirdparty/Third_party/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.o ./Common_Thirdparty/Third_party/SEGGER/SEGGER/SEGGER_RTT_printf.cyclo ./Common_Thirdparty/Third_party/SEGGER/SEGGER/SEGGER_RTT_printf.d ./Common_Thirdparty/Third_party/SEGGER/SEGGER/SEGGER_RTT_printf.o ./Common_Thirdparty/Third_party/SEGGER/SEGGER/SEGGER_RTT_printf.su ./Common_Thirdparty/Third_party/SEGGER/SEGGER/SEGGER_SYSVIEW.cyclo ./Common_Thirdparty/Third_party/SEGGER/SEGGER/SEGGER_SYSVIEW.d ./Common_Thirdparty/Third_party/SEGGER/SEGGER/SEGGER_SYSVIEW.o ./Common_Thirdparty/Third_party/SEGGER/SEGGER/SEGGER_SYSVIEW.su

.PHONY: clean-Common_Thirdparty-2f-Third_party-2f-SEGGER-2f-SEGGER

