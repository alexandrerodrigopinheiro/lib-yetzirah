################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../sources/connect/connect.cpp 

OBJS += \
./sources/connect/connect.o 

CPP_DEPS += \
./sources/connect/connect.d 


# Each subdirectory must supply rules for building sources it contributes
sources/connect/%.o: ../sources/connect/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


