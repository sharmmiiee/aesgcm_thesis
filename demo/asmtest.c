// Verification patterns
// This file is used to validate the functionality of the new instruction extensions


#include <stdint.h>
#include <stdio.h>
#include "asmtest.h"

void asmtest(void){

	//ori();

	// MULCL and MULCLH
        printf("\n\n\t ----- MULCL and MULCLH -----\n");
        printf("\n\nTEST A *************************************************\n");
	mulcl_ex1();
	nop();
	mulcl_ex2(); // with clock count
        nop();

      
        printf("\n\nTEST B *************************************************\n");
	mulcl_ex3();
	nop();
	mulcl_ex4(); // with clock count
	nop();

        printf("\n\nTEST C *************************************************\n");
	mulcl_ex5();
	nop();
	mulcl_ex6(); // with clock count
	nop();

        printf("\n\nTEST D *************************************************\n");
	mulcl_ex7();
	nop();
	mulcl_ex8(); // with clock count
	nop();

        printf("\n\nTEST E *************************************************\n");
	mulcl_ex9();
	nop();
	mulcl_ex10(); // with clock count
	nop();

        printf("\n\nTEST F *************************************************\n");
	mulcl_ex11();
	nop();
	mulcl_ex12(); // with clock count
	nop();


        printf("\n\nTEST G *************************************************\n");
	mulcl_ex13();
	nop();
	mulcl_ex14(); // with clock count
	nop();


        printf("\n\nTEST H *************************************************\n");
	mulcl_ex15();
	nop();
	mulcl_ex16(); // with clock count
	nop();


        printf("\n\n\t ----- MULCLI and MULCLHI (Immediate) -----\n");

        printf("\n\nTEST I *************************************************\n");
	mulclimm_ex1();
	nop();
	mulclimm_ex2(); // with clock count
	nop();

        printf("\n\nTEST J *************************************************\n");
	mulclimm_ex3();
	nop();
	mulclimm_ex4(); // with clock count
	nop();

        printf("\n\nTEST K *************************************************\n");
	mulclimm_ex5();
	nop();
	mulclimm_ex6(); // with clock count
	nop();

        printf("\n\nTEST L *************************************************\n");
	mulclimm_ex7();
	nop();
	mulclimm_ex8(); // with clock count
	nop();

        printf("\n\nTEST M *************************************************\n");
	mulclimm_ex9();
	nop();
	mulclimm_ex10(); // with clock count
	nop();

//        printf("\n\nTEST D *************************************************\n");
//	karatsuba1();
}




void mulcl_ex1(void) {
    int32_t mulcl_result, mulclh_result;
    int32_t operand1_print, operand2_print;

    asm volatile (
        ".text\n"
        "    lui %[reg_operand1], 0xA2CCF\n"                // Load upper immediate for operand1
        "    ori %[reg_operand1], %[reg_operand1], 0x053\n" // Load lower immediate for operand1
        "    lui %[reg_operand2], 0x96AA8\n"                // Load upper immediate for operand2
        "    ori %[reg_operand2], %[reg_operand2], 0x281\n" // Load lower immediate for operand2
        "    mulclh %[mulclh_result], %[reg_operand1], %[reg_operand2]\n"
        "    mulcl %[mulcl_result], %[reg_operand1], %[reg_operand2]\n"
        : [mulclh_result] "=r" (mulclh_result), [mulcl_result] "=r" (mulcl_result),
          [reg_operand1] "=&r" (operand1_print), [reg_operand2] "=&r" (operand2_print)  // Use early-clobber to prevent input/output conflict
    );

    printf("\n=== MULCL and MULCLH ===\n");

    // Print the loaded values for debugging purposes
    printf("Operand1: %lxh\n", (unsigned long)operand1_print);
    printf("Operand2: %lxh\n", (unsigned long)operand2_print);
    // Print the results
    printf("mulclh: actual = %lxh \t expected = 58c52167h \n", (unsigned long)mulclh_result);
    printf("mulcl : actual = %lxh \t expected = 3ea3ffd3h \n", (unsigned long)mulcl_result);
}

void mulcl_ex2(void) { // mulcl_ex1 with clock count
    int32_t mulcl_result, mulclh_result;
    int32_t operand1_print, operand2_print;
    unsigned int start_cc_h, start_cc_l, end_cc_h, end_cc_l;

    unsigned int pcmr = 1; /* global enable without saturation */
    unsigned int pcer = 3; /* cycles and instr count enable */

    // Enable cycle and instruction count
    asm volatile ("csrw 0x7e0, %0" :: "r" (pcer));

    // Enable global cycle counter
    asm volatile ("csrw 0x7e1, %0" :: "r" (pcmr));

    // main program of carry-less multiplication
    asm volatile (
        ".text\n"
        "    lui %[reg_operand1], 0xA2CCF\n"                // Load upper immediate for operand1
        "    ori %[reg_operand1], %[reg_operand1], 0x053\n" // Load lower immediate for operand1
        "    lui %[reg_operand2], 0x96AA8\n"                // Load upper immediate for operand2
        "    ori %[reg_operand2], %[reg_operand2], 0x281\n" // Load lower immediate for operand2
        "    csrr %0, 0x780 \n" // Clock cycle counter start for MULCLH
        "    mulclh %[mulclh_result], %[reg_operand1], %[reg_operand2]\n"
        "    csrr %1, 0x780 \n" // Clock Counter End for MULCLH
        "    csrr %2, 0x780 \n" // Clock cycle counter start for MULCL
        "    mulcl %[mulcl_result], %[reg_operand1], %[reg_operand2]\n"
        "    csrr %3, 0x780 \n" // Clock Counter End for MULCL
        : "=r" (start_cc_h), "=r" (end_cc_h), "=r" (start_cc_l), "=r" (end_cc_l), [mulclh_result] "=r" (mulclh_result), [mulcl_result] "=r" (mulcl_result),
         [reg_operand1] "=&r" (operand1_print), [reg_operand2] "=&r" (operand2_print)  // Input operands
    );

    // Disable cycle and instruction count
    asm volatile ("csrw 0x7e0, %0" :: "r" (0));

    printf("\n=== MULCL and MULCLH (with clock cycle counts) ===\n");

    // Print the loaded values for debugging purposes
    printf("Operand1: %lxh\n", (unsigned long)operand1_print);
    printf("Operand2: %lxh\n", (unsigned long)operand2_print);

    // Print the results
    printf("mulclh: actual = %lxh \t expected = 58c52167h \n", (unsigned long)mulclh_result);
    printf(" start clock cycle (MULCLH) = %u\n", start_cc_h);
    printf(" end clock cycle (MULCLH) = %u\n", end_cc_h);
    printf(" total clock cycle (MULCLH) = %u\n", end_cc_h - start_cc_h);

    printf("mulcl : actual = %lxh \t expected = 3ea3ffd3h \n", (unsigned long)mulcl_result);
    printf(" start clock cycle (MULCL) = %u\n", start_cc_l);
    printf(" end clock cycle (MULCL) = %u\n", end_cc_l);
    printf(" total clock cycle (MULCL) = %u\n\n", end_cc_l - start_cc_l);
}


void mulcl_ex3(void) {
    int32_t mulcl_result, mulclh_result;
    int32_t operand1_print,operand2_print;

    asm volatile (
        ".text\n"
        "    lui %[reg_operand1], 0x58C52\n"                // Load upper immediate for operand1
        "    ori %[reg_operand1], %[reg_operand1], 0x167\n" // Load lower immediate for operand1
        "    lui %[reg_operand2], 0x00000\n"                // Load upper immediate for operand2
        "    ori %[reg_operand2], %[reg_operand2], 0x000\n" // Load lower immediate for operand2
        "    mulclh %[mulclh_result], %[reg_operand1], %[reg_operand2]\n"
        "    mulcl %[mulcl_result], %[reg_operand1], %[reg_operand2]\n"
        : [mulclh_result] "=r" (mulclh_result), [mulcl_result] "=r" (mulcl_result),
          [reg_operand1] "=&r" (operand1_print), [reg_operand2] "=&r" (operand2_print)  // Input operands
    );

    printf("\n=== MULCL and MULCLH example 2 ===\n");

    // Print the loaded values for debugging purposes
    printf("Operand1: %lxh\n", (unsigned long)operand1_print);
    printf("Operand2: %lxh\n", (unsigned long)operand2_print);
    // Print the results
    printf("mulclh: actual = %lxh \t expected = 0h \n", (unsigned long)mulclh_result);
    printf("mulcl : actual = %lxh \t expected = 0h \n", (unsigned long)mulcl_result);
}




