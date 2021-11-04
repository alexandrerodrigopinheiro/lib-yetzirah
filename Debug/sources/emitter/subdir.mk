################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../sources/emitter/emitter.cpp \
../sources/emitter/generator.cpp \
../sources/emitter/launcher.cpp \
../sources/emitter/particle.cpp 

OBJS += \
./sources/emitter/emitter.o \
./sources/emitter/generator.o \
./sources/emitter/launcher.o \
./sources/emitter/particle.o 

CPP_DEPS += \
./sources/emitter/emitter.d \
./sources/emitter/generator.d \
./sources/emitter/launcher.d \
./sources/emitter/particle.d 


# Each subdirectory must supply rules for building sources it contributes
sources/emitter/%.o: ../sources/emitter/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


