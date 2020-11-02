################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/slimakanzer/source/itmo-fourth-year/SoC/lab3/part2/log2.c 

OBJS += \
./source/log2.o 

C_DEPS += \
./source/log2.d 


# Each subdirectory must supply rules for building sources it contributes
source/log2.o: C:/Users/slimakanzer/source/itmo-fourth-year/SoC/lab3/part2/log2.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -DAESL_TB -D__llvm__ -D__llvm__ -IC:/Xilinx/Vivado/2019.1/include -IC:/Xilinx/Vivado/2019.1/include/ap_sysc -IC:/Xilinx/Vivado/2019.1/win64/tools/systemc/include -IC:/Users/slimakanzer/source/itmo-fourth-year/SoC/lab3/part2 -IC:/Xilinx/Vivado/2019.1/include/etc -IC:/Xilinx/Vivado/2019.1/win64/tools/auto_cc/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


