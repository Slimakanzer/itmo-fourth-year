
log_wave [get_objects -filter {type == in_port || type == out_port || type == inout_port || type == port} /apatb_mul_top/AESL_inst_mul/*]
set designtopgroup [add_wave_group "Design Top Signals"]
set cinputgroup [add_wave_group "C Inputs" -into $designtopgroup]
set a__b__c__n_group [add_wave_group a__b__c__n(axi_slave) -into $cinputgroup]
add_wave /apatb_mul_top/AESL_inst_mul/s_axi_AXILiteS_BRESP -into $a__b__c__n_group -radix hex
add_wave /apatb_mul_top/AESL_inst_mul/s_axi_AXILiteS_BREADY -into $a__b__c__n_group -color #ffff00 -radix hex
add_wave /apatb_mul_top/AESL_inst_mul/s_axi_AXILiteS_BVALID -into $a__b__c__n_group -color #ffff00 -radix hex
add_wave /apatb_mul_top/AESL_inst_mul/s_axi_AXILiteS_RRESP -into $a__b__c__n_group -radix hex
add_wave /apatb_mul_top/AESL_inst_mul/s_axi_AXILiteS_RDATA -into $a__b__c__n_group -radix hex
add_wave /apatb_mul_top/AESL_inst_mul/s_axi_AXILiteS_RREADY -into $a__b__c__n_group -color #ffff00 -radix hex
add_wave /apatb_mul_top/AESL_inst_mul/s_axi_AXILiteS_RVALID -into $a__b__c__n_group -color #ffff00 -radix hex
add_wave /apatb_mul_top/AESL_inst_mul/s_axi_AXILiteS_ARREADY -into $a__b__c__n_group -color #ffff00 -radix hex
add_wave /apatb_mul_top/AESL_inst_mul/s_axi_AXILiteS_ARVALID -into $a__b__c__n_group -color #ffff00 -radix hex
add_wave /apatb_mul_top/AESL_inst_mul/s_axi_AXILiteS_ARADDR -into $a__b__c__n_group -radix hex
add_wave /apatb_mul_top/AESL_inst_mul/s_axi_AXILiteS_WSTRB -into $a__b__c__n_group -radix hex
add_wave /apatb_mul_top/AESL_inst_mul/s_axi_AXILiteS_WDATA -into $a__b__c__n_group -radix hex
add_wave /apatb_mul_top/AESL_inst_mul/s_axi_AXILiteS_WREADY -into $a__b__c__n_group -color #ffff00 -radix hex
add_wave /apatb_mul_top/AESL_inst_mul/s_axi_AXILiteS_WVALID -into $a__b__c__n_group -color #ffff00 -radix hex
add_wave /apatb_mul_top/AESL_inst_mul/s_axi_AXILiteS_AWREADY -into $a__b__c__n_group -color #ffff00 -radix hex
add_wave /apatb_mul_top/AESL_inst_mul/s_axi_AXILiteS_AWVALID -into $a__b__c__n_group -color #ffff00 -radix hex
add_wave /apatb_mul_top/AESL_inst_mul/s_axi_AXILiteS_AWADDR -into $a__b__c__n_group -radix hex
set blocksiggroup [add_wave_group "Block-level IO Handshake" -into $designtopgroup]
add_wave /apatb_mul_top/AESL_inst_mul/ap_start -into $blocksiggroup
add_wave /apatb_mul_top/AESL_inst_mul/ap_done -into $blocksiggroup
add_wave /apatb_mul_top/AESL_inst_mul/ap_idle -into $blocksiggroup
add_wave /apatb_mul_top/AESL_inst_mul/ap_ready -into $blocksiggroup
set resetgroup [add_wave_group "Reset" -into $designtopgroup]
add_wave /apatb_mul_top/AESL_inst_mul/ap_rst_n -into $resetgroup
set clockgroup [add_wave_group "Clock" -into $designtopgroup]
add_wave /apatb_mul_top/AESL_inst_mul/ap_clk -into $clockgroup
save_wave_config mul.wcfg
run all
quit

