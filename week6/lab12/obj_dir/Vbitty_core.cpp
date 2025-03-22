// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbitty_core.h for the primary calling header

#include "Vbitty_core.h"
#include "Vbitty_core__Syms.h"

//==========

void Vbitty_core::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vbitty_core::eval\n"); );
    Vbitty_core__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vbitty_core* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("rtl/bitty_core.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vbitty_core::_eval_initial_loop(Vbitty_core__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("rtl/bitty_core.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vbitty_core::_sequent__TOP__1(Vbitty_core__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core::_sequent__TOP__1\n"); );
    Vbitty_core* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->reset) {
        vlTOPp->reg_s_out = 0U;
    } else {
        if (vlTOPp->bitty_core__DOT__en_s) {
            vlTOPp->reg_s_out = vlTOPp->mux_out;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->reg7_out = 0U;
    } else {
        if (vlTOPp->bitty_core__DOT__en_7) {
            vlTOPp->reg7_out = vlTOPp->reg_c_out;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->reg6_out = 0U;
    } else {
        if (vlTOPp->bitty_core__DOT__en_6) {
            vlTOPp->reg6_out = vlTOPp->reg_c_out;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->reg5_out = 0U;
    } else {
        if (vlTOPp->bitty_core__DOT__en_5) {
            vlTOPp->reg5_out = vlTOPp->reg_c_out;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->reg4_out = 0U;
    } else {
        if (vlTOPp->bitty_core__DOT__en_4) {
            vlTOPp->reg4_out = vlTOPp->reg_c_out;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->reg3_out = 0U;
    } else {
        if (vlTOPp->bitty_core__DOT__en_3) {
            vlTOPp->reg3_out = vlTOPp->reg_c_out;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->reg2_out = 0U;
    } else {
        if (vlTOPp->bitty_core__DOT__en_2) {
            vlTOPp->reg2_out = vlTOPp->reg_c_out;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->reg1_out = 0U;
    } else {
        if (vlTOPp->bitty_core__DOT__en_1) {
            vlTOPp->reg1_out = vlTOPp->reg_c_out;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->reg0_out = 0U;
    } else {
        if (vlTOPp->bitty_core__DOT__en_0) {
            vlTOPp->reg0_out = vlTOPp->reg_c_out;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->reg_instr_out = 0U;
    } else {
        if (vlTOPp->bitty_core__DOT__en_i) {
            vlTOPp->reg_instr_out = vlTOPp->instruction;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->bitty_core__DOT__control_inst__DOT__state = 0U;
    } else {
        if (vlTOPp->run) {
            vlTOPp->bitty_core__DOT__control_inst__DOT__state 
                = vlTOPp->bitty_core__DOT__control_inst__DOT__next_state;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->reg_c_out = 0U;
    } else {
        if (vlTOPp->bitty_core__DOT__en_c) {
            vlTOPp->reg_c_out = vlTOPp->alu_out;
        }
    }
    vlTOPp->bitty_core__DOT__control_inst__DOT__next_state 
        = ((2U & (IData)(vlTOPp->bitty_core__DOT__control_inst__DOT__state))
            ? ((1U & (IData)(vlTOPp->bitty_core__DOT__control_inst__DOT__state))
                ? 0U : 3U) : ((1U & (IData)(vlTOPp->bitty_core__DOT__control_inst__DOT__state))
                               ? 2U : 1U));
    if ((2U & (IData)(vlTOPp->bitty_core__DOT__control_inst__DOT__state))) {
        if ((1U & (IData)(vlTOPp->bitty_core__DOT__control_inst__DOT__state))) {
            vlTOPp->done = 1U;
        }
    } else {
        if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__control_inst__DOT__state)))) {
            vlTOPp->done = 0U;
        }
    }
    vlTOPp->bitty_core__DOT__en_i = (1U & ((~ ((IData)(vlTOPp->bitty_core__DOT__control_inst__DOT__state) 
                                               >> 1U)) 
                                           & (~ (IData)(vlTOPp->bitty_core__DOT__control_inst__DOT__state))));
    vlTOPp->bitty_core__DOT__en_s = (1U & ((~ ((IData)(vlTOPp->bitty_core__DOT__control_inst__DOT__state) 
                                               >> 1U)) 
                                           & (IData)(vlTOPp->bitty_core__DOT__control_inst__DOT__state)));
    if ((2U & (IData)(vlTOPp->bitty_core__DOT__control_inst__DOT__state))) {
        if ((1U & (IData)(vlTOPp->bitty_core__DOT__control_inst__DOT__state))) {
            vlTOPp->bitty_core__DOT__en_6 = 0U;
            if ((0x8000U & (IData)(vlTOPp->reg_instr_out))) {
                if ((0x4000U & (IData)(vlTOPp->reg_instr_out))) {
                    if ((1U & (~ ((IData)(vlTOPp->reg_instr_out) 
                                  >> 0xdU)))) {
                        vlTOPp->bitty_core__DOT__en_6 = 1U;
                    }
                }
            }
        }
    } else {
        if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__control_inst__DOT__state)))) {
            vlTOPp->bitty_core__DOT__en_6 = 0U;
        }
    }
    if ((2U & (IData)(vlTOPp->bitty_core__DOT__control_inst__DOT__state))) {
        if ((1U & (IData)(vlTOPp->bitty_core__DOT__control_inst__DOT__state))) {
            vlTOPp->bitty_core__DOT__en_5 = 0U;
            if ((0x8000U & (IData)(vlTOPp->reg_instr_out))) {
                if ((1U & (~ ((IData)(vlTOPp->reg_instr_out) 
                              >> 0xeU)))) {
                    if ((0x2000U & (IData)(vlTOPp->reg_instr_out))) {
                        vlTOPp->bitty_core__DOT__en_5 = 1U;
                    }
                }
            }
        }
    } else {
        if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__control_inst__DOT__state)))) {
            vlTOPp->bitty_core__DOT__en_5 = 0U;
        }
    }
    if ((2U & (IData)(vlTOPp->bitty_core__DOT__control_inst__DOT__state))) {
        if ((1U & (IData)(vlTOPp->bitty_core__DOT__control_inst__DOT__state))) {
            vlTOPp->bitty_core__DOT__en_4 = 0U;
            if ((0x8000U & (IData)(vlTOPp->reg_instr_out))) {
                if ((1U & (~ ((IData)(vlTOPp->reg_instr_out) 
                              >> 0xeU)))) {
                    if ((1U & (~ ((IData)(vlTOPp->reg_instr_out) 
                                  >> 0xdU)))) {
                        vlTOPp->bitty_core__DOT__en_4 = 1U;
                    }
                }
            }
        }
    } else {
        if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__control_inst__DOT__state)))) {
            vlTOPp->bitty_core__DOT__en_4 = 0U;
        }
    }
    if ((2U & (IData)(vlTOPp->bitty_core__DOT__control_inst__DOT__state))) {
        if ((1U & (IData)(vlTOPp->bitty_core__DOT__control_inst__DOT__state))) {
            vlTOPp->bitty_core__DOT__en_3 = 0U;
            if ((1U & (~ ((IData)(vlTOPp->reg_instr_out) 
                          >> 0xfU)))) {
                if ((0x4000U & (IData)(vlTOPp->reg_instr_out))) {
                    if ((0x2000U & (IData)(vlTOPp->reg_instr_out))) {
                        vlTOPp->bitty_core__DOT__en_3 = 1U;
                    }
                }
            }
        }
    } else {
        if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__control_inst__DOT__state)))) {
            vlTOPp->bitty_core__DOT__en_3 = 0U;
        }
    }
    if ((2U & (IData)(vlTOPp->bitty_core__DOT__control_inst__DOT__state))) {
        if ((1U & (IData)(vlTOPp->bitty_core__DOT__control_inst__DOT__state))) {
            vlTOPp->bitty_core__DOT__en_0 = 0U;
            if ((1U & (~ ((IData)(vlTOPp->reg_instr_out) 
                          >> 0xfU)))) {
                if ((1U & (~ ((IData)(vlTOPp->reg_instr_out) 
                              >> 0xeU)))) {
                    if ((1U & (~ ((IData)(vlTOPp->reg_instr_out) 
                                  >> 0xdU)))) {
                        vlTOPp->bitty_core__DOT__en_0 = 1U;
                    }
                }
            }
        }
    } else {
        if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__control_inst__DOT__state)))) {
            vlTOPp->bitty_core__DOT__en_0 = 0U;
        }
    }
    if ((2U & (IData)(vlTOPp->bitty_core__DOT__control_inst__DOT__state))) {
        if ((1U & (IData)(vlTOPp->bitty_core__DOT__control_inst__DOT__state))) {
            vlTOPp->bitty_core__DOT__en_2 = 0U;
            if ((1U & (~ ((IData)(vlTOPp->reg_instr_out) 
                          >> 0xfU)))) {
                if ((0x4000U & (IData)(vlTOPp->reg_instr_out))) {
                    if ((1U & (~ ((IData)(vlTOPp->reg_instr_out) 
                                  >> 0xdU)))) {
                        vlTOPp->bitty_core__DOT__en_2 = 1U;
                    }
                }
            }
        }
    } else {
        if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__control_inst__DOT__state)))) {
            vlTOPp->bitty_core__DOT__en_2 = 0U;
        }
    }
    if ((2U & (IData)(vlTOPp->bitty_core__DOT__control_inst__DOT__state))) {
        if ((1U & (IData)(vlTOPp->bitty_core__DOT__control_inst__DOT__state))) {
            vlTOPp->bitty_core__DOT__en_1 = 0U;
            if ((1U & (~ ((IData)(vlTOPp->reg_instr_out) 
                          >> 0xfU)))) {
                if ((1U & (~ ((IData)(vlTOPp->reg_instr_out) 
                              >> 0xeU)))) {
                    if ((0x2000U & (IData)(vlTOPp->reg_instr_out))) {
                        vlTOPp->bitty_core__DOT__en_1 = 1U;
                    }
                }
            }
        }
    } else {
        if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__control_inst__DOT__state)))) {
            vlTOPp->bitty_core__DOT__en_1 = 0U;
        }
    }
    if ((2U & (IData)(vlTOPp->bitty_core__DOT__control_inst__DOT__state))) {
        if ((1U & (IData)(vlTOPp->bitty_core__DOT__control_inst__DOT__state))) {
            vlTOPp->bitty_core__DOT__en_7 = 0U;
            if ((0x8000U & (IData)(vlTOPp->reg_instr_out))) {
                if ((0x4000U & (IData)(vlTOPp->reg_instr_out))) {
                    if ((0x2000U & (IData)(vlTOPp->reg_instr_out))) {
                        vlTOPp->bitty_core__DOT__en_7 = 1U;
                    }
                }
            }
        }
    } else {
        if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__control_inst__DOT__state)))) {
            vlTOPp->bitty_core__DOT__en_7 = 0U;
        }
    }
    if ((2U & (IData)(vlTOPp->bitty_core__DOT__control_inst__DOT__state))) {
        if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__control_inst__DOT__state)))) {
            vlTOPp->bitty_core__DOT__alu_sel = (7U 
                                                & ((IData)(vlTOPp->reg_instr_out) 
                                                   >> 2U));
        }
    }
    if ((2U & (IData)(vlTOPp->bitty_core__DOT__control_inst__DOT__state))) {
        if ((1U & (~ (IData)(vlTOPp->bitty_core__DOT__control_inst__DOT__state)))) {
            vlTOPp->bitty_core__DOT__mux_sel = (7U 
                                                & ((IData)(vlTOPp->reg_instr_out) 
                                                   >> 0xaU));
        }
    } else {
        if ((1U & (IData)(vlTOPp->bitty_core__DOT__control_inst__DOT__state))) {
            vlTOPp->bitty_core__DOT__mux_sel = (7U 
                                                & ((IData)(vlTOPp->reg_instr_out) 
                                                   >> 0xdU));
        }
    }
    vlTOPp->bitty_core__DOT__en_c = (1U & (((IData)(vlTOPp->bitty_core__DOT__control_inst__DOT__state) 
                                            >> 1U) 
                                           & (~ (IData)(vlTOPp->bitty_core__DOT__control_inst__DOT__state))));
    vlTOPp->mux_out = ((4U & (IData)(vlTOPp->bitty_core__DOT__mux_sel))
                        ? ((2U & (IData)(vlTOPp->bitty_core__DOT__mux_sel))
                            ? ((1U & (IData)(vlTOPp->bitty_core__DOT__mux_sel))
                                ? (IData)(vlTOPp->reg7_out)
                                : (IData)(vlTOPp->reg6_out))
                            : ((1U & (IData)(vlTOPp->bitty_core__DOT__mux_sel))
                                ? (IData)(vlTOPp->reg5_out)
                                : (IData)(vlTOPp->reg4_out)))
                        : ((2U & (IData)(vlTOPp->bitty_core__DOT__mux_sel))
                            ? ((1U & (IData)(vlTOPp->bitty_core__DOT__mux_sel))
                                ? (IData)(vlTOPp->reg3_out)
                                : (IData)(vlTOPp->reg2_out))
                            : ((1U & (IData)(vlTOPp->bitty_core__DOT__mux_sel))
                                ? (IData)(vlTOPp->reg1_out)
                                : (IData)(vlTOPp->reg0_out))));
    vlTOPp->alu_out = (0xffffU & ((4U & (IData)(vlTOPp->bitty_core__DOT__alu_sel))
                                   ? ((2U & (IData)(vlTOPp->bitty_core__DOT__alu_sel))
                                       ? ((1U & (IData)(vlTOPp->bitty_core__DOT__alu_sel))
                                           ? (((IData)(vlTOPp->reg_s_out) 
                                               == (IData)(vlTOPp->mux_out))
                                               ? 0xffffU
                                               : 0U)
                                           : ((0xfU 
                                               >= (IData)(vlTOPp->mux_out))
                                               ? ((IData)(vlTOPp->reg_s_out) 
                                                  >> (IData)(vlTOPp->mux_out))
                                               : 0U))
                                       : ((1U & (IData)(vlTOPp->bitty_core__DOT__alu_sel))
                                           ? ((0xfU 
                                               >= (IData)(vlTOPp->mux_out))
                                               ? ((IData)(vlTOPp->reg_s_out) 
                                                  << (IData)(vlTOPp->mux_out))
                                               : 0U)
                                           : ((IData)(vlTOPp->reg_s_out) 
                                              ^ (IData)(vlTOPp->mux_out))))
                                   : ((2U & (IData)(vlTOPp->bitty_core__DOT__alu_sel))
                                       ? ((1U & (IData)(vlTOPp->bitty_core__DOT__alu_sel))
                                           ? ((IData)(vlTOPp->reg_s_out) 
                                              | (IData)(vlTOPp->mux_out))
                                           : ((IData)(vlTOPp->reg_s_out) 
                                              & (IData)(vlTOPp->mux_out)))
                                       : ((1U & (IData)(vlTOPp->bitty_core__DOT__alu_sel))
                                           ? ((IData)(vlTOPp->reg_s_out) 
                                              - (IData)(vlTOPp->mux_out))
                                           : ((IData)(vlTOPp->reg_s_out) 
                                              + (IData)(vlTOPp->mux_out))))));
}

void Vbitty_core::_eval(Vbitty_core__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core::_eval\n"); );
    Vbitty_core* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
}

VL_INLINE_OPT QData Vbitty_core::_change_request(Vbitty_core__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core::_change_request\n"); );
    Vbitty_core* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vbitty_core::_change_request_1(Vbitty_core__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core::_change_request_1\n"); );
    Vbitty_core* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vbitty_core::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((run & 0xfeU))) {
        Verilated::overWidthError("run");}
}
#endif  // VL_DEBUG
