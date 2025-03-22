module bitty_core(
    input clk,
    input reset,
    input [15:0] instruction,
    input run,
    output done,
    output [15:0] reg_instr_out,
    output [15:0] reg_s_out,
    output [15:0] reg_c_out,
    output [15:0] reg0_out,
    output [15:0] reg1_out,
    output [15:0] reg2_out,
    output [15:0] reg3_out,
    output [15:0] reg4_out,
    output [15:0] reg5_out,
    output [15:0] reg6_out,
    output [15:0] reg7_out,
    output [15:0] mux_out,
    output [15:0] alu_out
);
    wire en_i, en_s, en_c, en_0, en_1, en_2, en_3, en_4, en_5, en_6, en_7, cmp, cout;
    wire [2:0] alu_sel;
    wire [2:0] mux_sel;
    // wire [15:0] mux_out, alu_out, reg_s_out, reg_c_out, reg0_out, reg1_out, reg2_out, reg3_out, reg4_out, reg5_out, reg6_out, reg7_out;
    // reg_instr_out
    control_unit control_inst(
        .clk(clk),
        .reset(reset),
        .d_in(reg_instr_out),
        .run(run),
        .alu_sel(alu_sel),
        .mux_sel(mux_sel),
        .en_i(en_i),
        .en_s(en_s),
        .en_c(en_c),
        .en_0(en_0),
        .en_1(en_1),
        .en_2(en_2),
        .en_3(en_3),
        .en_4(en_4),
        .en_5(en_5),
        .en_6(en_6),
        .en_7(en_7),
        .done(done)
    );

    register reg_instr_inst(
        .clk(clk),
        .reset(reset), 
        .d_in(instruction), 
        .en(en_i),
        .d_out(reg_instr_out)
    );

    register reg_s_inst(
        .clk(clk),
        .reset(reset),
        .d_in(mux_out),
        .en(en_s),
        .d_out(reg_s_out)
    );
    register reg_c_inst(
        .clk(clk),
        .reset(reset),
        .d_in(alu_out),
        .en(en_c),
        .d_out(reg_c_out)
    );
    register reg0_inst(
        .clk(clk),
        .reset(reset),
        .d_in(reg_c_out),
        .en(en_0),
        .d_out(reg0_out)
    );
    register reg1_inst(
        .clk(clk),
        .reset(reset),
        .d_in(reg_c_out),
        .en(en_1),
        .d_out(reg1_out)
    );
    register reg2_inst(
        .clk(clk),
        .reset(reset),
        .d_in(reg_c_out),
        .en(en_2),
        .d_out(reg2_out)
    );
    register reg3_inst(
        .clk(clk),
        .reset(reset),
        .d_in(reg_c_out),
        .en(en_3),
        .d_out(reg3_out)
    );
    register reg4_inst(
        .clk(clk),
        .reset(reset),
        .d_in(reg_c_out),
        .en(en_4),
        .d_out(reg4_out)
    );
    register reg5_inst(
        .clk(clk),
        .reset(reset),
        .d_in(reg_c_out),
        .en(en_5),
        .d_out(reg5_out)
    );
    register reg6_inst(
        .clk(clk),
        .reset(reset),
        .d_in(reg_c_out),
        .en(en_6),
        .d_out(reg6_out)
    );
    register reg7_inst(
        .clk(clk),
        .reset(reset),
        .d_in(reg_c_out),
        .en(en_7),
        .d_out(reg7_out)
    );

    mux mux_inst(
        .sel(mux_sel),
        .in0(reg0_out),
        .in1(reg1_out),
        .in2(reg2_out),
        .in3(reg3_out),
        .in4(reg4_out),
        .in5(reg5_out), 
        .in6(reg6_out),
        .in7(reg7_out),
        .out(mux_out)
    );

    alu alu_inst(
        .in_a(reg_s_out),
        .in_b(mux_out),
        .sel(alu_sel),
        .out(alu_out)
    );


endmodule