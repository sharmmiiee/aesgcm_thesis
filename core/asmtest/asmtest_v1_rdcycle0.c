#include <stdint.h>
#include <stdio.h>
#include "asmtest.h"

//void asmtest(void) {
//        int32_t a, b;
//	asm volatile (
//	   "li t1, 5;"
//	   "li t2, 2;"
//	   "add %[add_result], t1, t2;"
//	   "mul %[mul_result], t1, t2;"
//	   :[add_result] "=r" (a), [mul_result] "=r" (b)
//	);
//	printf("add = %ld \n",a);
//	printf("mul = %ld \n",b);
//}
//
//int main(void) {
//	asmtest();
//	return 0;
//}

//void clmultest(void) {
//        int32_t a, b;
//	asm volatile (
//	   "nop;"
//	   "nop;"
//	   "nop;"
//	   "nop;"
//	   "nop;"
//	   "nop;"
//	   "nop;"
//	   "nop;"
//	   "nop;"
//	   "nop;"
//	   "nop;"
//	   "nop;"
//	   "nop;"
//	   "nop;"
//	   "nop;"
//	   "nop;"
//	   "li t1, 5;"
//	   "li t2, 2;"
//	   "clmul %[clmul_result], t1, t2;"
//	   "clmulh %[clmulh_result], t1, t2;"
//	   :[clmul_result] "=r" (a), 
//            [clmulh_result] "=r" (b)
//	);
//	printf("clmul = %ld \n",a);
//	printf("clmulh = %ld \n",b);
//}




 
 
// void mulcl_custom(void) {
//         int32_t a, b;
// 
// 	asm volatile (
// 	   "nop;"
// 	   //"li t1, 0b0101;"
// 	   //"li t2, 0b1001;"
// 	   //"li t1, 0b10100010;" // CLMUL =22764
// 	   //"li t2, 0b10010110;" // CLMUL =22764
// 	   "li t1, 0b10100010110011001111000001010011;" // CMUL = 1426067717 CMULH = 1141133392 
// 	   "li t2, 0b10100010110011001111000001010011;" // CMUL = 1426067717 CMULH = 1141133392 
// 	   "mulcl %[mulcl_result], t1, t2;"
// 	   "mulclh %[mulclh_result], t1, t2;"
//            :[mulcl_result] "=r" (a),
//             [mulclh_result] "=r" (b)
// 	);
// 
// 
// 	printf("mulcl = %ld \n",a);
// 	printf("mulclh = %ld \n",b);
// 
// }
// int main(void) {
// 	//asmtest();
// 
// 	mulcl_custom();
//
// 	return 0;
// }





//#include <inttypes.h>

 //uint64_t read_cycle(void) {
 //    uint64_t cycle;
 //    asm volatile ("csrr %0, mcycle" : "=r"(cycle));
 //    //asm volatile ("rdcycle %0" : "=r"(cycle));
 //    return cycle;
 //}
 //
 //
 //void mulcl_custom(void) {
 //        int32_t a, b;
 //	// Start counting clock cycles
 //        uint64_t start_cycle = read_cycle();
 //
 //	asm volatile (
 //	   "nop;"
 //	   //"li t1, 0b0101;"
 //	   //"li t2, 0b1001;"
 //	   //"li t1, 0b10100010;" // CLMUL =22764
 //	   //"li t2, 0b10010110;" // CLMUL =22764
 //	   "li t1, 0b10100010110011001111000001010011;" // CMUL = 1426067717 CMULH = 1141133392 
 //	   "li t2, 0b10100010110011001111000001010011;" // CMUL = 1426067717 CMULH = 1141133392 
 //	   "mulcl %[mulcl_result], t1, t2;"
 //	   "mulclh %[mulclh_result], t1, t2;"
 //           :[mulcl_result] "=r" (a),
 //            [mulclh_result] "=r" (b)
 //	);
 //
 //	// End counting clock cycles
 //        uint64_t end_cycle = read_cycle();
 //
 //	printf("mulcl = %ld \n",a);
 //	printf("mulclh = %ld \n",b);
 //
 //
 //	// Calculate and print the number of clock cycles
 //        printf("Start Clock cycles: %lu\n", start_cycle);
 //        printf("Start Clock cycles: %d int\n", (int)start_cycle);
 //        printf("End Clock cycles: %lu\n", end_cycle);
 //        printf("End Clock cycles: %d int\n", (int)end_cycle);

 //        printf("Clock cycles: %ld\n", (long)(end_cycle - start_cycle));
 //        printf("Clock cycles: %d\n", ((int)end_cycle - (int)start_cycle));

 //}
 //int main(void) {
 //	//asmtest();
 //
 //	mulcl_custom();

 //   uint64_t num1 = 72594;
 //   uint64_t num2 = 72589;
 //   
 //   uint64_t result = num1 - num2;
 //   
 //   printf("%" PRIu64 " - %" PRIu64 " = %" PRIu64 "\n", num1, num2, result);
 // 
 //	return 0;
 //}


