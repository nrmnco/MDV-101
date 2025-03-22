// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Varithmetic_unit.h for the primary calling header

#include "Varithmetic_unit.h"
#include "Varithmetic_unit__Syms.h"

//==========

void Varithmetic_unit::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Varithmetic_unit::eval\n"); );
    Varithmetic_unit__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Varithmetic_unit* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("rtl/arithmetic_unit.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Varithmetic_unit::_eval_initial_loop(Varithmetic_unit__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("rtl/arithmetic_unit.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Varithmetic_unit::_combo__TOP__1(Varithmetic_unit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Varithmetic_unit::_combo__TOP__1\n"); );
    Varithmetic_unit* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->cmp = ((IData)(vlTOPp->in_a) == (IData)(vlTOPp->in_b));
    if ((8U & (IData)(vlTOPp->sel))) {
        vlTOPp->res = (0xffffU & ((4U & (IData)(vlTOPp->sel))
                                   ? ((2U & (IData)(vlTOPp->sel))
                                       ? ((1U & (IData)(vlTOPp->sel))
                                           ? ((IData)(vlTOPp->in_a) 
                                              - (IData)(1U))
                                           : (((IData)(vlTOPp->in_a) 
                                               | (~ (IData)(vlTOPp->in_b))) 
                                              + (IData)(vlTOPp->in_a)))
                                       : ((1U & (IData)(vlTOPp->sel))
                                           ? (((IData)(vlTOPp->in_a) 
                                               | (IData)(vlTOPp->in_b)) 
                                              + (IData)(vlTOPp->in_a))
                                           : ((IData)(vlTOPp->in_a) 
                                              + (IData)(vlTOPp->in_a))))
                                   : ((2U & (IData)(vlTOPp->sel))
                                       ? ((1U & (IData)(vlTOPp->sel))
                                           ? ((IData)(vlTOPp->in_a) 
                                              & ((IData)(vlTOPp->in_b) 
                                                 - (IData)(1U)))
                                           : ((((IData)(vlTOPp->in_a) 
                                                | (~ (IData)(vlTOPp->in_b))) 
                                               + (IData)(vlTOPp->in_a)) 
                                              & (IData)(vlTOPp->in_b)))
                                       : ((1U & (IData)(vlTOPp->sel))
                                           ? ((IData)(vlTOPp->in_a) 
                                              + (IData)(vlTOPp->in_b))
                                           : (((IData)(vlTOPp->in_a) 
                                               + (IData)(vlTOPp->in_a)) 
                                              & (IData)(vlTOPp->in_b))))));
        vlTOPp->cout = (1U & ((4U & (IData)(vlTOPp->sel))
                               ? ((2U & (IData)(vlTOPp->sel))
                                   ? ((1U & (IData)(vlTOPp->sel))
                                       ? (1U & (((IData)(vlTOPp->in_a) 
                                                 - (IData)(1U)) 
                                                >> 0x10U))
                                       : (1U & ((((IData)(vlTOPp->in_a) 
                                                  | (~ (IData)(vlTOPp->in_b))) 
                                                 + (IData)(vlTOPp->in_a)) 
                                                >> 0x10U)))
                                   : ((1U & (IData)(vlTOPp->sel))
                                       ? (1U & ((((IData)(vlTOPp->in_a) 
                                                  | (IData)(vlTOPp->in_b)) 
                                                 + (IData)(vlTOPp->in_a)) 
                                                >> 0x10U))
                                       : (1U & (((IData)(vlTOPp->in_a) 
                                                 + (IData)(vlTOPp->in_a)) 
                                                >> 0x10U))))
                               : ((2U & (IData)(vlTOPp->sel))
                                   ? ((1U & (IData)(vlTOPp->sel))
                                       ? (1U & (((IData)(vlTOPp->in_a) 
                                                 & ((IData)(vlTOPp->in_b) 
                                                    - (IData)(1U))) 
                                                >> 0x10U))
                                       : (((((IData)(vlTOPp->in_a) 
                                             | (~ (IData)(vlTOPp->in_b))) 
                                            + (IData)(vlTOPp->in_a)) 
                                           & (IData)(vlTOPp->in_b)) 
                                          >> 0x10U))
                                   : ((1U & (IData)(vlTOPp->sel))
                                       ? (1U & (((IData)(vlTOPp->in_a) 
                                                 + (IData)(vlTOPp->in_b)) 
                                                >> 0x10U))
                                       : ((((IData)(vlTOPp->in_a) 
                                            + (IData)(vlTOPp->in_a)) 
                                           & (IData)(vlTOPp->in_b)) 
                                          >> 0x10U)))));
    } else {
        vlTOPp->res = (0xffffU & ((4U & (IData)(vlTOPp->sel))
                                   ? ((2U & (IData)(vlTOPp->sel))
                                       ? ((1U & (IData)(vlTOPp->sel))
                                           ? ((IData)(vlTOPp->in_a) 
                                              & ((~ (IData)(vlTOPp->in_b)) 
                                                 - (IData)(1U)))
                                           : (((IData)(vlTOPp->in_a) 
                                               - (IData)(vlTOPp->in_b)) 
                                              - (IData)(1U)))
                                       : ((1U & (IData)(vlTOPp->sel))
                                           ? (((IData)(vlTOPp->in_a) 
                                               | (IData)(vlTOPp->in_b)) 
                                              + ((IData)(vlTOPp->in_a) 
                                                 & (~ (IData)(vlTOPp->in_b))))
                                           : ((IData)(vlTOPp->in_a) 
                                              | ((IData)(vlTOPp->in_a) 
                                                 & (~ (IData)(vlTOPp->in_b))))))
                                   : ((2U & (IData)(vlTOPp->sel))
                                       ? ((1U & (IData)(vlTOPp->sel))
                                           ? 0xffffU
                                           : ((IData)(vlTOPp->in_a) 
                                              | (~ (IData)(vlTOPp->in_b))))
                                       : ((1U & (IData)(vlTOPp->sel))
                                           ? ((IData)(vlTOPp->in_a) 
                                              | (IData)(vlTOPp->in_b))
                                           : (IData)(vlTOPp->in_a)))));
        vlTOPp->cout = (1U & ((4U & (IData)(vlTOPp->sel))
                               ? ((2U & (IData)(vlTOPp->sel))
                                   ? ((1U & (IData)(vlTOPp->sel))
                                       ? (1U & (((IData)(vlTOPp->in_a) 
                                                 & ((~ (IData)(vlTOPp->in_b)) 
                                                    - (IData)(1U))) 
                                                >> 0x10U))
                                       : (1U & ((((IData)(vlTOPp->in_a) 
                                                  - (IData)(vlTOPp->in_b)) 
                                                 - (IData)(1U)) 
                                                >> 0x10U)))
                                   : ((1U & (IData)(vlTOPp->sel))
                                       ? (1U & ((((IData)(vlTOPp->in_a) 
                                                  | (IData)(vlTOPp->in_b)) 
                                                 + 
                                                 ((IData)(vlTOPp->in_a) 
                                                  & (~ (IData)(vlTOPp->in_b)))) 
                                                >> 0x10U))
                                       : (((IData)(vlTOPp->in_a) 
                                           | ((IData)(vlTOPp->in_a) 
                                              & (~ (IData)(vlTOPp->in_b)))) 
                                          >> 0x10U)))
                               : ((2U & (IData)(vlTOPp->sel))
                                   ? ((IData)(vlTOPp->sel) 
                                      | (1U & (((IData)(vlTOPp->in_a) 
                                                | (~ (IData)(vlTOPp->in_b))) 
                                               >> 0x10U)))
                                   : ((1U & (IData)(vlTOPp->sel))
                                       ? (((IData)(vlTOPp->in_a) 
                                           | (IData)(vlTOPp->in_b)) 
                                          >> 0x10U)
                                       : ((IData)(vlTOPp->in_a) 
                                          >> 0x10U)))));
    }
}

void Varithmetic_unit::_eval(Varithmetic_unit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Varithmetic_unit::_eval\n"); );
    Varithmetic_unit* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData Varithmetic_unit::_change_request(Varithmetic_unit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Varithmetic_unit::_change_request\n"); );
    Varithmetic_unit* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Varithmetic_unit::_change_request_1(Varithmetic_unit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Varithmetic_unit::_change_request_1\n"); );
    Varithmetic_unit* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Varithmetic_unit::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Varithmetic_unit::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((sel & 0xf0U))) {
        Verilated::overWidthError("sel");}
    if (VL_UNLIKELY((cin & 0xfeU))) {
        Verilated::overWidthError("cin");}
}
#endif  // VL_DEBUG
