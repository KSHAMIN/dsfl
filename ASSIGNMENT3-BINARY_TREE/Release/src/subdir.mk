################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ASSIGNMENT3-BINARY_TREE.cpp \
../src/BTREE.cpp 

OBJS += \
./src/ASSIGNMENT3-BINARY_TREE.o \
./src/BTREE.o 

CPP_DEPS += \
./src/ASSIGNMENT3-BINARY_TREE.d \
./src/BTREE.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

