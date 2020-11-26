`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/03/2020 05:45:48 PM
// Design Name: 
// Module Name: all_dev_tb
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module all_dev_tb;
reg diff_clock_rtl_clk_n;
reg diff_clock_rtl_clk_p;
reg uart_rx = 0;
wire uart_out;
reg reset_rtl = 1;
wire [16:0] gpio;
design_1_wrapper uut (
 .diff_clock_rtl_0_clk_n(diff_clock_rtl_clk_n),
 .diff_clock_rtl_0_clk_p(diff_clock_rtl_clk_p),
 .rst_i(reset_rtl),
 .uart_o(uart_out),
 .uart_i(uart_rx),
 .gpio_bo(gpio)
);

initial begin
 diff_clock_rtl_clk_p = 0;
 diff_clock_rtl_clk_n = 1;
 reset_rtl = 1;

 #100;
 reset_rtl = 0;

end
always begin
 #5;
 diff_clock_rtl_clk_n = ~diff_clock_rtl_clk_n;
 diff_clock_rtl_clk_p = ~diff_clock_rtl_clk_p;
end

endmodule
