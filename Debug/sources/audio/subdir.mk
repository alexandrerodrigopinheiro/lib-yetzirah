################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../sources/audio/effect.cpp \
../sources/audio/music.cpp 

OBJS += \
./sources/audio/effect.o \
./sources/audio/music.o 

CPP_DEPS += \
./sources/audio/effect.d \
./sources/audio/music.d 


# Each subdirectory must supply rules for building sources it contributes
sources/audio/%.o: ../sources/audio/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


