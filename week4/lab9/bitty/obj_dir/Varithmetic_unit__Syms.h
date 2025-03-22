// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VARITHMETIC_UNIT__SYMS_H_
#define _VARITHMETIC_UNIT__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Varithmetic_unit.h"

// SYMS CLASS
class Varithmetic_unit__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Varithmetic_unit*              TOPp;
    
    // CREATORS
    Varithmetic_unit__Syms(Varithmetic_unit* topp, const char* namep);
    ~Varithmetic_unit__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
