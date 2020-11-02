//Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2019.1 (win64) Build 2552052 Fri May 24 14:49:42 MDT 2019
//Date        : Tue Nov  3 00:43:04 2020
//Host        : whoami running 64-bit major release  (build 9200)
//Command     : generate_target design_1_wrapper.bd
//Design      : design_1_wrapper
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

module design_1_wrapper
   (clk_100MHz,
    gpio_bo_tri_o,
    rst_i,
    uart_i,
    uart_o);
  input clk_100MHz;
  output [15:0]gpio_bo_tri_o;
  input rst_i;
  input uart_i;
  output uart_o;

  wire clk_100MHz;
  wire [15:0]gpio_bo_tri_o;
  wire rst_i;
  wire uart_i;
  wire uart_o;

  design_1 design_1_i
       (.clk_100MHz(clk_100MHz),
        .gpio_bo_tri_o(gpio_bo_tri_o),
        .rst_i(rst_i),
        .uart_i(uart_i),
        .uart_o(uart_o));
endmodule
