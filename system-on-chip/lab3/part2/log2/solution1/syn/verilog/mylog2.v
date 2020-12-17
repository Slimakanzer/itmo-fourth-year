// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2019.1
// Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

(* CORE_GENERATION_INFO="mylog2,hls_ip_2019_1,{HLS_INPUT_TYPE=c,HLS_INPUT_FLOAT=1,HLS_INPUT_FIXED=0,HLS_INPUT_PART=xc7a100t-csg324-1,HLS_INPUT_CLOCK=10.000000,HLS_INPUT_ARCH=others,HLS_SYN_CLOCK=9.250875,HLS_SYN_LAT=83,HLS_SYN_TPT=none,HLS_SYN_MEM=0,HLS_SYN_DSP=10,HLS_SYN_FF=1867,HLS_SYN_LUT=2170,HLS_VERSION=2019_1}" *)

module mylog2 (
        ap_clk,
        ap_rst_n,
        s_axi_AXILiteS_AWVALID,
        s_axi_AXILiteS_AWREADY,
        s_axi_AXILiteS_AWADDR,
        s_axi_AXILiteS_WVALID,
        s_axi_AXILiteS_WREADY,
        s_axi_AXILiteS_WDATA,
        s_axi_AXILiteS_WSTRB,
        s_axi_AXILiteS_ARVALID,
        s_axi_AXILiteS_ARREADY,
        s_axi_AXILiteS_ARADDR,
        s_axi_AXILiteS_RVALID,
        s_axi_AXILiteS_RREADY,
        s_axi_AXILiteS_RDATA,
        s_axi_AXILiteS_RRESP,
        s_axi_AXILiteS_BVALID,
        s_axi_AXILiteS_BREADY,
        s_axi_AXILiteS_BRESP,
        interrupt
);

parameter    ap_ST_fsm_state1 = 25'd1;
parameter    ap_ST_fsm_state2 = 25'd2;
parameter    ap_ST_fsm_state3 = 25'd4;
parameter    ap_ST_fsm_state4 = 25'd8;
parameter    ap_ST_fsm_state5 = 25'd16;
parameter    ap_ST_fsm_state6 = 25'd32;
parameter    ap_ST_fsm_state7 = 25'd64;
parameter    ap_ST_fsm_pp0_stage0 = 25'd128;
parameter    ap_ST_fsm_pp0_stage1 = 25'd256;
parameter    ap_ST_fsm_state11 = 25'd512;
parameter    ap_ST_fsm_state12 = 25'd1024;
parameter    ap_ST_fsm_state13 = 25'd2048;
parameter    ap_ST_fsm_state14 = 25'd4096;
parameter    ap_ST_fsm_state15 = 25'd8192;
parameter    ap_ST_fsm_state16 = 25'd16384;
parameter    ap_ST_fsm_state17 = 25'd32768;
parameter    ap_ST_fsm_state18 = 25'd65536;
parameter    ap_ST_fsm_state19 = 25'd131072;
parameter    ap_ST_fsm_state20 = 25'd262144;
parameter    ap_ST_fsm_state21 = 25'd524288;
parameter    ap_ST_fsm_state22 = 25'd1048576;
parameter    ap_ST_fsm_state23 = 25'd2097152;
parameter    ap_ST_fsm_state24 = 25'd4194304;
parameter    ap_ST_fsm_state25 = 25'd8388608;
parameter    ap_ST_fsm_state26 = 25'd16777216;
parameter    C_S_AXI_AXILITES_DATA_WIDTH = 32;
parameter    C_S_AXI_AXILITES_ADDR_WIDTH = 5;
parameter    C_S_AXI_DATA_WIDTH = 32;

parameter C_S_AXI_AXILITES_WSTRB_WIDTH = (32 / 8);
parameter C_S_AXI_WSTRB_WIDTH = (32 / 8);

