// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VKEY_LOCK_SYSTEM__SYMS_H_
#define _VKEY_LOCK_SYSTEM__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vkey_lock_system.h"

// SYMS CLASS
class Vkey_lock_system__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vkey_lock_system*              TOPp;
    
    // CREATORS
    Vkey_lock_system__Syms(Vkey_lock_system* topp, const char* namep);
    ~Vkey_lock_system__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
