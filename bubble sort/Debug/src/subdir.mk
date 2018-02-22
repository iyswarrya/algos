################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/bubble\ sort.c 

OBJS += \
./src/bubble\ sort.o 

C_DEPS += \
./src/bubble\ sort.d 


# Each subdirectory must supply rules for building sources it contributes
src/bubble\ sort.o: ../src/bubble\ sort.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/bubble sort.d" -MT"src/bubble\ sort.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


