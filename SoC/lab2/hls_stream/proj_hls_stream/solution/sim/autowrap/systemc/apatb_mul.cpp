// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================

#include <systemc>
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <stdint.h>
#include "SysCFileHandler.h"
#include "ap_int.h"
#include "ap_fixed.h"
#include <complex>
#include <stdbool.h>
#include "autopilot_cbe.h"
#include "hls_stream.h"
#include "hls_half.h"
#include "hls_signal_handler.h"

using namespace std;
using namespace sc_core;
using namespace sc_dt;


// [dump_struct_tree [build_nameSpaceTree] dumpedStructList] ---------->


// [dump_enumeration [get_enumeration_list]] ---------->


// wrapc file define: "a_V"
#define AUTOTB_TVIN_a_V  "../tv/cdatafile/c.mul.autotvin_a_V.dat"
#define WRAPC_STREAM_SIZE_IN_a_V  "../tv/stream_size/stream_size_in_a_V.dat"
#define WRAPC_STREAM_INGRESS_STATUS_a_V  "../tv/stream_size/stream_ingress_status_a_V.dat"
// wrapc file define: "b_V"
#define AUTOTB_TVIN_b_V  "../tv/cdatafile/c.mul.autotvin_b_V.dat"
#define WRAPC_STREAM_SIZE_IN_b_V  "../tv/stream_size/stream_size_in_b_V.dat"
#define WRAPC_STREAM_INGRESS_STATUS_b_V  "../tv/stream_size/stream_ingress_status_b_V.dat"
// wrapc file define: "c_V"
#define AUTOTB_TVOUT_c_V  "../tv/cdatafile/c.mul.autotvout_c_V.dat"
#define AUTOTB_TVIN_c_V  "../tv/cdatafile/c.mul.autotvin_c_V.dat"
#define WRAPC_STREAM_SIZE_OUT_c_V  "../tv/stream_size/stream_size_out_c_V.dat"
#define WRAPC_STREAM_EGRESS_STATUS_c_V  "../tv/stream_size/stream_egress_status_c_V.dat"
// wrapc file define: "n"
#define AUTOTB_TVIN_n  "../tv/cdatafile/c.mul.autotvin_n.dat"

#define INTER_TCL  "../tv/cdatafile/ref.tcl"

// tvout file define: "c_V"
#define AUTOTB_TVOUT_PC_c_V  "../tv/rtldatafile/rtl.mul.autotvout_c_V.dat"

class INTER_TCL_FILE {
	public:
		INTER_TCL_FILE(const char* name) {
			mName = name;
			a_V_depth = 0;
			b_V_depth = 0;
			c_V_depth = 0;
			n_depth = 0;
			trans_num =0;
		}

		~INTER_TCL_FILE() {
			mFile.open(mName);
			if (!mFile.good()) {
				cout << "Failed to open file ref.tcl" << endl;
				exit (1);
			}
			string total_list = get_depth_list();
			mFile << "set depth_list {\n";
			mFile << total_list;
			mFile << "}\n";
			mFile << "set trans_num "<<trans_num<<endl;
			mFile.close();
		}

		string get_depth_list () {
			stringstream total_list;
			total_list << "{a_V " << a_V_depth << "}\n";
			total_list << "{b_V " << b_V_depth << "}\n";
			total_list << "{c_V " << c_V_depth << "}\n";
			total_list << "{n " << n_depth << "}\n";
			return total_list.str();
		}

		void set_num (int num , int* class_num) {
			(*class_num) = (*class_num) > num ? (*class_num) : num;
		}
	public:
		int a_V_depth;
		int b_V_depth;
		int c_V_depth;
		int n_depth;
		int trans_num;

	private:
		ofstream mFile;
		const char* mName;
};

extern void mul (
hls::stream<int > (&a),
hls::stream<int > (&b),
hls::stream<int > (&c),
unsigned int n);

