#include "Valu.h"
#include "verilated.h"

#include <iostream>
#include <random>

int main(int argc, char **argv)
{
    Verilated::commandArgs(argc, argv);
    Valu* dut = new Valu();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<uint16_t> dist(0, 65535);
    

    dut->sel = 0;
    bool flag = 1;
    for(int j = 0; j <= 1000; j++){
        uint16_t random_a = dist(gen);
        uint16_t random_b = dist(gen);
        uint16_t expected_output = random_a + random_b;
        dut->in_a = random_a;
        dut->in_b = random_b;
        dut->eval();
        if (dut->out != expected_output){
            flag = 0;
            std::cout << "error: result is: " << dut->out << " expected: " << expected_output << std::endl;
            break;
        }
    }
    if (flag){
        std::cout << "sel 0 pass" << std::endl;
    }   

    dut->sel = 1;
    flag = 1;
    for(int j = 0; j <= 1000; j++){
        uint16_t random_a = dist(gen);
        uint16_t random_b = dist(gen);
        uint16_t expected_output = random_a - random_b;
        dut->in_a = random_a;
        dut->in_b = random_b;
        dut->eval();
        if (dut->out != expected_output){
            flag = 0;
            std::cout << "error: result is: " << dut->out << " expected: " << expected_output << std::endl;
            break;
        }
    }
    if (flag){
        std::cout << "sel 1 pass" << std::endl;
    }

    dut->sel = 2;
    flag = 1;
    for(int j = 0; j <= 1000; j++){
        uint16_t random_a = dist(gen);
        uint16_t random_b = dist(gen);
        uint16_t expected_output = random_a & random_b;
        dut->in_a = random_a;
        dut->in_b = random_b;
        dut->eval();
        if (dut->out != expected_output){
            flag = 0;
            std::cout << "error: result is: " << dut->out << " expected: " << expected_output << std::endl;
            break;
        }
    }
    if (flag){
        std::cout << "sel 2 pass" << std::endl;
    }

    dut->sel = 3;
    flag = 1;
    for(int j = 0; j <= 1000; j++){
        uint16_t random_a = dist(gen);
        uint16_t random_b = dist(gen);
        uint16_t expected_output = random_a | random_b;
        dut->in_a = random_a;
        dut->in_b = random_b;
        dut->eval();
        if (dut->out != expected_output){
            flag = 0;
            std::cout << "error: result is: " << dut->out << " expected: " << expected_output << std::endl;
            break;
        }
    }
    if (flag){
        std::cout << "sel 3 pass" << std::endl;
    }

    dut->sel = 4;
    flag = 1;
    for(int j = 0; j <= 1000; j++){
        uint16_t random_a = dist(gen);
        uint16_t random_b = dist(gen);
        uint16_t expected_output = random_a ^ random_b;
        dut->in_a = random_a;
        dut->in_b = random_b;
        dut->eval();
        if (dut->out != expected_output){
            flag = 0;
            std::cout << "error: result is: " << dut->out << " expected: " << expected_output << " :::: " << random_a << " " << random_b << std::endl;
            break;
        }
    }
    if (flag){
        std::cout << "sel 4 pass" << std::endl;
    }

    dut->sel = 5;
    flag = 1;
    for(int j = 0; j <= 1000; j++){
        uint16_t a = dist(gen);
        int b = dist(gen);
        uint16_t expected_output = (b < 16) ? a << b : 0;

        dut->in_a = a;
        dut->in_b = b;
        dut->eval();
        if (dut->out != expected_output){
            flag = 0;
            std::cout << "error: result is: " << dut->out << " expected: " << expected_output << std::endl;
            break;
        }
    }
    if (flag){
        std::cout << "sel 5 pass" << std::endl;
    }

    dut->sel = 6;
    flag = 1;
    for(int j = 0; j <= 1000; j++){
        uint16_t a = dist(gen);
        uint16_t b = dist(gen);
        uint16_t expected_output = (b < 16) ? a << b : 0;
        dut->in_a = a;
        dut->in_b = b;
        dut->eval();
        if (dut->out != expected_output){
            flag = 0;
            std::cout << "error: result is: " << dut->out << " expected: " << expected_output << std::endl;
            break;
        } 
    }
    if (flag){
        std::cout << "sel 6 pass" << std::endl;
    }

    dut->sel = 7;
    flag = 1;
    for(int j = 0; j <= 1000; j++){
        uint16_t a = dist(gen);
        uint16_t b = dist(gen);
        uint16_t expected_output = (a == b) ? 65535 : 0;
        dut->in_a = a;
        dut->in_b = b;
        dut->eval();
        if (dut->out != expected_output){
            flag = 0;
            std::cout << "error: result is: " << dut->out << " expected: " << expected_output << std::endl;
            break;
        } 
    }
    if (flag){
        std::cout << "sel 7 pass" << std::endl;
    }


    delete dut;

    return 0;
}