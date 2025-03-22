module alu(
    input wire cin,
    input wire [15:0] in_a, in_b,
    input wire [3:0] sel,
    input wire mode,
    output wire cout,
    output wire cmp,
    output reg [15:0] out
);
    wire [15:0] ar_out, lo_out;
    wire carry, comp;

    logic_unit ins1(.in_a(in_a), .in_b(in_b), .sel(sel), .res(lo_out));
    arithmetic_unit ins2(.in_a(in_a), .in_b(in_b), .sel(sel), .cin(cin), .res(ar_out), .cout(cout), .cmp(cmp));

    assign out = mode ? lo_out : ar_out;
    assign cout = carry;
    assign cmp = comp;
endmodule