void mulcl_ex4(void) { // mulcl_ex3 with clock count
    int32_t mulcl_result, mulclh_result;
    int32_t operand1_print,operand2_print;

    unsigned int pcmr = 1; /* global enable without saturation */
    unsigned int pcer = 3; /* cycles and instr count enable */
    unsigned int start_cc_h, start_cc_l, end_cc_h, end_cc_l;

    // Enable cycle and instruction count
    asm volatile ("csrw 0x7e0, %0" :: "r" (pcer));

    // Enable global cycle counter
    asm volatile ("csrw 0x7e1, %0" :: "r" (pcmr));

    // main program of carry-less multiplication
    asm volatile (
        ".text\n"
        "    lui %[reg_operand1], 0x58C52\n"                // Load upper immediate for operand1
        "    ori %[reg_operand1], %[reg_operand1], 0x167\n" // Load lower immediate for operand1
        "    lui %[reg_operand2], 0x00000\n"                // Load upper immediate for operand2
        "    ori %[reg_operand2], %[reg_operand2], 0x000\n" // Load lower immediate for operand2
        "    csrr %0, 0x780 \n" // Clock cycle counter start for MULCLH
        "    mulclh %[mulclh_result], %[reg_operand1], %[reg_operand2]\n"
        "    csrr %1, 0x780 \n" // Clock Counter End for MULCLH
        "    csrr %2, 0x780 \n" // Clock cycle counter start for MULCL
        "    mulcl %[mulcl_result], %[reg_operand1], %[reg_operand2]\n"
        "    csrr %3, 0x780 \n" // Clock Counter End for MULCL
        : "=r" (start_cc_h), "=r" (end_cc_h), "=r" (start_cc_l), "=r" (end_cc_l), [mulclh_result] "=r" (mulclh_result), [mulcl_result] "=r" (mulcl_result),
          [reg_operand1] "=&r" (operand1_print), [reg_operand2] "=&r" (operand2_print)  // Input operands
    );

    // Disable cycle and instruction count
    asm volatile ("csrw 0x7e0, %0" :: "r" (0));

    printf("\n=== MULCL and MULCLH example 2 (with clock cycle counts) ===\n");

    // Print the loaded values for debugging purposes
    printf("Operand1: %lxh\n", (unsigned long)operand1_print);
    printf("Operand2: %lxh\n", (unsigned long)operand2_print);

    // Print the results
    printf("mulclh: actual = %lxh \t expected = 0h \n", (unsigned long)mulclh_result);
    printf(" start clock cycle (MULCLH) = %u\n", start_cc_h);
    printf(" end clock cycle (MULCLH) = %u\n", end_cc_h);
    printf(" total clock cycle (MULCLH) = %u\n", end_cc_h - start_cc_h);

    printf("mulcl : actual = %lxh \t expected = 0h \n", (unsigned long)mulcl_result);
    printf(" start clock cycle (MULCL) = %u\n", start_cc_l);
    printf(" end clock cycle (MULCL) = %u\n", end_cc_l);
    printf(" total clock cycle (MULCL) = %u\n\n", end_cc_l - start_cc_l);
}

void mulcl_ex5(void) {
    int32_t mulcl_result, mulclh_result;
    int32_t operand1_print,operand2_print;

    asm volatile (
        ".text\n"
        "    lui %[reg_operand1], 0x00000\n"                // Load upper immediate for operand1
        "    ori %[reg_operand1], %[reg_operand1], 0x000\n" // Load lower immediate for operand1
        "    lui %[reg_operand2], 0x58C52\n"                // Load upper immediate for operand2
        "    ori %[reg_operand2], %[reg_operand2], 0x167\n" // Load lower immediate for operand2
        "    mulclh %[mulclh_result], %[reg_operand1], %[reg_operand2]\n"
        "    mulcl %[mulcl_result], %[reg_operand1], %[reg_operand2]\n"
        : [mulclh_result] "=r" (mulclh_result), [mulcl_result] "=r" (mulcl_result),
          [reg_operand1] "=&r" (operand1_print), [reg_operand2] "=&r" (operand2_print)  // Input operands
    );

    printf("\n=== MULCL and MULCLH example 2 ===\n");

    // Print the loaded values for debugging purposes
    printf("Operand1: %lxh\n", (unsigned long)operand1_print);
    printf("Operand2: %lxh\n", (unsigned long)operand2_print);
    // Print the results
    printf("mulclh: actual = %lxh \t expected = 0h \n", (unsigned long)mulclh_result);
    printf("mulcl : actual = %lxh \t expected = 0h \n", (unsigned long)mulcl_result);
}




void mulcl_ex6(void) { // mulcl_ex5 with clock count
    int32_t mulcl_result, mulclh_result;
    int32_t operand1_print,operand2_print;

    unsigned int pcmr = 1; /* global enable without saturation */
    unsigned int pcer = 3; /* cycles and instr count enable */
    unsigned int start_cc_h, start_cc_l, end_cc_h, end_cc_l;

    // Enable cycle and instruction count
    asm volatile ("csrw 0x7e0, %0" :: "r" (pcer));

    // Enable global cycle counter
    asm volatile ("csrw 0x7e1, %0" :: "r" (pcmr));

    // main program of carry-less multiplication
    asm volatile (
        ".text\n"
        "    lui %[reg_operand1], 0x00000\n"                // Load upper immediate for operand1
        "    ori %[reg_operand1], %[reg_operand1], 0x000\n" // Load lower immediate for operand1
        "    lui %[reg_operand2], 0x58C52\n"                // Load upper immediate for operand2
        "    ori %[reg_operand2], %[reg_operand2], 0x167\n" // Load lower immediate for operand2
        "    csrr %0, 0x780 \n" // Clock cycle counter start for MULCLH
        "    mulclh %[mulclh_result], %[reg_operand1], %[reg_operand2]\n"
        "    csrr %1, 0x780 \n" // Clock Counter End for MULCLH
        "    csrr %2, 0x780 \n" // Clock cycle counter start for MULCL
        "    mulcl %[mulcl_result], %[reg_operand1], %[reg_operand2]\n"
        "    csrr %3, 0x780 \n" // Clock Counter End for MULCL
        : "=r" (start_cc_h), "=r" (end_cc_h), "=r" (start_cc_l), "=r" (end_cc_l), [mulclh_result] "=r" (mulclh_result), [mulcl_result] "=r" (mulcl_result),
          [reg_operand1] "=&r" (operand1_print), [reg_operand2] "=&r" (operand2_print)  // Input operands
    );

    // Disable cycle and instruction count
    asm volatile ("csrw 0x7e0, %0" :: "r" (0));

    printf("\n=== MULCL and MULCLH example 2 (with clock cycle counts) ===\n");

    // Print the loaded values for debugging purposes
    printf("Operand1: %lxh\n", (unsigned long)operand1_print);
    printf("Operand2: %lxh\n", (unsigned long)operand2_print);

    // Print the results
    printf("mulclh: actual = %lxh \t expected = 0h \n", (unsigned long)mulclh_result);
    printf(" start clock cycle (MULCLH) = %u\n", start_cc_h);
    printf(" end clock cycle (MULCLH) = %u\n", end_cc_h);
    printf(" total clock cycle (MULCLH) = %u\n", end_cc_h - start_cc_h);

    printf("mulcl : actual = %lxh \t expected = 0h \n", (unsigned long)mulcl_result);
    printf(" start clock cycle (MULCL) = %u\n", start_cc_l);
    printf(" end clock cycle (MULCL) = %u\n", end_cc_l);
    printf(" total clock cycle (MULCL) = %u\n\n", end_cc_l - start_cc_l);
}

void mulcl_ex7(void) {
    int32_t mulcl_result, mulclh_result;
    int32_t operand1 = 0xAAAAAAAA;
    int32_t operand2 = 0xFFFFFFFF;
    asm volatile (
        "mulclh %[mulclh_result], %[operand1], %[operand2]\n"
        "mulcl  %[mulcl_result],  %[operand1], %[operand2]\n"
        : [mulclh_result] "=r" (mulclh_result), [mulcl_result] "=r" (mulcl_result) // output
        : [operand1] "r" (operand1), [operand2] "r" (operand2)                       // input
    );

    printf("\n=== MULCL and MULCLH ===\n");
    // Print the loaded values for debugging purposes
    printf("Operand1: %lxh\n", (unsigned long)operand1);
    printf("Operand2: %lxh\n", (unsigned long)operand2);
    // Print the results
    printf("mulclh: actual = %lxh \t expected = 66666666h \n", (unsigned long)mulclh_result);
    printf("mulcl : actual = %lxh \t expected = 66666666h \n", (unsigned long)mulcl_result);
}

