// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xmul.h"

extern XMul_Config XMul_ConfigTable[];

XMul_Config *XMul_LookupConfig(u16 DeviceId) {
	XMul_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XMUL_NUM_INSTANCES; Index++) {
		if (XMul_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XMul_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XMul_Initialize(XMul *InstancePtr, u16 DeviceId) {
	XMul_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XMul_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XMul_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

