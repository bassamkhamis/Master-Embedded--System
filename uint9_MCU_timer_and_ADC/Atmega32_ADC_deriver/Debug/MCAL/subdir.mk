################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/ADC.c \
../MCAL/GPIO.c \
../MCAL/PWM.c \
../MCAL/SPI.c \
../MCAL/TWI.c \
../MCAL/Timer.c \
../MCAL/UART.c \
../MCAL/WDT.c 

OBJS += \
./MCAL/ADC.o \
./MCAL/GPIO.o \
./MCAL/PWM.o \
./MCAL/SPI.o \
./MCAL/TWI.o \
./MCAL/Timer.o \
./MCAL/UART.o \
./MCAL/WDT.o 

C_DEPS += \
./MCAL/ADC.d \
./MCAL/GPIO.d \
./MCAL/PWM.d \
./MCAL/SPI.d \
./MCAL/TWI.d \
./MCAL/Timer.d \
./MCAL/UART.d \
./MCAL/WDT.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/%.o: ../MCAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

