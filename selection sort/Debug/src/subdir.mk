################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/selection\ sort.c 

OBJS += \
./src/selection\ sort.o 

C_DEPS += \
./src/selection\ sort.d 


# Each subdirectory must supply rules for building sources it contributes
src/selection\ sort.o: ../src/selection\ sort.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/selection sort.d" -MT"src/selection\ sort.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


