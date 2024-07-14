// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vchip.h for the primary calling header

#include "Vchip__pch.h"
#include "Vchip__Syms.h"
#include "Vchip___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vchip___024root___dump_triggers__act(Vchip___024root* vlSelf);
#endif  // VL_DEBUG

void Vchip___024root___eval_triggers__act(Vchip___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vchip__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchip___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, (((IData)(vlSelf->clk) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clk__0))) 
                                     | ((IData)(vlSelf->rst) 
                                        & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__rst__0)))));
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__rst__0 = vlSelf->rst;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vchip___024root___dump_triggers__act(vlSelf);
    }
#endif
}
