// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbitty_core.h for the primary calling header

#include "Vbitty_core.h"
#include "Vbitty_core__Syms.h"

//==========

VL_CTOR_IMP(Vbitty_core) {
    Vbitty_core__Syms* __restrict vlSymsp = __VlSymsp = new Vbitty_core__Syms(this, name());
    Vbitty_core* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vbitty_core::__Vconfigure(Vbitty_core__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vbitty_core::~Vbitty_core() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vbitty_core::_settle__TOP__2(Vbitty_core__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core::_settle__TOP__2\n"); );
    Vbitty_core* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
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

void Vbitty_core::_eval_initial(Vbitty_core__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core::_eval_initial\n"); );
    Vbitty_core* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
}

void Vbitty_core::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core::final\n"); );
    // Variables
    Vbitty_core__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vbitty_core* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vbitty_core::_eval_settle(Vbitty_core__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core::_eval_settle\n"); );
    Vbitty_core* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

void Vbitty_core::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbitty_core::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    instruction = VL_RAND_RESET_I(16);
    run = VL_RAND_RESET_I(1);
    done = VL_RAND_RESET_I(1);
    reg_instr_out = VL_RAND_RESET_I(16);
    reg_s_out = VL_RAND_RESET_I(16);
    reg_c_out = VL_RAND_RESET_I(16);
    reg0_out = VL_RAND_RESET_I(16);
    reg1_out = VL_RAND_RESET_I(16);
    reg2_out = VL_RAND_RESET_I(16);
    reg3_out = VL_RAND_RESET_I(16);
    reg4_out = VL_RAND_RESET_I(16);
    reg5_out = VL_RAND_RESET_I(16);
    reg6_out = VL_RAND_RESET_I(16);
    reg7_out = VL_RAND_RESET_I(16);
    mux_out = VL_RAND_RESET_I(16);
    alu_out = VL_RAND_RESET_I(16);
    bitty_core__DOT__en_i = VL_RAND_RESET_I(1);
    bitty_core__DOT__en_s = VL_RAND_RESET_I(1);
    bitty_core__DOT__en_c = VL_RAND_RESET_I(1);
    bitty_core__DOT__en_0 = VL_RAND_RESET_I(1);
    bitty_core__DOT__en_1 = VL_RAND_RESET_I(1);
    bitty_core__DOT__en_2 = VL_RAND_RESET_I(1);
    bitty_core__DOT__en_3 = VL_RAND_RESET_I(1);
    bitty_core__DOT__en_4 = VL_RAND_RESET_I(1);
    bitty_core__DOT__en_5 = VL_RAND_RESET_I(1);
    bitty_core__DOT__en_6 = VL_RAND_RESET_I(1);
    bitty_core__DOT__en_7 = VL_RAND_RESET_I(1);
    bitty_core__DOT__alu_sel = VL_RAND_RESET_I(3);
    bitty_core__DOT__mux_sel = VL_RAND_RESET_I(3);
    bitty_core__DOT__control_inst__DOT__state = VL_RAND_RESET_I(2);
    bitty_core__DOT__control_inst__DOT__next_state = VL_RAND_RESET_I(2);
}
