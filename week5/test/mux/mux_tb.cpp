#include "Vmux.h"
#include "verilated.h"
#include <iostream>
#include <random>

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vmux* dut = new Vmux;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<uint16_t> dis(0, 65535);


    dut->in0 = dis(gen);
    dut->in1 = dis(gen);
    dut->in2 = dis(gen);
    dut->in3 = dis(gen);
    dut->in4 = dis(gen);
    dut->in5 = dis(gen);
    dut->in6 = dis(gen);
    dut->in7 = dis(gen);

    for (int i = 0; i < 8; ++i) {
        dut->sel = i;
        dut->eval();
        std::cout << "Test case 1." << i + 1 << ": sel = " << i << " -> out = " << dut->out;
        switch (i) {
            case 0: std::cout << " (Expected: " << dut->in0 << ")" << std::endl; break;
            case 1: std::cout << " (Expected: " << dut->in1 << ")" << std::endl; break;
            case 2: std::cout << " (Expected: " << dut->in2 << ")" << std::endl; break;
            case 3: std::cout << " (Expected: " << dut->in3 << ")" << std::endl; break;
            case 4: std::cout << " (Expected: " << dut->in4 << ")" << std::endl; break;
            case 5: std::cout << " (Expected: " << dut->in5 << ")" << std::endl; break;
            case 6: std::cout << " (Expected: " << dut->in6 << ")" << std::endl; break;
            case 7: std::cout << " (Expected: " << dut->in7 << ")" << std::endl; break;
        }
    }

    dut->sel = 3;
    for (int i = 0; i < 5; ++i) {
        dut->in3 = dis(gen);
        dut->eval();
        std::cout << "Test case 2." << i + 1 << ": sel = 3, in3 = " << dut->in3 << " -> out = " << dut->out << " (Expected: " << dut->in3 << ")" << std::endl;
    }


    dut->sel = 4;
    dut->eval();
    std::cout << "Test case 3: sel changed to 4 -> out = " << dut->out << " (Expected: " << dut->in4 << ")" << std::endl;


    dut->in4 = dis(gen);
    dut->sel = 4;
    dut->eval();
    std::cout << "Test case 4: sel = 4, in4 updated -> out = " << dut->out << " (Expected: " << dut->in4 << ")" << std::endl;


    dut->sel = 5;
    dut->in5 = dis(gen);
    dut->eval();
    std::cout << "Test case 5: sel = 5, in5 updated -> out = " << dut->out << " (Expected: " << dut->in5 << ")" << std::endl;

    // Clean up
    delete dut;
    return 0;
}