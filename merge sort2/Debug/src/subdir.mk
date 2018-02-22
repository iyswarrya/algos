################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/merge\ sort.c 

OBJS += \
./src/merge\ sort.o 

C_DEPS += \
./src/merge\ sort.d 


# Each subdirectory must supply rules for building sources it contributes
src/merge\ sort.o: ../src/merge\ sort.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/merge sort.d" -MT"src/merge\ sort.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


