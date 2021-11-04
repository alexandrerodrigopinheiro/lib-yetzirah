################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../sources/core/camera.cpp \
../sources/core/core.cpp \
../sources/core/handler.cpp \
../sources/core/render.cpp \
../sources/core/system.cpp 

OBJS += \
./sources/core/camera.o \
./sources/core/core.o \
./sources/core/handler.o \
./sources/core/render.o \
./sources/core/system.o 

CPP_DEPS += \
./sources/core/camera.d \
./sources/core/core.d \
./sources/core/handler.d \
./sources/core/render.d \
./sources/core/system.d 


# Each subdirectory must supply rules for building sources it contributes
sources/core/%.o: ../sources/core/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


