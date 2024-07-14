// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vchip__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vchip::Vchip(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vchip__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , op_in{vlSymsp->TOP.op_in}
    , a_in{vlSymsp->TOP.a_in}
    , b_in{vlSymsp->TOP.b_in}
    , in_valid{vlSymsp->TOP.in_valid}
    , out{vlSymsp->TOP.out}
    , out_valid{vlSymsp->TOP.out_valid}
    , __PVT____024unit{vlSymsp->TOP.__PVT____024unit}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vchip::Vchip(const char* _vcname__)
    : Vchip(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vchip::~Vchip() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vchip___024root___eval_debug_assertions(Vchip___024root* vlSelf);
#endif  // VL_DEBUG
void Vchip___024root___eval_static(Vchip___024root* vlSelf);
void Vchip___024root___eval_initial(Vchip___024root* vlSelf);
void Vchip___024root___eval_settle(Vchip___024root* vlSelf);
void Vchip___024root___eval(Vchip___024root* vlSelf);

void Vchip::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vchip::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vchip___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vchip___024root___eval_static(&(vlSymsp->TOP));
        Vchip___024root___eval_initial(&(vlSymsp->TOP));
        Vchip___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vchip___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vchip::eventsPending() { return false; }

uint64_t Vchip::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vchip::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vchip___024root___eval_final(Vchip___024root* vlSelf);

VL_ATTR_COLD void Vchip::final() {
    Vchip___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vchip::hierName() const { return vlSymsp->name(); }
const char* Vchip::modelName() const { return "Vchip"; }
unsigned Vchip::threads() const { return 1; }
void Vchip::prepareClone() const { contextp()->prepareClone(); }
void Vchip::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vchip::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vchip___024root__trace_decl_types(VerilatedVcd* tracep);

void Vchip___024root__trace_init_top(Vchip___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vchip___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vchip___024root*>(voidSelf);
    Vchip__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    if (strlen(vlSymsp->name())) tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vchip___024root__trace_decl_types(tracep);
    Vchip___024root__trace_init_top(vlSelf, tracep);
    if (strlen(vlSymsp->name())) tracep->popPrefix();
}

VL_ATTR_COLD void Vchip___024root__trace_register(Vchip___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vchip::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vchip::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vchip___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
