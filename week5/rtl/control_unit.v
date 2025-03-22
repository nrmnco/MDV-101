module control_unit(
    input clk,
    input reset,
    input [15:0] d_in,
    input run,
    output reg [3:0] alu_sel,
    output reg alu_mode,
    output reg [2:0] mux_sel,
    output reg en_s,
    output reg en_c,
    output reg en_0,
    output reg en_1,
    output reg en_2,
    output reg en_3,
    output reg en_4,
    output reg en_5,
    output reg en_6,
    output reg en_7,
    output reg en_i,
    output reg done
);
    parameter STATE0 = 2'b00, STATE1 = 2'b01, STATE2 = 2'b10, STATE3 = 2'b11;

    reg [1:0] state, next_state;


    always @(posedge clk or posedge reset) begin
      if (reset) begin
          	state <= STATE0;
      end
      else if (run) begin
            state <= next_state;
      end
    end

    //next_state logic
    always @(*) begin
        case(state)
            STATE0: next_state = STATE1;
            STATE1: next_state = STATE2;
            STATE2: next_state = STATE3;
            STATE3: next_state = STATE0;
        endcase
    end
    
    //main logic
  always @(*) begin
        case(state)
            STATE0: begin
              	en_s = 1'b0;
                done = 1'b0;
              	en_i = 1'b1;
              	en_c = 1'b0;
              	en_0 = 1'b0;
              	en_1 = 1'b0;
                en_2 = 1'b0;
                en_3 = 1'b0;
                en_4 = 1'b0;
                en_5 = 1'b0;
                en_6 = 1'b0;
                en_7 = 1'b0;
            end
            STATE1: begin
                mux_sel = d_in[15:13];
              	en_c = 1'b0;
                en_s = 1'b1;
                en_i = 1'b0;
            end
            STATE2: begin
              	en_i = 1'b0;
                en_s = 1'b0;
                en_c = 1'b1;
                mux_sel = d_in[12:10];
                alu_sel = d_in[6:3];
                alu_mode = d_in[2];
            end
            STATE3: begin
              	en_s = 1'b0;
              	en_i = 1'b0;
                en_c = 1'b0;
                done = 1'b1;
                en_0 = 1'b0;
            	  en_1 = 1'b0;
                en_2 = 1'b0;
                en_3 = 1'b0;
                en_4 = 1'b0;
                en_5 = 1'b0;
                en_6 = 1'b0;
                en_7 = 1'b0;
                case(d_in[15:13])
                    3'b000: en_0 = 1'b1;
                    3'b001: en_1 = 1'b1;
                    3'b010: en_2 = 1'b1;
                    3'b011: en_3 = 1'b1;
                    3'b100: en_4 = 1'b1;
                    3'b101: en_5 = 1'b1;
                    3'b110: en_6 = 1'b1;
                    3'b111: en_7 = 1'b1;
                endcase
            end
        endcase
    end

endmodule