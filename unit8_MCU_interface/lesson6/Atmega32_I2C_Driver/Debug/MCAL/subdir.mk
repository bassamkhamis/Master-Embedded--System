################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/GPIO.c \
../MCAL/SPI.c \
../MCAL/TWI.c \
../MCAL/UART.c 

OBJS += \
./MCAL/GPIO.o \
./MCAL/SPI.o \
./MCAL/TWI.o \
./MCAL/UART.o 

C_DEPS += \
./MCAL/GPIO.d \
./MCAL/SPI.d \
./MCAL/TWI.d \
./MCAL/UART.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/%.o: ../MCAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


