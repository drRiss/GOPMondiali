################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/carta/Carta.cpp \
../src/carta/CartaAvanza.cpp \
../src/carta/CartaBloccaAvversario.cpp \
../src/carta/CartaDimezza.cpp \
../src/carta/CartaDomanda.cpp \
../src/carta/CartaIndietro.cpp \
../src/carta/CartaRitira.cpp \
../src/carta/CartaTiraTreDadi.cpp \
../src/carta/CartaVittoria.cpp 

OBJS += \
./src/carta/Carta.o \
./src/carta/CartaAvanza.o \
./src/carta/CartaBloccaAvversario.o \
./src/carta/CartaDimezza.o \
./src/carta/CartaDomanda.o \
./src/carta/CartaIndietro.o \
./src/carta/CartaRitira.o \
./src/carta/CartaTiraTreDadi.o \
./src/carta/CartaVittoria.o 

CPP_DEPS += \
./src/carta/Carta.d \
./src/carta/CartaAvanza.d \
./src/carta/CartaBloccaAvversario.d \
./src/carta/CartaDimezza.d \
./src/carta/CartaDomanda.d \
./src/carta/CartaIndietro.d \
./src/carta/CartaRitira.d \
./src/carta/CartaTiraTreDadi.d \
./src/carta/CartaVittoria.d 


# Each subdirectory must supply rules for building sources it contributes
src/carta/%.o: ../src/carta/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


