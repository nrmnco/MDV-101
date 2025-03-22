// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfibonacci_generator.h for the primary calling header

#include "Vfibonacci_generator.h"
#include "Vfibonacci_generator__Syms.h"

//==========

VL_CTOR_IMP(Vfibonacci_generator) {
    Vfibonacci_generator__Syms* __restrict vlSymsp = __VlSymsp = new Vfibonacci_generator__Syms(this, name());
    Vfibonacci_generator* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vfibonacci_generator::__Vconfigure(Vfibonacci_generator__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vfibonacci_generator::~Vfibonacci_generator() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vfibonacci_generator::_eval_initial(Vfibonacci_generator__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibonacci_generator::_eval_initial\n"); );
    Vfibonacci_generator* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__rst = vlTOPp->rst;
}

void Vfibonacci_generator::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibonacci_generator::final\n"); );
    // Variables
    Vfibonacci_generator__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vfibonacci_generator* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vfibonacci_generator::_eval_settle(Vfibonacci_generator__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibonacci_generator::_eval_settle\n"); );
    Vfibonacci_generator* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vfibonacci_generator::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibonacci_generator::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    rst = VL_RAND_RESET_I(1);
    enable = VL_RAND_RESET_I(1);
    fib_out = VL_RAND_RESET_I(32);
    fib_prev1 = VL_RAND_RESET_I(32);
    fib_prev2 = VL_RAND_RESET_I(32);
    fibonacci_generator__DOT__fib_current = VL_RAND_RESET_I(32);
}
