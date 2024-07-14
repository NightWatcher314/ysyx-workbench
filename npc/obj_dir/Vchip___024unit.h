// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vchip.h for the primary calling header

#ifndef VERILATED_VCHIP___024UNIT_H_
#define VERILATED_VCHIP___024UNIT_H_  // guard

#include "verilated.h"


class Vchip__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vchip___024unit final : public VerilatedModule {
  public:

    // ENUMS (that were declared public)
    enum operation_t {
        add = 1U,
        sub = 2U,
        nop = 0U
    };

    // INTERNAL VARIABLES
    Vchip__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vchip___024unit(Vchip__Syms* symsp, const char* v__name);
    ~Vchip___024unit();
    VL_UNCOPYABLE(Vchip___024unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
