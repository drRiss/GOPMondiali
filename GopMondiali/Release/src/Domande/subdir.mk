################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Domande/domande.cpp 

OBJS += \
./src/Domande/domande.o 

CPP_DEPS += \
./src/Domande/domande.d 


# Each subdirectory must supply rules for building sources it contributes
src/Domande/%.o: ../src/Domande/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