//void mulcl_custom(void) {
//    int32_t a, b;
//
//    uint64_t start_cycles, end_cycles, start_instret, end_instret;
//
//    asm volatile (
//       "rdcycle %[start_cycles];"
//       "rdinstret %[start_instret];"
//       "nop;"
//	   "li t1, 0b10100010110011001111000001010011;" // CMUL = 1426067717 CMULH = 1141133392 
//	   "li t2, 0b10100010110011001111000001010011;" // CMUL = 1426067717 CMULH = 1141133392 
// 	   "mulcl %[mulcl_result], t1, t2;"
//	   "mulclh %[mulclh_result], t1, t2;"
//
//       "rdcycle %[end_cycles];"
//       "rdinstret %[end_instret];"
//       : [mulcl_result] "=r" (a),
//         [mulclh_result] "=r" (b),
//         [start_cycles] "=r" (start_cycles),
//         [start_instret] "=r" (start_instret),
//         [end_cycles] "=r" (end_cycles),
//         [end_instret] "=r" (end_instret)
//    );
//
//    uint64_t cycle_count = end_cycles - start_cycles;
//    uint64_t instret_count = end_instret - start_instret;
//
//    printf("mulcl = %ld\n", a);
//    printf("mulclh = %ld\n", b);
//    printf("start cycles: %lu\n", start_cycles);
//    printf("end cycles: %lu\n", end_cycles);
//    printf("Clock cycles: %lu\n", cycle_count);
//    printf("Instructions retired: %lu\n", instret_count);
//    //printf("CPI: %.2f\n", cycle_count / instret_count);
//}
//
//int main(void) {
//    mulcl_custom();
//
//    return 0;
//}





//#include <inttypes.h>
//
// uint64_t read_cycle(void) {
//     uint64_t cycle;
//     asm volatile ("csrr %0, mcycle" : "=r"(cycle));
//     //asm volatile ("rdcycle %0" : "=r"(cycle));
//     return cycle;
// }
// 
// 
// void mulcl_custom(void) {
//         int32_t a, b;
//
// 	// Start counting clock cycles
//         uint64_t start_cycle = read_cycle();
// 
// 	asm volatile (
// 	   "nop;"
// 	   //"li t1, 0b0101;"
// 	   //"li t2, 0b1001;"
// 	   //"li t1, 0b10100010;" // CLMUL =22764
// 	   //"li t2, 0b10010110;" // CLMUL =22764
// 	   "li t1, 0b10100010110011001111000001010011;" // CMUL = 1426067717 CMULH = 1141133392 
// 	   "li t2, 0b10100010110011001111000001010011;" // CMUL = 1426067717 CMULH = 1141133392 
// 	   "mulcl %[mulcl_result], t1, t2;"
// 	   "mulclh %[mulclh_result], t1, t2;"
//            :[mulcl_result] "=r" (a),
//             [mulclh_result] "=r" (b)
// 	);
// 
// 	// End counting clock cycles
//        uint64_t end_cycle = read_cycle();
// 
//        // Calculate and print the cycle difference
//        uint64_t cycle_difference = end_cycle - start_cycle;
// 	
//	printf("mulcl = %ld \n",a);
// 	printf("mulclh = %ld \n",b);
//	printf("start cycle: %ld\n", start_cycle);
//        printf("end cycle: %ld\n", end_cycle);
//        printf("Cycle Difference = %ld \n", cycle_difference);
//
// }
// int main(void) {
// 	//asmtest();
// 
// 	mulcl_custom();
//
//  
// 	return 0;
// }

