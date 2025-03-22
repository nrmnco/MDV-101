// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VKEY_LOCK_SYSTEM_H_
#define _VKEY_LOCK_SYSTEM_H_  // guard

#include "verilated.h"

//==========

class Vkey_lock_system__Syms;

//----------

VL_MODULE(Vkey_lock_system) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(digit,3,0);
    VL_OUT8(locked,0,0);
    VL_OUT8(state,2,0);
    VL_OUT8(next_state,2,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*7:0*/ __Vtableidx1;
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP__rst;
    CData/*0:0*/ __Vtablechg1[256];
    static CData/*2:0*/ __Vtable1_next_state[256];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vkey_lock_system__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vkey_lock_system);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vkey_lock_system(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vkey_lock_system();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vkey_lock_system__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vkey_lock_system__Syms* symsp, bool first);
  private:
    static QData _change_request(Vkey_lock_system__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vkey_lock_system__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vkey_lock_system__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vkey_lock_system__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vkey_lock_system__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(Vkey_lock_system__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(Vkey_lock_system__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