input   ap_clk;
input   ap_rst_n;
input   s_axi_AXILiteS_AWVALID;
output   s_axi_AXILiteS_AWREADY;
input  [C_S_AXI_AXILITES_ADDR_WIDTH - 1:0] s_axi_AXILiteS_AWADDR;
input   s_axi_AXILiteS_WVALID;
output   s_axi_AXILiteS_WREADY;
input  [C_S_AXI_AXILITES_DATA_WIDTH - 1:0] s_axi_AXILiteS_WDATA;
input  [C_S_AXI_AXILITES_WSTRB_WIDTH - 1:0] s_axi_AXILiteS_WSTRB;
input   s_axi_AXILiteS_ARVALID;
output   s_axi_AXILiteS_ARREADY;
input  [C_S_AXI_AXILITES_ADDR_WIDTH - 1:0] s_axi_AXILiteS_ARADDR;
output   s_axi_AXILiteS_RVALID;
input   s_axi_AXILiteS_RREADY;
output  [C_S_AXI_AXILITES_DATA_WIDTH - 1:0] s_axi_AXILiteS_RDATA;
output  [1:0] s_axi_AXILiteS_RRESP;
output   s_axi_AXILiteS_BVALID;
input   s_axi_AXILiteS_BREADY;
output  [1:0] s_axi_AXILiteS_BRESP;
output   interrupt;

 reg    ap_rst_n_inv;
wire    ap_start;
reg    ap_done;
reg    ap_idle;
(* fsm_encoding = "none" *) reg   [24:0] ap_CS_fsm;
wire    ap_CS_fsm_state1;
reg    ap_ready;
wire   [31:0] x;
reg    y_ap_vld;
reg   [31:0] res_lo_0_reg_172;
reg   [41:0] val_2_reg_184;
reg   [4:0] i_0_reg_193;
wire   [22:0] tmp_V_1_fu_237_p1;
reg   [22:0] tmp_V_1_reg_506;
wire    ap_CS_fsm_state4;
wire   [8:0] add_ln339_fu_245_p2;
reg   [8:0] add_ln339_reg_511;
reg   [0:0] isNeg_reg_516;
wire   [7:0] sub_ln1311_fu_259_p2;
reg   [7:0] sub_ln1311_reg_522;
wire   [31:0] val_V_fu_333_p3;
wire    ap_CS_fsm_state5;
wire   [31:0] zext_ln21_fu_368_p1;
wire    ap_CS_fsm_state6;
wire   [0:0] icmp_ln18_fu_350_p2;
wire   [31:0] res_hi_fu_372_p2;
wire   [0:0] icmp_ln24_fu_388_p2;
wire    ap_CS_fsm_state7;
wire   [31:0] val_4_fu_404_p1;
wire   [31:0] res_hi_2_fu_408_p2;
wire   [41:0] zext_ln31_1_fu_414_p1;
wire   [0:0] icmp_ln31_fu_418_p2;
reg   [0:0] icmp_ln31_reg_564;
wire    ap_CS_fsm_pp0_stage0;
wire    ap_block_state8_pp0_stage0_iter0;
wire    ap_block_state10_pp0_stage0_iter1;
wire    ap_block_pp0_stage0_11001;
wire   [4:0] i_fu_424_p2;
reg   [4:0] i_reg_568;
reg    ap_enable_reg_pp0_iter0;
wire   [63:0] zext_ln31_fu_430_p1;
wire   [0:0] icmp_ln36_fu_450_p2;
reg   [0:0] icmp_ln36_reg_579;
wire    ap_CS_fsm_pp0_stage1;
wire    ap_block_state9_pp0_stage1_iter0;
wire    ap_block_pp0_stage1_11001;
wire   [30:0] trunc_ln36_fu_456_p1;
reg   [30:0] trunc_ln36_reg_585;
reg   [41:0] tmp_s_reg_590;
reg   [40:0] tmp_14_reg_595;
wire   [31:0] res_lo_fu_485_p3;
reg    ap_enable_reg_pp0_iter1;
wire   [41:0] select_ln36_fu_495_p3;
wire   [31:0] grp_fu_215_p1;
reg   [31:0] tmp_4_reg_610;
wire    ap_CS_fsm_state16;
wire   [31:0] grp_fu_208_p2;
reg   [31:0] tmp_6_reg_615;
wire    ap_CS_fsm_state20;
wire   [31:0] grp_fu_219_p1;
reg   [31:0] tmp_7_reg_620;
wire   [31:0] grp_fu_204_p2;
reg   [31:0] tmp_8_reg_625;
wire    ap_CS_fsm_state25;
wire    ap_block_pp0_stage0_subdone;
reg    ap_condition_pp0_exit_iter0_state8;
wire    ap_block_pp0_stage1_subdone;
reg   [31:0] res_hi_0_reg_129;
reg   [31:0] val_0_reg_141;
reg   [31:0] res_hi_1_reg_151;
reg   [31:0] val_1_reg_162;
wire    ap_block_pp0_stage0;
reg   [41:0] ap_phi_mux_val_2_phi_fu_187_p4;
reg   [4:0] ap_phi_mux_i_0_phi_fu_197_p4;
wire    ap_CS_fsm_state26;
wire    ap_CS_fsm_state21;
reg   [31:0] grp_fu_208_p0;
reg   [31:0] grp_fu_208_p1;
wire    ap_CS_fsm_state17;
wire    ap_CS_fsm_state11;
wire    ap_CS_fsm_state15;
wire   [31:0] p_Val2_s_fu_223_p1;
wire   [7:0] tmp_V_fu_227_p4;
wire   [8:0] zext_ln339_fu_241_p1;
wire   [24:0] mantissa_V_fu_265_p4;
wire  signed [8:0] sext_ln1311_fu_278_p1;
wire  signed [8:0] ush_fu_281_p3;
wire  signed [31:0] sext_ln1311_1_fu_287_p1;
wire  signed [24:0] sext_ln1311_2_fu_291_p1;
wire   [78:0] zext_ln682_fu_274_p1;
wire   [78:0] zext_ln1287_fu_295_p1;
wire   [24:0] r_V_fu_299_p2;
wire   [0:0] tmp_3_fu_311_p3;
wire   [78:0] r_V_1_fu_305_p2;
wire   [31:0] zext_ln662_fu_319_p1;
wire   [31:0] tmp_9_fu_323_p4;
wire   [9:0] tmp_10_fu_340_p4;
wire   [21:0] trunc_ln21_fu_356_p1;
wire   [22:0] val_fu_360_p3;
wire   [8:0] tmp_12_fu_378_p4;
wire   [30:0] val_3_fu_394_p4;
wire   [41:0] grp_fu_434_p0;
wire   [41:0] grp_fu_434_p1;
wire   [63:0] grp_fu_434_p2;
wire    ap_block_pp0_stage1;
wire   [18:0] tmp_13_fu_440_p4;
wire   [0:0] xor_ln36_fu_480_p2;
wire   [41:0] zext_ln36_fu_492_p1;
reg   [24:0] ap_NS_fsm;
reg    ap_idle_pp0;
wire    ap_enable_pp0;