// // Function to enable counting the number of cycles
// void enable_cycles_counter(void) {
//     // Choose the desired event ID (Bit #0 corresponds to CYCLES)
//     uint32_t event_id = 0;
// 
//     // Set the corresponding bit in the mhpmevent3 CSR
//     asm volatile ("csrw mhpmevent3, %0" : : "r"(event_id));
// }
// 
// // Function to read the counter value for cycles
// uint64_t read_cycles_counter(void) {
//     uint64_t cycles;
//     asm volatile ("csrr %0, mhpmcounter3" : "=r"(cycles));
//     return cycles;
// }
// 
// void mulcl_custom(void) {
//          int32_t a, b;
// 
// 
//  	asm volatile (
//  	   "nop;"
//  	   "li t1, 0b10100010110011001111000001010011;" // CMUL = 1426067717 CMULH = 1141133392 
//  	   "li t2, 0b10100010110011001111000001010011;" // CMUL = 1426067717 CMULH = 1141133392 
//  	   "mulcl %[mulcl_result], t1, t2;"
//  	   "mulclh %[mulclh_result], t1, t2;"
//             :[mulcl_result] "=r" (a),
//              [mulclh_result] "=r" (b)
//  	);
//  
// 	printf("mulcl = %ld \n",a);
//  	printf("mulclh = %ld \n",b);
// 
//  }
// 
// int main(void) {
//     // Enable counting the number of cycles
//     enable_cycles_counter();
// 
//     mulcl_custom(); 
// 
//     // Read and print the number of cycles
//     uint64_t cycles = read_cycles_counter();
//     printf("Number of Cycles: %ld\n", cycles);
// 
//     return 0;
// }
//
//



//#include <stdint.h>
//#include <stdio.h>
//
//    uint64_t start_cycle;
//
//    uint64_t end_cycle;
//
//    uint64_t cycle_difference;
//    int32_t a, b;
//// Function to read the cycle counter
//
//uint64_t read_cycle(void) {
//    uint64_t cycle;
//    asm (
//        "nop;"
//        "nop;"
//        "nop;"
//        "nop;"
//        "nop;"
//        "nop;"
//        "nop;"
//        "nop;"
//        "nop;"
//        "nop;"
//        "nop;"
//        "csrr %0, mcycle;"
//        "nop;"
//        "nop;"
//        "nop;"
//        "nop;"
//        "nop;"
//        "nop;"
//        "nop;"
//        "nop;"
//        "nop;"
//        "nop;"
//        "nop;"
//        : "=r"(cycle)
//    );
//    return cycle;
//}
//// Function to perform custom multiplication
//void mulcl_custom(void) {
//
//    // Start counting clock cycles
//    start_cycle = (uint64_t)read_cycle();
//
//    asm volatile (
//	   "nop;"
//  	   "li t1, 0b10100010110011001111000001010011;" // CMUL = 1426067717 CMULH = 1141133392 
//  	   "li t2, 0b10100010110011001111000001010011;" // CMUL = 1426067717 CMULH = 1141133392 
//  	   "mulcl %[mulcl_result], t1, t2;"
//  	   "mulclh %[mulclh_result], t1, t2;"
//             :[mulcl_result] "=r" (a),
//              [mulclh_result] "=r" (b)
//    );
//
//    // End counting clock cycles
//   end_cycle = (uint64_t)read_cycle();
//
//    // Calculate and print the number of clock cycles
//   cycle_difference = (uint64_t)(end_cycle - start_cycle);
//
//    printf("Number of Start Clock Cycles: %x\n", start_cycle);
//    printf("Number of End Clock Cycles: %x\n", end_cycle);
//    printf("Number of Clock Cycles: %x\n",cycle_difference );
//    printf("mulcl = %x \n", a);
//    printf("mulclh = %x \n", b);
//}
//
//int main(void) {
//    // Perform custom multiplication and print the result
//    mulcl_custom();
//
//    return 0;
//}





































 //void mulcl_custom(void) {
 //        int32_t a, b;
 //
 //	asm volatile (
 //	   "nop;"
 //	   //"li t1, 0b0101;"
 //	   //"li t2, 0b1001;"
 //	   //"li t1, 0b10100010;" // CLMUL =22764
 //	   //"li t2, 0b10010110;" // CLMUL =22764
 //	   "li t1, 0b10100010110011001111000001010011;" // CMUL = 1426067717 CMULH = 1141133392 
 //	   "li t2, 0b10100010110011001111000001010011;" // CMUL = 1426067717 CMULH = 1141133392 
 //	   "mulcl %[mulcl_result], t1, t2;"
 //	   "mulclh %[mulclh_result], t1, t2;"
 //           :[mulcl_result] "=r" (a),
 //            [mulclh_result] "=r" (b)
 //	);
 //
 //
 //	printf("mulcl = %ld \n",a);
 //	printf("mulclh = %ld \n",b);
 //
 //}
 //int main(void) {
 //
 //       uint64_t start_cycle, end_cycle;
 //       __asm__ volatile("csrr %0, mcycle" : "=r"(start_cycle));
 //       printf("start cycle: %ld\n", start_cycle);

 //	mulcl_custom();

 //       __asm__ volatile("csrr %0, mcycle" : "=r"(end_cycle));
 //       printf("end cycle: %ld\n", end_cycle);

 //       //printf("total clock cycles: %d\n", end_cycle - start_cycle);
 //	return 0;
 //}