void mulcl_ex8(void) {
    int32_t mulcl_result, mulclh_result;
    int32_t operand1 = 0xAAAAAAAA;
    int32_t operand2 = 0xFFFFFFFF;
    //int32_t operand1 = 0xA2CCF053;
    //int32_t operand2 = 0x96AA8281;
    
    unsigned int pcmr = 1; /* global enable without saturation */
    unsigned int pcer = 3; /* cycles and instr count enable */
    unsigned int start_cc_h, start_cc_l, end_cc_h, end_cc_l;

    // Enable cycle and instruction count
    asm volatile ("csrw 0x7e0, %0" :: "r" (pcer));

    // Enable global cycle counter
    asm volatile ("csrw 0x7e1, %0" :: "r" (pcmr));

    asm volatile (
        "csrr %0, 0x780 \n" // Clock cycle counter start for MULCLH
        "mulclh %[mulclh_result], %[operand1], %[operand2]\n"
        "csrr %1, 0x780 \n" // Clock Counter End for MULCLH
        "csrr %2, 0x780 \n" // Clock cycle counter start for MULCL
        "mulcl  %[mulcl_result],  %[operand1], %[operand2]\n"
        "csrr %3, 0x780 \n" // Clock Counter End for MULCL
        : "=r" (start_cc_h), "=r" (end_cc_h), "=r" (start_cc_l), "=r" (end_cc_l), [mulclh_result] "=r" (mulclh_result), [mulcl_result] "=r" (mulcl_result) // output
        : [operand1] "r" (operand1), [operand2] "r" (operand2)                       // input
    );

    // Disable cycle and instruction count
    asm volatile ("csrw 0x7e0, %0" :: "r" (0));

    printf("\n=== MULCL and MULCLH (with clock cycle counts) ===\n");

    // Print the loaded values for debugging purposes
    printf("Operand1: %lxh\n", (unsigned long)operand1);
    printf("Operand2: %lxh\n", (unsigned long)operand2);

    // Print the results
    printf("mulclh: actual = %lxh \t expected = 66666666h \n", (unsigned long)mulclh_result);
    printf(" start clock cycle (MULCLH) = %u\n", start_cc_h);
    printf(" end clock cycle (MULCLH) = %u\n", end_cc_h);
    printf(" total clock cycle (MULCLH) = %u\n", end_cc_h - start_cc_h);

    printf("mulcl : actual = %lxh \t expected = 66666666h \n", (unsigned long)mulcl_result);
    printf(" start clock cycle (MULCL) = %u\n", start_cc_l);
    printf(" end clock cycle (MULCL) = %u\n", end_cc_l);
    printf(" total clock cycle (MULCL) = %u\n\n", end_cc_l - start_cc_l);
}

void mulcl_ex9(void) {
    int32_t mulcl_result, mulclh_result;
    int32_t operand2 = 0xAAAAAAAA;
    int32_t operand1 = 0xFFFFFFFF;

    asm volatile (
        "mulclh %[mulclh_result], %[operand1], %[operand2]\n"
        "mulcl  %[mulcl_result],  %[operand1], %[operand2]\n"
        : [mulclh_result] "=r" (mulclh_result), [mulcl_result] "=r" (mulcl_result) // output
        : [operand1] "r" (operand1), [operand2] "r" (operand2)                       // input
    );

    printf("\n=== MULCL and MULCLH ===\n");
    // Print the loaded values for debugging purposes
    printf("Operand1: %lxh\n", (unsigned long)operand1);
    printf("Operand2: %lxh\n", (unsigned long)operand2);
    // Print the results
    printf("mulclh: actual = %lxh \t expected = 66666666h \n", (unsigned long)mulclh_result);
    printf("mulcl : actual = %lxh \t expected = 66666666h \n", (unsigned long)mulcl_result);
}

void mulcl_ex10(void) {
    int32_t mulcl_result, mulclh_result;
    int32_t operand2 = 0xAAAAAAAA;
    int32_t operand1 = 0xFFFFFFFF;
    
    unsigned int pcmr = 1; /* global enable without saturation */
    unsigned int pcer = 3; /* cycles and instr count enable */
    unsigned int start_cc_h, start_cc_l, end_cc_h, end_cc_l;

    // Enable cycle and instruction count
    asm volatile ("csrw 0x7e0, %0" :: "r" (pcer));

    // Enable global cycle counter
    asm volatile ("csrw 0x7e1, %0" :: "r" (pcmr));

    asm volatile (
        "csrr %0, 0x780 \n" // Clock cycle counter start for MULCLH
        "mulclh %[mulclh_result], %[operand1], %[operand2]\n"
        "csrr %1, 0x780 \n" // Clock Counter End for MULCLH
        "csrr %2, 0x780 \n" // Clock cycle counter start for MULCL
        "mulcl  %[mulcl_result],  %[operand1], %[operand2]\n"
        "csrr %3, 0x780 \n" // Clock Counter End for MULCL
        : "=r" (start_cc_h), "=r" (end_cc_h), "=r" (start_cc_l), "=r" (end_cc_l), [mulclh_result] "=r" (mulclh_result), [mulcl_result] "=r" (mulcl_result) // output
        : [operand1] "r" (operand1), [operand2] "r" (operand2)                       // input
    );

    // Disable cycle and instruction count
    asm volatile ("csrw 0x7e0, %0" :: "r" (0));

    printf("\n=== MULCL and MULCLH (with clock cycle counts) ===\n");

    // Print the loaded values for debugging purposes
    printf("Operand1: %lxh\n", (unsigned long)operand1);
    printf("Operand2: %lxh\n", (unsigned long)operand2);

    // Print the results
    printf("mulclh: actual = %lxh \t expected = 66666666h \n", (unsigned long)mulclh_result);
    printf(" start clock cycle (MULCLH) = %u\n", start_cc_h);
    printf(" end clock cycle (MULCLH) = %u\n", end_cc_h);
    printf(" total clock cycle (MULCLH) = %u\n", end_cc_h - start_cc_h);

    printf("mulcl : actual = %lxh \t expected = 66666666h \n", (unsigned long)mulcl_result);
    printf(" start clock cycle (MULCL) = %u\n", start_cc_l);
    printf(" end clock cycle (MULCL) = %u\n", end_cc_l);
    printf(" total clock cycle (MULCL) = %u\n\n", end_cc_l - start_cc_l);
}

void mulcl_ex11(void) {
    int32_t mulcl_result, mulclh_result;
    int32_t operand1 = 0xFFFFFFFF;
    int32_t operand2 = 0xFFFFFFFF;

    asm volatile (
        "mulclh %[mulclh_result], %[operand1], %[operand2]\n"
        "mulcl  %[mulcl_result],  %[operand1], %[operand2]\n"
        : [mulclh_result] "=r" (mulclh_result), [mulcl_result] "=r" (mulcl_result) // output
        : [operand1] "r" (operand1), [operand2] "r" (operand2)                       // input
    );

    printf("\n=== MULCL and MULCLH ===\n");
    // Print the loaded values for debugging purposes
    printf("Operand1: %lxh\n", (unsigned long)operand1);
    printf("Operand2: %lxh\n", (unsigned long)operand2);
    // Print the results
    printf("mulclh: actual = %lxh \t expected = 55555555h \n", (unsigned long)mulclh_result);
    printf("mulcl : actual = %lxh \t expected = 55555555h \n", (unsigned long)mulcl_result);
}

void mulcl_ex12(void) {
    int32_t mulcl_result, mulclh_result;
    int32_t operand1 = 0xFFFFFFFF;
    int32_t operand2 = 0xFFFFFFFF;
    
    unsigned int pcmr = 1; /* global enable without saturation */
    unsigned int pcer = 3; /* cycles and instr count enable */
    unsigned int start_cc_h, start_cc_l, end_cc_h, end_cc_l;

    // Enable cycle and instruction count
    asm volatile ("csrw 0x7e0, %0" :: "r" (pcer));

    // Enable global cycle counter
    asm volatile ("csrw 0x7e1, %0" :: "r" (pcmr));

    asm volatile (
        "csrr %0, 0x780 \n" // Clock cycle counter start for MULCLH
        "mulclh %[mulclh_result], %[operand1], %[operand2]\n"
        "csrr %1, 0x780 \n" // Clock Counter End for MULCLH
        "csrr %2, 0x780 \n" // Clock cycle counter start for MULCL
        "mulcl  %[mulcl_result],  %[operand1], %[operand2]\n"
        "csrr %3, 0x780 \n" // Clock Counter End for MULCL
        : "=r" (start_cc_h), "=r" (end_cc_h), "=r" (start_cc_l), "=r" (end_cc_l), [mulclh_result] "=r" (mulclh_result), [mulcl_result] "=r" (mulcl_result) // output
        : [operand1] "r" (operand1), [operand2] "r" (operand2)                       // input
    );

    // Disable cycle and instruction count
    asm volatile ("csrw 0x7e0, %0" :: "r" (0));

    printf("\n=== MULCL and MULCLH (with clock cycle counts) ===\n");

    // Print the loaded values for debugging purposes
    printf("Operand1: %lxh\n", (unsigned long)operand1);
    printf("Operand2: %lxh\n", (unsigned long)operand2);

    // Print the results
    printf("mulclh: actual = %lxh \t expected = 55555555h \n", (unsigned long)mulclh_result);
    printf(" start clock cycle (MULCLH) = %u\n", start_cc_h);
    printf(" end clock cycle (MULCLH) = %u\n", end_cc_h);
    printf(" total clock cycle (MULCLH) = %u\n", end_cc_h - start_cc_h);

    printf("mulcl : actual = %lxh \t expected = 55555555h \n", (unsigned long)mulcl_result);
    printf(" start clock cycle (MULCL) = %u\n", start_cc_l);
    printf(" end clock cycle (MULCL) = %u\n", end_cc_l);
    printf(" total clock cycle (MULCL) = %u\n\n", end_cc_l - start_cc_l);
}