// power-on initialization
initial begin
#0 ap_CS_fsm = 25'd1;
#0 ap_enable_reg_pp0_iter0 = 1'b0;
#0 ap_enable_reg_pp0_iter1 = 1'b0;
end

mylog2_AXILiteS_s_axi #(
    .C_S_AXI_ADDR_WIDTH( C_S_AXI_AXILITES_ADDR_WIDTH ),
    .C_S_AXI_DATA_WIDTH( C_S_AXI_AXILITES_DATA_WIDTH ))
mylog2_AXILiteS_s_axi_U(
    .AWVALID(s_axi_AXILiteS_AWVALID),
    .AWREADY(s_axi_AXILiteS_AWREADY),
    .AWADDR(s_axi_AXILiteS_AWADDR),
    .WVALID(s_axi_AXILiteS_WVALID),
    .WREADY(s_axi_AXILiteS_WREADY),
    .WDATA(s_axi_AXILiteS_WDATA),
    .WSTRB(s_axi_AXILiteS_WSTRB),
    .ARVALID(s_axi_AXILiteS_ARVALID),
    .ARREADY(s_axi_AXILiteS_ARREADY),
    .ARADDR(s_axi_AXILiteS_ARADDR),
    .RVALID(s_axi_AXILiteS_RVALID),
    .RREADY(s_axi_AXILiteS_RREADY),
    .RDATA(s_axi_AXILiteS_RDATA),
    .RRESP(s_axi_AXILiteS_RRESP),
    .BVALID(s_axi_AXILiteS_BVALID),
    .BREADY(s_axi_AXILiteS_BREADY),
    .BRESP(s_axi_AXILiteS_BRESP),
    .ACLK(ap_clk),
    .ARESET(ap_rst_n_inv),
    .ACLK_EN(1'b1),
    .ap_start(ap_start),
    .interrupt(interrupt),
    .ap_ready(ap_ready),
    .ap_done(ap_done),
    .ap_idle(ap_idle),
    .x(x),
    .y(tmp_8_reg_625),
    .y_ap_vld(y_ap_vld)
);

mylog2_fadd_32ns_bkb #(
    .ID( 1 ),
    .NUM_STAGE( 5 ),
    .din0_WIDTH( 32 ),
    .din1_WIDTH( 32 ),
    .dout_WIDTH( 32 ))
