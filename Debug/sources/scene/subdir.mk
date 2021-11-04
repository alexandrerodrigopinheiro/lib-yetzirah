################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../sources/scene/component.cpp \
../sources/scene/scene.cpp 

OBJS += \
./sources/scene/component.o \
./sources/scene/scene.o 

CPP_DEPS += \
./sources/scene/component.d \
./sources/scene/scene.d 


# Each subdirectory must supply rules for building sources it contributes
sources/scene/%.o: ../sources/scene/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