void mulcl_ex13(void) {
    int32_t mulcl_result_1, mulclh_result_1;
    int32_t mulcl_result_2, mulclh_result_2;
    int32_t mulcl_result_3, mulclh_result_3;
    int32_t operandA_1 = 0x12345678;
    int32_t operandB_1 = 0xABCDEF12;
    int32_t operandA_2 = 0x00112233;
    int32_t operandB_2 = 0x44556677;
    int32_t operandA_3 = 0xFFFFFFFF;
    int32_t operandB_3 = 0xFFFFFFFF;

    asm volatile (
        "mulclh %[mulclh_result_1], %[operandA_1], %[operandB_1]\n"
        "mulcl  %[mulcl_result_1],  %[operandA_1], %[operandB_1]\n"
        "mulclh %[mulclh_result_2], %[operandA_2], %[operandB_2]\n"
        "mulcl  %[mulcl_result_2],  %[operandA_2], %[operandB_2]\n"
	"nop\n"
        "mulclh %[mulclh_result_3], %[operandA_3], %[operandB_3]\n"
        "mulcl  %[mulcl_result_3],  %[operandA_3], %[operandB_3]\n"
        : [mulclh_result_1] "=r" (mulclh_result_1), [mulcl_result_1] "=r" (mulcl_result_1), 
	  [mulclh_result_2] "=r" (mulclh_result_2), [mulcl_result_2] "=r" (mulcl_result_2),
	  [mulclh_result_3] "=r" (mulclh_result_3), [mulcl_result_3] "=r" (mulcl_result_3) // output
        : [operandA_1] "r" (operandA_1), [operandB_1] "r" (operandB_1),
          [operandA_2] "r" (operandA_2), [operandB_2] "r" (operandB_2),
          [operandA_3] "r" (operandA_3), [operandB_3] "r" (operandB_3)                     // input
    );

    printf("\n=== MULCL and MULCLH ===\n");
    // Print the loaded values for debugging purposes
    printf("\nOperandA_1: %lxh\n", (unsigned long)operandA_1);
    printf("OperandB_1: %lxh\n", (unsigned long)operandB_1);
    // Print the results
    printf("mulclh_1: actual = %lxh \t expected = bf60cfch \n", (unsigned long)mulclh_result_1);
    printf("mulcl_1 : actual = %lxh \t expected = ca086370h \n", (unsigned long)mulcl_result_1);

    printf("\nOperandA_2: %lxh\n", (unsigned long)operandA_2);
    printf("OperandB_2: %lxh\n", (unsigned long)operandB_2);
    printf("mulclh_2: actual = %lxh \t expected = 4090dh \n", (unsigned long)mulclh_result_2);
    printf("mulcl_2 : actual = %lxh \t expected = 4000d09h \n", (unsigned long)mulcl_result_2);

    printf("\nOperandA_3: %lxh\n", (unsigned long)operandA_3);
    printf("OperandB_3: %lxh\n", (unsigned long)operandB_3);
    printf("mulclh_3: actual = %lxh \t expected = 55555555h \n", (unsigned long)mulclh_result_3);
    printf("mulcl_3 : actual = %lxh \t expected = 55555555h \n", (unsigned long)mulcl_result_3);
}

void mulcl_ex14(void) {
    int32_t mulcl_result_1, mulclh_result_1;
    int32_t mulcl_result_2, mulclh_result_2;
    int32_t mulcl_result_3, mulclh_result_3;
    int32_t operandA_1 = 0x12345678;
    int32_t operandB_1 = 0xABCDEF12;
    int32_t operandA_2 = 0x00112233;
    int32_t operandB_2 = 0x44556677;
    int32_t operandA_3 = 0xFFFFFFFF;
    int32_t operandB_3 = 0xFFFFFFFF;

    unsigned int pcmr = 1; /* global enable without saturation */
    unsigned int pcer = 3; /* cycles and instr count enable */
    unsigned int start_cc_h_1, start_cc_l_1, end_cc_h_1, end_cc_l_1;
    unsigned int start_cc_h_2, start_cc_l_2, end_cc_h_2, end_cc_l_2;
    unsigned int start_cc_h_3, start_cc_l_3, end_cc_h_3, end_cc_l_3;

    // Enable cycle and instruction count
    asm volatile ("csrw 0x7e0, %0" :: "r" (pcer));

    // Enable global cycle counter
    asm volatile ("csrw 0x7e1, %0" :: "r" (pcmr));


    asm volatile (
        "csrr %0, 0x780 \n" // Clock cycle counter start for MULCLH_1
        "mulclh %[mulclh_result_1], %[operandA_1], %[operandB_1]\n"
        "csrr %1, 0x780 \n" // Clock Counter End for MULCLH_1
        "csrr %2, 0x780 \n" // Clock cycle counter start for MULCL_1
        "mulcl  %[mulcl_result_1],  %[operandA_1], %[operandB_1]\n"
        "csrr %3, 0x780 \n" // Clock Counter End for MULCL_1
        "csrr %4, 0x780 \n" // Clock cycle counter start for MULCLH_2	
        "mulclh %[mulclh_result_2], %[operandA_2], %[operandB_2]\n"
        "csrr %5, 0x780 \n" // Clock Counter End for MULCLH_2
        "csrr %6, 0x780 \n" // Clock cycle counter start for MULCL_2	
        "mulcl  %[mulcl_result_2],  %[operandA_2], %[operandB_2]\n"
        "csrr %7, 0x780 \n" // Clock Counter End for MULCL_2
        "csrr %8, 0x780 \n" // Clock cycle counter start for MULCLH_3	
        "mulclh %[mulclh_result_3], %[operandA_3], %[operandB_3]\n"
        "csrr %9, 0x780 \n" // Clock Counter End for MULCLH_3
        "csrr %10, 0x780 \n" // Clock cycle counter start for MULCL_3	
        "mulcl  %[mulcl_result_3],  %[operandA_3], %[operandB_3]\n"
        "csrr %11, 0x780 \n" // Clock Counter End for MULCL_3
        : "=r" (start_cc_h_1), "=r" (end_cc_h_1), "=r" (start_cc_l_1), "=r" (end_cc_l_1), 
          "=r" (start_cc_h_2), "=r" (end_cc_h_2), "=r" (start_cc_l_2), "=r" (end_cc_l_2), 
          "=r" (start_cc_h_3), "=r" (end_cc_h_3), "=r" (start_cc_l_3), "=r" (end_cc_l_3), 
          [mulclh_result_1] "=r" (mulclh_result_1), [mulcl_result_1] "=r" (mulcl_result_1), 
	  [mulclh_result_2] "=r" (mulclh_result_2), [mulcl_result_2] "=r" (mulcl_result_2),
	  [mulclh_result_3] "=r" (mulclh_result_3), [mulcl_result_3] "=r" (mulcl_result_3) // output
        : [operandA_1] "r" (operandA_1), [operandB_1] "r" (operandB_1),
          [operandA_2] "r" (operandA_2), [operandB_2] "r" (operandB_2),
          [operandA_3] "r" (operandA_3), [operandB_3] "r" (operandB_3)                     // input
    );

    printf("\n=== MULCL and MULCLH ===\n");
    // Print the loaded values for debugging purposes
    printf("\nOperandA_1: %lxh\n", (unsigned long)operandA_1);
    printf("OperandB_1: %lxh\n", (unsigned long)operandB_1);
    // Print the results
    printf("mulclh_1: actual = %lxh \t expected = bf60cfch \n", (unsigned long)mulclh_result_1);
    printf(" start clock cycle (MULCLH_1) = %u\n", start_cc_h_1);
    printf(" end clock cycle (MULCLH_1) = %u\n", end_cc_h_1);
    printf(" total clock cycle (MULCLH_1) = %u\n", end_cc_h_1 - start_cc_h_1);
    printf("mulcl_1 : actual = %lxh \t expected = ca086370h \n", (unsigned long)mulcl_result_1);
    printf(" start clock cycle (MULCL_1) = %u\n", start_cc_l_1);
    printf(" end clock cycle (MULCL_1) = %u\n", end_cc_l_1);
    printf(" total clock cycle (MULCL_1) = %u\n\n", end_cc_l_1 - start_cc_l_1);

    printf("\nOperandA_2: %lxh\n", (unsigned long)operandA_2);
    printf("OperandB_2: %lxh\n", (unsigned long)operandB_2);
    printf("mulclh_2: actual = %lxh \t expected = 4090dh \n", (unsigned long)mulclh_result_2);
    printf(" start clock cycle (MULCLH_2) = %u\n", start_cc_h_2);
    printf(" end clock cycle (MULCLH_2) = %u\n", end_cc_h_2);
    printf(" total clock cycle (MULCLH_2) = %u\n", end_cc_h_2 - start_cc_h_2);
    printf("mulcl_2 : actual = %lxh \t expected = 4000d09h \n", (unsigned long)mulcl_result_2);
    printf(" start clock cycle (MULCL_2) = %u\n", start_cc_l_2);
    printf(" end clock cycle (MULCL_2) = %u\n", end_cc_l_2);
    printf(" total clock cycle (MULCL_2) = %u\n\n", end_cc_l_2 - start_cc_l_2);

    printf("\nOperandA_3: %lxh\n", (unsigned long)operandA_3);
    printf("OperandB_3: %lxh\n", (unsigned long)operandB_3);
    printf("mulclh_3: actual = %lxh \t expected = 55555555h \n", (unsigned long)mulclh_result_3);
    printf(" start clock cycle (MULCLH_3) = %u\n", start_cc_h_3);
    printf(" end clock cycle (MULCLH_3) = %u\n", end_cc_h_3);
    printf(" total clock cycle (MULCLH_3) = %u\n", end_cc_h_3 - start_cc_h_3);
    printf("mulcl_3 : actual = %lxh \t expected = 55555555h \n", (unsigned long)mulcl_result_3);
    printf(" start clock cycle (MULCL_3) = %u\n", start_cc_l_3);
    printf(" end clock cycle (MULCL_3) = %u\n", end_cc_l_3);
    printf(" total clock cycle (MULCL_3) = %u\n\n", end_cc_l_3 - start_cc_l_3);
}


