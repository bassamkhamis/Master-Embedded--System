################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32f103c6_Drivers/GPIO/STM32F103x8_gpio_driver.c 

OBJS += \
./STM32f103c6_Drivers/GPIO/STM32F103x8_gpio_driver.o 

C_DEPS += \
./STM32f103c6_Drivers/GPIO/STM32F103x8_gpio_driver.d 


# Each subdirectory must supply rules for building sources it contributes
STM32f103c6_Drivers/GPIO/STM32F103x8_gpio_driver.o: ../STM32f103c6_Drivers/GPIO/STM32F103x8_gpio_driver.c STM32f103c6_Drivers/GPIO/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I"E:/Learn-in-depth/utility/CUBE_IDE/Drivers/HAL_layer/inc" -I"E:/Learn-in-depth/utility/CUBE_IDE/Drivers/STM32f103c6_Drivers/Inc" -I"E:/Learn-in-depth/utility/CUBE_IDE/Drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32f103c6_Drivers/GPIO/STM32F103x8_gpio_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

