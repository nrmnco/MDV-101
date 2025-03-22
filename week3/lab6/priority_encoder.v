module priority_encoder(
    input in0, in1, in2, in3, in4, in5, in6, in7, in8,
    output [3:0] out 
);
    always @(*) begin
        if (in8)
            out = 4'b1001;
        else if (in7)
            out = 4'b1000;
        else if (in6)
            out = 4'b0111;
        else if (in5)
            out = 4'b0110;
        else if (in4)
            out = 4'b0101;
        else if (in3)
            out = 4'b0100;
        else if (in2)
            out = 4'b0011;
        else if (in1)
            out = 4'b0010;
        else if (in0)
            out = 4'b0001;
        else
            out = 4'b0000;
    end
endmodule