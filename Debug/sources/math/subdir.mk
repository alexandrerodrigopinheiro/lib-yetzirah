################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../sources/math/circle.cpp \
../sources/math/color.cpp \
../sources/math/math.cpp \
../sources/math/matrix.cpp \
../sources/math/monetary.cpp \
../sources/math/point.cpp \
../sources/math/range.cpp \
../sources/math/rotate.cpp \
../sources/math/size.cpp \
../sources/math/surface.cpp \
../sources/math/uvmap.cpp \
../sources/math/vertex.cpp 

OBJS += \
./sources/math/circle.o \
./sources/math/color.o \
./sources/math/math.o \
./sources/math/matrix.o \
./sources/math/monetary.o \
./sources/math/point.o \
./sources/math/range.o \
./sources/math/rotate.o \
./sources/math/size.o \
./sources/math/surface.o \
./sources/math/uvmap.o \
./sources/math/vertex.o 

CPP_DEPS += \
./sources/math/circle.d \
./sources/math/color.d \
./sources/math/math.d \
./sources/math/matrix.d \
./sources/math/monetary.d \
./sources/math/point.d \
./sources/math/range.d \
./sources/math/rotate.d \
./sources/math/size.d \
./sources/math/surface.d \
./sources/math/uvmap.d \
./sources/math/vertex.d 


# Each subdirectory must supply rules for building sources it contributes
sources/math/%.o: ../sources/math/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


