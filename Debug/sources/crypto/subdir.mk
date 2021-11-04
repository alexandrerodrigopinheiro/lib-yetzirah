################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../sources/crypto/crypto.cpp \
../sources/crypto/keygen.cpp \
../sources/crypto/md5.cpp 

OBJS += \
./sources/crypto/crypto.o \
./sources/crypto/keygen.o \
./sources/crypto/md5.o 

CPP_DEPS += \
./sources/crypto/crypto.d \
./sources/crypto/keygen.d \
./sources/crypto/md5.d 


# Each subdirectory must supply rules for building sources it contributes
sources/crypto/%.o: ../sources/crypto/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


