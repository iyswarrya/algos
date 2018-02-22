################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/circulat\ linked\ list.c 

OBJS += \
./src/circulat\ linked\ list.o 

C_DEPS += \
./src/circulat\ linked\ list.d 


# Each subdirectory must supply rules for building sources it contributes
src/circulat\ linked\ list.o: ../src/circulat\ linked\ list.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/circulat linked list.d" -MT"src/circulat\ linked\ list.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


