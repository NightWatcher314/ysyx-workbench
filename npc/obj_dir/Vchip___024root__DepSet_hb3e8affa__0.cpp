// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vchip.h for the primary calling header

#include "Vchip__pch.h"
#include "Vchip___024root.h"

void Vchip___024root___eval_act(Vchip___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vchip__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip___024root___eval_act\n"); );
}

void Vchip___024root___nba_sequent__TOP__0(Vchip___024root* vlSelf);

void Vchip___024root___eval_nba(Vchip___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vchip__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vchip___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

VL_INLINE_OPT void Vchip___024root___nba_sequent__TOP__0(Vchip___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vchip__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip___024root___nba_sequent__TOP__0\n"); );
    // Body
    if (vlSelf->rst) {
        vlSelf->out = 0U;
        vlSelf->chip__DOT__b_in_r = 0U;
        vlSelf->chip__DOT__a_in_r = 0U;
        vlSelf->chip__DOT__op_in_r = 0U;
    } else {
        vlSelf->out = vlSelf->chip__DOT__result;
        vlSelf->chip__DOT__b_in_r = vlSelf->b_in;
        vlSelf->chip__DOT__a_in_r = vlSelf->a_in;
        vlSelf->chip__DOT__op_in_r = vlSelf->op_in;
    }
    vlSelf->out_valid = ((1U & (~ (IData)(vlSelf->rst))) 
                         && (IData)(vlSelf->chip__DOT__in_valid_r));
    vlSelf->chip__DOT__in_valid_r = ((1U & (~ (IData)(vlSelf->rst))) 
                                     && (IData)(vlSelf->in_valid));
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

void Vchip___024root___eval_triggers__act(Vchip___024root* vlSelf);

bool Vchip___024root___eval_phase__act(Vchip___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vchip__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vchip___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vchip___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vchip___024root___eval_phase__nba(Vchip___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vchip__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vchip___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vchip___024root___dump_triggers__nba(Vchip___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vchip___024root___dump_triggers__act(Vchip___024root* vlSelf);
#endif  // VL_DEBUG

void Vchip___024root___eval(Vchip___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vchip__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vchip___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("vsrc/chip.v", 7, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vchip___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("vsrc/chip.v", 7, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vchip___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vchip___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vchip___024root___eval_debug_assertions(Vchip___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vchip__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->op_in & 0xfcU))) {
        Verilated::overWidthError("op_in");}
    if (VL_UNLIKELY((vlSelf->in_valid & 0xfeU))) {
        Verilated::overWidthError("in_valid");}
}
#endif  // VL_DEBUG
