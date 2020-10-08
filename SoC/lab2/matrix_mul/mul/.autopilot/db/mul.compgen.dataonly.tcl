# This script segment is generated automatically by AutoPilot

set axilite_register_dict [dict create]
set port_AXILiteS {
a { 
	dir I
	width 32
	depth 100
	mode ap_memory
	offset 512
	offset_end 1023
}
b { 
	dir I
	width 32
	depth 100
	mode ap_memory
	offset 1024
	offset_end 1535
}
c { 
	dir O
	width 32
	depth 100
	mode ap_memory
	offset 1536
	offset_end 2047
}
n { 
	dir I
	width 8
	depth 1
	mode ap_none
	offset 2048
	offset_end 2055
}
}
dict set axilite_register_dict AXILiteS $port_AXILiteS


