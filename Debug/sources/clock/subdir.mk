################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../sources/clock/clock.cpp \
../sources/clock/frequency.cpp \
../sources/clock/hertz.cpp \
../sources/clock/timer.cpp 

OBJS += \
./sources/clock/clock.o \
./sources/clock/frequency.o \
./sources/clock/hertz.o \
./sources/clock/timer.o 

CPP_DEPS += \
./sources/clock/clock.d \
./sources/clock/frequency.d \
./sources/clock/hertz.d \
./sources/clock/timer.d 


# Each subdirectory must supply rules for building sources it contributes
sources/clock/%.o: ../sources/clock/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


