// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XMYLOG2_H
#define XMYLOG2_H

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
#include "xmylog2_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef struct {
    u16 DeviceId;
    u32 Axilites_BaseAddress;
} XMylog2_Config;
#endif

typedef struct {
    u32 Axilites_BaseAddress;
    u32 IsReady;
} XMylog2;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XMylog2_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XMylog2_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XMylog2_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XMylog2_ReadReg(BaseAddress, RegOffset) \
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
int XMylog2_Initialize(XMylog2 *InstancePtr, u16 DeviceId);
XMylog2_Config* XMylog2_LookupConfig(u16 DeviceId);
int XMylog2_CfgInitialize(XMylog2 *InstancePtr, XMylog2_Config *ConfigPtr);
#else
int XMylog2_Initialize(XMylog2 *InstancePtr, const char* InstanceName);
int XMylog2_Release(XMylog2 *InstancePtr);
#endif

void XMylog2_Start(XMylog2 *InstancePtr);
u32 XMylog2_IsDone(XMylog2 *InstancePtr);
u32 XMylog2_IsIdle(XMylog2 *InstancePtr);
u32 XMylog2_IsReady(XMylog2 *InstancePtr);
void XMylog2_EnableAutoRestart(XMylog2 *InstancePtr);
void XMylog2_DisableAutoRestart(XMylog2 *InstancePtr);

void XMylog2_Set_x(XMylog2 *InstancePtr, u32 Data);
u32 XMylog2_Get_x(XMylog2 *InstancePtr);
u32 XMylog2_Get_y(XMylog2 *InstancePtr);
u32 XMylog2_Get_y_vld(XMylog2 *InstancePtr);

void XMylog2_InterruptGlobalEnable(XMylog2 *InstancePtr);
void XMylog2_InterruptGlobalDisable(XMylog2 *InstancePtr);
void XMylog2_InterruptEnable(XMylog2 *InstancePtr, u32 Mask);
void XMylog2_InterruptDisable(XMylog2 *InstancePtr, u32 Mask);
void XMylog2_InterruptClear(XMylog2 *InstancePtr, u32 Mask);
u32 XMylog2_InterruptGetEnabled(XMylog2 *InstancePtr);
u32 XMylog2_InterruptGetStatus(XMylog2 *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
