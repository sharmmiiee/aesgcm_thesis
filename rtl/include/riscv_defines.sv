// Copyright 2018 ETH Zurich and University of Bologna.
// Copyright and related rights are licensed under the Solderpad Hardware
// License, Version 0.51 (the "License"); you may not use this file except in
// compliance with the License.  You may obtain a copy of the License at
// http://solderpad.org/licenses/SHL-0.51. Unless required by applicable law
// or agreed to in writing, software, hardware and materials distributed under
// this License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.

////////////////////////////////////////////////////////////////////////////////
// Engineer:       Matthias Baer - baermatt@student.ethz.ch                   //
//                                                                            //
// Additional contributions by:                                               //
//                 Sven Stucki - svstucki@student.ethz.ch                     //
//                                                                            //
//                                                                            //
// Design Name:    RISC-V processor core                                      //
// Project Name:   RI5CY                                                      //
// Language:       SystemVerilog                                              //
//                                                                            //
// Description:    Defines for various constants used by the processor core.  //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

package riscv_defines;

import fpnew_pkg::OP_BITS;
import fpnew_pkg::FP_FORMAT_BITS;
import fpnew_pkg::INT_FORMAT_BITS;

////////////////////////////////////////////////
//    ___         ____          _             //
//   / _ \ _ __  / ___|___   __| | ___  ___   //
//  | | | | '_ \| |   / _ \ / _` |/ _ \/ __|  //
//  | |_| | |_) | |__| (_) | (_| |  __/\__ \  //
//   \___/| .__/ \____\___/ \__,_|\___||___/  //
//        |_|                                 //
////////////////////////////////////////////////

parameter OPCODE_SYSTEM    = 7'h73;
parameter OPCODE_FENCE     = 7'h0f;
parameter OPCODE_OP        = 7'h33;
parameter OPCODE_OPIMM     = 7'h13;
parameter OPCODE_STORE     = 7'h23;
parameter OPCODE_LOAD      = 7'h03;
parameter OPCODE_BRANCH    = 7'h63;
parameter OPCODE_JALR      = 7'h67;
parameter OPCODE_JAL       = 7'h6f;
parameter OPCODE_AUIPC     = 7'h17;
parameter OPCODE_LUI       = 7'h37;
parameter OPCODE_OP_FP     = 7'h53;
parameter OPCODE_OP_FMADD  = 7'h43;
parameter OPCODE_OP_FNMADD = 7'h4f;
parameter OPCODE_OP_FMSUB  = 7'h47;
parameter OPCODE_OP_FNMSUB = 7'h4b;
parameter OPCODE_STORE_FP  = 7'h27;
parameter OPCODE_LOAD_FP   = 7'h07;
parameter OPCODE_AMO       = 7'h2F;

// those opcodes are now used for PULP custom instructions
// parameter OPCODE_CUST0     = 7'h0b
// parameter OPCODE_CUST1     = 7'h2b

// PULP custom
parameter OPCODE_LOAD_POST  = 7'h0b; // Also used in MUL_CLI and MUL_CLHI (sharmine)
parameter OPCODE_STORE_POST = 7'h2b; // Also used in MUL_CL and MUL_CLH (sharmine)
parameter OPCODE_PULP_OP    = 7'h5b;
parameter OPCODE_VECOP      = 7'h57;
parameter OPCODE_HWLOOP     = 7'h7b;

parameter REGC_S1   = 2'b10;
parameter REGC_S4   = 2'b00;
parameter REGC_RD   = 2'b01;
parameter REGC_ZERO = 2'b11;


//////////////////////////////////////////////////////////////////////////////
//      _    _    _   _    ___                       _   _                  //
//     / \  | |  | | | |  / _ \ _ __   ___ _ __ __ _| |_(_) ___  _ __  ___  //
//    / _ \ | |  | | | | | | | | '_ \ / _ \ '__/ _` | __| |/ _ \| '_ \/ __| //
//   / ___ \| |__| |_| | | |_| | |_) |  __/ | | (_| | |_| | (_) | | | \__ \ //
//  /_/   \_\_____\___/   \___/| .__/ \___|_|  \__,_|\__|_|\___/|_| |_|___/ //
//                             |_|                                          //
//////////////////////////////////////////////////////////////////////////////

