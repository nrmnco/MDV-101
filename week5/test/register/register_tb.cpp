#include "Vregister.h"
#include "verilated.h"
#include <iostream>
#include <random>

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vregister* dut = new Vregister;


    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<uint16_t> dis(0, 65535);


    dut->reset = 1;
    dut->en = 0;
    dut->clk = 0;
    dut->eval();
    dut->clk = 1;
    dut->eval();
    std::cout << "Test case 1: Reset -> d_out = " << dut->d_out << " (Expected: 0)" << std::endl;


    dut->reset = 0;
    dut->en = 1;
    dut->d_in = dis(gen);
    dut->clk = 0;
    dut->eval();
    dut->clk = 1;
    dut->eval();
    std::cout << "Test case 2: Load random value -> d_out = " << dut->d_out << " (Expected: " << dut->d_in << ")" << std::endl;


    uint16_t previous_value = dut->d_out;
    dut->en = 0;
    dut->d_in = dis(gen);
    dut->clk = 0;
    dut->eval();
    dut->clk = 1;
    dut->eval();
    std::cout << "Test case 3: Disable -> d_out = " << dut->d_out << " (Expected: " << previous_value << ")" << std::endl;


    dut->reset = 1;
    dut->clk = 0;
    dut->eval();
    dut->clk = 1;
    dut->eval();
    std::cout << "Test case 4: Reset -> d_out = " << dut->d_out << " (Expected: 0)" << std::endl;


    for (int i = 0; i < 5; ++i) {
        dut->reset = 0;
        dut->en = 1;
        dut->d_in = dis(gen);
        dut->clk = 0;
        dut->eval();
        dut->clk = 1;
        dut->eval();
        std::cout << "Test case 5." << i + 1 << ": Load random value -> d_out = " << dut->d_out << " (Expected: " << dut->d_in << ")" << std::endl;
    }


    dut->reset = 0;
    dut->en = 1;
    dut->d_in = dis(gen);
    dut->clk = 0;
    dut->eval();
    dut->clk = 1;
    dut->eval();
    std::cout << "Test case 6.1: Enable on -> d_out = " << dut->d_out << " (Expected: " << dut->d_in << ")" << std::endl;

    dut->en = 0;
    dut->d_in = dis(gen);
    dut->clk = 0;
    dut->eval();
    dut->clk = 1;
    dut->eval();
    std::cout << "Test case 6.2: Enable off -> d_out = " << dut->d_out << " (Expected: " << dut->d_out << ")" << std::endl;

    delete dut;
    return 0;
}