mylog2_fadd_32ns_bkb_U1(
    .clk(ap_clk),
    .reset(ap_rst_n_inv),
    .din0(tmp_6_reg_615),
    .din1(tmp_7_reg_620),
    .ce(1'b1),
    .dout(grp_fu_204_p2)
);

mylog2_fmul_32ns_cud #(
    .ID( 1 ),
    .NUM_STAGE( 4 ),
    .din0_WIDTH( 32 ),
    .din1_WIDTH( 32 ),
    .dout_WIDTH( 32 ))
mylog2_fmul_32ns_cud_U2(
    .clk(ap_clk),
    .reset(ap_rst_n_inv),
    .din0(grp_fu_208_p0),
    .din1(grp_fu_208_p1),
    .ce(1'b1),
    .dout(grp_fu_208_p2)
);

mylog2_uitofp_32ndEe #(
    .ID( 1 ),
    .NUM_STAGE( 6 ),
    .din0_WIDTH( 32 ),
    .dout_WIDTH( 32 ))
mylog2_uitofp_32ndEe_U3(
    .clk(ap_clk),
    .reset(ap_rst_n_inv),
    .din0(res_lo_0_reg_172),
    .ce(1'b1),
    .dout(grp_fu_215_p1)
);

mylog2_sitofp_32neOg #(
    .ID( 1 ),
    .NUM_STAGE( 6 ),
    .din0_WIDTH( 32 ),
    .dout_WIDTH( 32 ))
mylog2_sitofp_32neOg_U4(
    .clk(ap_clk),
    .reset(ap_rst_n_inv),
    .din0(res_hi_1_reg_151),
    .ce(1'b1),
    .dout(grp_fu_219_p1)
);

mylog2_mul_42ns_4fYi #(
    .ID( 1 ),
    .NUM_STAGE( 2 ),
    .din0_WIDTH( 42 ),
    .din1_WIDTH( 42 ),
    .dout_WIDTH( 64 ))
