################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../sources/error/error.cpp \
../sources/error/exception.cpp 

OBJS += \
./sources/error/error.o \
./sources/error/exception.o 

CPP_DEPS += \
./sources/error/error.d \
./sources/error/exception.d 


# Each subdirectory must supply rules for building sources it contributes
sources/error/%.o: ../sources/error/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


