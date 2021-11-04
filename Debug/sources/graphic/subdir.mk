################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../sources/graphic/atlas.cpp \
../sources/graphic/graphic.cpp \
../sources/graphic/layer.cpp \
../sources/graphic/light.cpp \
../sources/graphic/shape.cpp \
../sources/graphic/sprite.cpp \
../sources/graphic/stack.cpp \
../sources/graphic/stream.cpp \
../sources/graphic/text.cpp 

OBJS += \
./sources/graphic/atlas.o \
./sources/graphic/graphic.o \
./sources/graphic/layer.o \
./sources/graphic/light.o \
./sources/graphic/shape.o \
./sources/graphic/sprite.o \
./sources/graphic/stack.o \
./sources/graphic/stream.o \
./sources/graphic/text.o 

CPP_DEPS += \
./sources/graphic/atlas.d \
./sources/graphic/graphic.d \
./sources/graphic/layer.d \
./sources/graphic/light.d \
./sources/graphic/shape.d \
./sources/graphic/sprite.d \
./sources/graphic/stack.d \
./sources/graphic/stream.d \
./sources/graphic/text.d 


# Each subdirectory must supply rules for building sources it contributes
sources/graphic/%.o: ../sources/graphic/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


