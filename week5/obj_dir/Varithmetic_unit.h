// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VARITHMETIC_UNIT_H_
#define _VARITHMETIC_UNIT_H_  // guard

#include "verilated.h"

//==========

class Varithmetic_unit__Syms;

//----------

VL_MODULE(Varithmetic_unit) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(sel,3,0);
    VL_IN8(cin,0,0);
    VL_OUT8(cout,0,0);
    VL_OUT8(cmp,0,0);
    VL_IN16(in_a,15,0);
    VL_IN16(in_b,15,0);
    VL_OUT16(res,15,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Varithmetic_unit__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Varithmetic_unit);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Varithmetic_unit(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Varithmetic_unit();
    
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
    static void _eval_initial_loop(Varithmetic_unit__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Varithmetic_unit__Syms* symsp, bool first);
  private:
    static QData _change_request(Varithmetic_unit__Syms* __restrict vlSymsp);
    static QData _change_request_1(Varithmetic_unit__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__1(Varithmetic_unit__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Varithmetic_unit__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Varithmetic_unit__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Varithmetic_unit__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
