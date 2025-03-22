#include "Vcontrol_unit.h"
#include "verilated.h"
#include <iostream>
#include <random>

void print_outputs(Vcontrol_unit* dut) {
    std::cout << "Outputs: ";
    std::cout << "alu_sel = " << (int)dut->alu_sel << ", ";
    std::cout << "alu_mode = " << (int)dut->alu_mode << ", ";
    std::cout << "mux_sel = " << (int)dut->mux_sel << ", ";
    std::cout << "en_s = " << (int)dut->en_s << ", ";
    std::cout << "en_c = " << (int)dut->en_c << ", ";
    std::cout << "en_0 = " << (int)dut->en_0 << ", ";
    std::cout << "en_1 = " << (int)dut->en_1 << ", ";
    std::cout << "en_2 = " << (int)dut->en_2 << ", ";
    std::cout << "en_3 = " << (int)dut->en_3 << ", ";
    std::cout << "en_4 = " << (int)dut->en_4 << ", ";
    std::cout << "en_5 = " << (int)dut->en_5 << ", ";
    std::cout << "en_6 = " << (int)dut->en_6 << ", ";
    std::cout << "en_7 = " << (int)dut->en_7 << ", ";
    std::cout << "en_i = " << (int)dut->en_i << ", ";
    std::cout << "done = " << (int)dut->done << std::endl;
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vcontrol_unit* dut = new Vcontrol_unit;


    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<uint16_t> dis(0, 65535);

    dut->reset = 1;
    dut->clk = 0;
    dut->run = 0;
    dut->eval();
    dut->clk = 1;
    dut->eval();
    std::cout << "Test case 1: Reset" << std::endl;
    print_outputs(dut);


    dut->reset = 0;
    dut->run = 1;
    for (int i = 0; i < 4; ++i) {
        dut->clk = 0;
        dut->eval();
        dut->clk = 1;
        dut->eval();
        std::cout << "Test case 2." << i + 1 << ": Clock cycle " << i + 1 << std::endl;
        print_outputs(dut);
    }


    dut->reset = 0;
    dut->run = 1;
    dut->d_in = 0b1110000000000000; // d_in[15:13] = 111
    dut->clk = 0;
    dut->eval();
    dut->clk = 1;
    dut->eval();
    std::cout << "Test case 3: STATE1" << std::endl;
    print_outputs(dut);

    dut->d_in = 0b0001110000000000;
    dut->clk = 0;
    dut->eval();
    dut->clk = 1;
    dut->eval();
    std::cout << "Test case 4: STATE2" << std::endl;
    print_outputs(dut);

    dut->d_in = 0b1110000000000000; // d_in[15:13] = 111
    dut->clk = 0;
    dut->eval();
    dut->clk = 1;
    dut->eval();
    std::cout << "Test case 5: STATE3" << std::endl;
    print_outputs(dut);


    dut->run = 0;
    dut->clk = 0;
    dut->eval();
    dut->clk = 1;
    dut->eval();
    std::cout << "Test case 6: run = 0" << std::endl;
    print_outputs(dut);

    dut->run = 1;
    dut->clk = 0;
    dut->eval();
    dut->clk = 1;
    dut->eval();
    dut->reset = 1;
    dut->clk = 0;
    dut->eval();
    dut->clk = 1;
    dut->eval();
    std::cout << "Test case 7: Reset during operation" << std::endl;
    print_outputs(dut);


    delete dut;
    return 0;
}