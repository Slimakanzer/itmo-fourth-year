// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xmylog2.h"

extern XMylog2_Config XMylog2_ConfigTable[];

XMylog2_Config *XMylog2_LookupConfig(u16 DeviceId) {
	XMylog2_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XMYLOG2_NUM_INSTANCES; Index++) {
		if (XMylog2_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XMylog2_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XMylog2_Initialize(XMylog2 *InstancePtr, u16 DeviceId) {
	XMylog2_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XMylog2_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XMylog2_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

