################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../sources/gui/button.cpp \
../sources/gui/gui.cpp \
../sources/gui/hud.cpp \
../sources/gui/menubar.cpp \
../sources/gui/ruler.cpp \
../sources/gui/sensible.cpp 

OBJS += \
./sources/gui/button.o \
./sources/gui/gui.o \
./sources/gui/hud.o \
./sources/gui/menubar.o \
./sources/gui/ruler.o \
./sources/gui/sensible.o 

CPP_DEPS += \
./sources/gui/button.d \
./sources/gui/gui.d \
./sources/gui/hud.d \
./sources/gui/menubar.d \
./sources/gui/ruler.d \
./sources/gui/sensible.d 


# Each subdirectory must supply rules for building sources it contributes
sources/gui/%.o: ../sources/gui/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


