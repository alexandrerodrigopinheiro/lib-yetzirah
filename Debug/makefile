################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include sources/serialize/subdir.mk
-include sources/scene/subdir.mk
-include sources/random/subdir.mk
-include sources/math/subdir.mk
-include sources/gui/subdir.mk
-include sources/graphic/subdir.mk
-include sources/error/subdir.mk
-include sources/emitter/subdir.mk
-include sources/device/subdir.mk
-include sources/crypto/subdir.mk
-include sources/core/subdir.mk
-include sources/connect/subdir.mk
-include sources/command/subdir.mk
-include sources/clock/subdir.mk
-include sources/basic/subdir.mk
-include sources/audio/subdir.mk
-include sources/animation/subdir.mk
-include build/serialize/subdir.mk
-include build/random/subdir.mk
-include build/math/subdir.mk
-include build/gui/subdir.mk
-include build/graphic/subdir.mk
-include build/error/subdir.mk
-include build/emitter/subdir.mk
-include build/device/subdir.mk
-include build/crypto/subdir.mk
-include build/core/subdir.mk
-include build/connect/subdir.mk
-include build/command/subdir.mk
-include build/clock/subdir.mk
-include build/basic/subdir.mk
-include build/audio/subdir.mk
-include build/animation/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: libyetzirah

# Tool invocations
libyetzirah: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C++ Linker'
	g++  -o "libyetzirah" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(EXECUTABLES)$(C_UPPER_DEPS)$(CXX_DEPS)$(OBJS)$(CPP_DEPS)$(C_DEPS) libyetzirah
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