//void mulcl_custom(int32_t *mulcl_result, int32_t *mulclh_result, uint64_t *start_cycle, uint64_t *end_cycle) {
//    // Use t1 and t2 as temporary registers for the assembly code
//    asm volatile (
//        "csrr %[start_cycle], mcycle;"
//        "nop;"
//        "li t1, 0b10100010110011001111000001010011;" // CMUL = 1426067717 CMULH = 1141133392 
//        "li t2, 0b10100010110011001111000001010011;" // CMUL = 1426067717 CMULH = 1141133392 
//        "mulcl %[mulcl_result], t1, t2;"
//        "mulclh %[mulclh_result], t1, t2;"
//        "csrr %[end_cycle], mcycle;"
//        : [mulcl_result] "=r" (*mulcl_result),
//          [mulclh_result] "=r" (*mulclh_result),
//          [start_cycle] "=r" (*start_cycle),
//          [end_cycle] "=r" (*end_cycle)
//    );
//}
//
//int main(void) {
//    uint64_t start_cycle, end_cycle;
//    int32_t mulcl_result, mulclh_result;
//
//    mulcl_custom(&mulcl_result, &mulclh_result, &start_cycle, &end_cycle);
//
//    printf("mulcl = %ld \n", mulcl_result);
//    printf("mulclh = %ld \n", mulclh_result);
//    printf("start cycle: %lu\n", start_cycle);
//    printf("end cycle: %lu\n", end_cycle);
//    printf("total clock cycles: %lu\n", end_cycle - start_cycle);
//
//    long long sc = (long long)start_cycle;
//    long long ec = (long long)end_cycle;
//    printf("sc: %ld\n",sc);
//    printf("ec: %ld\n",ec);
//    printf("cc: %ld\n",(ec - sc));
//    return 0;
//}
//
//
//


