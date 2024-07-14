// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vchip.h for the primary calling header

#include "Vchip__pch.h"
#include "Vchip__Syms.h"
#include "Vchip___024unit.h"

void Vchip___024unit___ctor_var_reset(Vchip___024unit* vlSelf);

Vchip___024unit::Vchip___024unit(Vchip__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vchip___024unit___ctor_var_reset(this);
}

void Vchip___024unit::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vchip___024unit::~Vchip___024unit() {
}
