// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vchip.h for the primary calling header

#ifndef VERILATED_VCHIP___024ROOT_H_
#define VERILATED_VCHIP___024ROOT_H_  // guard

#include "verilated.h"
class Vchip___024unit;


class Vchip__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vchip___024root final : public VerilatedModule {
  public:
    // CELLS
    Vchip___024unit* __PVT____024unit;

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(op_in,1,0);
    VL_IN8(a_in,7,0);
    VL_IN8(b_in,7,0);
    VL_IN8(in_valid,0,0);
    VL_OUT8(out,7,0);
    VL_OUT8(out_valid,0,0);
    CData/*1:0*/ chip__DOT__op_in_r;
    CData/*7:0*/ chip__DOT__a_in_r;
    CData/*7:0*/ chip__DOT__b_in_r;
    CData/*0:0*/ chip__DOT__in_valid_r;
    CData/*7:0*/ chip__DOT__result;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vchip__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vchip___024root(Vchip__Syms* symsp, const char* v__name);
    ~Vchip___024root();
    VL_UNCOPYABLE(Vchip___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