parameter ALU_OP_WIDTH = 7;

parameter ALU_ADD   = 7'b0011000;
parameter ALU_SUB   = 7'b0011001;
parameter ALU_ADDU  = 7'b0011010;
parameter ALU_SUBU  = 7'b0011011;
parameter ALU_ADDR  = 7'b0011100;
parameter ALU_SUBR  = 7'b0011101;
parameter ALU_ADDUR = 7'b0011110;
parameter ALU_SUBUR = 7'b0011111;

parameter ALU_XOR   = 7'b0101111;
parameter ALU_OR    = 7'b0101110;
parameter ALU_AND   = 7'b0010101;

// Shifts
parameter ALU_SRA   = 7'b0100100;
parameter ALU_SRL   = 7'b0100101;
parameter ALU_ROR   = 7'b0100110;
parameter ALU_SLL   = 7'b0100111;

// bit manipulation
parameter ALU_BEXT  = 7'b0101000;
parameter ALU_BEXTU = 7'b0101001;
parameter ALU_BINS  = 7'b0101010;
parameter ALU_BCLR  = 7'b0101011;
parameter ALU_BSET  = 7'b0101100;
parameter ALU_BREV  = 7'b1001001;

// Bit counting
parameter ALU_FF1   = 7'b0110110;
parameter ALU_FL1   = 7'b0110111;
parameter ALU_CNT   = 7'b0110100;
parameter ALU_CLB   = 7'b0110101;

// Sign-/zero-extensions
parameter ALU_EXTS  = 7'b0111110;
parameter ALU_EXT   = 7'b0111111;

// Comparisons
parameter ALU_LTS   = 7'b0000000;
parameter ALU_LTU   = 7'b0000001;
parameter ALU_LES   = 7'b0000100;
parameter ALU_LEU   = 7'b0000101;
parameter ALU_GTS   = 7'b0001000;
parameter ALU_GTU   = 7'b0001001;
parameter ALU_GES   = 7'b0001010;
parameter ALU_GEU   = 7'b0001011;
parameter ALU_EQ    = 7'b0001100;
parameter ALU_NE    = 7'b0001101;

// Set Lower Than operations
parameter ALU_SLTS  = 7'b0000010;
parameter ALU_SLTU  = 7'b0000011;
parameter ALU_SLETS = 7'b0000110;
parameter ALU_SLETU = 7'b0000111;

// Absolute value
parameter ALU_ABS   = 7'b0010100;
parameter ALU_CLIP  = 7'b0010110;
parameter ALU_CLIPU = 7'b0010111;

// Insert/extract
parameter ALU_INS   = 7'b0101101;

// min/max
parameter ALU_MIN   = 7'b0010000;
parameter ALU_MINU  = 7'b0010001;
parameter ALU_MAX   = 7'b0010010;
parameter ALU_MAXU  = 7'b0010011;

// div/rem
parameter ALU_DIVU  = 7'b0110000; // bit 0 is used for signed mode, bit 1 is used for remdiv
parameter ALU_DIV   = 7'b0110001; // bit 0 is used for signed mode, bit 1 is used for remdiv
parameter ALU_REMU  = 7'b0110010; // bit 0 is used for signed mode, bit 1 is used for remdiv
parameter ALU_REM   = 7'b0110011; // bit 0 is used for signed mode, bit 1 is used for remdiv

parameter ALU_SHUF  = 7'b0111010;
parameter ALU_SHUF2 = 7'b0111011;
parameter ALU_PCKLO = 7'b0111000;
parameter ALU_PCKHI = 7'b0111001;

// fpu
parameter ALU_FKEEP   = 7'b1111111;   // hack, to support fcvt.s.d
parameter ALU_FSGNJ   = 7'b1000000;
parameter ALU_FSGNJN  = 7'b1000001;
parameter ALU_FSGNJX  = 7'b1000010;
parameter ALU_FEQ     = 7'b1000011;
parameter ALU_FLT     = 7'b1000100;
parameter ALU_FLE     = 7'b1000101;
parameter ALU_FMAX    = 7'b1000110;
parameter ALU_FMIN    = 7'b1000111;
parameter ALU_FCLASS  = 7'b1001000;

