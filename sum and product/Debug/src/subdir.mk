################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/sum\ and\ product.c 

OBJS += \
./src/sum\ and\ product.o 

C_DEPS += \
./src/sum\ and\ product.d 


# Each subdirectory must supply rules for building sources it contributes
src/sum\ and\ product.o: ../src/sum\ and\ product.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/sum and product.d" -MT"src/sum\ and\ product.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


