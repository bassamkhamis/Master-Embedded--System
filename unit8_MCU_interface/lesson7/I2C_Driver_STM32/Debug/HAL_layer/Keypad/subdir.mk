################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL_layer/Keypad/keypad.c 

OBJS += \
./HAL_layer/Keypad/keypad.o 

C_DEPS += \
./HAL_layer/Keypad/keypad.d 


# Each subdirectory must supply rules for building sources it contributes
HAL_layer/Keypad/keypad.o: ../HAL_layer/Keypad/keypad.c HAL_layer/Keypad/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I"E:/Learn-in-depth/utility/CUBE_IDE/Drivers/HAL_layer/inc" -I"E:/Learn-in-depth/utility/CUBE_IDE/Drivers/STM32f103c6_Drivers/Inc" -I"E:/Learn-in-depth/utility/CUBE_IDE/Drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL_layer/Keypad/keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

