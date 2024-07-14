// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vchip.h for the primary calling header

#include "Vchip__pch.h"
#include "Vchip___024root.h"

VL_ATTR_COLD void Vchip___024root___eval_static(Vchip___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vchip__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vchip___024root___eval_initial(Vchip___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vchip__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__rst__0 = vlSelf->rst;
}

VL_ATTR_COLD void Vchip___024root___eval_final(Vchip___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vchip__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vchip___024root___dump_triggers__stl(Vchip___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vchip___024root___eval_phase__stl(Vchip___024root* vlSelf);

VL_ATTR_COLD void Vchip___024root___eval_settle(Vchip___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vchip__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vchip___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("vsrc/chip.v", 7, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vchip___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vchip___024root___dump_triggers__stl(Vchip___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vchip__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ vlSelf->__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vchip___024root___stl_sequent__TOP__0(Vchip___024root* vlSelf);

VL_ATTR_COLD void Vchip___024root___eval_stl(Vchip___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vchip__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vchip___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

VL_ATTR_COLD void Vchip___024root___stl_sequent__TOP__0(Vchip___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vchip__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->chip__DOT__result = 0U;
    if (vlSelf->chip__DOT__in_valid_r) {
        vlSelf->chip__DOT__result = (0xffU & ((1U == (IData)(vlSelf->chip__DOT__op_in_r))
                                               ? ((IData)(vlSelf->chip__DOT__a_in_r) 
                                                  + (IData)(vlSelf->chip__DOT__b_in_r))
                                               : ((2U 
                                                   == (IData)(vlSelf->chip__DOT__op_in_r))
                                                   ? 
                                                  ((IData)(1U) 
                                                   + 
                                                   ((IData)(vlSelf->chip__DOT__a_in_r) 
                                                    + 
                                                    (~ (IData)(vlSelf->chip__DOT__b_in_r))))
                                                   : 0U)));
    }
}

VL_ATTR_COLD void Vchip___024root___eval_triggers__stl(Vchip___024root* vlSelf);

VL_ATTR_COLD bool Vchip___024root___eval_phase__stl(Vchip___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vchip__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vchip___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vchip___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vchip___024root___dump_triggers__act(Vchip___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vchip__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ vlSelf->__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk or posedge rst)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vchip___024root___dump_triggers__nba(Vchip___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vchip__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ vlSelf->__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk or posedge rst)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vchip___024root___ctor_var_reset(Vchip___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vchip__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->op_in = VL_RAND_RESET_I(2);
    vlSelf->a_in = VL_RAND_RESET_I(8);
    vlSelf->b_in = VL_RAND_RESET_I(8);
    vlSelf->in_valid = VL_RAND_RESET_I(1);
    vlSelf->out = VL_RAND_RESET_I(8);
    vlSelf->out_valid = VL_RAND_RESET_I(1);
    vlSelf->chip__DOT__op_in_r = VL_RAND_RESET_I(2);
    vlSelf->chip__DOT__a_in_r = VL_RAND_RESET_I(8);
    vlSelf->chip__DOT__b_in_r = VL_RAND_RESET_I(8);
    vlSelf->chip__DOT__in_valid_r = VL_RAND_RESET_I(1);
    vlSelf->chip__DOT__result = VL_RAND_RESET_I(8);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
