// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VFIBONACCI_GENERATOR__SYMS_H_
#define _VFIBONACCI_GENERATOR__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vfibonacci_generator.h"

// SYMS CLASS
class Vfibonacci_generator__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vfibonacci_generator*          TOPp;
    
    // CREATORS
    Vfibonacci_generator__Syms(Vfibonacci_generator* topp, const char* namep);
    ~Vfibonacci_generator__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