parameter MUL_MAC32 = 4'b0000; // from 3bits to 4bits (modified by sharmine)
parameter MUL_MSU32 = 4'b0001; // from 3bits to 4bits (modified by sharmine)
parameter MUL_I     = 4'b0010; // from 3bits to 4bits (modified by sharmine)
parameter MUL_IR    = 4'b0011; // from 3bits to 4bits (modified by sharmine)
parameter MUL_DOT8  = 4'b0100; // from 3bits to 4bits (modified by sharmine)
parameter MUL_DOT16 = 4'b0101; // from 3bits to 4bits (modified by sharmine)
parameter MUL_H     = 4'b0110; // from 3bits to 4bits (modified by sharmine)

parameter MUL_CL    = 4'b0111; // carry-less multiplication (added by Sharmine)
parameter MUL_CLH   = 4'b1000; // carry-less multiplication (added by Sharmine)
parameter MUL_CLI   = 4'b1001; // carry-less multiplication immediate (added by Sharmine)
parameter MUL_CLHI  = 4'b1010; // carry-less multiplication immediate (added by Sharmine)

// vector modes
parameter VEC_MODE32 = 2'b00;
parameter VEC_MODE16 = 2'b10;
parameter VEC_MODE8  = 2'b11;

/////////////////////////////////////////////////////////
//    ____ ____    ____            _     _             //
//   / ___/ ___|  |  _ \ ___  __ _(_)___| |_ ___ _ __  //
//  | |   \___ \  | |_) / _ \/ _` | / __| __/ _ \ '__| //
//  | |___ ___) | |  _ <  __/ (_| | \__ \ ||  __/ |    //
//   \____|____/  |_| \_\___|\__, |_|___/\__\___|_|    //
//                           |___/                     //
/////////////////////////////////////////////////////////

// CSRs mnemonics
// imported form IBEX, some regs may be still not implemented
typedef enum logic[11:0] {
  // Machine information
  CSR_MHARTID   = 12'hF14,

  // Machine trap setup
  CSR_MSTATUS   = 12'h300,
  CSR_MISA      = 12'h301,
  CSR_MIE       = 12'h304,
  CSR_MTVEC     = 12'h305,
  CSR_MIEX      = 12'h7D0,
  CSR_MTVECX    = 12'h7D1,

  // Machine trap handling
  CSR_MSCRATCH  = 12'h340,
  CSR_MEPC      = 12'h341,
  CSR_MCAUSE    = 12'h342,
  CSR_MIP       = 12'h344,
  CSR_MIPX      = 12'h7D2,

  // User trap setup
  CSR_USTATUS   = 12'h000,
  CSR_UTVEC     = 12'h005,

  // User trap handling
  CSR_UEPC      = 12'h041,
  CSR_UCAUSE    = 12'h042,

  // Physical memory protection
  CSR_PMPCFG0   = 12'h3A0,
  CSR_PMPCFG1   = 12'h3A1,
  CSR_PMPCFG2   = 12'h3A2,
  CSR_PMPCFG3   = 12'h3A3,
  CSR_PMPADDR0  = 12'h3B0,
  CSR_PMPADDR1  = 12'h3B1,
  CSR_PMPADDR2  = 12'h3B2,
  CSR_PMPADDR3  = 12'h3B3,
  CSR_PMPADDR4  = 12'h3B4,
  CSR_PMPADDR5  = 12'h3B5,
  CSR_PMPADDR6  = 12'h3B6,
  CSR_PMPADDR7  = 12'h3B7,
  CSR_PMPADDR8  = 12'h3B8,
  CSR_PMPADDR9  = 12'h3B9,
  CSR_PMPADDR10 = 12'h3BA,
  CSR_PMPADDR11 = 12'h3BB,
  CSR_PMPADDR12 = 12'h3BC,
  CSR_PMPADDR13 = 12'h3BD,
  CSR_PMPADDR14 = 12'h3BE,
  CSR_PMPADDR15 = 12'h3BF,

  // Debug/trace
  CSR_DCSR      = 12'h7b0,
  CSR_DPC       = 12'h7b1,

  // Debug
  CSR_DSCRATCH0 = 12'h7b2, // optional
  CSR_DSCRATCH1 = 12'h7b3 // optional

} csr_num_e;

// CSR operations
parameter CSR_OP_NONE  = 2'b00;
parameter CSR_OP_WRITE = 2'b01;
parameter CSR_OP_SET   = 2'b10;
parameter CSR_OP_CLEAR = 2'b11;

