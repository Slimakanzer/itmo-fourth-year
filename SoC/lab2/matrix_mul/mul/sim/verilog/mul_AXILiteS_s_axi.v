// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
`timescale 1ns/1ps
module mul_AXILiteS_s_axi
#(parameter
    C_S_AXI_ADDR_WIDTH = 12,
    C_S_AXI_DATA_WIDTH = 32
)(
    input  wire                          ACLK,
    input  wire                          ARESET,
    input  wire                          ACLK_EN,
    input  wire [C_S_AXI_ADDR_WIDTH-1:0] AWADDR,
    input  wire                          AWVALID,
    output wire                          AWREADY,
    input  wire [C_S_AXI_DATA_WIDTH-1:0] WDATA,
    input  wire [C_S_AXI_DATA_WIDTH/8-1:0] WSTRB,
    input  wire                          WVALID,
    output wire                          WREADY,
    output wire [1:0]                    BRESP,
    output wire                          BVALID,
    input  wire                          BREADY,
    input  wire [C_S_AXI_ADDR_WIDTH-1:0] ARADDR,
    input  wire                          ARVALID,
    output wire                          ARREADY,
    output wire [C_S_AXI_DATA_WIDTH-1:0] RDATA,
    output wire [1:0]                    RRESP,
    output wire                          RVALID,
    input  wire                          RREADY,
    input  wire [6:0]                    a_address0,
    input  wire                          a_ce0,
    output wire [31:0]                   a_q0,
    input  wire [6:0]                    b_address0,
    input  wire                          b_ce0,
    output wire [31:0]                   b_q0,
    input  wire [6:0]                    c_address0,
    input  wire                          c_ce0,
    input  wire                          c_we0,
    input  wire [31:0]                   c_d0,
    output wire [7:0]                    n
);
//------------------------Address Info-------------------
// 0x000 : reserved
// 0x004 : reserved
// 0x008 : reserved
// 0x00c : reserved
// 0x800 : Data signal of n
//         bit 7~0 - n[7:0] (Read/Write)
//         others  - reserved
// 0x804 : reserved
// 0x200 ~
// 0x3ff : Memory 'a' (100 * 32b)
//         Word n : bit [31:0] - a[n]
// 0x400 ~
// 0x5ff : Memory 'b' (100 * 32b)
//         Word n : bit [31:0] - b[n]
// 0x600 ~
// 0x7ff : Memory 'c' (100 * 32b)
//         Word n : bit [31:0] - c[n]
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

//------------------------Parameter----------------------
localparam
    ADDR_N_DATA_0 = 12'h800,
    ADDR_N_CTRL   = 12'h804,
    ADDR_A_BASE   = 12'h200,
    ADDR_A_HIGH   = 12'h3ff,
    ADDR_B_BASE   = 12'h400,
    ADDR_B_HIGH   = 12'h5ff,
    ADDR_C_BASE   = 12'h600,
    ADDR_C_HIGH   = 12'h7ff,
    WRIDLE        = 2'd0,
    WRDATA        = 2'd1,
    WRRESP        = 2'd2,
    WRRESET       = 2'd3,
    RDIDLE        = 2'd0,
    RDDATA        = 2'd1,
    RDRESET       = 2'd2,
    ADDR_BITS         = 12;

//------------------------Local signal-------------------
    reg  [1:0]                    wstate = WRRESET;
    reg  [1:0]                    wnext;
    reg  [ADDR_BITS-1:0]          waddr;
    wire [31:0]                   wmask;
    wire                          aw_hs;
    wire                          w_hs;
    reg  [1:0]                    rstate = RDRESET;
    reg  [1:0]                    rnext;
    reg  [31:0]                   rdata;
    wire                          ar_hs;
    wire [ADDR_BITS-1:0]          raddr;
    // internal registers
    reg  [7:0]                    int_n = 'b0;
    // memory signals
    wire [6:0]                    int_a_address0;
    wire                          int_a_ce0;
    wire                          int_a_we0;
    wire [3:0]                    int_a_be0;
    wire [31:0]                   int_a_d0;
    wire [31:0]                   int_a_q0;
    wire [6:0]                    int_a_address1;
    wire                          int_a_ce1;
    wire                          int_a_we1;
    wire [3:0]                    int_a_be1;
    wire [31:0]                   int_a_d1;
    wire [31:0]                   int_a_q1;
    reg                           int_a_read;
    reg                           int_a_write;
    wire [6:0]                    int_b_address0;
    wire                          int_b_ce0;
    wire                          int_b_we0;
    wire [3:0]                    int_b_be0;
    wire [31:0]                   int_b_d0;
    wire [31:0]                   int_b_q0;
    wire [6:0]                    int_b_address1;
    wire                          int_b_ce1;
    wire                          int_b_we1;
    wire [3:0]                    int_b_be1;
    wire [31:0]                   int_b_d1;
    wire [31:0]                   int_b_q1;
    reg                           int_b_read;
    reg                           int_b_write;
    wire [6:0]                    int_c_address0;
    wire                          int_c_ce0;
    wire                          int_c_we0;
    wire [3:0]                    int_c_be0;
    wire [31:0]                   int_c_d0;
    wire [31:0]                   int_c_q0;
    wire [6:0]                    int_c_address1;
    wire                          int_c_ce1;
    wire                          int_c_we1;
    wire [3:0]                    int_c_be1;
    wire [31:0]                   int_c_d1;
    wire [31:0]                   int_c_q1;
    reg                           int_c_read;
    reg                           int_c_write;

//------------------------Instantiation------------------
// int_a
mul_AXILiteS_s_axi_ram #(
    .BYTES    ( 4 ),
    .DEPTH    ( 100 )
) int_a (
    .clk0     ( ACLK ),
    .address0 ( int_a_address0 ),
    .ce0      ( int_a_ce0 ),
    .we0      ( int_a_we0 ),
    .be0      ( int_a_be0 ),
    .d0       ( int_a_d0 ),
    .q0       ( int_a_q0 ),
    .clk1     ( ACLK ),
    .address1 ( int_a_address1 ),
    .ce1      ( int_a_ce1 ),
    .we1      ( int_a_we1 ),
    .be1      ( int_a_be1 ),
    .d1       ( int_a_d1 ),
    .q1       ( int_a_q1 )
);
// int_b
mul_AXILiteS_s_axi_ram #(
    .BYTES    ( 4 ),
    .DEPTH    ( 100 )
) int_b (
    .clk0     ( ACLK ),
    .address0 ( int_b_address0 ),
    .ce0      ( int_b_ce0 ),
    .we0      ( int_b_we0 ),
    .be0      ( int_b_be0 ),
    .d0       ( int_b_d0 ),
    .q0       ( int_b_q0 ),
    .clk1     ( ACLK ),
    .address1 ( int_b_address1 ),
    .ce1      ( int_b_ce1 ),
    .we1      ( int_b_we1 ),
    .be1      ( int_b_be1 ),
    .d1       ( int_b_d1 ),
    .q1       ( int_b_q1 )
);
// int_c
mul_AXILiteS_s_axi_ram #(
    .BYTES    ( 4 ),
    .DEPTH    ( 100 )
) int_c (
    .clk0     ( ACLK ),
    .address0 ( int_c_address0 ),
    .ce0      ( int_c_ce0 ),
    .we0      ( int_c_we0 ),
    .be0      ( int_c_be0 ),
    .d0       ( int_c_d0 ),
    .q0       ( int_c_q0 ),
    .clk1     ( ACLK ),
    .address1 ( int_c_address1 ),
    .ce1      ( int_c_ce1 ),
    .we1      ( int_c_we1 ),
    .be1      ( int_c_be1 ),
    .d1       ( int_c_d1 ),
    .q1       ( int_c_q1 )
);

//------------------------AXI write fsm------------------
assign AWREADY = (wstate == WRIDLE);
assign WREADY  = (wstate == WRDATA);
assign BRESP   = 2'b00;  // OKAY
assign BVALID  = (wstate == WRRESP);
assign wmask   = { {8{WSTRB[3]}}, {8{WSTRB[2]}}, {8{WSTRB[1]}}, {8{WSTRB[0]}} };
assign aw_hs   = AWVALID & AWREADY;
assign w_hs    = WVALID & WREADY;

// wstate
always @(posedge ACLK) begin
    if (ARESET)
        wstate <= WRRESET;
    else if (ACLK_EN)
        wstate <= wnext;
end

// wnext
always @(*) begin
    case (wstate)
        WRIDLE:
            if (AWVALID)
                wnext = WRDATA;
            else
                wnext = WRIDLE;
        WRDATA:
            if (WVALID)
                wnext = WRRESP;
            else
                wnext = WRDATA;
        WRRESP:
            if (BREADY)
                wnext = WRIDLE;
            else
                wnext = WRRESP;
        default:
            wnext = WRIDLE;
    endcase
end

// waddr
always @(posedge ACLK) begin
    if (ACLK_EN) begin
        if (aw_hs)
            waddr <= AWADDR[ADDR_BITS-1:0];
    end
end

//------------------------AXI read fsm-------------------
assign ARREADY = (rstate == RDIDLE);
assign RDATA   = rdata;
assign RRESP   = 2'b00;  // OKAY
assign RVALID  = (rstate == RDDATA) & !int_a_read & !int_b_read & !int_c_read;
assign ar_hs   = ARVALID & ARREADY;
assign raddr   = ARADDR[ADDR_BITS-1:0];

// rstate
always @(posedge ACLK) begin
    if (ARESET)
        rstate <= RDRESET;
    else if (ACLK_EN)
        rstate <= rnext;
end

// rnext
always @(*) begin
    case (rstate)
        RDIDLE:
            if (ARVALID)
                rnext = RDDATA;
            else
                rnext = RDIDLE;
        RDDATA:
            if (RREADY & RVALID)
                rnext = RDIDLE;
            else
                rnext = RDDATA;
        default:
            rnext = RDIDLE;
    endcase
end

// rdata
always @(posedge ACLK) begin
    if (ACLK_EN) begin
        if (ar_hs) begin
            rdata <= 1'b0;
            case (raddr)
                ADDR_N_DATA_0: begin
                    rdata <= int_n[7:0];
                end
            endcase
        end
        else if (int_a_read) begin
            rdata <= int_a_q1;
        end
        else if (int_b_read) begin
            rdata <= int_b_q1;
        end
        else if (int_c_read) begin
            rdata <= int_c_q1;
        end
    end
end


//------------------------Register logic-----------------
assign n = int_n;
// int_n[7:0]
always @(posedge ACLK) begin
    if (ARESET)
        int_n[7:0] <= 0;
    else if (ACLK_EN) begin
        if (w_hs && waddr == ADDR_N_DATA_0)
            int_n[7:0] <= (WDATA[31:0] & wmask) | (int_n[7:0] & ~wmask);
    end
end


//------------------------Memory logic-------------------
// a
assign int_a_address0 = a_address0;
assign int_a_ce0      = a_ce0;
assign int_a_we0      = 1'b0;
assign int_a_be0      = 1'b0;
assign int_a_d0       = 1'b0;
assign a_q0           = int_a_q0;
assign int_a_address1 = ar_hs? raddr[8:2] : waddr[8:2];
assign int_a_ce1      = ar_hs | (int_a_write & WVALID);
assign int_a_we1      = int_a_write & WVALID;
assign int_a_be1      = WSTRB;
assign int_a_d1       = WDATA;
// b
assign int_b_address0 = b_address0;
assign int_b_ce0      = b_ce0;
assign int_b_we0      = 1'b0;
assign int_b_be0      = 1'b0;
assign int_b_d0       = 1'b0;
assign b_q0           = int_b_q0;
assign int_b_address1 = ar_hs? raddr[8:2] : waddr[8:2];
assign int_b_ce1      = ar_hs | (int_b_write & WVALID);
assign int_b_we1      = int_b_write & WVALID;
assign int_b_be1      = WSTRB;
assign int_b_d1       = WDATA;
// c
assign int_c_address0 = c_address0;
assign int_c_ce0      = c_ce0;
assign int_c_we0      = c_we0;
assign int_c_be0      = {4{c_we0}};
assign int_c_d0       = c_d0;
assign int_c_address1 = ar_hs? raddr[8:2] : waddr[8:2];
assign int_c_ce1      = ar_hs | (int_c_write & WVALID);
assign int_c_we1      = int_c_write & WVALID;
assign int_c_be1      = WSTRB;
assign int_c_d1       = WDATA;
// int_a_read
always @(posedge ACLK) begin
    if (ARESET)
        int_a_read <= 1'b0;
    else if (ACLK_EN) begin
        if (ar_hs && raddr >= ADDR_A_BASE && raddr <= ADDR_A_HIGH)
            int_a_read <= 1'b1;
        else
            int_a_read <= 1'b0;
    end
end

// int_a_write
always @(posedge ACLK) begin
    if (ARESET)
        int_a_write <= 1'b0;
    else if (ACLK_EN) begin
        if (aw_hs && AWADDR[ADDR_BITS-1:0] >= ADDR_A_BASE && AWADDR[ADDR_BITS-1:0] <= ADDR_A_HIGH)
            int_a_write <= 1'b1;
        else if (WVALID)
            int_a_write <= 1'b0;
    end
end

// int_b_read
always @(posedge ACLK) begin
    if (ARESET)
        int_b_read <= 1'b0;
    else if (ACLK_EN) begin
        if (ar_hs && raddr >= ADDR_B_BASE && raddr <= ADDR_B_HIGH)
            int_b_read <= 1'b1;
        else
            int_b_read <= 1'b0;
    end
end

// int_b_write
always @(posedge ACLK) begin
    if (ARESET)
        int_b_write <= 1'b0;
    else if (ACLK_EN) begin
        if (aw_hs && AWADDR[ADDR_BITS-1:0] >= ADDR_B_BASE && AWADDR[ADDR_BITS-1:0] <= ADDR_B_HIGH)
            int_b_write <= 1'b1;
        else if (WVALID)
            int_b_write <= 1'b0;
    end
end

// int_c_read
always @(posedge ACLK) begin
    if (ARESET)
        int_c_read <= 1'b0;
    else if (ACLK_EN) begin
        if (ar_hs && raddr >= ADDR_C_BASE && raddr <= ADDR_C_HIGH)
            int_c_read <= 1'b1;
        else
            int_c_read <= 1'b0;
    end
end

// int_c_write
always @(posedge ACLK) begin
    if (ARESET)
        int_c_write <= 1'b0;
    else if (ACLK_EN) begin
        if (aw_hs && AWADDR[ADDR_BITS-1:0] >= ADDR_C_BASE && AWADDR[ADDR_BITS-1:0] <= ADDR_C_HIGH)
            int_c_write <= 1'b1;
        else if (WVALID)
            int_c_write <= 1'b0;
    end
end


endmodule


`timescale 1ns/1ps

