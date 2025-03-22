// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Varithmetic_unit.h for the primary calling header

#include "Varithmetic_unit.h"
#include "Varithmetic_unit__Syms.h"

//==========

VL_CTOR_IMP(Varithmetic_unit) {
    Varithmetic_unit__Syms* __restrict vlSymsp = __VlSymsp = new Varithmetic_unit__Syms(this, name());
    Varithmetic_unit* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Varithmetic_unit::__Vconfigure(Varithmetic_unit__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Varithmetic_unit::~Varithmetic_unit() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Varithmetic_unit::_eval_initial(Varithmetic_unit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Varithmetic_unit::_eval_initial\n"); );
    Varithmetic_unit* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Varithmetic_unit::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Varithmetic_unit::final\n"); );
    // Variables
    Varithmetic_unit__Syms* __restrict vlSymsp = this->__VlSymsp;
    Varithmetic_unit* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Varithmetic_unit::_eval_settle(Varithmetic_unit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Varithmetic_unit::_eval_settle\n"); );
    Varithmetic_unit* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

void Varithmetic_unit::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Varithmetic_unit::_ctor_var_reset\n"); );
    // Body
    in_a = VL_RAND_RESET_I(16);
    in_b = VL_RAND_RESET_I(16);
    sel = VL_RAND_RESET_I(4);
    cin = VL_RAND_RESET_I(1);
    res = VL_RAND_RESET_I(16);
    cout = VL_RAND_RESET_I(1);
    cmp = VL_RAND_RESET_I(1);
}
