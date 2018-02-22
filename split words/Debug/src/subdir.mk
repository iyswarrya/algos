################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/split\ words.c 

OBJS += \
./src/split\ words.o 

C_DEPS += \
./src/split\ words.d 


# Each subdirectory must supply rules for building sources it contributes
src/split\ words.o: ../src/split\ words.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/split words.d" -MT"src/split\ words.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


