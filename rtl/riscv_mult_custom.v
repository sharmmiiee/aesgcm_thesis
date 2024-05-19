// Added by Sharmine Reyes
// Polynomial Multiplication using carry-less multiplication for GF(2^n) multiplication

module riscv_mult_custom(

   input  wire        calculate_mulcl_i,
   input  wire        fetch_mulcl_i,
   input  wire [31:0] op_a_i,
   input  wire [31:0] op_b_i,
   output wire [31:0] result_l_o,
   output wire [31:0] result_h_o

);

   reg [31:0] temp_result_l;
   reg [31:0] temp_result_h;

   reg [6:0]  bit_count;

   // Default assignments
   initial begin
       temp_result_l = 32'h0;
       temp_result_h = 32'h0; 
   end

   always @* begin      
          
       // Perform carry-less multiplication if instr = mulclh
       if ((calculate_mulcl_i==1) && (fetch_mulcl_i==0)) begin 
       
	   temp_result_l = 32'd0;
           temp_result_h = 32'd0;	
           
	   for ( bit_count = 0; bit_count < 32; bit_count = bit_count + 1 ) begin 
	       if ( op_b_i[bit_count] == 1'b1) begin
	           // operation: Shift by bit_count and add to result
	           temp_result_l = temp_result_l ^ (op_a_i << bit_count);
                   temp_result_h = temp_result_h ^ (op_a_i >> (32 - bit_count));
	       end  
	   end  
       end  
   end

   assign result_l_o = temp_result_l;
   assign result_h_o = temp_result_h;   
   
endmodule



//module riscv_mult_custom(
//   input  wire        calculate_mulcl_i,
//   input  wire        fetch_mulcl_i,
//   input  wire [31:0] op_a_i,
//   input  wire [31:0] op_b_i,
//   output wire [31:0] result_l_o,
//   output wire [31:0] result_h_o
//);
//
//   reg [31:0] temp_result_l;
//   reg [31:0] temp_result_h;
//   reg        calc_done     = 1'b0;
//
//   integer i;
//
//   always @* begin
//       if (calculate_mulcl_i && !calc_done) begin
//	  temp_result_l = 32'd0;
//	  temp_result_h = 32'd0;
//          // Carryless multiplication logic
//          for (i = 0; i < 32; i = i + 1) begin
//              if (op_b_i[i]) begin
//                  temp_result_l = temp_result_l ^ (op_a_i << i);
//                  temp_result_h = temp_result_h ^ (op_a_i >> (32 - i));
//              end //if
//          end // for
//          calc_done = 1'b1;
//       end // else if
//       else if (fetch_mulcl_i) begin
//          calc_done     = 1'b0;
//       end
//       else begin
//	       // Keep the results unchanged
//       end
//   end
//
//
//   assign result_l_o = temp_result_l;
//   assign result_h_o = temp_result_h;
//
//endmodule

////// -------------------------------------------------------------------------------------
//// The result is OK but the result is prone to race condition
//// Error message: %Error: tb_top_verilator.sv:14: Input combinational region did not converge.
////// -------------------------------------------------------------------------------------
//module riscv_mult_custom(
//   input  wire        clk,
//   input  wire        rst_n,
//   input  wire        calculate_mulcl_i,
//   input  wire        fetch_mulcl_i,
//   input  wire [31:0] op_a_i,
//   input  wire [31:0] op_b_i,
//   output wire [31:0] result_l_o,
//   output wire [31:0] result_h_o
//);
//
//   reg [31:0] temp_result_l, temp_result_h;
//   reg        calc_done;
//
//   always @* begin
//       if (!rst_n) begin
//          calc_done     = 1'b0;
//          temp_result_l = 32'b0;
//          temp_result_h = 32'b0;
//       end
//       else if (calculate_mulcl_i && !calc_done) begin
//          // Carryless multiplication logic
//          for (integer i = 0; i < 32; i = i + 1) begin
//              if (op_b_i[i]) begin
//                  temp_result_l = temp_result_l ^ (op_a_i << i);
//                  temp_result_h = temp_result_h ^ (op_a_i >> (32 - i));
//              end //if
//          end // for
//          calc_done = 1'b1;
//       end // else if
//       else if (fetch_mulcl_i) begin
//          calc_done     = 1'b0;
//          temp_result_l = temp_result_l;
//          temp_result_h = temp_result_h;
//       end
//       else begin
//          calc_done     = calc_done;
//          temp_result_l = temp_result_l;
//          temp_result_h = temp_result_h;
//       end
//   end
//
//
//   assign result_l_o = temp_result_l;
//   assign result_h_o = temp_result_h;
//
//endmodule



//module riscv_mult_custom(
//   input  [31:0] op_a_i,
//   input  [31:0] op_b_i,
//   output [31:0] result_l_o,
//   output [31:0] result_h_o
//);
//
//   reg [31:0] temp_result_l, temp_result_h;
//   integer i, j;
//    
//   always @* begin
//      temp_result_l = 32'b0;
//      temp_result_h = 32'b0;
//
//      // Carryless multiplication logic
//      for (i = 0; i < 32; i = i + 1) begin
//         if (op_b_i[i]) begin
//            temp_result_l = temp_result_l ^ (op_a_i << i);
//            temp_result_h = temp_result_h ^ (op_a_i >> (32 - i));
//         end
//      end
//   end
//
//   assign result_l_o = temp_result_l;
//   assign result_h_o = temp_result_h;
//
//endmodule

