################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/TSS/TSS_Freemaster.c" \
"../Sources/TSS/TSS_Sensor.c" \
"../Sources/TSS/TSS_SensorGPIO.c" \
"../Sources/TSS/TSS_SensorTSI.c" \
"../Sources/TSS/TSS_SensorTSIL.c" \
"../Sources/TSS/TSS_SystemSetupData.c" \

C_SRCS += \
../Sources/TSS/TSS_Freemaster.c \
../Sources/TSS/TSS_Sensor.c \
../Sources/TSS/TSS_SensorGPIO.c \
../Sources/TSS/TSS_SensorTSI.c \
../Sources/TSS/TSS_SensorTSIL.c \
../Sources/TSS/TSS_SystemSetupData.c \

OBJS += \
./Sources/TSS/TSS_Freemaster.o \
./Sources/TSS/TSS_Sensor.o \
./Sources/TSS/TSS_SensorGPIO.o \
./Sources/TSS/TSS_SensorTSI.o \
./Sources/TSS/TSS_SensorTSIL.o \
./Sources/TSS/TSS_SystemSetupData.o \

C_DEPS += \
./Sources/TSS/TSS_Freemaster.d \
./Sources/TSS/TSS_Sensor.d \
./Sources/TSS/TSS_SensorGPIO.d \
./Sources/TSS/TSS_SensorTSI.d \
./Sources/TSS/TSS_SensorTSIL.d \
./Sources/TSS/TSS_SystemSetupData.d \

OBJS_QUOTED += \
"./Sources/TSS/TSS_Freemaster.o" \
"./Sources/TSS/TSS_Sensor.o" \
"./Sources/TSS/TSS_SensorGPIO.o" \
"./Sources/TSS/TSS_SensorTSI.o" \
"./Sources/TSS/TSS_SensorTSIL.o" \
"./Sources/TSS/TSS_SystemSetupData.o" \

C_DEPS_QUOTED += \
"./Sources/TSS/TSS_Freemaster.d" \
"./Sources/TSS/TSS_Sensor.d" \
"./Sources/TSS/TSS_SensorGPIO.d" \
"./Sources/TSS/TSS_SensorTSI.d" \
"./Sources/TSS/TSS_SensorTSIL.d" \
"./Sources/TSS/TSS_SystemSetupData.d" \

OBJS_OS_FORMAT += \
./Sources/TSS/TSS_Freemaster.o \
./Sources/TSS/TSS_Sensor.o \
./Sources/TSS/TSS_SensorGPIO.o \
./Sources/TSS/TSS_SensorTSI.o \
./Sources/TSS/TSS_SensorTSIL.o \
./Sources/TSS/TSS_SystemSetupData.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/TSS/TSS_Freemaster.o: ../Sources/TSS/TSS_Freemaster.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/TSS/TSS_Freemaster.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/TSS/TSS_Freemaster.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/TSS/TSS_Sensor.o: ../Sources/TSS/TSS_Sensor.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/TSS/TSS_Sensor.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/TSS/TSS_Sensor.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/TSS/TSS_SensorGPIO.o: ../Sources/TSS/TSS_SensorGPIO.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/TSS/TSS_SensorGPIO.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/TSS/TSS_SensorGPIO.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/TSS/TSS_SensorTSI.o: ../Sources/TSS/TSS_SensorTSI.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/TSS/TSS_SensorTSI.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/TSS/TSS_SensorTSI.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/TSS/TSS_SensorTSIL.o: ../Sources/TSS/TSS_SensorTSIL.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/TSS/TSS_SensorTSIL.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/TSS/TSS_SensorTSIL.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/TSS/TSS_SystemSetupData.o: ../Sources/TSS/TSS_SystemSetupData.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/TSS/TSS_SystemSetupData.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/TSS/TSS_SystemSetupData.o"
	@echo 'Finished building: $<'
	@echo ' '


