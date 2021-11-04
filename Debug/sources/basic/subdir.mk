################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../sources/basic/basic.cpp \
../sources/basic/helper.cpp 

OBJS += \
./sources/basic/basic.o \
./sources/basic/helper.o 

CPP_DEPS += \
./sources/basic/basic.d \
./sources/basic/helper.d 


# Each subdirectory must supply rules for building sources it contributes
sources/basic/%.o: ../sources/basic/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


