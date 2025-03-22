module logic_unit(
    input wire [15:0] in_a, in_b,
    input wire [3:0] sel,
    output reg [15:0] res
);
    always @(*) begin
        case(sel)
            4'b0000: res = ~in_a;
            4'b0001: res = ~(in_a | in_b);
            4'b0010: res = ~in_a & in_b;
            4'b0011: res = 16'h0000;
            4'b0100: res = ~(in_a & in_b);
            4'b0101: res = ~in_b;
            4'b0110: res = in_a ^ in_b;
            4'b0111: res = in_a & ~in_b;
            4'b1000: res = ~in_a | in_b;
            4'b1001: res = ~(in_a ^ in_b);
            4'b1010: res = in_b;
            4'b1011: res = in_a & in_b;
            4'b1100: res = 16'hffff;
            4'b1101: res = in_a | ~in_b;
            4'b1110: res = in_a | in_b;
            4'b1111: res = in_a;
        endcase 
    end


endmodule