mylog2_mul_42ns_4fYi_U5(
    .clk(ap_clk),
    .reset(ap_rst_n_inv),
    .din0(grp_fu_434_p0),
    .din1(grp_fu_434_p1),
    .ce(1'b1),
    .dout(grp_fu_434_p2)
);

always @ (posedge ap_clk) begin
    if (ap_rst_n_inv == 1'b1) begin
        ap_CS_fsm <= ap_ST_fsm_state1;
    end else begin
        ap_CS_fsm <= ap_NS_fsm;
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst_n_inv == 1'b1) begin
        ap_enable_reg_pp0_iter0 <= 1'b0;
    end else begin
        if (((1'b0 == ap_block_pp0_stage0_subdone) & (1'b1 == ap_condition_pp0_exit_iter0_state8) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
            ap_enable_reg_pp0_iter0 <= 1'b0;
        end else if (((1'b1 == ap_CS_fsm_state7) & (icmp_ln24_fu_388_p2 == 1'd1))) begin
            ap_enable_reg_pp0_iter0 <= 1'b1;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst_n_inv == 1'b1) begin
        ap_enable_reg_pp0_iter1 <= 1'b0;
    end else begin
        if ((((1'b0 == ap_block_pp0_stage1_subdone) & (1'b1 == ap_CS_fsm_pp0_stage1)) | ((1'b0 == ap_block_pp0_stage0_subdone) & (1'b1 == ap_CS_fsm_pp0_stage0)))) begin
            ap_enable_reg_pp0_iter1 <= ap_enable_reg_pp0_iter0;
        end else if (((1'b1 == ap_CS_fsm_state7) & (icmp_ln24_fu_388_p2 == 1'd1))) begin
            ap_enable_reg_pp0_iter1 <= 1'b0;
        end
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_state7) & (icmp_ln24_fu_388_p2 == 1'd1))) begin
        i_0_reg_193 <= 5'd0;
    end else if (((ap_enable_reg_pp0_iter1 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0_11001) & (icmp_ln31_reg_564 == 1'd0))) begin
        i_0_reg_193 <= i_reg_568;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_state6) & (icmp_ln18_fu_350_p2 == 1'd1))) begin
        res_hi_0_reg_129 <= res_hi_fu_372_p2;
    end else if ((1'b1 == ap_CS_fsm_state5)) begin
        res_hi_0_reg_129 <= 32'd0;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_state6) & (icmp_ln18_fu_350_p2 == 1'd0))) begin
        res_hi_1_reg_151 <= res_hi_0_reg_129;
    end else if (((1'b1 == ap_CS_fsm_state7) & (icmp_ln24_fu_388_p2 == 1'd0))) begin
        res_hi_1_reg_151 <= res_hi_2_fu_408_p2;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_state7) & (icmp_ln24_fu_388_p2 == 1'd1))) begin
        res_lo_0_reg_172 <= 32'd0;
    end else if (((ap_enable_reg_pp0_iter1 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0_11001) & (icmp_ln31_reg_564 == 1'd0))) begin
        res_lo_0_reg_172 <= res_lo_fu_485_p3;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_state6) & (icmp_ln18_fu_350_p2 == 1'd1))) begin
        val_0_reg_141 <= zext_ln21_fu_368_p1;
    end else if ((1'b1 == ap_CS_fsm_state5)) begin
        val_0_reg_141 <= val_V_fu_333_p3;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_state6) & (icmp_ln18_fu_350_p2 == 1'd0))) begin
        val_1_reg_162 <= val_0_reg_141;
    end else if (((1'b1 == ap_CS_fsm_state7) & (icmp_ln24_fu_388_p2 == 1'd0))) begin
        val_1_reg_162 <= val_4_fu_404_p1;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_state7) & (icmp_ln24_fu_388_p2 == 1'd1))) begin
        val_2_reg_184 <= zext_ln31_1_fu_414_p1;
    end else if (((ap_enable_reg_pp0_iter1 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0_11001) & (icmp_ln31_reg_564 == 1'd0))) begin
        val_2_reg_184 <= select_ln36_fu_495_p3;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state4)) begin
        add_ln339_reg_511 <= add_ln339_fu_245_p2;
        isNeg_reg_516 <= add_ln339_fu_245_p2[32'd8];
        sub_ln1311_reg_522 <= sub_ln1311_fu_259_p2;
        tmp_V_1_reg_506 <= tmp_V_1_fu_237_p1;
    end
end

always @ (posedge ap_clk) begin
    if (((ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0_11001))) begin
        i_reg_568 <= i_fu_424_p2;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0_11001))) begin
        icmp_ln31_reg_564 <= icmp_ln31_fu_418_p2;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_pp0_stage1) & (1'b0 == ap_block_pp0_stage1_11001) & (icmp_ln31_reg_564 == 1'd0))) begin
        icmp_ln36_reg_579 <= icmp_ln36_fu_450_p2;
        tmp_14_reg_595 <= {{grp_fu_434_p2[63:23]}};
        tmp_s_reg_590 <= {{grp_fu_434_p2[63:22]}};
        trunc_ln36_reg_585 <= trunc_ln36_fu_456_p1;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state16)) begin
        tmp_4_reg_610 <= grp_fu_215_p1;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state20)) begin
        tmp_6_reg_615 <= grp_fu_208_p2;
        tmp_7_reg_620 <= grp_fu_219_p1;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state25)) begin
        tmp_8_reg_625 <= grp_fu_204_p2;
    end
end

