############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project proj_hls_stream
set_top mul
add_files mul.cpp
add_files -tb mul_test.cpp
open_solution "solution"
set_part {xc7a100t-csg324-1} -tool vivado
create_clock -period 10 -name default
#source "./proj_hls_stream/solution/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
