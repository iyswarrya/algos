################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/array\ of\ strings_pointers.c 

OBJS += \
./src/array\ of\ strings_pointers.o 

C_DEPS += \
./src/array\ of\ strings_pointers.d 


# Each subdirectory must supply rules for building sources it contributes
src/array\ of\ strings_pointers.o: ../src/array\ of\ strings_pointers.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/array of strings_pointers.d" -MT"src/array\ of\ strings_pointers.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


