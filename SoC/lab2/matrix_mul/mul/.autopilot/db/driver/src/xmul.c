// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xmul.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XMul_CfgInitialize(XMul *InstancePtr, XMul_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Axilites_BaseAddress = ConfigPtr->Axilites_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XMul_Set_n(XMul *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMul_WriteReg(InstancePtr->Axilites_BaseAddress, XMUL_AXILITES_ADDR_N_DATA, Data);
}

u32 XMul_Get_n(XMul *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMul_ReadReg(InstancePtr->Axilites_BaseAddress, XMUL_AXILITES_ADDR_N_DATA);
    return Data;
}

u32 XMul_Get_a_BaseAddress(XMul *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Axilites_BaseAddress + XMUL_AXILITES_ADDR_A_BASE);
}

u32 XMul_Get_a_HighAddress(XMul *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Axilites_BaseAddress + XMUL_AXILITES_ADDR_A_HIGH);
}

u32 XMul_Get_a_TotalBytes(XMul *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XMUL_AXILITES_ADDR_A_HIGH - XMUL_AXILITES_ADDR_A_BASE + 1);
}

u32 XMul_Get_a_BitWidth(XMul *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMUL_AXILITES_WIDTH_A;
}

u32 XMul_Get_a_Depth(XMul *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMUL_AXILITES_DEPTH_A;
}

u32 XMul_Write_a_Words(XMul *InstancePtr, int offset, int *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMUL_AXILITES_ADDR_A_HIGH - XMUL_AXILITES_ADDR_A_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Axilites_BaseAddress + XMUL_AXILITES_ADDR_A_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XMul_Read_a_Words(XMul *InstancePtr, int offset, int *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMUL_AXILITES_ADDR_A_HIGH - XMUL_AXILITES_ADDR_A_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Axilites_BaseAddress + XMUL_AXILITES_ADDR_A_BASE + (offset + i)*4);
    }
    return length;
}

u32 XMul_Write_a_Bytes(XMul *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMUL_AXILITES_ADDR_A_HIGH - XMUL_AXILITES_ADDR_A_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Axilites_BaseAddress + XMUL_AXILITES_ADDR_A_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XMul_Read_a_Bytes(XMul *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMUL_AXILITES_ADDR_A_HIGH - XMUL_AXILITES_ADDR_A_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Axilites_BaseAddress + XMUL_AXILITES_ADDR_A_BASE + offset + i);
    }
    return length;
}

u32 XMul_Get_b_BaseAddress(XMul *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Axilites_BaseAddress + XMUL_AXILITES_ADDR_B_BASE);
}

u32 XMul_Get_b_HighAddress(XMul *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Axilites_BaseAddress + XMUL_AXILITES_ADDR_B_HIGH);
}

u32 XMul_Get_b_TotalBytes(XMul *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XMUL_AXILITES_ADDR_B_HIGH - XMUL_AXILITES_ADDR_B_BASE + 1);
}

u32 XMul_Get_b_BitWidth(XMul *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMUL_AXILITES_WIDTH_B;
}

u32 XMul_Get_b_Depth(XMul *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMUL_AXILITES_DEPTH_B;
}

u32 XMul_Write_b_Words(XMul *InstancePtr, int offset, int *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMUL_AXILITES_ADDR_B_HIGH - XMUL_AXILITES_ADDR_B_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Axilites_BaseAddress + XMUL_AXILITES_ADDR_B_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XMul_Read_b_Words(XMul *InstancePtr, int offset, int *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMUL_AXILITES_ADDR_B_HIGH - XMUL_AXILITES_ADDR_B_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Axilites_BaseAddress + XMUL_AXILITES_ADDR_B_BASE + (offset + i)*4);
    }
    return length;
}

u32 XMul_Write_b_Bytes(XMul *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMUL_AXILITES_ADDR_B_HIGH - XMUL_AXILITES_ADDR_B_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Axilites_BaseAddress + XMUL_AXILITES_ADDR_B_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XMul_Read_b_Bytes(XMul *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMUL_AXILITES_ADDR_B_HIGH - XMUL_AXILITES_ADDR_B_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Axilites_BaseAddress + XMUL_AXILITES_ADDR_B_BASE + offset + i);
    }
    return length;
}

u32 XMul_Get_c_BaseAddress(XMul *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Axilites_BaseAddress + XMUL_AXILITES_ADDR_C_BASE);
}

u32 XMul_Get_c_HighAddress(XMul *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Axilites_BaseAddress + XMUL_AXILITES_ADDR_C_HIGH);
}

u32 XMul_Get_c_TotalBytes(XMul *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XMUL_AXILITES_ADDR_C_HIGH - XMUL_AXILITES_ADDR_C_BASE + 1);
}

u32 XMul_Get_c_BitWidth(XMul *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMUL_AXILITES_WIDTH_C;
}

u32 XMul_Get_c_Depth(XMul *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMUL_AXILITES_DEPTH_C;
}

u32 XMul_Write_c_Words(XMul *InstancePtr, int offset, int *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMUL_AXILITES_ADDR_C_HIGH - XMUL_AXILITES_ADDR_C_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Axilites_BaseAddress + XMUL_AXILITES_ADDR_C_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XMul_Read_c_Words(XMul *InstancePtr, int offset, int *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMUL_AXILITES_ADDR_C_HIGH - XMUL_AXILITES_ADDR_C_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Axilites_BaseAddress + XMUL_AXILITES_ADDR_C_BASE + (offset + i)*4);
    }
    return length;
}

u32 XMul_Write_c_Bytes(XMul *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMUL_AXILITES_ADDR_C_HIGH - XMUL_AXILITES_ADDR_C_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Axilites_BaseAddress + XMUL_AXILITES_ADDR_C_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XMul_Read_c_Bytes(XMul *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMUL_AXILITES_ADDR_C_HIGH - XMUL_AXILITES_ADDR_C_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Axilites_BaseAddress + XMUL_AXILITES_ADDR_C_BASE + offset + i);
    }
    return length;
}