void mulcl_ex15(void) {
    int32_t mulcl_result, mulclh_result;
    int32_t operand1_print,operand2_print;

    asm volatile (
        ".text\n"
        "    lui %[reg_operand1], 0x12345\n"                // Load upper immediate for operand1
        "    ori %[reg_operand1], %[reg_operand1], 0x055\n" // Load lower immediate for operand1
        "    mv t0, %[reg_operand1]\n"                      // Move 32 bits into register
        "    mulclh %[mulclh_result], t0, t0\n"
        "    mulcl %[mulcl_result], t0, t0\n"
        : [mulclh_result] "=r" (mulclh_result), [mulcl_result] "=r" (mulcl_result),
          [reg_operand1] "=&r" (operand1_print), [reg_operand2] "=&r" (operand2_print)  // Input operands
    );

    printf("\n=== MULCL and MULCLH ===\n");

    // Print the loaded values for debugging purposes
    printf("Operand1: %lxh\n", (unsigned long)operand1_print);
    printf("Operand2: %lxh\n", (unsigned long)operand2_print);
    // Print the results
    printf("mulclh: actual = %lxh \t expected = 1040510h \n", (unsigned long)mulclh_result);
    printf("mulcl : actual = %lxh \t expected = 11001111h \n", (unsigned long)mulcl_result);
}


void mulcl_ex16(void) {
    int32_t mulcl_result, mulclh_result;
    int32_t operand1_print,operand2_print;
    unsigned int start_cc_h, start_cc_l, end_cc_h, end_cc_l;

    unsigned int pcmr = 1; /* global enable without saturation */
    unsigned int pcer = 3; /* cycles and instr count enable */

    // Enable cycle and instruction count
    asm volatile ("csrw 0x7e0, %0" :: "r" (pcer));

    // Enable global cycle counter
    asm volatile ("csrw 0x7e1, %0" :: "r" (pcmr));


    asm volatile (
        ".text\n"
        "    lui %[reg_operand1], 0x12345\n"                // Load upper immediate for operand1
        "    ori %[reg_operand1], %[reg_operand1], 0x055\n" // Load lower immediate for operand1
        "    mv t0, %[reg_operand1]\n"                      // Move 32 bits into register
        "    csrr %0, 0x780 \n" // Clock cycle counter start for MULCLH
        "    mulclh %[mulclh_result], t0, t0\n"
        "    csrr %1, 0x780 \n" // Clock Counter End for MULCLH
        "    csrr %2, 0x780 \n" // Clock cycle counter start for MULCL
        "    mulcl %[mulcl_result], t0, t0\n"
        "    csrr %3, 0x780 \n" // Clock Counter End for MULCL
        : "=r" (start_cc_h), "=r" (end_cc_h), "=r" (start_cc_l), "=r" (end_cc_l),  
	  [mulclh_result] "=r" (mulclh_result), [mulcl_result] "=r" (mulcl_result),
          [reg_operand1] "=&r" (operand1_print), [reg_operand2] "=&r" (operand2_print)  // Input operands
    );

    // Disable cycle and instruction count
    asm volatile ("csrw 0x7e0, %0" :: "r" (0));

    printf("\n=== MULCL and MULCLH ===\n");

    // Print the loaded values for debugging purposes
    printf("Operand1: %lxh\n", (unsigned long)operand1_print);
    printf("Operand2: %lxh\n", (unsigned long)operand2_print);

    // Print the results
    printf("mulclh: actual = %lxh \t expected = 1040510h \n", (unsigned long)mulclh_result);
    printf(" start clock cycle (MULCLH) = %u\n", start_cc_h);
    printf(" end clock cycle (MULCLH) = %u\n", end_cc_h);
    printf(" total clock cycle (MULCLH) = %u\n", end_cc_h - start_cc_h);

    printf("mulcl : actual = %lxh \t expected = 11001111h \n", (unsigned long)mulcl_result);
    printf(" start clock cycle (MULCL) = %u\n", start_cc_l);
    printf(" end clock cycle (MULCL) = %u\n", end_cc_l);
    printf(" total clock cycle (MULCL) = %u\n\n", end_cc_l - start_cc_l);
}



void mulclimm_ex1(void) {
    int32_t mulclimm_result, mulclhimm_result;
    int32_t operand1_print;

    asm volatile (
        ".text\n"
        "    lui %[reg_operand1], 0xA2CCF\n"                // Load upper immediate for operand1
        //"    lui %[reg_operand1], 0x000F1\n"                // Load upper immediate for operand1
        "    ori %[reg_operand1], %[reg_operand1], 0x053\n" // Load lower immediate for operand1
	//"    nop\n"
        "    mulclhi %[mulclhimm_result], %[reg_operand1], %[imm_value]\n"
        "    mulcli %[mulclimm_result], %[reg_operand1], %[imm_value]\n"
        : [mulclhimm_result] "=r" (mulclhimm_result), [mulclimm_result] "=r" (mulclimm_result),
          [reg_operand1] "=&r" (operand1_print)  // Use early-clobber to prevent input/output conflict
	: [imm_value] "i" (0x87)  // Input operands
    );

    printf("\n=== MULCLI and MULCLHI (Immediate) ===\n");

    // Print the loaded values for debugging purposes
    printf("Operand1: %lxh\n", (unsigned long)operand1_print);
    printf("Irreducible polynomial: 87h\n");
    // Print the results
    printf("mulclhi: actual = %lxh \t expected = 52h \n", (unsigned long)mulclhimm_result);
    printf("mulcli : actual = %lxh \t expected = a1ef839h \n", (unsigned long)mulclimm_result);
}

