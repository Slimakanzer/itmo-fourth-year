// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xmylog2.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XMylog2_CfgInitialize(XMylog2 *InstancePtr, XMylog2_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Axilites_BaseAddress = ConfigPtr->Axilites_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XMylog2_Start(XMylog2 *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMylog2_ReadReg(InstancePtr->Axilites_BaseAddress, XMYLOG2_AXILITES_ADDR_AP_CTRL) & 0x80;
    XMylog2_WriteReg(InstancePtr->Axilites_BaseAddress, XMYLOG2_AXILITES_ADDR_AP_CTRL, Data | 0x01);
}

u32 XMylog2_IsDone(XMylog2 *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMylog2_ReadReg(InstancePtr->Axilites_BaseAddress, XMYLOG2_AXILITES_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XMylog2_IsIdle(XMylog2 *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMylog2_ReadReg(InstancePtr->Axilites_BaseAddress, XMYLOG2_AXILITES_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XMylog2_IsReady(XMylog2 *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMylog2_ReadReg(InstancePtr->Axilites_BaseAddress, XMYLOG2_AXILITES_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XMylog2_EnableAutoRestart(XMylog2 *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMylog2_WriteReg(InstancePtr->Axilites_BaseAddress, XMYLOG2_AXILITES_ADDR_AP_CTRL, 0x80);
}

void XMylog2_DisableAutoRestart(XMylog2 *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMylog2_WriteReg(InstancePtr->Axilites_BaseAddress, XMYLOG2_AXILITES_ADDR_AP_CTRL, 0);
}

void XMylog2_Set_x(XMylog2 *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMylog2_WriteReg(InstancePtr->Axilites_BaseAddress, XMYLOG2_AXILITES_ADDR_X_DATA, Data);
}

u32 XMylog2_Get_x(XMylog2 *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMylog2_ReadReg(InstancePtr->Axilites_BaseAddress, XMYLOG2_AXILITES_ADDR_X_DATA);
    return Data;
}

u32 XMylog2_Get_y(XMylog2 *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMylog2_ReadReg(InstancePtr->Axilites_BaseAddress, XMYLOG2_AXILITES_ADDR_Y_DATA);
    return Data;
}

u32 XMylog2_Get_y_vld(XMylog2 *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMylog2_ReadReg(InstancePtr->Axilites_BaseAddress, XMYLOG2_AXILITES_ADDR_Y_CTRL);
    return Data & 0x1;
}

void XMylog2_InterruptGlobalEnable(XMylog2 *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMylog2_WriteReg(InstancePtr->Axilites_BaseAddress, XMYLOG2_AXILITES_ADDR_GIE, 1);
}

void XMylog2_InterruptGlobalDisable(XMylog2 *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMylog2_WriteReg(InstancePtr->Axilites_BaseAddress, XMYLOG2_AXILITES_ADDR_GIE, 0);
}

void XMylog2_InterruptEnable(XMylog2 *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XMylog2_ReadReg(InstancePtr->Axilites_BaseAddress, XMYLOG2_AXILITES_ADDR_IER);
    XMylog2_WriteReg(InstancePtr->Axilites_BaseAddress, XMYLOG2_AXILITES_ADDR_IER, Register | Mask);
}

void XMylog2_InterruptDisable(XMylog2 *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XMylog2_ReadReg(InstancePtr->Axilites_BaseAddress, XMYLOG2_AXILITES_ADDR_IER);
    XMylog2_WriteReg(InstancePtr->Axilites_BaseAddress, XMYLOG2_AXILITES_ADDR_IER, Register & (~Mask));
}

void XMylog2_InterruptClear(XMylog2 *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMylog2_WriteReg(InstancePtr->Axilites_BaseAddress, XMYLOG2_AXILITES_ADDR_ISR, Mask);
}

u32 XMylog2_InterruptGetEnabled(XMylog2 *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMylog2_ReadReg(InstancePtr->Axilites_BaseAddress, XMYLOG2_AXILITES_ADDR_IER);
}

u32 XMylog2_InterruptGetStatus(XMylog2 *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMylog2_ReadReg(InstancePtr->Axilites_BaseAddress, XMYLOG2_AXILITES_ADDR_ISR);
}

