################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/src/EXTI_driver.c \
../Drivers/src/GPIO_driver.c 

OBJS += \
./Drivers/src/EXTI_driver.o \
./Drivers/src/GPIO_driver.o 

C_DEPS += \
./Drivers/src/EXTI_driver.d \
./Drivers/src/GPIO_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/src/EXTI_driver.o: ../Drivers/src/EXTI_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32 -DNUCLEO_F767ZI -DSTM32F7 -DDEBUG -DSTM32F767ZITx -c -I../Inc -I"C:/Users/erhan/github/mcu/stm32f7_c_sw/GPIO_driver/Drivers/inc" -I"C:/Users/erhan/github/mcu/stm32f7_c_sw/GPIO_driver/CMSIS" -I"C:/Users/erhan/github/mcu/stm32f7_c_sw/GPIO_driver/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/erhan/github/mcu/stm32f7_c_sw/GPIO_driver/CMSIS/Include" -I"C:/Users/erhan/github/mcu/stm32f7_c_sw/GPIO_driver/Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/src/EXTI_driver.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/src/GPIO_driver.o: ../Drivers/src/GPIO_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32 -DNUCLEO_F767ZI -DSTM32F7 -DDEBUG -DSTM32F767ZITx -c -I../Inc -I"C:/Users/erhan/github/mcu/stm32f7_c_sw/GPIO_driver/Drivers/inc" -I"C:/Users/erhan/github/mcu/stm32f7_c_sw/GPIO_driver/CMSIS" -I"C:/Users/erhan/github/mcu/stm32f7_c_sw/GPIO_driver/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/erhan/github/mcu/stm32f7_c_sw/GPIO_driver/CMSIS/Include" -I"C:/Users/erhan/github/mcu/stm32f7_c_sw/GPIO_driver/Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/src/GPIO_driver.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