void mulclimm_ex2(void) {
    int32_t mulclimm_result, mulclhimm_result;
    int32_t operand1_print;
    unsigned int start_cc_h, start_cc_l, end_cc_h, end_cc_l;

    unsigned int pcmr = 1; /* global enable without saturation */
    unsigned int pcer = 3; /* cycles and instr count enable */

    // Enable cycle and instruction count
    asm volatile ("csrw 0x7e0, %0" :: "r" (pcer));

    // Enable global cycle counter
    asm volatile ("csrw 0x7e1, %0" :: "r" (pcmr));

    // main program of carry-less multiplication immediate
    asm volatile (
        ".text\n"
        "    lui %[reg_operand1], 0xA2CCF\n"                // Load upper immediate for operand1
        "    ori %[reg_operand1], %[reg_operand1], 0x053\n" // Load lower immediate for operand1
        "    csrr %0, 0x780 \n" // Clock cycle counter start for MULCLHI
        "    mulclhi %[mulclhimm_result], %[reg_operand1], 0x87\n"
        "    csrr %1, 0x780 \n" // Clock Counter End for MULCLH
        "    csrr %2, 0x780 \n" // Clock cycle counter start for MULCL
        "    mulcli %[mulclimm_result], %[reg_operand1], 0x87\n"
        "    csrr %3, 0x780 \n" // Clock Counter End for MULCL
        : "=r" (start_cc_h), "=r" (end_cc_h), "=r" (start_cc_l), "=r" (end_cc_l), [mulclhimm_result] "=r" (mulclhimm_result), [mulclimm_result] "=r" (mulclimm_result),
         [reg_operand1] "=&r" (operand1_print)  // Input operands
    );

    // Disable cycle and instruction count
    asm volatile ("csrw 0x7e0, %0" :: "r" (0));

    printf("\n=== MULCLI and MULCLHI (Immediate with clock cycle counts) ===\n");

    // Print the loaded values for debugging purposes
    printf("Operand1: %lxh\n", (unsigned long)operand1_print);
    printf("Irreducible polynomial: 87h\n");

    // Print the results
    printf("mulclhi: actual = %lxh \t expected = 52h \n", (unsigned long)mulclhimm_result);
    printf(" start clock cycle (MULCLHI) = %u\n", start_cc_h);
    printf(" end clock cycle (MULCLHI) = %u\n", end_cc_h);
    printf(" total clock cycle (MULCLHI) = %u\n", end_cc_h - start_cc_h);

    printf("mulcli : actual = %lxh \t expected = a1ef839h \n", (unsigned long)mulclimm_result);
    printf(" start clock cycle (MULCLI) = %u\n", start_cc_l);
    printf(" end clock cycle (MULCLI) = %u\n", end_cc_l);
    printf(" total clock cycle (MULCLI) = %u\n\n", end_cc_l - start_cc_l);
}

void mulclimm_ex3(void) {
    int32_t mulclimm_result, mulclhimm_result;
    int32_t operand1_print;

    asm volatile (
        ".text\n"
        "    lui %[reg_operand1], 0x00000\n"                // Load upper immediate for operand1
        "    ori %[reg_operand1], %[reg_operand1], 0x000\n" // Load lower immediate for operand1
        "    mulclhi %[mulclhimm_result], %[reg_operand1], %[imm_value]\n"
        "    mulcli %[mulclimm_result], %[reg_operand1], %[imm_value]\n"
        : [mulclhimm_result] "=r" (mulclhimm_result), [mulclimm_result] "=r" (mulclimm_result),
          [reg_operand1] "=&r" (operand1_print)  // Use early-clobber to prevent input/output conflict
	: [imm_value] "i" (0x87)  // Input operands
    );

    printf("\n=== MULCLI and MULCLHI (Immediate) ===\n");

    // Print the loaded values for debugging purposes
    printf("Operand1: %lxh\n", (unsigned long)operand1_print);
    printf("Irreducible polynomial: 87h\n");
    // Print the results
    printf("mulclhi: actual = %lxh \t expected = 0h \n", (unsigned long)mulclhimm_result);
    printf("mulcli : actual = %lxh \t expected = 0h \n", (unsigned long)mulclimm_result);
}

void mulclimm_ex4(void) {
    int32_t mulclimm_result, mulclhimm_result;
    int32_t operand1_print;
    unsigned int start_cc_h, start_cc_l, end_cc_h, end_cc_l;

    unsigned int pcmr = 1; /* global enable without saturation */
    unsigned int pcer = 3; /* cycles and instr count enable */

    // Enable cycle and instruction count
    asm volatile ("csrw 0x7e0, %0" :: "r" (pcer));

    // Enable global cycle counter
    asm volatile ("csrw 0x7e1, %0" :: "r" (pcmr));

    // main program of carry-less multiplication immediate
    asm volatile (
        ".text\n"
        "    lui %[reg_operand1], 0x00000\n"                // Load upper immediate for operand1
        "    ori %[reg_operand1], %[reg_operand1], 0x000\n" // Load lower immediate for operand1
        "    csrr %0, 0x780 \n" // Clock cycle counter start for MULCLHI
        "    mulclhi %[mulclhimm_result], %[reg_operand1], 0x87\n"
        "    csrr %1, 0x780 \n" // Clock Counter End for MULCLH
        "    csrr %2, 0x780 \n" // Clock cycle counter start for MULCL
        "    mulcli %[mulclimm_result], %[reg_operand1], 0x87\n"
        "    csrr %3, 0x780 \n" // Clock Counter End for MULCL
        : "=r" (start_cc_h), "=r" (end_cc_h), "=r" (start_cc_l), "=r" (end_cc_l), [mulclhimm_result] "=r" (mulclhimm_result), [mulclimm_result] "=r" (mulclimm_result),
         [reg_operand1] "=&r" (operand1_print)  // Input operands
    );

    // Disable cycle and instruction count
    asm volatile ("csrw 0x7e0, %0" :: "r" (0));

    printf("\n=== MULCLI and MULCLHI (Immediate with clock cycle counts) ===\n");

    // Print the loaded values for debugging purposes
    printf("Operand1: %lxh\n", (unsigned long)operand1_print);
    printf("Irreducible polynomial: 87h\n");

    // Print the results
    printf("mulclhi: actual = %lxh \t expected = 0h \n", (unsigned long)mulclhimm_result);
    printf(" start clock cycle (MULCLHI) = %u\n", start_cc_h);
    printf(" end clock cycle (MULCLHI) = %u\n", end_cc_h);
    printf(" total clock cycle (MULCLHI) = %u\n", end_cc_h - start_cc_h);

    printf("mulcli : actual = %lxh \t expected = 0h \n", (unsigned long)mulclimm_result);
    printf(" start clock cycle (MULCLI) = %u\n", start_cc_l);
    printf(" end clock cycle (MULCLI) = %u\n", end_cc_l);
    printf(" total clock cycle (MULCLI) = %u\n\n", end_cc_l - start_cc_l);
}



void mulclimm_ex5(void) {
    int32_t mulclimm_result, mulclhimm_result;
    int32_t operand1 = 0xFFFFFFFF;
    //int32_t operand1 = 0x00000000;

    asm volatile (
        "    mulclhi %[mulclhimm_result], %[operand1], 0x87\n"
        "    mulcli %[mulclimm_result], %[operand1], 0x87\n"
        : [mulclhimm_result] "=r" (mulclhimm_result), [mulclimm_result] "=r" (mulclimm_result)
        :  [operand1] "r" (operand1)
    );

    printf("\n=== MULCLI and MULCLHI (Immediate) ===\n");

    // Print the loaded values for debugging purposes
    printf("Operand1: %lxh\n", (unsigned long)operand1);
    printf("Irreducible polynomial: 87h\n");
    // Print the results
    printf("mulclhi: actual = %lxh \t expected = 7dh \n", (unsigned long)mulclhimm_result);
    printf("mulcli : actual = %lxh \t expected = 7dh \n", (unsigned long)mulclimm_result);
}




void mulclimm_ex6(void) {
    int32_t mulclimm_result, mulclhimm_result;
    int32_t operand1_print = 0xFFFFFFFF;
    unsigned int start_cc_h, start_cc_l, end_cc_h, end_cc_l;

    unsigned int pcmr = 1; /* global enable without saturation */
    unsigned int pcer = 3; /* cycles and instr count enable */

    // Enable cycle and instruction count
    asm volatile ("csrw 0x7e0, %0" :: "r" (pcer));

    // Enable global cycle counter
    asm volatile ("csrw 0x7e1, %0" :: "r" (pcmr));

    // main program of carry-less multiplication immediate
    asm volatile (
        "    csrr %0, 0x780 \n" // Clock cycle counter start for MULCLHI
        "    mulclhi %[mulclhimm_result], %[reg_operand1], 0x87\n"
        "    csrr %1, 0x780 \n" // Clock Counter End for MULCLH
        "    csrr %2, 0x780 \n" // Clock cycle counter start for MULCL
        "    mulcli %[mulclimm_result], %[reg_operand1], 0x87\n"
        "    csrr %3, 0x780 \n" // Clock Counter End for MULCL
        : "=r" (start_cc_h), "=r" (end_cc_h), "=r" (start_cc_l), "=r" (end_cc_l), [mulclhimm_result] "=r" (mulclhimm_result), [mulclimm_result] "=r" (mulclimm_result)
        : [reg_operand1] "r" (operand1_print)  // Input operands
    );

    // Disable cycle and instruction count
    asm volatile ("csrw 0x7e0, %0" :: "r" (0));

    printf("\n=== MULCLI and MULCLHI (Immediate with clock cycle counts) ===\n");

    // Print the loaded values for debugging purposes
    printf("Operand1: %lxh\n", (unsigned long)operand1_print);
    printf("Irreducible polynomial: 87h\n");

    // Print the results
    printf("mulclhi: actual = %lxh \t expected = 7dh \n", (unsigned long)mulclhimm_result);
    printf(" start clock cycle (MULCLHI) = %u\n", start_cc_h);
    printf(" end clock cycle (MULCLHI) = %u\n", end_cc_h);
    printf(" total clock cycle (MULCLHI) = %u\n", end_cc_h - start_cc_h);

    printf("mulcli : actual = %lxh \t expected = 7dh \n", (unsigned long)mulclimm_result);
    printf(" start clock cycle (MULCLI) = %u\n", start_cc_l);
    printf(" end clock cycle (MULCLI) = %u\n", end_cc_l);
    printf(" total clock cycle (MULCLI) = %u\n\n", end_cc_l - start_cc_l);
}

