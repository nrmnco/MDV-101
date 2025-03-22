#include "Vbitty_core.h"
#include "verilated.h"
#include <iostream>
#include <random>
#include <sstream>
#include <map>
#include <string>

uint8_t to3BitBinary(int num) {
    return static_cast<uint8_t>(num & 0b111);
}

uint16_t instructionToBinary(const std::string& instruction) {
    std::map<std::string, uint8_t> aluSelectBits = {
        {"add", 0b000},
        {"sub", 0b001},
        {"and", 0b010},
        {"or",  0b011},
        {"xor", 0b100},
        {"sll", 0b101},
        {"slr", 0b110},
        {"cmp", 0b111}
    };

    std::string operation, op1Str, op2Str;
    std::istringstream iss(instruction);
    iss >> operation >> op1Str >> op2Str;

    int op1 = std::stoi(op1Str);
    int op2 = std::stoi(op2Str);

    uint8_t op1Binary = to3BitBinary(op1);
    uint8_t op2Binary = to3BitBinary(op2);

    uint8_t aluBits = aluSelectBits[operation];

    uint8_t reserved1 = 0b00000;
    uint8_t reserved2 = 0b00;

    uint16_t binaryInstruction = (static_cast<uint16_t>(op1Binary) << 13) |
                                 (static_cast<uint16_t>(op2Binary) << 10) | 
                                 (static_cast<uint16_t>(reserved1) << 5) | 
                                 (static_cast<uint16_t>(aluBits) << 2) |
                                 static_cast<uint16_t>(reserved2);

    return binaryInstruction;
}

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

    std::string instr;
    std::getline(std::cin, instr);
    while (instr != "exit") {
        if (instr == "reset") {
            dut->reset = 1;
            dut->eval();
            dut->clk = 1;
            dut->eval();
            print_outputs(dut);
            std::getline(std::cin, instr);
            continue;
        }
        uint16_t binaryOutput = instructionToBinary(instr);


        // Test case 2: Load an instruction and run the core
        dut->reset = 0;
        dut->run = 1;
        dut->instruction = binaryOutput;
        dut->clk = 0;
        dut->eval();
        dut->clk = 1;
        dut->eval();
        // std::cout << "Test case 2: Load instruction and run" << std::endl;
        // print_outputs(dut);

        // Test case 3: Execute ALU operation (e.g., addition)
        dut->clk = 0;
        dut->eval();
        dut->clk = 1;
        dut->eval();
        // std::cout << "Test case 3: Execute ALU operation" << std::endl;
        // print_outputs(dut);

        // Test case 4: Store result in a register
        dut->clk = 0;
        dut->eval();
        dut->clk = 1;
        dut->eval();
        // std::cout << "Test case 4: Store result in register" << std::endl;
        // print_outputs(dut);

        // Test case 5: Verify done signal
        dut->clk = 0;
        dut->eval();
        dut->clk = 1;
        dut->eval();
        // std::cout << "Test case 5: Verify done signal" << std::endl;
        print_outputs(dut);

        std::getline(std::cin, instr);
    }

    delete dut;
    return 0;
}