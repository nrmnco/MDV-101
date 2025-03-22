#include "Vbitty_core.h"
#include "verilated.h"
#include <iostream>
#include <random>

void print_outputs(Vbitty_core* dut) {
    std::cout << "Outputs: ";
    std::cout << "done = " << (int)dut->done << ", ";
    std::cout << "reg_instr_out = " << dut->reg_instr_out << ", ";
    std::cout << "reg_s_out = " << dut->reg_s_out << ", ";
    std::cout << "reg_c_out = " << dut->reg_c_out << ", ";
    std::cout << "reg0_out = " << dut->reg0_out << ", ";
    std::cout << "reg1_out = " << dut->reg1_out << ", ";
    std::cout << "reg2_out = " << dut->reg2_out << ", ";
    std::cout << "reg3_out = " << dut->reg3_out << ", ";
    std::cout << "reg4_out = " << dut->reg4_out << ", ";
    std::cout << "reg5_out = " << dut->reg5_out << ", ";
    std::cout << "reg6_out = " << dut->reg6_out << ", ";
    std::cout << "reg7_out = " << dut->reg7_out << ", ";
    std::cout << "mux_out = " << dut->mux_out << ", ";
    std::cout << "alu_out = " << dut->alu_out << std::endl;
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vbitty_core* dut = new Vbitty_core;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<uint16_t> dis(0, 65535);

    // Test case 1: Reset the core
    dut->reset = 1;
    dut->clk = 0;
    dut->run = 0;
    dut->instruction = 0;
    dut->eval();
    dut->clk = 1;
    dut->eval();
    std::cout << "Test case 1: Reset" << std::endl;
    print_outputs(dut);

    // Test case 2: Load an instruction and run the core
    dut->reset = 0;
    dut->run = 1;
    dut->instruction = 0b1011110000011000;
    dut->clk = 0;
    dut->eval();
    dut->clk = 1;
    dut->eval();
    std::cout << "Test case 2: Load instruction and run" << std::endl;
    print_outputs(dut);

    // Test case 3: Execute ALU operation (e.g., addition)
    dut->instruction = 0b1011110000011000;
    dut->clk = 0;
    dut->eval();
    dut->clk = 1;
    dut->eval();
    std::cout << "Test case 3: Execute ALU operation" << std::endl;
    print_outputs(dut);

    // Test case 4: Store result in a register
    dut->instruction = 0b1011110000011000;
    dut->clk = 0;
    dut->eval();
    dut->clk = 1;
    dut->eval();
    std::cout << "Test case 4: Store result in register" << std::endl;
    print_outputs(dut);

    // Test case 5: Verify done signal
    dut->instruction = 0b1011110000011000;
    dut->clk = 0;
    dut->eval();
    dut->clk = 1;
    dut->eval();
    std::cout << "Test case 5: Verify done signal" << std::endl;
    print_outputs(dut);

    // Test case 6: Reset during operation
    dut->reset = 1;
    dut->clk = 0;
    dut->eval();
    dut->clk = 1;
    dut->eval();
    std::cout << "Test case 6: Reset during operation" << std::endl;
    print_outputs(dut);

    delete dut;
    return 0;
}