void mulclimm_ex7(void) {
    int32_t mulclimm_result_1, mulclhimm_result_1;
    int32_t mulclimm_result_2, mulclhimm_result_2;
    int32_t mulclimm_result_3, mulclhimm_result_3;
    int32_t operandA_1 = 0x12345678;
    int32_t operandA_2 = 0x00112233;
    int32_t operandA_3 = 0xFFFFFFFF;

    asm volatile (
        "mulclhi %[mulclhimm_result_1], %[operandA_1], 0x87\n"
        "mulcli  %[mulclimm_result_1],  %[operandA_1], 0x87\n"
        "mulclhi %[mulclhimm_result_2], %[operandA_2], 0x87\n"
        "mulcli  %[mulclimm_result_2],  %[operandA_2], 0x87\n"
        "mulclhi %[mulclhimm_result_3], %[operandA_3], 0x87\n"
        "mulcli  %[mulclimm_result_3],  %[operandA_3], 0x87\n"
        : [mulclhimm_result_1] "=r" (mulclhimm_result_1), [mulclimm_result_1] "=r" (mulclimm_result_1), 
	  [mulclhimm_result_2] "=r" (mulclhimm_result_2), [mulclimm_result_2] "=r" (mulclimm_result_2),
	  [mulclhimm_result_3] "=r" (mulclhimm_result_3), [mulclimm_result_3] "=r" (mulclimm_result_3) // output
        : [operandA_1] "r" (operandA_1),
          [operandA_2] "r" (operandA_2),
          [operandA_3] "r" (operandA_3)                     // input
    );

    printf("\n=== MULCLI and MULCLHI ===\n");
    // Print the loaded values for debugging purposes
    printf("\nOperandA_1: %lxh\n", (unsigned long)operandA_1);
    // Print the results
    printf("mulclhi_1: actual = %lxh \t expected = 9h \n", (unsigned long)mulclhimm_result_1);
    printf("mulcli_1 : actual = %lxh \t expected = 64a69f68h \n", (unsigned long)mulclimm_result_1);

    printf("\nOperandA_2: %lxh\n", (unsigned long)operandA_2);
    printf("mulclhi_2: actual = %lxh \t expected = 0h \n", (unsigned long)mulclhimm_result_2);
    printf("mulcli_2 : actual = %lxh \t expected = 8e6f719h \n", (unsigned long)mulclimm_result_2);

    printf("\nOperandA_3: %lxh\n", (unsigned long)operandA_3);
    printf("mulclhi_3: actual = %lxh \t expected = 7dh \n", (unsigned long)mulclhimm_result_3);
    printf("mulcli_3 : actual = %lxh \t expected = 7dh \n", (unsigned long)mulclimm_result_3);
}
     

void mulclimm_ex8(void) {
    int32_t mulclimm_result_1, mulclhimm_result_1;
    int32_t mulclimm_result_2, mulclhimm_result_2;
    int32_t mulclimm_result_3, mulclhimm_result_3;
    int32_t operandA_1 = 0x12345678;
    int32_t operandA_2 = 0x00112233;
    int32_t operandA_3 = 0xFFFFFFFF;

    unsigned int pcmr = 1; /* global enable without saturation */
    unsigned int pcer = 3; /* cycles and instr count enable */
    unsigned int start_cc_h_1, start_cc_l_1, end_cc_h_1, end_cc_l_1;
    unsigned int start_cc_h_2, start_cc_l_2, end_cc_h_2, end_cc_l_2;
    unsigned int start_cc_h_3, start_cc_l_3, end_cc_h_3, end_cc_l_3;

    // Enable cycle and instruction count
    asm volatile ("csrw 0x7e0, %0" :: "r" (pcer));

    // Enable global cycle counter
    asm volatile ("csrw 0x7e1, %0" :: "r" (pcmr));

    asm volatile (
        "csrr %0, 0x780 \n" // Clock cycle counter start for MULCLH_1
        "mulclhi %[mulclhimm_result_1], %[operandA_1], 0x87\n"
        "csrr %1, 0x780 \n" // Clock Counter End for MULCLH_1
        "csrr %2, 0x780 \n" // Clock cycle counter start for MULCL_1
        "mulcli  %[mulclimm_result_1],  %[operandA_1], 0x87\n"
        "csrr %3, 0x780 \n" // Clock Counter End for MULCL_1
        "csrr %4, 0x780 \n" // Clock cycle counter start for MULCLH_2	
        "mulclhi %[mulclhimm_result_2], %[operandA_2], 0x87\n"
        "csrr %5, 0x780 \n" // Clock Counter End for MULCLH_2
        "csrr %6, 0x780 \n" // Clock cycle counter start for MULCL_2	
        "mulcli  %[mulclimm_result_2],  %[operandA_2], 0x87\n"
        "csrr %7, 0x780 \n" // Clock Counter End for MULCL_2
        "csrr %8, 0x780 \n" // Clock cycle counter start for MULCLH_3	
        "mulclhi %[mulclhimm_result_3], %[operandA_3], 0x87\n"
        "csrr %9, 0x780 \n" // Clock Counter End for MULCLH_3
        "csrr %10, 0x780 \n" // Clock cycle counter start for MULCL_3	
        "mulcli  %[mulclimm_result_3],  %[operandA_3], 0x87\n"
        "csrr %11, 0x780 \n" // Clock Counter End for MULCL_3
        : "=r" (start_cc_h_1), "=r" (end_cc_h_1), "=r" (start_cc_l_1), "=r" (end_cc_l_1), 
          "=r" (start_cc_h_2), "=r" (end_cc_h_2), "=r" (start_cc_l_2), "=r" (end_cc_l_2), 
          "=r" (start_cc_h_3), "=r" (end_cc_h_3), "=r" (start_cc_l_3), "=r" (end_cc_l_3), 
          [mulclhimm_result_1] "=r" (mulclhimm_result_1), [mulclimm_result_1] "=r" (mulclimm_result_1), 
	  [mulclhimm_result_2] "=r" (mulclhimm_result_2), [mulclimm_result_2] "=r" (mulclimm_result_2),
	  [mulclhimm_result_3] "=r" (mulclhimm_result_3), [mulclimm_result_3] "=r" (mulclimm_result_3) // output
        : [operandA_1] "r" (operandA_1),
          [operandA_2] "r" (operandA_2),
          [operandA_3] "r" (operandA_3)                     // input
    );

    printf("\n=== MULCLI and MULCLHI ===\n");
    // Print the loaded values for debugging purposes
    printf("\nOperandA_1: %lxh\n", (unsigned long)operandA_1);
    // Print the results
    printf("mulclhi_1: actual = %lxh \t expected = 9h \n", (unsigned long)mulclhimm_result_1);
    printf(" start clock cycle (MULCLH_1) = %u\n", start_cc_h_1);
    printf(" end clock cycle (MULCLH_1) = %u\n", end_cc_h_1);
    printf(" total clock cycle (MULCLH_1) = %u\n", end_cc_h_1 - start_cc_h_1);
    printf("mulcli_1 : actual = %lxh \t expected = 64a69f68h \n", (unsigned long)mulclimm_result_1);
    printf(" start clock cycle (MULCL_1) = %u\n", start_cc_l_1);
    printf(" end clock cycle (MULCL_1) = %u\n", end_cc_l_1);
    printf(" total clock cycle (MULCL_1) = %u\n\n", end_cc_l_1 - start_cc_l_1);

    printf("\nOperandA_2: %lxh\n", (unsigned long)operandA_2);
    printf("mulclhi_2: actual = %lxh \t expected = 0h \n", (unsigned long)mulclhimm_result_2);
    printf(" start clock cycle (MULCLH_2) = %u\n", start_cc_h_2);
    printf(" end clock cycle (MULCLH_2) = %u\n", end_cc_h_2);
    printf(" total clock cycle (MULCLH_2) = %u\n", end_cc_h_2 - start_cc_h_2);
    printf("mulcli_2 : actual = %lxh \t expected = 8e6f719h \n", (unsigned long)mulclimm_result_2);
    printf(" start clock cycle (MULCL_2) = %u\n", start_cc_l_2);
    printf(" end clock cycle (MULCL_2) = %u\n", end_cc_l_2);
    printf(" total clock cycle (MULCL_2) = %u\n\n", end_cc_l_2 - start_cc_l_2);

    printf("\nOperandA_3: %lxh\n", (unsigned long)operandA_3);
    printf("mulclhi_3: actual = %lxh \t expected = 7dh \n", (unsigned long)mulclhimm_result_3);
    printf(" start clock cycle (MULCLH_3) = %u\n", start_cc_h_3);
    printf(" end clock cycle (MULCLH_3) = %u\n", end_cc_h_3);
    printf(" total clock cycle (MULCLH_3) = %u\n", end_cc_h_3 - start_cc_h_3);
    printf("mulcli_3 : actual = %lxh \t expected = 7dh \n", (unsigned long)mulclimm_result_3);
    printf(" start clock cycle (MULCL_3) = %u\n", start_cc_l_3);
    printf(" end clock cycle (MULCL_3) = %u\n", end_cc_l_3);
    printf(" total clock cycle (MULCL_3) = %u\n\n", end_cc_l_3 - start_cc_l_3);
}