void AESL_WRAP_mul (
hls::stream<int > (&a),
hls::stream<int > (&b),
hls::stream<int > (&c),
unsigned int n)
{
	refine_signal_handler();
	fstream wrapc_switch_file_token;
	wrapc_switch_file_token.open(".hls_cosim_wrapc_switch.log");
	int AESL_i;
	if (wrapc_switch_file_token.good())
	{
		CodeState = ENTER_WRAPC_PC;
		static unsigned AESL_transaction_pc = 0;
		string AESL_token;
		string AESL_num;
		static AESL_FILE_HANDLER aesl_fh;

		// pop stream input: "a"
		aesl_fh.read(WRAPC_STREAM_SIZE_IN_a_V, AESL_token); // [[transaction]]
		aesl_fh.read(WRAPC_STREAM_SIZE_IN_a_V, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(WRAPC_STREAM_SIZE_IN_a_V, AESL_token); // pop_size
			int aesl_tmp_1 = atoi(AESL_token.c_str());
			for (int i = 0; i < aesl_tmp_1; i++)
			{
				a.read();
			}
			aesl_fh.read(WRAPC_STREAM_SIZE_IN_a_V, AESL_token); // [[/transaction]]
		}

		// pop stream input: "b"
		aesl_fh.read(WRAPC_STREAM_SIZE_IN_b_V, AESL_token); // [[transaction]]
		aesl_fh.read(WRAPC_STREAM_SIZE_IN_b_V, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(WRAPC_STREAM_SIZE_IN_b_V, AESL_token); // pop_size
			int aesl_tmp_4 = atoi(AESL_token.c_str());
			for (int i = 0; i < aesl_tmp_4; i++)
			{
				b.read();
			}
			aesl_fh.read(WRAPC_STREAM_SIZE_IN_b_V, AESL_token); // [[/transaction]]
		}

		// define output stream variables: "c"
		std::vector<int > aesl_tmp_6;
		int aesl_tmp_7;
		int aesl_tmp_8 = 0;

		// read output stream size: "c"
		aesl_fh.read(WRAPC_STREAM_SIZE_OUT_c_V, AESL_token); // [[transaction]]
		aesl_fh.read(WRAPC_STREAM_SIZE_OUT_c_V, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(WRAPC_STREAM_SIZE_OUT_c_V, AESL_token); // pop_size
			aesl_tmp_7 = atoi(AESL_token.c_str());
			aesl_fh.read(WRAPC_STREAM_SIZE_OUT_c_V, AESL_token); // [[/transaction]]
		}

		// output port post check: "c_V"
		aesl_fh.read(AUTOTB_TVOUT_PC_c_V, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_c_V, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_c_V, AESL_token); // data

			std::vector<sc_bv<32> > c_V_pc_buffer;
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'c_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'c_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					c_V_pc_buffer.push_back(AESL_token.c_str());
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_c_V, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_c_V))
				{
					exit(1);
				}
			}

			// correct the buffer size the current transaction
			if (i != aesl_tmp_7)
			{
				aesl_tmp_7 = i;
			}

			if (aesl_tmp_7 > 0 && aesl_tmp_6.size() < aesl_tmp_7)
			{
				int aesl_tmp_6_size = aesl_tmp_6.size();

				for (int tmp_aesl_tmp_6 = 0; tmp_aesl_tmp_6 < aesl_tmp_7 - aesl_tmp_6_size; tmp_aesl_tmp_6++)
				{
					int tmp;
					aesl_tmp_6.push_back(tmp);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: c_V
				{
					// bitslice(31, 0)
					// {
						// celement: c.V(31, 0)
						// {
							sc_lv<32>* c_V_lv0_0_0_1 = new sc_lv<32>[aesl_tmp_7 - aesl_tmp_8];
						// }
					// }

					// bitslice(31, 0)
					{
						int hls_map_index = 0;
						// celement: c.V(31, 0)
						{
							// carray: (aesl_tmp_8) => (aesl_tmp_7 - 1) @ (1)
							for (int i_0 = aesl_tmp_8; i_0 <= aesl_tmp_7 - 1; i_0 += 1)
							{
								if (&(aesl_tmp_6[0]) != NULL) // check the null address if the c port is array or others
								{
									c_V_lv0_0_0_1[hls_map_index].range(31, 0) = sc_bv<32>(c_V_pc_buffer[hls_map_index].range(31, 0));
									hls_map_index++;
								}
							}
						}
					}

					// bitslice(31, 0)
					{
						int hls_map_index = 0;
						// celement: c.V(31, 0)
						{
							// carray: (aesl_tmp_8) => (aesl_tmp_7 - 1) @ (1)
							for (int i_0 = aesl_tmp_8; i_0 <= aesl_tmp_7 - 1; i_0 += 1)
							{
								// sub                    : i_0
								// ori_name               : aesl_tmp_6[i_0]
								// sub_1st_elem           : 0
								// ori_name_1st_elem      : aesl_tmp_6[0]
								// output_left_conversion : aesl_tmp_6[i_0]
								// output_type_conversion : (c_V_lv0_0_0_1[hls_map_index]).to_uint64()
								if (&(aesl_tmp_6[0]) != NULL) // check the null address if the c port is array or others
								{
									aesl_tmp_6[i_0] = (c_V_lv0_0_0_1[hls_map_index]).to_uint64();
									hls_map_index++;
								}
							}
						}
					}
				}
			}
		}

		// push back output stream: "c"
		for (int i = 0; i < aesl_tmp_7; i++)
		{
			c.write(aesl_tmp_6[i]);
		}

		AESL_transaction_pc++;
	}
	else
	{
		CodeState = ENTER_WRAPC;
		static unsigned AESL_transaction;

		static AESL_FILE_HANDLER aesl_fh;

		// "a_V"
		char* tvin_a_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_a_V);
		char* wrapc_stream_size_in_a_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_SIZE_IN_a_V);
		char* wrapc_stream_ingress_status_a_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_a_V);

		// "b_V"
		char* tvin_b_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_b_V);
		char* wrapc_stream_size_in_b_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_SIZE_IN_b_V);
		char* wrapc_stream_ingress_status_b_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_b_V);

		// "c_V"
		char* tvin_c_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_c_V);
		char* tvout_c_V = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_c_V);
		char* wrapc_stream_size_out_c_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_c_V);
		char* wrapc_stream_egress_status_c_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_c_V);

		// "n"
		char* tvin_n = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_n);

		CodeState = DUMP_INPUTS;
		static INTER_TCL_FILE tcl_file(INTER_TCL);
		int leading_zero;

		// dump stream tvin: "a"
		std::vector<int > aesl_tmp_0;
		int aesl_tmp_1 = 0;
		while (!a.empty())
		{
			aesl_tmp_0.push_back(a.read());
			aesl_tmp_1++;
		}

		// dump stream tvin: "b"
		std::vector<int > aesl_tmp_3;
		int aesl_tmp_4 = 0;
		while (!b.empty())
		{
			aesl_tmp_3.push_back(b.read());
			aesl_tmp_4++;
		}

		// dump stream tvin: "c"
		std::vector<int > aesl_tmp_6;
		int aesl_tmp_7 = 0;
		while (!c.empty())
		{
			aesl_tmp_6.push_back(c.read());
			aesl_tmp_7++;
		}

		// [[transaction]]
		sprintf(tvin_n, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_n, tvin_n);

		sc_bv<32> n_tvin_wrapc_buffer;

		// RTL Name: n
		{
			// bitslice(31, 0)
			{
				// celement: n(31, 0)
				{
					// carray: (0) => (0) @ (0)
					{
						// sub                   : 
						// ori_name              : n
						// sub_1st_elem          : 
						// ori_name_1st_elem     : n
						// regulate_c_name       : n
						// input_type_conversion : n
						if (&(n) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> n_tmp_mem;
							n_tmp_mem = n;
							n_tvin_wrapc_buffer.range(31, 0) = n_tmp_mem.range(31, 0);
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_n, "%s\n", (n_tvin_wrapc_buffer).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_n, tvin_n);
		}

		tcl_file.set_num(1, &tcl_file.n_depth);
		sprintf(tvin_n, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_n, tvin_n);

		// push back input stream: "a"
		for (int i = 0; i < aesl_tmp_1; i++)
		{
			a.write(aesl_tmp_0[i]);
		}

		// push back input stream: "b"
		for (int i = 0; i < aesl_tmp_4; i++)
		{
			b.write(aesl_tmp_3[i]);
		}

		// push back input stream: "c"
		for (int i = 0; i < aesl_tmp_7; i++)
		{
			c.write(aesl_tmp_6[i]);
		}

// [call_c_dut] ---------->

		CodeState = CALL_C_DUT;
		mul(a, b, c, n);

		CodeState = DUMP_OUTPUTS;
		// record input size to tv3: "a"
		int aesl_tmp_2 = a.size();

		// record input size to tv3: "b"
		int aesl_tmp_5 = b.size();

		// pop output stream: "c"
		int aesl_tmp_8 = aesl_tmp_7;
		aesl_tmp_7 = 0;
     aesl_tmp_6.clear();
		while (!c.empty())
		{
			aesl_tmp_6.push_back(c.read());
			aesl_tmp_7++;
		}

		// [[transaction]]
		sprintf(tvin_a_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_a_V, tvin_a_V);
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_a_V, tvin_a_V);

		sc_bv<32>* a_V_tvin_wrapc_buffer = new sc_bv<32>[aesl_tmp_1 - aesl_tmp_2];

		// RTL Name: a_V
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: a.V(31, 0)
				{
					// carray: (0) => (aesl_tmp_1 - aesl_tmp_2 - 1) @ (1)
					for (int i_0 = 0; i_0 <= aesl_tmp_1 - aesl_tmp_2 - 1; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : aesl_tmp_0[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : aesl_tmp_0[0]
						// regulate_c_name       : a_V
						// input_type_conversion : aesl_tmp_0[i_0]
						if (&(aesl_tmp_0[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> a_V_tmp_mem;
							a_V_tmp_mem = aesl_tmp_0[i_0];
							a_V_tvin_wrapc_buffer[hls_map_index].range(31, 0) = a_V_tmp_mem.range(31, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < aesl_tmp_1 - aesl_tmp_2; i++)
		{
			sprintf(tvin_a_V, "%s\n", (a_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_a_V, tvin_a_V);
		}

		// dump stream ingress status to file
     if (aesl_tmp_1 > aesl_tmp_2)
     {
		sc_int<32> stream_ingress_size_a_V = aesl_tmp_1;
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_a_V, stream_ingress_size_a_V.to_string().c_str());
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_a_V, "\n");

		for (int i = 0; i < aesl_tmp_1 - aesl_tmp_2; i++)
		{
			stream_ingress_size_a_V--;
			aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_a_V, stream_ingress_size_a_V.to_string().c_str());
			aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_a_V, "\n");
		}
     }
     else {
		    sc_int<32> stream_ingress_size_a_V = 0;
		    aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_a_V, stream_ingress_size_a_V.to_string().c_str());
		    aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_a_V, "\n");
     }

		tcl_file.set_num(aesl_tmp_1 - aesl_tmp_2, &tcl_file.a_V_depth);
		sprintf(tvin_a_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_a_V, tvin_a_V);
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_a_V, tvin_a_V);

		// release memory allocation
		delete [] a_V_tvin_wrapc_buffer;

		// dump stream size
		sprintf(wrapc_stream_size_in_a_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_a_V, wrapc_stream_size_in_a_V);
		sprintf(wrapc_stream_size_in_a_V, "%d\n", aesl_tmp_1 - aesl_tmp_2);
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_a_V, wrapc_stream_size_in_a_V);
		sprintf(wrapc_stream_size_in_a_V, "[[/transaction]] \n");
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_a_V, wrapc_stream_size_in_a_V);

		// [[transaction]]
		sprintf(tvin_b_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_b_V, tvin_b_V);
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_b_V, tvin_b_V);

		sc_bv<32>* b_V_tvin_wrapc_buffer = new sc_bv<32>[aesl_tmp_4 - aesl_tmp_5];

		// RTL Name: b_V
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: b.V(31, 0)
				{
					// carray: (0) => (aesl_tmp_4 - aesl_tmp_5 - 1) @ (1)
					for (int i_0 = 0; i_0 <= aesl_tmp_4 - aesl_tmp_5 - 1; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : aesl_tmp_3[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : aesl_tmp_3[0]
						// regulate_c_name       : b_V
						// input_type_conversion : aesl_tmp_3[i_0]
						if (&(aesl_tmp_3[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> b_V_tmp_mem;
							b_V_tmp_mem = aesl_tmp_3[i_0];
							b_V_tvin_wrapc_buffer[hls_map_index].range(31, 0) = b_V_tmp_mem.range(31, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < aesl_tmp_4 - aesl_tmp_5; i++)
		{
			sprintf(tvin_b_V, "%s\n", (b_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_b_V, tvin_b_V);
		}

		// dump stream ingress status to file
     if (aesl_tmp_4 > aesl_tmp_5)
     {
		sc_int<32> stream_ingress_size_b_V = aesl_tmp_4;
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_b_V, stream_ingress_size_b_V.to_string().c_str());
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_b_V, "\n");

		for (int i = 0; i < aesl_tmp_4 - aesl_tmp_5; i++)
		{
			stream_ingress_size_b_V--;
			aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_b_V, stream_ingress_size_b_V.to_string().c_str());
			aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_b_V, "\n");
		}
     }
     else {
		    sc_int<32> stream_ingress_size_b_V = 0;
		    aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_b_V, stream_ingress_size_b_V.to_string().c_str());
		    aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_b_V, "\n");
     }

		tcl_file.set_num(aesl_tmp_4 - aesl_tmp_5, &tcl_file.b_V_depth);
		sprintf(tvin_b_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_b_V, tvin_b_V);
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_b_V, tvin_b_V);

		// release memory allocation
		delete [] b_V_tvin_wrapc_buffer;

		// dump stream size
		sprintf(wrapc_stream_size_in_b_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_b_V, wrapc_stream_size_in_b_V);
		sprintf(wrapc_stream_size_in_b_V, "%d\n", aesl_tmp_4 - aesl_tmp_5);
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_b_V, wrapc_stream_size_in_b_V);
		sprintf(wrapc_stream_size_in_b_V, "[[/transaction]] \n");
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_b_V, wrapc_stream_size_in_b_V);

		// [[transaction]]
		sprintf(tvout_c_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_c_V, tvout_c_V);

		sc_bv<32>* c_V_tvout_wrapc_buffer = new sc_bv<32>[aesl_tmp_7 - aesl_tmp_8];

		// RTL Name: c_V
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: c.V(31, 0)
				{
					// carray: (aesl_tmp_8) => (aesl_tmp_7 - 1) @ (1)
					for (int i_0 = aesl_tmp_8; i_0 <= aesl_tmp_7 - 1; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : aesl_tmp_6[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : aesl_tmp_6[0]
						// regulate_c_name       : c_V
						// input_type_conversion : aesl_tmp_6[i_0]
						if (&(aesl_tmp_6[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> c_V_tmp_mem;
							c_V_tmp_mem = aesl_tmp_6[i_0];
							c_V_tvout_wrapc_buffer[hls_map_index].range(31, 0) = c_V_tmp_mem.range(31, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < aesl_tmp_7 - aesl_tmp_8; i++)
		{
			sprintf(tvout_c_V, "%s\n", (c_V_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_c_V, tvout_c_V);
		}

		tcl_file.set_num(aesl_tmp_7 - aesl_tmp_8, &tcl_file.c_V_depth);
		sprintf(tvout_c_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_c_V, tvout_c_V);

		// release memory allocation
		delete [] c_V_tvout_wrapc_buffer;

		// dump stream size
		sprintf(wrapc_stream_size_out_c_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(WRAPC_STREAM_SIZE_OUT_c_V, wrapc_stream_size_out_c_V);
		sprintf(wrapc_stream_size_out_c_V, "%d\n", aesl_tmp_7 - aesl_tmp_8);
		aesl_fh.write(WRAPC_STREAM_SIZE_OUT_c_V, wrapc_stream_size_out_c_V);
		sprintf(wrapc_stream_size_out_c_V, "[[/transaction]] \n");
		aesl_fh.write(WRAPC_STREAM_SIZE_OUT_c_V, wrapc_stream_size_out_c_V);

		// push back output stream: "c"
		for (int i = 0; i < aesl_tmp_7; i++)
		{
			c.write(aesl_tmp_6[i]);
		}

		CodeState = DELETE_CHAR_BUFFERS;
		// release memory allocation: "a_V"
		delete [] tvin_a_V;
		delete [] wrapc_stream_size_in_a_V;
		// release memory allocation: "b_V"
		delete [] tvin_b_V;
		delete [] wrapc_stream_size_in_b_V;
		// release memory allocation: "c_V"
		delete [] tvout_c_V;
		delete [] tvin_c_V;
		delete [] wrapc_stream_size_out_c_V;
		// release memory allocation: "n"
		delete [] tvin_n;

		AESL_transaction++;

		tcl_file.set_num(AESL_transaction , &tcl_file.trans_num);
	}
}

