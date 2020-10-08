############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project matrix_mul
set_top mul
add_files src/mul.c
add_files -tb src/mul_test.c -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "mul"
set_part {xc7a100t-csg324-1} -tool vivado
create_clock -period 10 -name default
#source "./matrix_mul/mul/directives.tcl"
csim_design
csynth_design
cosim_design -trace_level port
export_design -format ip_catalog
