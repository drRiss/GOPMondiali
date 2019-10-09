################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/casella/Casella.cpp \
../src/casella/CasellaAvanza.cpp \
../src/casella/CasellaFinale.cpp \
../src/casella/CasellaIndietro.cpp \
../src/casella/CasellaIniziale.cpp \
../src/casella/CasellaPescaCarta.cpp \
../src/casella/CasellaSaltaTurno.cpp \
../src/casella/CasellaTornaInizio.cpp \
../src/casella/CasellaVuota.cpp 

OBJS += \
./src/casella/Casella.o \
./src/casella/CasellaAvanza.o \
./src/casella/CasellaFinale.o \
./src/casella/CasellaIndietro.o \
./src/casella/CasellaIniziale.o \
./src/casella/CasellaPescaCarta.o \
./src/casella/CasellaSaltaTurno.o \
./src/casella/CasellaTornaInizio.o \
./src/casella/CasellaVuota.o 

CPP_DEPS += \
./src/casella/Casella.d \
./src/casella/CasellaAvanza.d \
./src/casella/CasellaFinale.d \
./src/casella/CasellaIndietro.d \
./src/casella/CasellaIniziale.d \
./src/casella/CasellaPescaCarta.d \
./src/casella/CasellaSaltaTurno.d \
./src/casella/CasellaTornaInizio.d \
./src/casella/CasellaVuota.d 


# Each subdirectory must supply rules for building sources it contributes
src/casella/%.o: ../src/casella/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


