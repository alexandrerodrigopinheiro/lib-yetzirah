################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../sources/device/audio.cpp \
../sources/device/device.cpp \
../sources/device/event.cpp \
../sources/device/keyboard.cpp \
../sources/device/mouse.cpp \
../sources/device/touch.cpp \
../sources/device/window.cpp 

OBJS += \
./sources/device/audio.o \
./sources/device/device.o \
./sources/device/event.o \
./sources/device/keyboard.o \
./sources/device/mouse.o \
./sources/device/touch.o \
./sources/device/window.o 

CPP_DEPS += \
./sources/device/audio.d \
./sources/device/device.d \
./sources/device/event.d \
./sources/device/keyboard.d \
./sources/device/mouse.d \
./sources/device/touch.d \
./sources/device/window.d 


# Each subdirectory must supply rules for building sources it contributes
sources/device/%.o: ../sources/device/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


