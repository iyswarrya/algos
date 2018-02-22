################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/inserion\ sort.c 

OBJS += \
./src/inserion\ sort.o 

C_DEPS += \
./src/inserion\ sort.d 


# Each subdirectory must supply rules for building sources it contributes
src/inserion\ sort.o: ../src/inserion\ sort.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/inserion sort.d" -MT"src/inserion\ sort.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


