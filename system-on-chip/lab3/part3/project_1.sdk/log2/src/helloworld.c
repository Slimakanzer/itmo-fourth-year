/******************************************************************************
*
* Copyright (C) 2009 - 2014 Xilinx, Inc.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* Use of the Software is limited solely to applications:
* (a) running on a Xilinx device, or
* (b) that interact with a Xilinx device through a bus or interconnect.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
* OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Except as contained in this notice, the name of the Xilinx shall not be used
* in advertising or otherwise to promote the sale, use or other dealings in
* this Software without prior written authorization from Xilinx.
*
******************************************************************************/

/*
 * helloworld.c: simple test application
 *
 * This application configures UART 16550 to baud rate 9600.
 * PS7 UART (Zynq) is not initialized by this application, since
 * bootrom/bsp configures it to baud rate 115200
 *
 * ------------------------------------------------
 * | UART TYPE   BAUD RATE                        |
 * ------------------------------------------------
 *   uartns550   9600
 *   uartlite    Configurable only in HW design
 *   ps7_uart    115200 (configured by bootrom/bsp)
 */

#include <stdio.h>
#include "platform.h"
#include <xil_io.h>

#define ADDR_GPIO_BASE 0x40000000
#define ADDR_LOG2_BASE 0x44A00000
#define LOG2_X 0x10
#define LOG2_Y 0x18
#define LOG2_START 0x1
#define LOG2_DONE 0x2

void print_float(float n)
{

}

int main()
{
	init_platform();
	float x_val = 1.4;
	unsigned int *x = (unsigned int *) &x_val;
	float y_val = 0.0;
	unsigned int *y = (unsigned int *) &y_val;
	int count = 1;

	while (1) {
		xil_printf("Write float value x: ");
		scanf("%f", &x_val);
		printf("%f\n", x_val);
		unsigned status  = 0;
		Xil_Out32(ADDR_LOG2_BASE + LOG2_X, *x);
		Xil_Out32(ADDR_LOG2_BASE, LOG2_START);
		Xil_Out16(ADDR_GPIO_BASE, 0xFFFF);

		while (!(status & LOG2_DONE))
		{
			status = Xil_In32(ADDR_LOG2_BASE);
		}

		Xil_Out16(ADDR_GPIO_BASE, 0xBEBE);
		*y = Xil_In32(ADDR_LOG2_BASE + LOG2_Y);

		printf("Result: %f", y_val);
		count++;
	}

	cleanup_platform();
	return 0;
}
