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
    


    // ===========================================================================================
    // =============================== arithmetic_unit tests =====================================
    // ===========================================================================================

    std::cout << "ARITHMETIC_UNIT TEST" << std::endl;
    dut->mode = 0;
    dut->cin = 0;
    dut->sel = 0;
    bool flag = 1;
    for(int j = 0; j <= 1000; j++){
        uint16_t random_a = dist(gen);
        uint16_t random_b = dist(gen);
        uint16_t expected_output = random_a;
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
        std::cout << "sel 1 pass" << std::endl;
    }

    dut->sel = 2;
    flag = 1;
    for(int j = 0; j <= 1000; j++){
        uint16_t random_a = dist(gen);
        uint16_t random_b = dist(gen);
        uint16_t expected_output = random_a | ~random_b;
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
        uint16_t expected_output = -1;
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
        uint16_t expected_output = random_a | (random_a & ~random_b);
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
        uint16_t b = dist(gen);
        uint16_t expected_output = (a | b) + (a & ~b);
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
        uint16_t expected_output = a - b - 1;
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
        uint16_t expected_output = a & ~b - 1;
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


    dut->sel = 8;
    flag = 1;
    for(int j = 0; j <= 1000; j++){
        uint16_t a = dist(gen);
        uint16_t b = dist(gen);
        uint16_t expected_output = a + a&b;
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
        std::cout << "sel 8 pass" << std::endl;
    }

    dut->sel = 9;
    flag = 1;
    for(int j = 0; j <= 1000; j++){
        uint16_t a = dist(gen);
        uint16_t b = dist(gen);
        uint16_t expected_output = a + b;
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
        std::cout << "sel 9 pass" << std::endl;
    }

    dut->sel = 10;
    flag = 1;
    for(int j = 0; j <= 1000; j++){
        uint16_t a = dist(gen);
        uint16_t b = dist(gen);
        uint16_t expected_output = (a | ~b) + a&b;
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
        std::cout << "sel 10 pass" << std::endl;
    }

dut->sel = 11;
    flag = 1;
    for(int j = 0; j <= 1000; j++){
        uint16_t a = dist(gen);
        uint16_t b = dist(gen);
        uint16_t expected_output = a & b - 1;
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
        std::cout << "sel 11 pass" << std::endl;
    }

    dut->sel = 12;
    flag = 1;
    for(int j = 0; j <= 1000; j++){
        uint16_t a = dist(gen);
        uint16_t b = dist(gen);
        uint16_t expected_output = a + a;
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
        std::cout << "sel 12 pass" << std::endl;
    }

    dut->sel = 13;
    flag = 1;
    for(int j = 0; j <= 1000; j++){
        uint16_t a = dist(gen);
        uint16_t b = dist(gen);
        uint16_t expected_output = (a|b) + a;
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
        std::cout << "sel 13 pass" << std::endl;
    }


    dut->sel = 14;
    flag = 1;
    for(int j = 0; j <= 1000; j++){
        uint16_t a = dist(gen);
        uint16_t b = dist(gen);
        uint16_t expected_output = (a|~b) + a;
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
        std::cout << "sel 14 pass" << std::endl;
    }

    dut->sel = 15;
    flag = 1;
    for(int j = 0; j <= 1000; j++){
        uint16_t a = dist(gen);
        uint16_t b = dist(gen);
        uint16_t expected_output = a - 1;
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
        std::cout << "sel 15 pass" << std::endl;
    }



    // ===========================================================================================
    // =============================== logic_unit tests ==========================================
    // ===========================================================================================

    std::cout << "\nLOGIC_UNIT TEST" << std::endl;
    dut->mode = 1;
    dut->cin = 0;
    dut->sel = 0;
    flag = 1;
    for(int j = 0; j <= 1000; j++){
        uint16_t a = dist(gen);
        uint16_t b = dist(gen);
        uint16_t expected_output = a;
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
        std::cout << "sel 0 pass" << std::endl;
    }   

    dut->sel = 1;
    flag = 1;
    for(int j = 0; j <= 1000; j++){
        uint16_t a = dist(gen);
        uint16_t b = dist(gen);
        uint16_t expected_output = ~(a | b);
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
        std::cout << "sel 1 pass" << std::endl;
    }

    dut->sel = 2;
    flag = 1;
    for(int j = 0; j <= 1000; j++){
        uint16_t a = dist(gen);
        uint16_t b = dist(gen);
        uint16_t expected_output = ~a & b;
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
        std::cout << "sel 2 pass" << std::endl;
    }

    dut->sel = 3;
    flag = 1;
    for(int j = 0; j <= 1000; j++){
        uint16_t a = dist(gen);
        uint16_t b = dist(gen);
        uint16_t expected_output = 0;
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
        std::cout << "sel 3 pass" << std::endl;
    }

    dut->sel = 4;
    flag = 1;
    for(int j = 0; j <= 1000; j++){
        uint16_t a = dist(gen);
        uint16_t b = dist(gen);
        uint16_t expected_output = ~(a & b);
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
        std::cout << "sel 4 pass" << std::endl;
    }

    dut->sel = 5;
    flag = 1;
    for(int j = 0; j <= 1000; j++){
        uint16_t a = dist(gen);
        uint16_t b = dist(gen);
        uint16_t expected_output = ~b;
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
        uint16_t expected_output = a ^ b;
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
        uint16_t expected_output = a & ~b;
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


    dut->sel = 8;
    flag = 1;
    for(int j = 0; j <= 1000; j++){
        uint16_t a = dist(gen);
        uint16_t b = dist(gen);
        uint16_t expected_output = ~a | b;
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
        std::cout << "sel 8 pass" << std::endl;
    }

    dut->sel = 9;
    flag = 1;
    for(int j = 0; j <= 1000; j++){
        uint16_t a = dist(gen);
        uint16_t b = dist(gen);
        uint16_t expected_output = ~(a ^ b);
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
        std::cout << "sel 9 pass" << std::endl;
    }

    dut->sel = 10;
    flag = 1;
    for(int j = 0; j <= 1000; j++){
        uint16_t a = dist(gen);
        uint16_t b = dist(gen);
        uint16_t expected_output = b;
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
        std::cout << "sel 10 pass" << std::endl;
    }

dut->sel = 11;
    flag = 1;
    for(int j = 0; j <= 1000; j++){
        uint16_t a = dist(gen);
        uint16_t b = dist(gen);
        uint16_t expected_output = a & b;
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
        std::cout << "sel 11 pass" << std::endl;
    }

    dut->sel = 12;
    flag = 1;
    for(int j = 0; j <= 1000; j++){
        uint16_t a = dist(gen);
        uint16_t b = dist(gen);
        uint16_t expected_output = 65535;
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
        std::cout << "sel 12 pass" << std::endl;
    }

    dut->sel = 13;
    flag = 1;
    for(int j = 0; j <= 1000; j++){
        uint16_t a = dist(gen);
        uint16_t b = dist(gen);
        uint16_t expected_output = a | ~b;
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
        std::cout << "sel 13 pass" << std::endl;
    }


    dut->sel = 14;
    flag = 1;
    for(int j = 0; j <= 1000; j++){
        uint16_t a = dist(gen);
        uint16_t b = dist(gen);
        uint16_t expected_output = a | b;
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
        std::cout << "sel 14 pass" << std::endl;
    }

    dut->sel = 15;
    flag = 1;
    for(int j = 0; j <= 1000; j++){
        uint16_t a = dist(gen);
        uint16_t b = dist(gen);
        uint16_t expected_output = a;
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
        std::cout << "sel 15 pass" << std::endl;
    }


    delete dut;

    return 0;
}