module mul_AXILiteS_s_axi_ram
#(parameter
    BYTES  = 4,
    DEPTH  = 256,
    AWIDTH = log2(DEPTH)
) (
    input  wire               clk0,
    input  wire [AWIDTH-1:0]  address0,
    input  wire               ce0,
    input  wire               we0,
    input  wire [BYTES-1:0]   be0,
    input  wire [BYTES*8-1:0] d0,
    output reg  [BYTES*8-1:0] q0,
    input  wire               clk1,
    input  wire [AWIDTH-1:0]  address1,
    input  wire               ce1,
    input  wire               we1,
    input  wire [BYTES-1:0]   be1,
    input  wire [BYTES*8-1:0] d1,
    output reg  [BYTES*8-1:0] q1
);
//------------------------Local signal-------------------
reg  [BYTES*8-1:0] mem[0:DEPTH-1];
//------------------------Task and function--------------
function integer log2;
    input integer x;
    integer n, m;
begin
    n = 1;
    m = 2;
    while (m < x) begin
        n = n + 1;
        m = m * 2;
    end
    log2 = n;
end
endfunction
//------------------------Body---------------------------
// read port 0
always @(posedge clk0) begin
    if (ce0) q0 <= mem[address0];
end

// read port 1
always @(posedge clk1) begin
    if (ce1) q1 <= mem[address1];
end

genvar i;
generate
    for (i = 0; i < BYTES; i = i + 1) begin : gen_write
        // write port 0
        always @(posedge clk0) begin
            if (ce0 & we0 & be0[i]) begin
                mem[address0][8*i+7:8*i] <= d0[8*i+7:8*i];
            end
        end
        // write port 1
        always @(posedge clk1) begin
            if (ce1 & we1 & be1[i]) begin
                mem[address1][8*i+7:8*i] <= d1[8*i+7:8*i];
            end
        end
    end
endgenerate

endmodule

