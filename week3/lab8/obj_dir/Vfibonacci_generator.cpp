// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfibonacci_generator.h for the primary calling header

#include "Vfibonacci_generator.h"
#include "Vfibonacci_generator__Syms.h"

//==========

void Vfibonacci_generator::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vfibonacci_generator::eval\n"); );
    Vfibonacci_generator__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vfibonacci_generator* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("fibonacci_generator.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vfibonacci_generator::_eval_initial_loop(Vfibonacci_generator__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("fibonacci_generator.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vfibonacci_generator::_sequent__TOP__1(Vfibonacci_generator__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibonacci_generator::_sequent__TOP__1\n"); );
    Vfibonacci_generator* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    IData/*31:0*/ __Vdly__fib_prev1;
    IData/*31:0*/ __Vdly__fib_prev2;
    // Body
    __Vdly__fib_prev2 = vlTOPp->fib_prev2;
    __Vdly__fib_prev1 = vlTOPp->fib_prev1;
    if (vlTOPp->rst) {
        __Vdly__fib_prev1 = 1U;
        __Vdly__fib_prev2 = 0U;
        vlTOPp->fib_out = 0U;
    } else {
        if (vlTOPp->enable) {
            vlTOPp->fibonacci_generator__DOT__fib_current 
                = (vlTOPp->fib_prev1 + vlTOPp->fib_prev2);
            vlTOPp->fib_out = vlTOPp->fibonacci_generator__DOT__fib_current;
            __Vdly__fib_prev2 = vlTOPp->fib_prev1;
            __Vdly__fib_prev1 = vlTOPp->fibonacci_generator__DOT__fib_current;
        }
    }
    vlTOPp->fib_prev1 = __Vdly__fib_prev1;
    vlTOPp->fib_prev2 = __Vdly__fib_prev2;
}

void Vfibonacci_generator::_eval(Vfibonacci_generator__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibonacci_generator::_eval\n"); );
    Vfibonacci_generator* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((IData)(vlTOPp->rst) & (~ (IData)(vlTOPp->__Vclklast__TOP__rst))))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__rst = vlTOPp->rst;
}

VL_INLINE_OPT QData Vfibonacci_generator::_change_request(Vfibonacci_generator__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibonacci_generator::_change_request\n"); );
    Vfibonacci_generator* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vfibonacci_generator::_change_request_1(Vfibonacci_generator__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibonacci_generator::_change_request_1\n"); );
    Vfibonacci_generator* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vfibonacci_generator::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfibonacci_generator::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((enable & 0xfeU))) {
        Verilated::overWidthError("enable");}
}
#endif  // VL_DEBUG
