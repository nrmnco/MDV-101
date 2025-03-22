// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcontrol_unit.h for the primary calling header

#include "Vcontrol_unit.h"
#include "Vcontrol_unit__Syms.h"

//==========

VL_CTOR_IMP(Vcontrol_unit) {
    Vcontrol_unit__Syms* __restrict vlSymsp = __VlSymsp = new Vcontrol_unit__Syms(this, name());
    Vcontrol_unit* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vcontrol_unit::__Vconfigure(Vcontrol_unit__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vcontrol_unit::~Vcontrol_unit() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vcontrol_unit::_settle__TOP__2(Vcontrol_unit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_unit::_settle__TOP__2\n"); );
    Vcontrol_unit* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->control_unit__DOT__next_state = ((2U & (IData)(vlTOPp->control_unit__DOT__state))
                                              ? ((1U 
                                                  & (IData)(vlTOPp->control_unit__DOT__state))
                                                  ? 0U
                                                  : 3U)
                                              : ((1U 
                                                  & (IData)(vlTOPp->control_unit__DOT__state))
                                                  ? 2U
                                                  : 1U));
    if ((2U & (IData)(vlTOPp->control_unit__DOT__state))) {
        if ((1U & (IData)(vlTOPp->control_unit__DOT__state))) {
            vlTOPp->done = 1U;
        }
    } else {
        if ((1U & (~ (IData)(vlTOPp->control_unit__DOT__state)))) {
            vlTOPp->done = 0U;
        }
    }
    vlTOPp->en_c = (1U & (((IData)(vlTOPp->control_unit__DOT__state) 
                           >> 1U) & (~ (IData)(vlTOPp->control_unit__DOT__state))));
    vlTOPp->en_i = (1U & ((~ ((IData)(vlTOPp->control_unit__DOT__state) 
                              >> 1U)) & (~ (IData)(vlTOPp->control_unit__DOT__state))));
    vlTOPp->en_s = (1U & ((~ ((IData)(vlTOPp->control_unit__DOT__state) 
                              >> 1U)) & (IData)(vlTOPp->control_unit__DOT__state)));
    if ((2U & (IData)(vlTOPp->control_unit__DOT__state))) {
        if ((1U & (IData)(vlTOPp->control_unit__DOT__state))) {
            vlTOPp->en_6 = 0U;
            if ((0x8000U & (IData)(vlTOPp->d_in))) {
                if ((0x4000U & (IData)(vlTOPp->d_in))) {
                    if ((1U & (~ ((IData)(vlTOPp->d_in) 
                                  >> 0xdU)))) {
                        vlTOPp->en_6 = 1U;
                    }
                }
            }
        }
    } else {
        if ((1U & (~ (IData)(vlTOPp->control_unit__DOT__state)))) {
            vlTOPp->en_6 = 0U;
        }
    }
    if ((2U & (IData)(vlTOPp->control_unit__DOT__state))) {
        if ((1U & (IData)(vlTOPp->control_unit__DOT__state))) {
            vlTOPp->en_5 = 0U;
            if ((0x8000U & (IData)(vlTOPp->d_in))) {
                if ((1U & (~ ((IData)(vlTOPp->d_in) 
                              >> 0xeU)))) {
                    if ((0x2000U & (IData)(vlTOPp->d_in))) {
                        vlTOPp->en_5 = 1U;
                    }
                }
            }
        }
    } else {
        if ((1U & (~ (IData)(vlTOPp->control_unit__DOT__state)))) {
            vlTOPp->en_5 = 0U;
        }
    }
    if ((2U & (IData)(vlTOPp->control_unit__DOT__state))) {
        if ((1U & (~ (IData)(vlTOPp->control_unit__DOT__state)))) {
            vlTOPp->alu_mode = (1U & ((IData)(vlTOPp->d_in) 
                                      >> 2U));
        }
    }
    if ((2U & (IData)(vlTOPp->control_unit__DOT__state))) {
        if ((1U & (IData)(vlTOPp->control_unit__DOT__state))) {
            vlTOPp->en_4 = 0U;
            if ((0x8000U & (IData)(vlTOPp->d_in))) {
                if ((1U & (~ ((IData)(vlTOPp->d_in) 
                              >> 0xeU)))) {
                    if ((1U & (~ ((IData)(vlTOPp->d_in) 
                                  >> 0xdU)))) {
                        vlTOPp->en_4 = 1U;
                    }
                }
            }
        }
    } else {
        if ((1U & (~ (IData)(vlTOPp->control_unit__DOT__state)))) {
            vlTOPp->en_4 = 0U;
        }
    }
    if ((2U & (IData)(vlTOPp->control_unit__DOT__state))) {
        if ((1U & (~ (IData)(vlTOPp->control_unit__DOT__state)))) {
            vlTOPp->alu_sel = (0xfU & ((IData)(vlTOPp->d_in) 
                                       >> 3U));
        }
    }
    if ((2U & (IData)(vlTOPp->control_unit__DOT__state))) {
        if ((1U & (IData)(vlTOPp->control_unit__DOT__state))) {
            vlTOPp->en_3 = 0U;
            if ((1U & (~ ((IData)(vlTOPp->d_in) >> 0xfU)))) {
                if ((0x4000U & (IData)(vlTOPp->d_in))) {
                    if ((0x2000U & (IData)(vlTOPp->d_in))) {
                        vlTOPp->en_3 = 1U;
                    }
                }
            }
        }
    } else {
        if ((1U & (~ (IData)(vlTOPp->control_unit__DOT__state)))) {
            vlTOPp->en_3 = 0U;
        }
    }
    if ((2U & (IData)(vlTOPp->control_unit__DOT__state))) {
        if ((1U & (~ (IData)(vlTOPp->control_unit__DOT__state)))) {
            vlTOPp->mux_sel = (7U & ((IData)(vlTOPp->d_in) 
                                     >> 0xaU));
        }
    } else {
        if ((1U & (IData)(vlTOPp->control_unit__DOT__state))) {
            vlTOPp->mux_sel = (7U & ((IData)(vlTOPp->d_in) 
                                     >> 0xdU));
        }
    }
    if ((2U & (IData)(vlTOPp->control_unit__DOT__state))) {
        if ((1U & (IData)(vlTOPp->control_unit__DOT__state))) {
            vlTOPp->en_0 = 0U;
            if ((1U & (~ ((IData)(vlTOPp->d_in) >> 0xfU)))) {
                if ((1U & (~ ((IData)(vlTOPp->d_in) 
                              >> 0xeU)))) {
                    if ((1U & (~ ((IData)(vlTOPp->d_in) 
                                  >> 0xdU)))) {
                        vlTOPp->en_0 = 1U;
                    }
                }
            }
        }
    } else {
        if ((1U & (~ (IData)(vlTOPp->control_unit__DOT__state)))) {
            vlTOPp->en_0 = 0U;
        }
    }
    if ((2U & (IData)(vlTOPp->control_unit__DOT__state))) {
        if ((1U & (IData)(vlTOPp->control_unit__DOT__state))) {
            vlTOPp->en_2 = 0U;
            if ((1U & (~ ((IData)(vlTOPp->d_in) >> 0xfU)))) {
                if ((0x4000U & (IData)(vlTOPp->d_in))) {
                    if ((1U & (~ ((IData)(vlTOPp->d_in) 
                                  >> 0xdU)))) {
                        vlTOPp->en_2 = 1U;
                    }
                }
            }
        }
    } else {
        if ((1U & (~ (IData)(vlTOPp->control_unit__DOT__state)))) {
            vlTOPp->en_2 = 0U;
        }
    }
    if ((2U & (IData)(vlTOPp->control_unit__DOT__state))) {
        if ((1U & (IData)(vlTOPp->control_unit__DOT__state))) {
            vlTOPp->en_1 = 0U;
            if ((1U & (~ ((IData)(vlTOPp->d_in) >> 0xfU)))) {
                if ((1U & (~ ((IData)(vlTOPp->d_in) 
                              >> 0xeU)))) {
                    if ((0x2000U & (IData)(vlTOPp->d_in))) {
                        vlTOPp->en_1 = 1U;
                    }
                }
            }
        }
    } else {
        if ((1U & (~ (IData)(vlTOPp->control_unit__DOT__state)))) {
            vlTOPp->en_1 = 0U;
        }
    }
    if ((2U & (IData)(vlTOPp->control_unit__DOT__state))) {
        if ((1U & (IData)(vlTOPp->control_unit__DOT__state))) {
            vlTOPp->en_7 = 0U;
            if ((0x8000U & (IData)(vlTOPp->d_in))) {
                if ((0x4000U & (IData)(vlTOPp->d_in))) {
                    if ((0x2000U & (IData)(vlTOPp->d_in))) {
                        vlTOPp->en_7 = 1U;
                    }
                }
            }
        }
    } else {
        if ((1U & (~ (IData)(vlTOPp->control_unit__DOT__state)))) {
            vlTOPp->en_7 = 0U;
        }
    }
}

void Vcontrol_unit::_eval_initial(Vcontrol_unit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_unit::_eval_initial\n"); );
    Vcontrol_unit* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
}

void Vcontrol_unit::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_unit::final\n"); );
    // Variables
    Vcontrol_unit__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vcontrol_unit* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vcontrol_unit::_eval_settle(Vcontrol_unit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_unit::_eval_settle\n"); );
    Vcontrol_unit* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

void Vcontrol_unit::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcontrol_unit::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    d_in = VL_RAND_RESET_I(16);
    run = VL_RAND_RESET_I(1);
    alu_sel = VL_RAND_RESET_I(4);
    alu_mode = VL_RAND_RESET_I(1);
    mux_sel = VL_RAND_RESET_I(3);
    en_s = VL_RAND_RESET_I(1);
    en_c = VL_RAND_RESET_I(1);
    en_0 = VL_RAND_RESET_I(1);
    en_1 = VL_RAND_RESET_I(1);
    en_2 = VL_RAND_RESET_I(1);
    en_3 = VL_RAND_RESET_I(1);
    en_4 = VL_RAND_RESET_I(1);
    en_5 = VL_RAND_RESET_I(1);
    en_6 = VL_RAND_RESET_I(1);
    en_7 = VL_RAND_RESET_I(1);
    en_i = VL_RAND_RESET_I(1);
    done = VL_RAND_RESET_I(1);
    control_unit__DOT__state = VL_RAND_RESET_I(2);
    control_unit__DOT__next_state = VL_RAND_RESET_I(2);
}
