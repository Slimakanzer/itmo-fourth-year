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
reg clk;
reg uart_rx = 0;
wire uart_out;
reg reset_rtl = 1;
wire [15:0] gpio;
design_1_wrapper uut (
 .clk_100MHz(clk),
 .rst_i(reset_rtl),
 .uart_o(uart_out),
 .uart_i(uart_rx),
 .gpio_bo_tri_o(gpio)
);

initial begin
 clk = 0;
 reset_rtl = 1;

 #100;
 reset_rtl = 0;

end
always begin
 #5;
 clk = ~clk;
end

endmodule
