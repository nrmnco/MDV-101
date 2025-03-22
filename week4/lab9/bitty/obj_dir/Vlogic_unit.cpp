// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vlogic_unit.h for the primary calling header

#include "Vlogic_unit.h"
#include "Vlogic_unit__Syms.h"

//==========

void Vlogic_unit::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vlogic_unit::eval\n"); );
    Vlogic_unit__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vlogic_unit* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("rtl/logic_unit.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vlogic_unit::_eval_initial_loop(Vlogic_unit__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("rtl/logic_unit.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vlogic_unit::_combo__TOP__1(Vlogic_unit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlogic_unit::_combo__TOP__1\n"); );
    Vlogic_unit* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->res = (0xffffU & ((8U & (IData)(vlTOPp->sel))
                               ? ((4U & (IData)(vlTOPp->sel))
                                   ? ((2U & (IData)(vlTOPp->sel))
                                       ? ((1U & (IData)(vlTOPp->sel))
                                           ? (IData)(vlTOPp->in_a)
                                           : ((IData)(vlTOPp->in_a) 
                                              | (IData)(vlTOPp->in_b)))
                                       : ((1U & (IData)(vlTOPp->sel))
                                           ? ((IData)(vlTOPp->in_a) 
                                              | (~ (IData)(vlTOPp->in_b)))
                                           : 0xffffU))
                                   : ((2U & (IData)(vlTOPp->sel))
                                       ? ((1U & (IData)(vlTOPp->sel))
                                           ? ((IData)(vlTOPp->in_a) 
                                              & (IData)(vlTOPp->in_b))
                                           : (IData)(vlTOPp->in_b))
                                       : ((1U & (IData)(vlTOPp->sel))
                                           ? (~ ((IData)(vlTOPp->in_a) 
                                                 ^ (IData)(vlTOPp->in_b)))
                                           : ((~ (IData)(vlTOPp->in_a)) 
                                              | (IData)(vlTOPp->in_b)))))
                               : ((4U & (IData)(vlTOPp->sel))
                                   ? ((2U & (IData)(vlTOPp->sel))
                                       ? ((1U & (IData)(vlTOPp->sel))
                                           ? ((IData)(vlTOPp->in_a) 
                                              & (~ (IData)(vlTOPp->in_b)))
                                           : ((IData)(vlTOPp->in_a) 
                                              ^ (IData)(vlTOPp->in_b)))
                                       : ((1U & (IData)(vlTOPp->sel))
                                           ? (~ (IData)(vlTOPp->in_b))
                                           : (~ ((IData)(vlTOPp->in_a) 
                                                 & (IData)(vlTOPp->in_b)))))
                                   : ((2U & (IData)(vlTOPp->sel))
                                       ? ((1U & (IData)(vlTOPp->sel))
                                           ? 0U : (
                                                   (~ (IData)(vlTOPp->in_a)) 
                                                   & (IData)(vlTOPp->in_b)))
                                       : ((1U & (IData)(vlTOPp->sel))
                                           ? (~ ((IData)(vlTOPp->in_a) 
                                                 | (IData)(vlTOPp->in_b)))
                                           : (~ (IData)(vlTOPp->in_a)))))));
}

void Vlogic_unit::_eval(Vlogic_unit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlogic_unit::_eval\n"); );
    Vlogic_unit* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData Vlogic_unit::_change_request(Vlogic_unit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlogic_unit::_change_request\n"); );
    Vlogic_unit* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vlogic_unit::_change_request_1(Vlogic_unit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlogic_unit::_change_request_1\n"); );
    Vlogic_unit* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vlogic_unit::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlogic_unit::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((sel & 0xf0U))) {
        Verilated::overWidthError("sel");}
}
#endif  // VL_DEBUG
