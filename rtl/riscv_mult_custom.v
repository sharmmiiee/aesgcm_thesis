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



