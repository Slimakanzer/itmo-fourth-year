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

void print(const char8 *ptr);

#define ADDR_GPIO_BASE 0x40000000

void matrix_mul(uint n, int *a, int *b, int *c)
{
    uint i = 0;
    uint j = 0;
    uint k = 0;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
        	int acc = 0;
            for (k = 0; k < n; ++k){
                acc += a[i*n + k] * b[k*n + j];
            }

            c[i*n + j] = acc;
        }
    }
}

void read_matrix(int *m, uint n)
{
	for (uint i = 0; i < n; i++){
		for (uint j = 0; j < n; j++){
			int val;
			scanf("%d", &val);
			m[i*n + j] = val;
			xil_printf("%d ", val);
		}
	}
	xil_printf("\r\n");
}

void print_matrix(int *m, uint n)
{
	for (uint i = 0; i < n; i++){
		for (uint j = 0; j < n; j++){
			xil_printf("%d ", m[i*n + j]);
		}
		xil_printf("\r\n");
	}
}

int main()
{
	int a[100];
	int b[100];
	int c[100];
	uint n;
	init_platform();

	while (1) {
		Xil_Out16(ADDR_GPIO_BASE, 0xFE12);
		xil_printf("Write matrix size: ");
		scanf("%u", &n);
		if (n > 10)
		{
			xil_printf("Incorrect size of n: %u	\r\n", n);
			continue;
		}
		xil_printf("%u 							\r\n", n);

		xil_printf("Write matrix A:				\r\n");
		Xil_Out16(ADDR_GPIO_BASE, 0xFE10);
		read_matrix(a, n);

		xil_printf("Write matrix B:				\r\n");
		Xil_Out16(ADDR_GPIO_BASE, 0xFE40);
		read_matrix(b, n);

		Xil_Out16(ADDR_GPIO_BASE, 0xFEC6);
		matrix_mul(n, a, b, c);
		print_matrix(c, n);
	}

	cleanup_platform();
	return 0;
}
