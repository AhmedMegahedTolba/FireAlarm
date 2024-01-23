################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_Proram.c \
../DIO.c \
../DIO_Cfg.c \
../EX_EEPROM.c \
../EX_Interrupt.c \
../FireAlarm.c \
../I2C.c \
../KEYPAD.c \
../LCD.c \
../MOTOR.c \
../MOTOR_Cfg.c \
../Pot.c \
../String_Serive.c \
../TEMP_Filter.c \
../Temp_Program.c \
../UART.c \
../UART_Service.c \
../WDT.c \
../main.c 

OBJS += \
./ADC_Proram.o \
./DIO.o \
./DIO_Cfg.o \
./EX_EEPROM.o \
./EX_Interrupt.o \
./FireAlarm.o \
./I2C.o \
./KEYPAD.o \
./LCD.o \
./MOTOR.o \
./MOTOR_Cfg.o \
./Pot.o \
./String_Serive.o \
./TEMP_Filter.o \
./Temp_Program.o \
./UART.o \
./UART_Service.o \
./WDT.o \
./main.o 

C_DEPS += \
./ADC_Proram.d \
./DIO.d \
./DIO_Cfg.d \
./EX_EEPROM.d \
./EX_Interrupt.d \
./FireAlarm.d \
./I2C.d \
./KEYPAD.d \
./LCD.d \
./MOTOR.d \
./MOTOR_Cfg.d \
./Pot.d \
./String_Serive.d \
./TEMP_Filter.d \
./Temp_Program.d \
./UART.d \
./UART_Service.d \
./WDT.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