// CSR interrupt pending/enable bits
parameter int unsigned CSR_MSIX_BIT      = 3;
parameter int unsigned CSR_MTIX_BIT      = 7;
parameter int unsigned CSR_MEIX_BIT      = 11;
parameter int unsigned CSR_MFIX_BIT_LOW  = 16;
parameter int unsigned CSR_MFIX_BIT_HIGH = 30;
parameter int unsigned CSR_NMIX_BIT      = 31; // nmi bit needed to read mip

// SPR for debugger, not accessible by CPU
parameter SP_DVR0       = 16'h3000;
parameter SP_DCR0       = 16'h3008;
parameter SP_DMR1       = 16'h3010;
parameter SP_DMR2       = 16'h3011;

parameter SP_DVR_MSB = 8'h00;
parameter SP_DCR_MSB = 8'h01;
parameter SP_DMR_MSB = 8'h02;
parameter SP_DSR_MSB = 8'h04;

// Privileged mode
typedef enum logic[1:0] {
  PRIV_LVL_M = 2'b11,
  PRIV_LVL_H = 2'b10,
  PRIV_LVL_S = 2'b01,
  PRIV_LVL_U = 2'b00
} PrivLvl_t;

///////////////////////////////////////////////
//   ___ ____    ____  _                     //
//  |_ _|  _ \  / ___|| |_ __ _  __ _  ___   //
//   | || | | | \___ \| __/ _` |/ _` |/ _ \  //
//   | || |_| |  ___) | || (_| | (_| |  __/  //
//  |___|____/  |____/ \__\__,_|\__, |\___|  //
//                              |___/        //
///////////////////////////////////////////////

// forwarding operand mux
parameter SEL_REGFILE      = 2'b00;
parameter SEL_FW_EX        = 2'b01;
parameter SEL_FW_WB        = 2'b10;

// operand a selection
parameter OP_A_REGA_OR_FWD = 3'b000;
parameter OP_A_CURRPC      = 3'b001;
parameter OP_A_IMM         = 3'b010;
parameter OP_A_REGB_OR_FWD = 3'b011;
parameter OP_A_REGC_OR_FWD = 3'b100;

// immediate a selection
parameter IMMA_Z      = 1'b0;
parameter IMMA_ZERO   = 1'b1;

// operand b selection
parameter OP_B_REGB_OR_FWD = 3'b000;
parameter OP_B_REGC_OR_FWD = 3'b001;
parameter OP_B_IMM         = 3'b010;
parameter OP_B_REGA_OR_FWD = 3'b011;
parameter OP_B_BMASK       = 3'b100;

// immediate b selection
parameter IMMB_I      = 4'b0000;
parameter IMMB_S      = 4'b0001;
parameter IMMB_U      = 4'b0010;
parameter IMMB_PCINCR = 4'b0011;
parameter IMMB_S2     = 4'b0100;
parameter IMMB_S3     = 4'b0101;
parameter IMMB_VS     = 4'b0110;
parameter IMMB_VU     = 4'b0111;
parameter IMMB_SHUF   = 4'b1000;
parameter IMMB_CLIP   = 4'b1001;
parameter IMMB_BI     = 4'b1011;

// bit mask selection
parameter BMASK_A_ZERO = 1'b0;
parameter BMASK_A_S3   = 1'b1;

parameter BMASK_B_S2   = 2'b00;
parameter BMASK_B_S3   = 2'b01;
parameter BMASK_B_ZERO = 2'b10;
parameter BMASK_B_ONE  = 2'b11;

parameter BMASK_A_REG  = 1'b0;
parameter BMASK_A_IMM  = 1'b1;
parameter BMASK_B_REG  = 1'b0;
parameter BMASK_B_IMM  = 1'b1;


// multiplication immediates
parameter MIMM_ZERO    = 1'b0;
parameter MIMM_S3      = 1'b1;

// operand c selection
parameter OP_C_REGC_OR_FWD = 2'b00;
parameter OP_C_REGB_OR_FWD = 2'b01;
parameter OP_C_JT          = 2'b10;

// branch types
parameter BRANCH_NONE = 2'b00;
parameter BRANCH_JAL  = 2'b01;
parameter BRANCH_JALR = 2'b10;
parameter BRANCH_COND = 2'b11; // conditional branches

