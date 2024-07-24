
#include <Vtop.h>
#include <nvboard.h>
#include <verilated_vcd_c.h>

static Vtop dut;

void nvboard_bind_all_pins(Vtop* top);

static void single_cycle()
{
    dut.clk = 0;
    dut.eval();
    dut.clk = 1;
    dut.eval();
}

static void reset(int n)
{
    dut.rst = 1;
    while (n-- > 0)
        single_cycle();
    dut.rst = 0;
}

int main(int argc, char** argv)
{
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    // VerilatedVcdC* tfp = new VerilatedVcdC();
    // tfp->open("top.vcd");
    // nvboard_bind_all_pins(&dut);
    // nvboard_init();

    reset(10);
    int i = 0;
    while (i++ <= 1000) {
        // nvboard_update();
        single_cycle();
    }

    // tfp->close();
    return 0;
}
