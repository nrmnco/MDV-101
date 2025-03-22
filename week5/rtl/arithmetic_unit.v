module arithmetic_unit(
    input wire [15:0] in_a, in_b,
    input wire [3:0] sel,
    input wire cin,
    output reg [15:0] res,
    output wire cout,
    output wire cmp
);
    always @(*) begin
      case(sel)
        4'b0000: {cout, res} = in_a;
        4'b0001: {cout, res} = in_a | in_b;
        4'b0010: {cout, res} = in_a | ~in_b;
        4'b0011: {cout, res} = -1;
        4'b0100: {cout, res} = in_a | (in_a & ~in_b);
        4'b0101: {cout, res} = (in_a | in_b) + (in_a & ~in_b);
        4'b0110: {cout, res} = in_a - in_b - 1;
        4'b0111: {cout, res} = in_a & ~in_b - 1;
        4'b1000: {cout, res} = in_a + in_a & in_b;
        4'b1001: {cout, res} = in_a + in_b;
        4'b1010: {cout, res} = (in_a | ~in_b) + in_a & in_b;
        4'b1011: {cout, res} = in_a & in_b - 1;
        4'b1100: {cout, res} = in_a + in_a;
        4'b1101: {cout, res} = (in_a | in_b) + in_a;
        4'b1110: {cout, res} = (in_a | ~in_b) + in_a;
        4'b1111: {cout, res} = in_a - 1;
      endcase 
    end

    
    assign cmp = (in_a == in_b) ? 1'b1 : 1'b0;
    

endmodule