always @ (*) begin
    if ((icmp_ln31_fu_418_p2 == 1'd1)) begin
        ap_condition_pp0_exit_iter0_state8 = 1'b1;
    end else begin
        ap_condition_pp0_exit_iter0_state8 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state26)) begin
        ap_done = 1'b1;
    end else begin
        ap_done = 1'b0;
    end
end

always @ (*) begin
    if (((ap_start == 1'b0) & (1'b1 == ap_CS_fsm_state1))) begin
        ap_idle = 1'b1;
    end else begin
        ap_idle = 1'b0;
    end
end

always @ (*) begin
    if (((ap_enable_reg_pp0_iter1 == 1'b0) & (ap_enable_reg_pp0_iter0 == 1'b0))) begin
        ap_idle_pp0 = 1'b1;
    end else begin
        ap_idle_pp0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0) & (ap_enable_reg_pp0_iter1 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0) & (icmp_ln31_reg_564 == 1'd0))) begin
        ap_phi_mux_i_0_phi_fu_197_p4 = i_reg_568;
    end else begin
        ap_phi_mux_i_0_phi_fu_197_p4 = i_0_reg_193;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0) & (ap_enable_reg_pp0_iter1 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0) & (icmp_ln31_reg_564 == 1'd0))) begin
        ap_phi_mux_val_2_phi_fu_187_p4 = select_ln36_fu_495_p3;
    end else begin
        ap_phi_mux_val_2_phi_fu_187_p4 = val_2_reg_184;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state26)) begin
        ap_ready = 1'b1;
    end else begin
        ap_ready = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state17)) begin
        grp_fu_208_p0 = tmp_4_reg_610;
    end else if ((1'b1 == ap_CS_fsm_state1)) begin
        grp_fu_208_p0 = x;
    end else begin
        grp_fu_208_p0 = 'bx;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state17)) begin
        grp_fu_208_p1 = 32'd880803840;
    end else if ((1'b1 == ap_CS_fsm_state1)) begin
        grp_fu_208_p1 = 32'd1249902592;
    end else begin
        grp_fu_208_p1 = 'bx;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state26)) begin
        y_ap_vld = 1'b1;
    end else begin
        y_ap_vld = 1'b0;
    end
end

always @ (*) begin
    case (ap_CS_fsm)
        ap_ST_fsm_state1 : begin
            if (((ap_start == 1'b1) & (1'b1 == ap_CS_fsm_state1))) begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end
        end
        ap_ST_fsm_state2 : begin
            ap_NS_fsm = ap_ST_fsm_state3;
        end
        ap_ST_fsm_state3 : begin
            ap_NS_fsm = ap_ST_fsm_state4;
        end
        ap_ST_fsm_state4 : begin
            ap_NS_fsm = ap_ST_fsm_state5;
        end
        ap_ST_fsm_state5 : begin
            ap_NS_fsm = ap_ST_fsm_state6;
        end
        ap_ST_fsm_state6 : begin
            if (((1'b1 == ap_CS_fsm_state6) & (icmp_ln18_fu_350_p2 == 1'd0))) begin
                ap_NS_fsm = ap_ST_fsm_state7;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state6;
            end
        end
        ap_ST_fsm_state7 : begin
            if (((1'b1 == ap_CS_fsm_state7) & (icmp_ln24_fu_388_p2 == 1'd1))) begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage0;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state7;
            end
        end
        ap_ST_fsm_pp0_stage0 : begin
            if ((~((1'b0 == ap_block_pp0_stage0_subdone) & (ap_enable_reg_pp0_iter0 == 1'b1) & (icmp_ln31_fu_418_p2 == 1'd1)) & (1'b0 == ap_block_pp0_stage0_subdone))) begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage1;
            end else if (((1'b0 == ap_block_pp0_stage0_subdone) & (ap_enable_reg_pp0_iter0 == 1'b1) & (icmp_ln31_fu_418_p2 == 1'd1))) begin
                ap_NS_fsm = ap_ST_fsm_state11;
            end else begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage0;
            end
        end
        ap_ST_fsm_pp0_stage1 : begin
            if ((1'b0 == ap_block_pp0_stage1_subdone)) begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage0;
            end else begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage1;
            end
        end
        ap_ST_fsm_state11 : begin
            ap_NS_fsm = ap_ST_fsm_state12;
        end
        ap_ST_fsm_state12 : begin
            ap_NS_fsm = ap_ST_fsm_state13;
        end
        ap_ST_fsm_state13 : begin
            ap_NS_fsm = ap_ST_fsm_state14;
        end
        ap_ST_fsm_state14 : begin
            ap_NS_fsm = ap_ST_fsm_state15;
        end
        ap_ST_fsm_state15 : begin
            ap_NS_fsm = ap_ST_fsm_state16;
        end
        ap_ST_fsm_state16 : begin
            ap_NS_fsm = ap_ST_fsm_state17;
        end
        ap_ST_fsm_state17 : begin
            ap_NS_fsm = ap_ST_fsm_state18;
        end
        ap_ST_fsm_state18 : begin
            ap_NS_fsm = ap_ST_fsm_state19;
        end
        ap_ST_fsm_state19 : begin
            ap_NS_fsm = ap_ST_fsm_state20;
        end
        ap_ST_fsm_state20 : begin
            ap_NS_fsm = ap_ST_fsm_state21;
        end
        ap_ST_fsm_state21 : begin
            ap_NS_fsm = ap_ST_fsm_state22;
        end
        ap_ST_fsm_state22 : begin
            ap_NS_fsm = ap_ST_fsm_state23;
        end
        ap_ST_fsm_state23 : begin
            ap_NS_fsm = ap_ST_fsm_state24;
        end
        ap_ST_fsm_state24 : begin
            ap_NS_fsm = ap_ST_fsm_state25;
        end
        ap_ST_fsm_state25 : begin
            ap_NS_fsm = ap_ST_fsm_state26;
        end
        ap_ST_fsm_state26 : begin
            ap_NS_fsm = ap_ST_fsm_state1;
        end
        default : begin
            ap_NS_fsm = 'bx;
        end
    endcase
end

assign add_ln339_fu_245_p2 = ($signed(9'd385) + $signed(zext_ln339_fu_241_p1));

assign ap_CS_fsm_pp0_stage0 = ap_CS_fsm[32'd7];

assign ap_CS_fsm_pp0_stage1 = ap_CS_fsm[32'd8];

assign ap_CS_fsm_state1 = ap_CS_fsm[32'd0];

assign ap_CS_fsm_state11 = ap_CS_fsm[32'd9];

assign ap_CS_fsm_state15 = ap_CS_fsm[32'd13];

assign ap_CS_fsm_state16 = ap_CS_fsm[32'd14];

assign ap_CS_fsm_state17 = ap_CS_fsm[32'd15];

assign ap_CS_fsm_state20 = ap_CS_fsm[32'd18];

assign ap_CS_fsm_state21 = ap_CS_fsm[32'd19];

assign ap_CS_fsm_state25 = ap_CS_fsm[32'd23];

assign ap_CS_fsm_state26 = ap_CS_fsm[32'd24];

assign ap_CS_fsm_state4 = ap_CS_fsm[32'd3];

assign ap_CS_fsm_state5 = ap_CS_fsm[32'd4];

assign ap_CS_fsm_state6 = ap_CS_fsm[32'd5];

assign ap_CS_fsm_state7 = ap_CS_fsm[32'd6];

assign ap_block_pp0_stage0 = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage0_11001 = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage0_subdone = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage1 = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage1_11001 = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage1_subdone = ~(1'b1 == 1'b1);

assign ap_block_state10_pp0_stage0_iter1 = ~(1'b1 == 1'b1);

assign ap_block_state8_pp0_stage0_iter0 = ~(1'b1 == 1'b1);

assign ap_block_state9_pp0_stage1_iter0 = ~(1'b1 == 1'b1);

assign ap_enable_pp0 = (ap_idle_pp0 ^ 1'b1);

always @ (*) begin
    ap_rst_n_inv = ~ap_rst_n;
end

assign grp_fu_434_p0 = zext_ln31_fu_430_p1;

assign grp_fu_434_p1 = zext_ln31_fu_430_p1;

assign i_fu_424_p2 = (ap_phi_mux_i_0_phi_fu_197_p4 + 5'd1);

assign icmp_ln18_fu_350_p2 = ((tmp_10_fu_340_p4 == 10'd0) ? 1'b1 : 1'b0);

assign icmp_ln24_fu_388_p2 = ((tmp_12_fu_378_p4 == 9'd0) ? 1'b1 : 1'b0);

assign icmp_ln31_fu_418_p2 = ((ap_phi_mux_i_0_phi_fu_197_p4 == 5'd22) ? 1'b1 : 1'b0);

assign icmp_ln36_fu_450_p2 = ((tmp_13_fu_440_p4 == 19'd0) ? 1'b1 : 1'b0);

assign mantissa_V_fu_265_p4 = {{{{1'd1}, {tmp_V_1_reg_506}}}, {1'd0}};

assign p_Val2_s_fu_223_p1 = grp_fu_208_p2;

assign r_V_1_fu_305_p2 = zext_ln682_fu_274_p1 << zext_ln1287_fu_295_p1;

assign r_V_fu_299_p2 = mantissa_V_fu_265_p4 >> sext_ln1311_2_fu_291_p1;

assign res_hi_2_fu_408_p2 = (res_hi_1_reg_151 + 32'd1);

assign res_hi_fu_372_p2 = ($signed(32'd4294967295) + $signed(res_hi_0_reg_129));

assign res_lo_fu_485_p3 = {{trunc_ln36_reg_585}, {xor_ln36_fu_480_p2}};

assign select_ln36_fu_495_p3 = ((icmp_ln36_reg_579[0:0] === 1'b1) ? tmp_s_reg_590 : zext_ln36_fu_492_p1);

assign sext_ln1311_1_fu_287_p1 = ush_fu_281_p3;

assign sext_ln1311_2_fu_291_p1 = ush_fu_281_p3;

assign sext_ln1311_fu_278_p1 = $signed(sub_ln1311_reg_522);

assign sub_ln1311_fu_259_p2 = (8'd127 - tmp_V_fu_227_p4);

assign tmp_10_fu_340_p4 = {{val_0_reg_141[31:22]}};

assign tmp_12_fu_378_p4 = {{val_1_reg_162[31:23]}};

assign tmp_13_fu_440_p4 = {{grp_fu_434_p2[63:45]}};

assign tmp_3_fu_311_p3 = r_V_fu_299_p2[32'd24];

assign tmp_9_fu_323_p4 = {{r_V_1_fu_305_p2[55:24]}};

assign tmp_V_1_fu_237_p1 = p_Val2_s_fu_223_p1[22:0];

assign tmp_V_fu_227_p4 = {{p_Val2_s_fu_223_p1[30:23]}};

assign trunc_ln21_fu_356_p1 = val_0_reg_141[21:0];

assign trunc_ln36_fu_456_p1 = res_lo_0_reg_172[30:0];

assign ush_fu_281_p3 = ((isNeg_reg_516[0:0] === 1'b1) ? sext_ln1311_fu_278_p1 : add_ln339_reg_511);

assign val_3_fu_394_p4 = {{val_1_reg_162[31:1]}};

assign val_4_fu_404_p1 = val_3_fu_394_p4;

assign val_V_fu_333_p3 = ((isNeg_reg_516[0:0] === 1'b1) ? zext_ln662_fu_319_p1 : tmp_9_fu_323_p4);

assign val_fu_360_p3 = {{trunc_ln21_fu_356_p1}, {1'd0}};

assign xor_ln36_fu_480_p2 = (icmp_ln36_reg_579 ^ 1'd1);

assign zext_ln1287_fu_295_p1 = $unsigned(sext_ln1311_1_fu_287_p1);

assign zext_ln21_fu_368_p1 = val_fu_360_p3;

assign zext_ln31_1_fu_414_p1 = val_1_reg_162;

assign zext_ln31_fu_430_p1 = ap_phi_mux_val_2_phi_fu_187_p4;

assign zext_ln339_fu_241_p1 = tmp_V_fu_227_p4;

assign zext_ln36_fu_492_p1 = tmp_14_reg_595;

assign zext_ln662_fu_319_p1 = tmp_3_fu_311_p3;

assign zext_ln682_fu_274_p1 = mantissa_V_fu_265_p4;

endmodule //mylog2