// jump target mux
parameter JT_JAL  = 2'b01;
parameter JT_JALR = 2'b10;
parameter JT_COND = 2'b11;

// Atomic operations
parameter AMO_LR   = 5'b00010;
parameter AMO_SC   = 5'b00011;
parameter AMO_SWAP = 5'b00001;
parameter AMO_ADD  = 5'b00000;
parameter AMO_XOR  = 5'b00100;
parameter AMO_AND  = 5'b01100;
parameter AMO_OR   = 5'b01000;
parameter AMO_MIN  = 5'b10000;
parameter AMO_MAX  = 5'b10100;
parameter AMO_MINU = 5'b11000;
parameter AMO_MAXU = 5'b11100;

///////////////////////////////////////////////
//   ___ _____   ____  _                     //
//  |_ _|  ___| / ___|| |_ __ _  __ _  ___   //
//   | || |_    \___ \| __/ _` |/ _` |/ _ \  //
//   | ||  _|    ___) | || (_| | (_| |  __/  //
//  |___|_|     |____/ \__\__,_|\__, |\___|  //
//                              |___/        //
///////////////////////////////////////////////

// PC mux selector defines
parameter PC_BOOT          = 3'b000;
parameter PC_JUMP          = 3'b010;
parameter PC_BRANCH        = 3'b011;
parameter PC_EXCEPTION     = 3'b100;
parameter PC_FENCEI        = 3'b001;
parameter PC_MRET          = 3'b101;
parameter PC_URET          = 3'b110;
parameter PC_DRET          = 3'b111;

// Exception PC mux selector defines
parameter EXC_PC_EXCEPTION = 3'b000;
parameter EXC_PC_IRQ       = 3'b001;

parameter EXC_PC_DBD       = 3'b010;

// Exception Cause
parameter EXC_CAUSE_INSTR_FAULT  = 6'h01;
parameter EXC_CAUSE_ILLEGAL_INSN = 6'h02;
parameter EXC_CAUSE_BREAKPOINT   = 6'h03;
parameter EXC_CAUSE_LOAD_FAULT   = 6'h05;
parameter EXC_CAUSE_STORE_FAULT  = 6'h07;
parameter EXC_CAUSE_ECALL_UMODE  = 6'h08;
parameter EXC_CAUSE_ECALL_MMODE  = 6'h0B;

parameter int unsigned IRQ_ID_BITS = 6;
parameter int unsigned IRQ_LINES_NUM = 51;  // number of physical irq lines to core
// Interrupt lines struct
typedef struct packed {
  logic        irq_software;
  logic        irq_timer;
  logic        irq_external;
  logic [14:0] irq_fast;
  logic        irq_nmi;
} Interrupts_t;


// Trap mux selector
parameter TRAP_MACHINE      = 2'b00;
parameter TRAP_USER         = 2'b01;
parameter TRAP_MACHINEX     = 2'b10;

// Debug Cause
parameter DBG_CAUSE_EBREAK     = 3'h1;
parameter DBG_CAUSE_TRIGGER    = 3'h2;
parameter DBG_CAUSE_HALTREQ    = 3'h3;
parameter DBG_CAUSE_STEP       = 3'h4;
parameter DBG_CAUSE_RSTHALTREQ = 3'h5;

// Debug module
parameter DBG_SETS_W = 6;

parameter DBG_SETS_IRQ    = 5;
parameter DBG_SETS_ECALL  = 4;
parameter DBG_SETS_EILL   = 3;
parameter DBG_SETS_ELSU   = 2;
parameter DBG_SETS_EBRK   = 1;
parameter DBG_SETS_SSTE   = 0;

parameter DBG_CAUSE_HALT   = 6'h1F;


/////////////////////////////////////
// THIS PART IS OBSOLETED BY FPNEW //
/////////////////////////////////////
// // private FPU
// parameter C_CMD               = 4;
// parameter C_FPU_ADD_CMD       = 4'h0;
// parameter C_FPU_SUB_CMD       = 4'h1;
// parameter C_FPU_MUL_CMD       = 4'h2;
// parameter C_FPU_DIV_CMD       = 4'h3;
// parameter C_FPU_I2F_CMD       = 4'h4;
// parameter C_FPU_F2I_CMD       = 4'h5;
// parameter C_FPU_SQRT_CMD      = 4'h6;
// parameter C_FPU_NOP_CMD       = 4'h7;
// parameter C_FPU_FMADD_CMD     = 4'h8;
// parameter C_FPU_FMSUB_CMD     = 4'h9;
// parameter C_FPU_FNMADD_CMD    = 4'hA;
// parameter C_FPU_FNMSUB_CMD    = 4'hB;

