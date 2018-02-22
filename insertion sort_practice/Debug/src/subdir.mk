################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/insertion\ sort_practice.c 

OBJS += \
./src/insertion\ sort_practice.o 

C_DEPS += \
./src/insertion\ sort_practice.d 


# Each subdirectory must supply rules for building sources it contributes
src/insertion\ sort_practice.o: ../src/insertion\ sort_practice.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/insertion sort_practice.d" -MT"src/insertion\ sort_practice.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