//void mulcl_custom(void) {
//        int32_t a, b;
//
//	asm volatile (
//	   "nop;"
//	   //"li t1, 0b0101;"
//	   //"li t2, 0b1001;"
//	   //"li t1, 0b10100010;" // CLMUL =22764
//	   //"li t2, 0b10010110;" // CLMUL =22764
//	   "li t1, 0b10100010110011001111000001010011;" // CMUL = 1426067717 CMULH = 1141133392 
//	   "li t2, 0b10100010110011001111000001010011;" // CMUL = 1426067717 CMULH = 1141133392 
//	   "mulcl %[mulcl_result], t1, t2;"
//	   "mulclh %[mulclh_result], t1, t2;"
//           :[mulcl_result] "=r" (a),
//            [mulclh_result] "=r" (b)
//	);
//
//
//	printf("mulcl = %ld \n",a);
//	printf("mulclh = %ld \n",b);
//
//}
//
//// Function to read the low part of the mcycle counter
//uint32_t read_mcycle_low(void) {
//    uint32_t low;
//    asm volatile ("csrr %0, mcycle" : "=r"(low));
//    return low;
//}
//
//// Function to read the high part of the mcycle counter
//uint32_t read_mcycle_high(void) {
//    uint32_t high;
//    asm volatile ("csrr %0, mcycleh" : "=r"(high));
//    return high;
//}
//
//int main(void) {
//    uint32_t low_start, high_start, low_end, high_end;
//
//    // Start counting clock cycles
//    low_start = read_mcycle_low();
//    high_start = read_mcycle_high();
//
//    mulcl_custom();
//    // End counting clock cycles
//    low_end = read_mcycle_low();
//    high_end = read_mcycle_high();
//
//    // Calculate the total clock cycles
//    uint64_t start_cycle = ((uint64_t)high_start << 32) | low_start;
//    uint64_t end_cycle = ((uint64_t)high_end << 32) | low_end;
//    uint64_t total_cycles = end_cycle - start_cycle;
//
//    printf("low_start: %u\n", low_start);
//    printf("high_start: %u\n", high_start);
//    printf("low_end: %u\n", low_end);
//    printf("high_end: %u\n", high_end);
//    printf("Total Clock Cycles: %lu\n", total_cycles);
//
//    return 0;
//}


//void mulcl_custom(void) {
//        int32_t a, b;
//
//	__asm__ volatile (
//	   "nop;"
//	   //"li t1, 0b0101;"
//	   //"li t2, 0b1001;"
//	   //"li t1, 0b10100010;" // CLMUL =22764
//	   //"li t2, 0b10010110;" // CLMUL =22764
//	   "li t1, 0b10100010110011001111000001010011;" // CMUL = 1426067717 CMULH = 1141133392 
//	   "li t2, 0b10100010110011001111000001010011;" // CMUL = 1426067717 CMULH = 1141133392 
//	   "mulcl %[mulcl_result], t1, t2;"
//	   "mulclh %[mulclh_result], t1, t2;"
//           :[mulcl_result] "=r" (a),
//            [mulclh_result] "=r" (b)
//	);
//
//
//	printf("mulcl = %ld \n",a);
//	printf("mulclh = %ld \n",b);
//
//}
//
////static uint64_t rdcycle_read()
//static uint32_t rdcycle_read()
//{
//    register uint32_t num_cycles;
//    __asm__ volatile("rdcycle %0;" : "=r"(num_cycles));
//    return num_cycles;
//}
//void enable_cycle_counter() {
//    __asm__ volatile("csrci mcountinhibit, 0x1"); // mcountinhibit.cy = 0
//}
//int main(void) {
//    enable_cycle_counter();
//    uint32_t cycle_start = rdcycle_read();
//
//    mulcl_custom();
//
//    uint32_t cycle_end = rdcycle_read();
//
//    uint32_t elapsed_cycle = cycle_end-cycle_start;
//    printf("#cycle = %lu\n", elapsed_cycle);
//    printf("#cycle start = %lu\n", cycle_start);
//    printf("#cycle end = %lu\n", cycle_end);
//}


