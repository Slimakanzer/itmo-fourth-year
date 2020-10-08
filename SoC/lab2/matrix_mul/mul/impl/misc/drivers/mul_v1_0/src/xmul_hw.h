// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
// AXILiteS
// 0x000 : reserved
// 0x004 : reserved
// 0x008 : reserved
// 0x00c : reserved
// 0x800 : Data signal of n
//         bit 7~0 - n[7:0] (Read/Write)
//         others  - reserved
// 0x804 : reserved
// 0x200 ~
// 0x3ff : Memory 'a' (100 * 32b)
//         Word n : bit [31:0] - a[n]
// 0x400 ~
// 0x5ff : Memory 'b' (100 * 32b)
//         Word n : bit [31:0] - b[n]
// 0x600 ~
// 0x7ff : Memory 'c' (100 * 32b)
//         Word n : bit [31:0] - c[n]
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XMUL_AXILITES_ADDR_N_DATA 0x800
#define XMUL_AXILITES_BITS_N_DATA 8
#define XMUL_AXILITES_ADDR_A_BASE 0x200
#define XMUL_AXILITES_ADDR_A_HIGH 0x3ff
#define XMUL_AXILITES_WIDTH_A     32
#define XMUL_AXILITES_DEPTH_A     100
#define XMUL_AXILITES_ADDR_B_BASE 0x400
#define XMUL_AXILITES_ADDR_B_HIGH 0x5ff
#define XMUL_AXILITES_WIDTH_B     32
#define XMUL_AXILITES_DEPTH_B     100
#define XMUL_AXILITES_ADDR_C_BASE 0x600
#define XMUL_AXILITES_ADDR_C_HIGH 0x7ff
#define XMUL_AXILITES_WIDTH_C     32
#define XMUL_AXILITES_DEPTH_C     100

