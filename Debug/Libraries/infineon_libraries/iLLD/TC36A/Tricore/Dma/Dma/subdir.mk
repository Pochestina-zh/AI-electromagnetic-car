################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/infineon_libraries/iLLD/TC36A/Tricore/Dma/Dma/IfxDma_Dma.c 

OBJS += \
./Libraries/infineon_libraries/iLLD/TC36A/Tricore/Dma/Dma/IfxDma_Dma.o 

COMPILED_SRCS += \
./Libraries/infineon_libraries/iLLD/TC36A/Tricore/Dma/Dma/IfxDma_Dma.src 

C_DEPS += \
./Libraries/infineon_libraries/iLLD/TC36A/Tricore/Dma/Dma/IfxDma_Dma.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/infineon_libraries/iLLD/TC36A/Tricore/Dma/Dma/%.src: ../Libraries/infineon_libraries/iLLD/TC36A/Tricore/Dma/Dma/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -D__CPU__=tc36x -I"G:\ADS\AI_CAR\CODE" -I"G:\ADS\AI_CAR\Libraries" -I"G:\ADS\AI_CAR\Libraries\doc" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\Configurations" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\_Build" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\_Impl" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\_Lib" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\_Lib\DataHandling" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\_Lib\InternalMux" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\_PinMap" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Asclin" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Asclin\Asc" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Asclin\Lin" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Asclin\Spi" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Asclin\Std" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Can" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Can\Can" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Can\Std" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Ccu6" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Ccu6\Icu" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Ccu6\PwmBc" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Ccu6\PwmHl" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Ccu6\Std" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Ccu6\Timer" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Ccu6\TimerWithTrigger" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Ccu6\TPwm" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Convctrl" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Convctrl\Std" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Cpu" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Cpu\Irq" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Cpu\Std" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Cpu\Trap" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Dma" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Dma\Dma" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Dma\Std" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Dts" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Dts\Dts" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Dts\Std" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Edsadc" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Edsadc\Edsadc" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Edsadc\Std" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Eray" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Eray\Eray" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Eray\Std" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Evadc" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Evadc\Adc" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Evadc\Std" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Fce" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Fce\Crc" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Fce\Std" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Flash" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Flash\Std" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Geth" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Geth\Eth" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Geth\Std" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Gpt12" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Gpt12\IncrEnc" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Gpt12\Std" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Gtm" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Gtm\Atom" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Gtm\Atom\Pwm" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Gtm\Atom\PwmHl" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Gtm\Atom\Timer" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Gtm\Std" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Gtm\Tim" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Gtm\Tim\In" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Gtm\Tim\Timer" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Gtm\Tom" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Gtm\Tom\Pwm" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Gtm\Tom\PwmHl" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Gtm\Tom\Timer" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Gtm\Trig" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Hssl" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Hssl\Hssl" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Hssl\Std" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\I2c" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\I2c\I2c" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\I2c\Std" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Iom" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Iom\Driver" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Iom\Iom" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Iom\Std" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Msc" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Msc\Msc" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Msc\Std" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Mtu" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Mtu\Std" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Pms" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Pms\Std" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Port" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Port\Io" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Port\Std" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Psi5" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Psi5\Psi5" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Psi5\Std" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Psi5s" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Psi5s\Psi5s" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Psi5s\Std" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Qspi" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Qspi\SpiMaster" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Qspi\SpiSlave" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Qspi\Std" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Scu" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Scu\Std" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Sent" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Sent\Sent" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Sent\Std" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Smu" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Smu\Smu" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Smu\Std" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Src" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Src\Std" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Stm" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Stm\Std" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\iLLD\TC36A\Tricore\Stm\Timer" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\Infra" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\Infra\Platform" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\Infra\Platform\Tricore" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\Infra\Platform\Tricore\Compilers" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\Infra\Sfr" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\Infra\Sfr\TC36A" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\Infra\Sfr\TC36A\_Reg" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\Infra\Ssw" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\Infra\Ssw\TC36A" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\Infra\Ssw\TC36A\Tricore" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\Service" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\Service\CpuGeneric" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\Service\CpuGeneric\_Utilities" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\Service\CpuGeneric\If" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\Service\CpuGeneric\If\Ccu6If" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\Service\CpuGeneric\StdIf" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\Service\CpuGeneric\SysSe" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\Service\CpuGeneric\SysSe\Bsp" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\Service\CpuGeneric\SysSe\Comm" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\Service\CpuGeneric\SysSe\General" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\Service\CpuGeneric\SysSe\Math" -I"G:\ADS\AI_CAR\Libraries\infineon_libraries\Service\CpuGeneric\SysSe\Time" -I"G:\ADS\AI_CAR\Libraries\seekfree_libraries" -I"G:\ADS\AI_CAR\Libraries\seekfree_libraries\common" -I"G:\ADS\AI_CAR\Libraries\seekfree_peripheral" -I"G:\ADS\AI_CAR\USER" --iso=99 --c++14 --language=+volatile --anachronisms --fp-model=3 --fp-model=c --fp-model=f --fp-model=l --fp-model=n --fp-model=r --fp-model=z -O0 --tradeoff=0 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc36x -o "$@"  "$<"  -cs --dep-file=$(@:.src=.d) --misrac-version=2012 -N0 -Z0 -Y0 2>&1;
	@echo 'Finished building: $<'
	@echo ' '

Libraries/infineon_libraries/iLLD/TC36A/Tricore/Dma/Dma/%.o: ./Libraries/infineon_libraries/iLLD/TC36A/Tricore/Dma/Dma/%.src
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -o  "$@" "$<" --list-format=L1 --optimize=gs
	@echo 'Finished building: $<'
	@echo ' '