// Floating-point extensions configuration
parameter bit C_RVF = 1'b1; // Is F extension enabled
parameter bit C_RVD = 1'b0; // Is D extension enabled - NOT SUPPORTED CURRENTLY

// Transprecision floating-point extensions configuration
parameter bit C_XF16    = 1'b0; // Is half-precision float extension (Xf16) enabled
parameter bit C_XF16ALT = 1'b0; // Is alternative half-precision float extension (Xf16alt) enabled
parameter bit C_XF8     = 1'b0; // Is quarter-precision float extension (Xf8) enabled
parameter bit C_XFVEC   = 1'b0; // Is vectorial float extension (Xfvec) enabled

// FPnew configuration
parameter C_FPNEW_OPBITS   = fpnew_pkg::OP_BITS;
parameter C_FPNEW_FMTBITS  = fpnew_pkg::FP_FORMAT_BITS;
parameter C_FPNEW_IFMTBITS = fpnew_pkg::INT_FORMAT_BITS;

// Latency of FP operations: 0 = no pipe registers, 1 = 1 pipe register etc.
parameter int unsigned C_LAT_FP64       = 'd5;
parameter int unsigned C_LAT_FP32       = 'd5;
parameter int unsigned C_LAT_FP16       = 'd5;
parameter int unsigned C_LAT_FP16ALT    = 'd5;
parameter int unsigned C_LAT_FP8        = 'd5;
parameter int unsigned C_LAT_DIVSQRT    = 'd5; // divsqrt post-processing pipe
parameter int unsigned C_LAT_CONV       = 'd5;
parameter int unsigned C_LAT_NONCOMP    = 'd5;

// General FPU-specific defines

// Length of widest floating-point format = width of fp regfile
parameter C_FLEN = C_RVD     ? 64 : // D ext.
                   C_RVF     ? 32 : // F ext.
                   C_XF16    ? 16 : // Xf16 ext.
                   C_XF16ALT ? 16 : // Xf16alt ext.
                   C_XF8     ? 8 :  // Xf8 ext.
                   0;               // Unused in case of no FP

parameter C_FFLAG             = 5;
parameter C_RM                = 3;

parameter C_PC                = 5;



/////////////////////////////////////////////////////////
//    ____ ____    ____                                //
//   / ___/ ___|  |  _ \                               //
//  | |   \___ \  | |_) |    MAPPING                   //
//  | |___ ___) | |  _ <                               //
//   \____|____/  |_| \_\                              //
//                                                     //
/////////////////////////////////////////////////////////

//Hardware Loop
parameter HWLoop0_START         = 12'h7C0; //NON standard read/write (Machine CSRs). Old address 12'h7B0;
parameter HWLoop0_END           = 12'h7C1; //NON standard read/write (Machine CSRs). Old address 12'h7B1;
parameter HWLoop0_COUNTER       = 12'h7C2; //NON standard read/write (Machine CSRs). Old address 12'h7B2;
parameter HWLoop1_START         = 12'h7C4; //NON standard read/write (Machine CSRs). Old address 12'h7B4;
parameter HWLoop1_END           = 12'h7C5; //NON standard read/write (Machine CSRs). Old address 12'h7B5;
parameter HWLoop1_COUNTER       = 12'h7C6; //NON standard read/write (Machine CSRs). Old address 12'h7B6;

//Performance Counters
//event and mode registers
parameter PCER_USER = 12'hCC0; //NON standard read-only (User CSRs). Old address 12'h7A0;
parameter PCMR_USER = 12'hCC1; //NON standard read-only (User CSRs). Old address 12'h7A1;

parameter PCER_MACHINE = 12'h7E0; //NON standard read/write (Machine CSRs)
parameter PCMR_MACHINE = 12'h7E1; //NON standard read/write (Machine CSRs)




endpackage