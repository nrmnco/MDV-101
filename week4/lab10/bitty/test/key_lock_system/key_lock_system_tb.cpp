#include "Vkey_lock_system.h"
#include "verilated.h"
#include <iostream>
#include <cstdlib>

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vkey_lock_system* top = new Vkey_lock_system;

    top->clk = 0;
    top->rst = 0;
    top->digit = 0;

    std::cout << "\ncorrect_sequence\n";
    int correct_sequence[] = {3, 3, 5, 2, 5, 6};
    int sequence_length = sizeof(correct_sequence) / sizeof(correct_sequence[0]);

    for (int i = 0; i < sequence_length; i++) {
        for (int j = 0; j < 2; j++) {
            top->clk = !top->clk;
            top->eval();
        }

        top->digit = correct_sequence[i];
        top->eval();

        std::cout << "Time: " << i
                  << ", Digit: " << int(top->digit)
                  << ", States " << int(top->state) << " " << int(top->next_state)
                  << ", Locked: " << int(top->locked) << std::endl;
    }

    if (top->locked == 0) {
        std::cout << "System unlocked successfully!" << std::endl;
    } else {
        std::cout << "System failed to unlock." << std::endl;
    }


    top->rst = 1;
    top->eval();
    top->rst = 0;

    std::cout << "\nincorrect_sequence\n";
    int incorrect_sequence[] = {3, 3, 4, 2, 5, 6};
    sequence_length = sizeof(incorrect_sequence) / sizeof(incorrect_sequence[0]);

    for (int i = 0; i < sequence_length; i++) {
        for (int j = 0; j < 2; j++) {
            top->clk = !top->clk;
            top->eval();
        }

        top->digit = incorrect_sequence[i];
        top->eval();

        std::cout << "Time: " << i
                  << ", Digit: " << int(top->digit)
                  << ", States " << int(top->state) << " " << int(top->next_state)
                  << ", Locked: " << int(top->locked) << std::endl;
    }

    if (top->locked == 1) {
        std::cout << "System remained locked as expected." << std::endl;
    } else {
        std::cout << "System unexpectedly unlocked." << std::endl;
    }


    top->rst = 1;
    top->eval();
    top->rst = 0;

    std::cout << "\npart_sequence\n";
    int part_sequence[] = {3, 3, 5, 2};
    sequence_length = sizeof(part_sequence) / sizeof(part_sequence[0]);

    for (int i = 0; i < sequence_length; i++) {
        for (int j = 0; j < 2; j++) {
            top->clk = !top->clk;
            top->eval();
        }

        top->digit = part_sequence[i];
        top->eval();

        std::cout << "Time: " << i
                  << ", Digit: " << int(top->digit)
                  << ", States " << int(top->state) << " " << int(top->next_state)
                  << ", Locked: " << int(top->locked) << std::endl;
    }

    if (top->locked == 0) {
        std::cout << "System unlocked successfully!" << std::endl;
    } else {
        std::cout << "System failed to unlock." << std::endl;
    }


    top->rst = 1;
    top->eval();
    top->rst = 0;

    std::cout << "\nreset_sequence\n";
    int reset_sequence[] = {3, 3, 5, 2, 5, 6};
    sequence_length = sizeof(reset_sequence) / sizeof(reset_sequence[0]);

    for (int i = 0; i < sequence_length; i++) {
        for (int j = 0; j < 2; j++) {
            top->clk = !top->clk;
            top->eval();
        }

        if (i == sequence_length / 2) {
            top->rst = 1;
        }

        top->digit = reset_sequence[i];
        top->eval();

        std::cout << "Time: " << i
                  << ", Digit: " << int(top->digit)
                  << ", States " << int(top->state) << " " << int(top->next_state)
                  << ", Locked: " << int(top->locked) << std::endl;
    }

    if (top->locked == 0) {
        std::cout << "System unlocked successfully!" << std::endl;
    } else {
        std::cout << "System failed to unlock." << std::endl;
    }


    top->rst = 1;
    top->eval();
    top->rst = 0;

    std::cout << "\nreset2_sequence\n";
    int reset2_sequence[] = {3, 3, 5, 2, 3, 3};
    sequence_length = sizeof(reset2_sequence) / sizeof(reset2_sequence[0]);

    for (int i = 0; i < sequence_length; i++) {
        for (int j = 0; j < 2; j++) {
            top->clk = !top->clk;
            top->eval();
        }

        if (i == sequence_length / 2) {
            top->rst = 1;
        } 
        else if (i == sequence_length / 2 + 1) {
            top->rst = 0;
        }

        top->digit = reset2_sequence[i];
        top->eval();

        std::cout << "Time: " << i
                  << ", Digit: " << int(top->digit)
                  << ", States " << int(top->state) << " " << int(top->next_state)
                  << ", Locked: " << int(top->locked) << std::endl;
    }

    if (top->locked == 0) {
        std::cout << "System unlocked successfully!" << std::endl;
    } else {
        std::cout << "System failed to unlock." << std::endl;
    }


    top->rst = 1;
    top->eval();
    top->rst = 0;
    top->digit = 9;


    std::cout << "\nsecond correct\n";
    int second_correct_sequence[] = {3, 3, 5, 2, 5, 6};
    sequence_length = sizeof(second_correct_sequence) / sizeof(second_correct_sequence[0]);

    for (int i = 0; i < sequence_length; i++) {
        for (int j = 0; j < 2; j++) {
            top->clk = !top->clk;
            top->eval();
        }

        top->digit = second_correct_sequence[i];
        top->eval();

        std::cout << "Time: " << i
                  << ", Digit: " << int(top->digit)
                  << ", States " << int(top->state) << " " << int(top->next_state)
                  << ", Locked: " << int(top->locked) << std::endl;
    }

    if (top->locked == 0) {
        std::cout << "System unlocked successfully!" << std::endl;
    } else {
        std::cout << "System failed to unlock." << std::endl;
    }

    delete top;

    return 0;
}