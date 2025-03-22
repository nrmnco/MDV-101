// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vlogic_unit.h for the primary calling header

#include "Vlogic_unit.h"
#include "Vlogic_unit__Syms.h"

//==========

VL_CTOR_IMP(Vlogic_unit) {
    Vlogic_unit__Syms* __restrict vlSymsp = __VlSymsp = new Vlogic_unit__Syms(this, name());
    Vlogic_unit* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vlogic_unit::__Vconfigure(Vlogic_unit__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vlogic_unit::~Vlogic_unit() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vlogic_unit::_eval_initial(Vlogic_unit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlogic_unit::_eval_initial\n"); );
    Vlogic_unit* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vlogic_unit::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlogic_unit::final\n"); );
    // Variables
    Vlogic_unit__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vlogic_unit* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vlogic_unit::_eval_settle(Vlogic_unit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlogic_unit::_eval_settle\n"); );
    Vlogic_unit* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

void Vlogic_unit::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlogic_unit::_ctor_var_reset\n"); );
    // Body
    in_a = VL_RAND_RESET_I(16);
    in_b = VL_RAND_RESET_I(16);
    sel = VL_RAND_RESET_I(4);
    res = VL_RAND_RESET_I(16);
}
