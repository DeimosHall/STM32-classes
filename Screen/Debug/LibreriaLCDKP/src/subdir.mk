################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/deimos/STM32CubeIDE/STM32-classes/Libraries/LibreriaLCDKP/src/keypad.c \
/home/deimos/STM32CubeIDE/STM32-classes/Libraries/LibreriaLCDKP/src/lcd.c 

OBJS += \
./LibreriaLCDKP/src/keypad.o \
./LibreriaLCDKP/src/lcd.o 

C_DEPS += \
./LibreriaLCDKP/src/keypad.d \
./LibreriaLCDKP/src/lcd.d 


# Each subdirectory must supply rules for building sources it contributes
LibreriaLCDKP/src/keypad.o: /home/deimos/STM32CubeIDE/STM32-classes/Libraries/LibreriaLCDKP/src/keypad.c LibreriaLCDKP/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"/home/deimos/STM32CubeIDE/Embedded system processors/STM32-classes/Libraries/LibreriaLCDKP/inc" -I/home/deimos/STM32CubeIDE/STM32-classes/Libraries/LibreriaLCDKP/inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
LibreriaLCDKP/src/lcd.o: /home/deimos/STM32CubeIDE/STM32-classes/Libraries/LibreriaLCDKP/src/lcd.c LibreriaLCDKP/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"/home/deimos/STM32CubeIDE/Embedded system processors/STM32-classes/Libraries/LibreriaLCDKP/inc" -I/home/deimos/STM32CubeIDE/STM32-classes/Libraries/LibreriaLCDKP/inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-LibreriaLCDKP-2f-src

clean-LibreriaLCDKP-2f-src:
	-$(RM) ./LibreriaLCDKP/src/keypad.d ./LibreriaLCDKP/src/keypad.o ./LibreriaLCDKP/src/keypad.su ./LibreriaLCDKP/src/lcd.d ./LibreriaLCDKP/src/lcd.o ./LibreriaLCDKP/src/lcd.su

.PHONY: clean-LibreriaLCDKP-2f-src

