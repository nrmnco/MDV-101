module key_lock_system(
    input clk,
    input [3:0] digit,
    input rst,
    output reg locked,
    output reg [2:0] state, next_state
);

    parameter [2:0] LOCKED = 3'b000,
    FIRST = 3'b001,
    SECOND = 3'b010,
    THIRD = 3'b011,
    FOURTH = 3'b100,
    FIFTH = 3'b101,
    OPEN = 3'b110;

    // reg [2:0] state, next_state;

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            state <= LOCKED;
            // next_state <= FIRST;
        end
        else begin
            state <= next_state;
        end
    end

    always @(*) begin
        if (!rst) begin
            case(state)
                LOCKED: begin
                        if (digit == 4'd3)
                            next_state = FIRST;
                        else
                            next_state = LOCKED;
                end 
                FIRST: begin
                        if (digit == 4'd3)
                            next_state = SECOND;
                        else
                            next_state = LOCKED;
                end 
                SECOND: begin
                        if (digit == 4'd5)
                            next_state = THIRD;
                        else
                            next_state = LOCKED;
                end 
                THIRD: begin
                        if (digit == 4'd2)
                            next_state = FOURTH;
                        else
                            next_state = LOCKED;
                end 
                FOURTH: begin
                        if (digit == 4'd5)
                            next_state = FIFTH;
                        else
                            next_state = LOCKED;
                end 
                FIFTH: begin
                        if (digit == 4'd6)
                            next_state = OPEN;
                        else
                            next_state = LOCKED;
                end 
                OPEN: begin
                        next_state = OPEN;
                end 
                // default: begin
                //         next_state = LOCKED;
                // end 
            endcase
        end
    end

    always @(*) begin
        if (next_state == OPEN) begin
            locked = 1'b0;
        end else begin
            locked = 1'b1;
        end
    end


endmodule
