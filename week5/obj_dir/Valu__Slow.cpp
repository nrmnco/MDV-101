// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Valu.h for the primary calling header

#include "Valu.h"
#include "Valu__Syms.h"

//==========

VL_CTOR_IMP(Valu) {
    Valu__Syms* __restrict vlSymsp = __VlSymsp = new Valu__Syms(this, name());
    Valu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Valu::__Vconfigure(Valu__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Valu::~Valu() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Valu::_settle__TOP__1(Valu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu::_settle__TOP__1\n"); );
    Valu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->cout = vlTOPp->alu__DOT__carry;
    vlTOPp->cmp = vlTOPp->alu__DOT__comp;
    vlTOPp->cmp = ((IData)(vlTOPp->in_a) == (IData)(vlTOPp->in_b));
    if ((8U & (IData)(vlTOPp->sel))) {
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
        vlTOPp->alu__DOT__lo_out = (0xffffU & ((4U 
                                                & (IData)(vlTOPp->sel))
                                                ? (
                                                   (2U 
                                                    & (IData)(vlTOPp->sel))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->sel))
                                                     ? (IData)(vlTOPp->in_a)
                                                     : 
                                                    ((IData)(vlTOPp->in_a) 
                                                     | (IData)(vlTOPp->in_b)))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->sel))
                                                     ? 
                                                    ((IData)(vlTOPp->in_a) 
                                                     | (~ (IData)(vlTOPp->in_b)))
                                                     : 0xffffU))
                                                : (
                                                   (2U 
                                                    & (IData)(vlTOPp->sel))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->sel))
                                                     ? 
                                                    ((IData)(vlTOPp->in_a) 
                                                     & (IData)(vlTOPp->in_b))
                                                     : (IData)(vlTOPp->in_b))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->sel))
                                                     ? 
                                                    (~ 
                                                     ((IData)(vlTOPp->in_a) 
                                                      ^ (IData)(vlTOPp->in_b)))
                                                     : 
                                                    ((~ (IData)(vlTOPp->in_a)) 
                                                     | (IData)(vlTOPp->in_b))))));
        vlTOPp->alu__DOT__ar_out = (0xffffU & ((4U 
                                                & (IData)(vlTOPp->sel))
                                                ? (
                                                   (2U 
                                                    & (IData)(vlTOPp->sel))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->sel))
                                                     ? 
                                                    ((IData)(vlTOPp->in_a) 
                                                     - (IData)(1U))
                                                     : 
                                                    (((IData)(vlTOPp->in_a) 
                                                      | (~ (IData)(vlTOPp->in_b))) 
                                                     + (IData)(vlTOPp->in_a)))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->sel))
                                                     ? 
                                                    (((IData)(vlTOPp->in_a) 
                                                      | (IData)(vlTOPp->in_b)) 
                                                     + (IData)(vlTOPp->in_a))
                                                     : 
                                                    ((IData)(vlTOPp->in_a) 
                                                     + (IData)(vlTOPp->in_a))))
                                                : (
                                                   (2U 
                                                    & (IData)(vlTOPp->sel))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->sel))
                                                     ? 
                                                    ((IData)(vlTOPp->in_a) 
                                                     & ((IData)(vlTOPp->in_b) 
                                                        - (IData)(1U)))
                                                     : 
                                                    ((((IData)(vlTOPp->in_a) 
                                                       | (~ (IData)(vlTOPp->in_b))) 
                                                      + (IData)(vlTOPp->in_a)) 
                                                     & (IData)(vlTOPp->in_b)))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->sel))
                                                     ? 
                                                    ((IData)(vlTOPp->in_a) 
                                                     + (IData)(vlTOPp->in_b))
                                                     : 
                                                    (((IData)(vlTOPp->in_a) 
                                                      + (IData)(vlTOPp->in_a)) 
                                                     & (IData)(vlTOPp->in_b))))));
    } else {
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
        vlTOPp->alu__DOT__lo_out = (0xffffU & ((4U 
                                                & (IData)(vlTOPp->sel))
                                                ? (
                                                   (2U 
                                                    & (IData)(vlTOPp->sel))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->sel))
                                                     ? 
                                                    ((IData)(vlTOPp->in_a) 
                                                     & (~ (IData)(vlTOPp->in_b)))
                                                     : 
                                                    ((IData)(vlTOPp->in_a) 
                                                     ^ (IData)(vlTOPp->in_b)))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->sel))
                                                     ? 
                                                    (~ (IData)(vlTOPp->in_b))
                                                     : 
                                                    (~ 
                                                     ((IData)(vlTOPp->in_a) 
                                                      & (IData)(vlTOPp->in_b)))))
                                                : (
                                                   (2U 
                                                    & (IData)(vlTOPp->sel))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->sel))
                                                     ? 0U
                                                     : 
                                                    ((~ (IData)(vlTOPp->in_a)) 
                                                     & (IData)(vlTOPp->in_b)))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->sel))
                                                     ? 
                                                    (~ 
                                                     ((IData)(vlTOPp->in_a) 
                                                      | (IData)(vlTOPp->in_b)))
                                                     : 
                                                    (~ (IData)(vlTOPp->in_a))))));
        vlTOPp->alu__DOT__ar_out = (0xffffU & ((4U 
                                                & (IData)(vlTOPp->sel))
                                                ? (
                                                   (2U 
                                                    & (IData)(vlTOPp->sel))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->sel))
                                                     ? 
                                                    ((IData)(vlTOPp->in_a) 
                                                     & ((~ (IData)(vlTOPp->in_b)) 
                                                        - (IData)(1U)))
                                                     : 
                                                    (((IData)(vlTOPp->in_a) 
                                                      - (IData)(vlTOPp->in_b)) 
                                                     - (IData)(1U)))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->sel))
                                                     ? 
                                                    (((IData)(vlTOPp->in_a) 
                                                      | (IData)(vlTOPp->in_b)) 
                                                     + 
                                                     ((IData)(vlTOPp->in_a) 
                                                      & (~ (IData)(vlTOPp->in_b))))
                                                     : 
                                                    ((IData)(vlTOPp->in_a) 
                                                     | ((IData)(vlTOPp->in_a) 
                                                        & (~ (IData)(vlTOPp->in_b))))))
                                                : (
                                                   (2U 
                                                    & (IData)(vlTOPp->sel))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->sel))
                                                     ? 0xffffU
                                                     : 
                                                    ((IData)(vlTOPp->in_a) 
                                                     | (~ (IData)(vlTOPp->in_b))))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->sel))
                                                     ? 
                                                    ((IData)(vlTOPp->in_a) 
                                                     | (IData)(vlTOPp->in_b))
                                                     : (IData)(vlTOPp->in_a)))));
    }
    vlTOPp->out = ((IData)(vlTOPp->mode) ? (IData)(vlTOPp->alu__DOT__lo_out)
                    : (IData)(vlTOPp->alu__DOT__ar_out));
}

void Valu::_eval_initial(Valu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu::_eval_initial\n"); );
    Valu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Valu::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu::final\n"); );
    // Variables
    Valu__Syms* __restrict vlSymsp = this->__VlSymsp;
    Valu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Valu::_eval_settle(Valu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu::_eval_settle\n"); );
    Valu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__1(vlSymsp);
}

void Valu::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu::_ctor_var_reset\n"); );
    // Body
    cin = VL_RAND_RESET_I(1);
    in_a = VL_RAND_RESET_I(16);
    in_b = VL_RAND_RESET_I(16);
    sel = VL_RAND_RESET_I(4);
    mode = VL_RAND_RESET_I(1);
    cout = VL_RAND_RESET_I(1);
    cmp = VL_RAND_RESET_I(1);
    out = VL_RAND_RESET_I(16);
    alu__DOT__ar_out = VL_RAND_RESET_I(16);
    alu__DOT__lo_out = VL_RAND_RESET_I(16);
    alu__DOT__carry = VL_RAND_RESET_I(1);
    alu__DOT__comp = VL_RAND_RESET_I(1);
}
