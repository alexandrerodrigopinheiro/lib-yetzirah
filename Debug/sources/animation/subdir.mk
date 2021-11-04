################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../sources/animation/animation.cpp \
../sources/animation/animator.cpp \
../sources/animation/frame.cpp \
../sources/animation/framer.cpp \
../sources/animation/key.cpp \
../sources/animation/keyframe.cpp \
../sources/animation/timeline.cpp \
../sources/animation/tween.cpp 

OBJS += \
./sources/animation/animation.o \
./sources/animation/animator.o \
./sources/animation/frame.o \
./sources/animation/framer.o \
./sources/animation/key.o \
./sources/animation/keyframe.o \
./sources/animation/timeline.o \
./sources/animation/tween.o 

CPP_DEPS += \
./sources/animation/animation.d \
./sources/animation/animator.d \
./sources/animation/frame.d \
./sources/animation/framer.d \
./sources/animation/key.d \
./sources/animation/keyframe.d \
./sources/animation/timeline.d \
./sources/animation/tween.d 


# Each subdirectory must supply rules for building sources it contributes
sources/animation/%.o: ../sources/animation/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


