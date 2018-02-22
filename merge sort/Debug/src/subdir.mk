################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/merge\ sort2.c 

OBJS += \
./src/merge\ sort2.o 

C_DEPS += \
./src/merge\ sort2.d 


# Each subdirectory must supply rules for building sources it contributes
src/merge\ sort2.o: ../src/merge\ sort2.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/merge sort2.d" -MT"src/merge\ sort2.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