//void mulcl_custom(void) {
//        int32_t a, b;
//
//	asm volatile (
//	   "nop;"
//	   "li t1, 0b10100010110011001111000001010011;" // CMUL = 1426067717 CMULH = 1141133392 
//	   "li t2, 0b10100010110011001111000001010011;" // CMUL = 1426067717 CMULH = 1141133392 
//	   "mulcl %[mulcl_result], t1, t2;"
//	   "mulclh %[mulclh_result], t1, t2;"
//           :[mulcl_result] "=r" (a),
//            [mulclh_result] "=r" (b)
//	);
//
//
//	printf("mulcl = %ld \n",a);
//	printf("mulclh = %ld \n",b);
//
//}
//
//// Function to read the low part of the mcycle counter
//uint32_t read_mcycle_low(void) {
//    uint32_t low;
//    __asm__ ("csrr %0, mcycle" : "=r"(low));
//    return low;
//}
//// Function to read the high part of the mcycle counter
//uint32_t read_mcycle_high(void) {
//    uint32_t high;
//    __asm__ ("csrr %0, mcycleh" : "=r"(high));
//    return high;
//}
//void enable_cycle_counter() {
//    __asm__ ("csrci mcountinhibit, 0x0000"); // mcountinhibit.cy = 0
//}
//
//int main(void) {
//    uint32_t low_start, high_start, low_end, high_end;
//
//    enable_cycle_counter();
//
//    // Start counting clock cycles
//    low_start = read_mcycle_low();
//    high_start = read_mcycle_high();
//    printf("low_start: %x\n", low_start);
//    printf("high_start: %x\n", high_start);
//
//    //mulcl_custom();
//
//    // End counting clock cycles
//    low_end = read_mcycle_low();
//    high_end = read_mcycle_high();
//    printf("low_end: %x\n", low_end);
//    printf("high_end: %x\n", high_end);
//
//    // Calculate the total clock cycles
//    uint64_t start_cycle = high_start << 32 | low_start;
//    uint64_t end_cycle = high_end << 32 | low_end;
//    uint64_t total_cycles = end_cycle - start_cycle;
//    uint32_t total_cycles_32 = low_end - low_start;
//
//    printf("Start Clock Cycles: %x\n", start_cycle);
//    printf("End Clock Cycles: %x\n", end_cycle);
//    printf("Total Clock Cycles: %x\n", total_cycles);
//    printf("Total Clock Cycles 32: %x\n", total_cycles_32);
//
//    return 0;
//}
//


//void mulcl_custom(void) {
//        int32_t a, b;
//
//	asm volatile (
//	   "li t1, 0b10100010110011001111000001010011;" // A2CCF053h  
//	   "li t2, 0b10010110101010101000001010000001;" // 96AA8281h  
//	   "mulcl %[mulcl_result], t1, t2;"
//	   "mulclh %[mulclh_result], t1, t2;"
//           :[mulcl_result] "=r" (a),
//            [mulclh_result] "=r" (b)
//	);
//


void mulcl_custom(void) {
        int32_t a, b;

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
	   "li t1, 0b10100010110011001111000001010011;" // A2CCF053h  
	   "li t2, 0b10010110101010101000001010000001;" // 96AA8281h  
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
	   "mulcl %[mulcl_result], t1, t2;"
	   "mulclh %[mulclh_result], t1, t2;"
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
           :[mulcl_result] "=r" (a),
            [mulclh_result] "=r" (b)
	);

        printf("mulcl = %lx \n", (unsigned long)a);
        printf("mulclh = %lx \n", (unsigned long)b);
}

// -------------------------------------------------------------
// main using rdcycle for counting the clock cycles
// -------------------------------------------------------------
int main(void) {
    uint32_t start_cycles, end_cycles;

    // Disable performance counter interrupts
    __asm__ volatile ("csrrc zero, mcountinhibit, zero");

    // Record the starting cycle count
    __asm__ volatile ("rdcycle %0" : "=r" (start_cycles));
    printf("start_cycles: %u\n", start_cycles);

    // Call your custom function
    mulcl_custom();

    // Record the ending cycle count
    __asm__ volatile ("rdcycle %0" : "=r" (end_cycles));
    printf("end_cycles: %u\n", end_cycles);

    // Enable performance counter interrupts if needed
    // __asm__ volatile ("csrrs zero, mcountinhibit, zero");

    // Calculate and print the cycle count
    uint32_t cycle_count = end_cycles - start_cycles;
    printf("Cycle Count: %u\n", cycle_count);

    return 0;
}

