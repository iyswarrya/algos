################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/string\ problems.c 

OBJS += \
./src/string\ problems.o 

C_DEPS += \
./src/string\ problems.d 


# Each subdirectory must supply rules for building sources it contributes
src/string\ problems.o: ../src/string\ problems.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/string problems.d" -MT"src/string\ problems.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