void mulclimm_ex9(void) {
    int32_t mulclimm_result, mulclhimm_result;
    int32_t operand1_print;

    asm volatile (
        "    lui %[reg_operand1], 0x12345\n"                // Load upper immediate for operand1
        "    ori %[reg_operand1], %[reg_operand1], 0x055\n" // Load lower immediate for operand1
        "    mv t0, %[reg_operand1]\n"                      // Move 32 bits into register
        "    mulclhi %[mulclhimm_result], t0, 0x87\n"
        "    mulcli %[mulclimm_result], t0, 0x87\n"
        : [mulclhimm_result] "=r" (mulclhimm_result), [mulclimm_result] "=r" (mulclimm_result),
          [reg_operand1] "=&r" (operand1_print)  // Input operands
    );

    printf("\n=== MULCLI and MULCLHI ===\n");

    // Print the loaded values for debugging purposes
    printf("Operand1: %lxh\n", (unsigned long)operand1_print);
    // Print the results
    printf("mulclhi: actual = %lxh \t expected = 9h \n", (unsigned long)mulclhimm_result);
    printf("mulcli : actual = %lxh \t expected = 64a59b2bh \n", (unsigned long)mulclimm_result);
}


void mulclimm_ex10(void) {
    int32_t mulclimm_result, mulclhimm_result;
    int32_t operand1_print;
    unsigned int start_cc_h, start_cc_l, end_cc_h, end_cc_l;

    unsigned int pcmr = 1; /* global enable without saturation */
    unsigned int pcer = 3; /* cycles and instr count enable */

    // Enable cycle and instruction count
    asm volatile ("csrw 0x7e0, %0" :: "r" (pcer));

    // Enable global cycle counter
    asm volatile ("csrw 0x7e1, %0" :: "r" (pcmr));


    asm volatile (
        ".text\n"
        "    lui %[reg_operand1], 0x12345\n"                // Load upper immediate for operand1
        "    ori %[reg_operand1], %[reg_operand1], 0x055\n" // Load lower immediate for operand1
        "    mv t0, %[reg_operand1]\n"                      // Move 32 bits into register
        "    csrr %0, 0x780 \n" // Clock cycle counter start for MULCLH
        "    mulclhi %[mulclhimm_result], t0, 0x87\n"
        "    csrr %1, 0x780 \n" // Clock Counter End for MULCLH
        "    csrr %2, 0x780 \n" // Clock cycle counter start for MULCL
        "    mulcli %[mulclimm_result], t0, 0x87\n"
        "    csrr %3, 0x780 \n" // Clock Counter End for MULCL
        : "=r" (start_cc_h), "=r" (end_cc_h), "=r" (start_cc_l), "=r" (end_cc_l),  
	  [mulclhimm_result] "=r" (mulclhimm_result), [mulclimm_result] "=r" (mulclimm_result),
          [reg_operand1] "=&r" (operand1_print)  // Input operands
    );

    // Disable cycle and instruction count
    asm volatile ("csrw 0x7e0, %0" :: "r" (0));

    printf("\n=== MULCLI and MULCLHI ===\n");

    // Print the loaded values for debugging purposes
    printf("Operand1: %lxh\n", (unsigned long)operand1_print);

    // Print the results
    printf("mulclhi: actual = %lxh \t expected = 9h \n", (unsigned long)mulclhimm_result);
    printf(" start clock cycle (MULCLH) = %u\n", start_cc_h);
    printf(" end clock cycle (MULCLH) = %u\n", end_cc_h);
    printf(" total clock cycle (MULCLH) = %u\n", end_cc_h - start_cc_h);

    printf("mulcli : actual = %lxh \t expected = 64a59b2bh \n", (unsigned long)mulclimm_result);
    printf(" start clock cycle (MULCL) = %u\n", start_cc_l);
    printf(" end clock cycle (MULCL) = %u\n", end_cc_l);
    printf(" total clock cycle (MULCL) = %u\n\n", end_cc_l - start_cc_l);
}



void nop(void) {
    asm volatile (
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
       "nop;"
    );
}


void karatsuba1(void) {
    int32_t mulcl_resultA, mulclh_resultA;
    int32_t mulcl_resultB, mulclh_resultB;
    int32_t operandA1_print,operandA2_print;
    int32_t operandB1_print,operandB2_print;

    asm volatile (
        ".text\n"

        "    lui %[reg_operandA1], 0x3E2D0\n"                // Load upper immediate for operand1
        "    ori %[reg_operandA1], %[reg_operandA1], 0x1E0\n" // Load lower immediate for operand1
        "    lui %[reg_operandA2], 0x7321E\n"                // Load upper immediate for operand2
        "    ori %[reg_operandA2], %[reg_operandA2], 0x0B0\n" // Load lower immediate for operand2

        "    lui %[reg_operandB1], 0x4A0B1\n"                // Load upper immediate for operand1
        "    ori %[reg_operandB1], %[reg_operandB1], 0x011\n" // Load lower immediate for operand1
        "    lui %[reg_operandB2], 0x12345\n"                // Load upper immediate for operand2
        "    ori %[reg_operandB2], %[reg_operandB2], 0x123\n" // Load lower immediate for operand2

        "    mulclh %[mulclh_resultA], %[reg_operandA1], %[reg_operandA2]\n"
        "    mulcl  %[mulcl_resultA],  %[reg_operandA1], %[reg_operandA2]\n"

        "    mulclh %[mulclh_resultB], %[reg_operandB1], %[reg_operandB2]\n"
        "    mulcl  %[mulcl_resultB],  %[reg_operandB1], %[reg_operandB2]\n"

        : [mulclh_resultA] "=r" (mulclh_resultA), [mulcl_resultA] "=r" (mulcl_resultA),
          [mulclh_resultB] "=r" (mulclh_resultB), [mulcl_resultB] "=r" (mulcl_resultB),
          [reg_operandA1] "=&r" (operandA1_print), [reg_operandA2] "=&r" (operandA2_print),  // Input operands
          [reg_operandB1] "=&r" (operandB1_print), [reg_operandB2] "=&r" (operandB2_print)  // Input operands
    );

    printf("\n=== MULCL and MULCLH example 2 ===\n");

    // Print the loaded values for debugging purposes
    printf("OperandA1: %lxh\n", (unsigned long)operandA1_print);
    printf("OperandA2: %lxh\n", (unsigned long)operandA2_print);
    printf("OperandB1: %lxh\n", (unsigned long)operandB1_print);
    printf("OperandB2: %lxh\n", (unsigned long)operandB2_print);
    // Print the results
    printf("mulclh: actual = %lxh \t expected = 2dh \n", (unsigned long)mulclh_resultA);
    printf("mulcl : actual = %lxh \t expected = e8cb55b5h \n", (unsigned long)mulcl_resultA);
    printf("mulclh: actual = %lxh \t expected = 2dh \n", (unsigned long)mulclh_resultB);
    printf("mulcl : actual = %lxh \t expected = e8cb55b5h \n", (unsigned long)mulcl_resultB);
}



