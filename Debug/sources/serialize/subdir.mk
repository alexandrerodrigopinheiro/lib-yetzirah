################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../sources/serialize/animated.cpp \
../sources/serialize/loader.cpp \
../sources/serialize/memorize.cpp \
../sources/serialize/meta.cpp \
../sources/serialize/serialize.cpp \
../sources/serialize/serializer.cpp 

OBJS += \
./sources/serialize/animated.o \
./sources/serialize/loader.o \
./sources/serialize/memorize.o \
./sources/serialize/meta.o \
./sources/serialize/serialize.o \
./sources/serialize/serializer.o 

CPP_DEPS += \
./sources/serialize/animated.d \
./sources/serialize/loader.d \
./sources/serialize/memorize.d \
./sources/serialize/meta.d \
./sources/serialize/serialize.d \
./sources/serialize/serializer.d 


# Each subdirectory must supply rules for building sources it contributes
sources/serialize/%.o: ../sources/serialize/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


