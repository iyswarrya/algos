################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/quick\ sort.c 

OBJS += \
./src/quick\ sort.o 

C_DEPS += \
./src/quick\ sort.d 


# Each subdirectory must supply rules for building sources it contributes
src/quick\ sort.o: ../src/quick\ sort.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/quick sort.d" -MT"src/quick\ sort.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


