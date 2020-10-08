// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XMUL_H
#define XMUL_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xmul_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef struct {
    u16 DeviceId;
    u32 Axilites_BaseAddress;
} XMul_Config;
#endif

typedef struct {
    u32 Axilites_BaseAddress;
    u32 IsReady;
} XMul;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XMul_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XMul_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XMul_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XMul_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XMul_Initialize(XMul *InstancePtr, u16 DeviceId);
XMul_Config* XMul_LookupConfig(u16 DeviceId);
int XMul_CfgInitialize(XMul *InstancePtr, XMul_Config *ConfigPtr);
#else
int XMul_Initialize(XMul *InstancePtr, const char* InstanceName);
int XMul_Release(XMul *InstancePtr);
#endif


void XMul_Set_n(XMul *InstancePtr, u32 Data);
u32 XMul_Get_n(XMul *InstancePtr);
u32 XMul_Get_a_BaseAddress(XMul *InstancePtr);
u32 XMul_Get_a_HighAddress(XMul *InstancePtr);
u32 XMul_Get_a_TotalBytes(XMul *InstancePtr);
u32 XMul_Get_a_BitWidth(XMul *InstancePtr);
u32 XMul_Get_a_Depth(XMul *InstancePtr);
u32 XMul_Write_a_Words(XMul *InstancePtr, int offset, int *data, int length);
u32 XMul_Read_a_Words(XMul *InstancePtr, int offset, int *data, int length);
u32 XMul_Write_a_Bytes(XMul *InstancePtr, int offset, char *data, int length);
u32 XMul_Read_a_Bytes(XMul *InstancePtr, int offset, char *data, int length);
u32 XMul_Get_b_BaseAddress(XMul *InstancePtr);
u32 XMul_Get_b_HighAddress(XMul *InstancePtr);
u32 XMul_Get_b_TotalBytes(XMul *InstancePtr);
u32 XMul_Get_b_BitWidth(XMul *InstancePtr);
u32 XMul_Get_b_Depth(XMul *InstancePtr);
u32 XMul_Write_b_Words(XMul *InstancePtr, int offset, int *data, int length);
u32 XMul_Read_b_Words(XMul *InstancePtr, int offset, int *data, int length);
u32 XMul_Write_b_Bytes(XMul *InstancePtr, int offset, char *data, int length);
u32 XMul_Read_b_Bytes(XMul *InstancePtr, int offset, char *data, int length);
u32 XMul_Get_c_BaseAddress(XMul *InstancePtr);
u32 XMul_Get_c_HighAddress(XMul *InstancePtr);
u32 XMul_Get_c_TotalBytes(XMul *InstancePtr);
u32 XMul_Get_c_BitWidth(XMul *InstancePtr);
u32 XMul_Get_c_Depth(XMul *InstancePtr);
u32 XMul_Write_c_Words(XMul *InstancePtr, int offset, int *data, int length);
u32 XMul_Read_c_Words(XMul *InstancePtr, int offset, int *data, int length);
u32 XMul_Write_c_Bytes(XMul *InstancePtr, int offset, char *data, int length);
u32 XMul_Read_c_Bytes(XMul *InstancePtr, int offset, char *data, int length);

#ifdef __cplusplus
}
#endif

#endif
