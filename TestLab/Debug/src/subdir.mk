################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/StructuresTest.cpp \
../src/TestLab.cpp 

OBJS += \
./src/StructuresTest.o \
./src/TestLab.o 

CPP_DEPS += \
./src/StructuresTest.d \
./src/TestLab.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/boost_1_51_0 -I"/home/bomj/Env/Job/Code/main/Structures" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


