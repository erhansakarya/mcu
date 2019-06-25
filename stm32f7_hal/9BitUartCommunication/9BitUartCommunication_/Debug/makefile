################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include Drivers/STM32F7xx_HAL_Driver/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
9BitUartCommunication_.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
9BitUartCommunication_.list \


# All Target
all: 9BitUartCommunication_.elf secondary-outputs

# Tool invocations
9BitUartCommunication_.elf: $(OBJS) $(USER_OBJS) C:\Users\erhan\github\mcu\stm32f7_hal\9BitUartCommunication\9BitUartCommunication_\STM32F767ZITX_FLASH.ld
	arm-none-eabi-gcc -o "9BitUartCommunication_.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m7 -T"C:\Users\erhan\github\mcu\stm32f7_hal\9BitUartCommunication\9BitUartCommunication_\STM32F767ZITX_FLASH.ld" --specs=nosys.specs -Wl,-Map="9BitUartCommunication_.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

9BitUartCommunication_.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "9BitUartCommunication_.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
