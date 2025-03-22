// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vand_gate.h for the primary calling header

#include "Vand_gate.h"
#include "Vand_gate__Syms.h"

//==========

VL_CTOR_IMP(Vand_gate) {
    Vand_gate__Syms* __restrict vlSymsp = __VlSymsp = new Vand_gate__Syms(this, name());
    Vand_gate* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vand_gate::__Vconfigure(Vand_gate__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vand_gate::~Vand_gate() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vand_gate::_eval_initial(Vand_gate__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vand_gate::_eval_initial\n"); );
    Vand_gate* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vand_gate::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vand_gate::final\n"); );
    // Variables
    Vand_gate__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vand_gate* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vand_gate::_eval_settle(Vand_gate__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vand_gate::_eval_settle\n"); );
    Vand_gate* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

void Vand_gate::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vand_gate::_ctor_var_reset\n"); );
    // Body
    a = VL_RAND_RESET_I(1);
    b = VL_RAND_RESET_I(1);
    y = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<1; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
