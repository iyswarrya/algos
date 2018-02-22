################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/string\ rotation.c 

OBJS += \
./src/string\ rotation.o 

C_DEPS += \
./src/string\ rotation.d 


# Each subdirectory must supply rules for building sources it contributes
src/string\ rotation.o: ../src/string\ rotation.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/string rotation.d" -MT"src/string\ rotation.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


