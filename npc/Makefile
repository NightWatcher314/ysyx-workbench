MODULE=chip

all:clean waves

waves: sim
	@echo
	@echo "### WAVES ###"
	gtkwave waveform.vcd

sim: waveform.vcd
	$(call git_commit, "sim RTL")

build: ./obj_dir/V$(MODULE)
	$(call git_commit, "build RTL")

verilate: .stamp.verilate



waveform.vcd: ./obj_dir/V$(MODULE)
	@echo
	@echo "### SIMULATING ###"
	@./obj_dir/V$(MODULE) +verilator+rand+reset+2

./obj_dir/V$(MODULE): .stamp.verilate
	@echo
	@echo "### BUILDING SIM ###"
	make -C obj_dir -f V$(MODULE).mk V$(MODULE)

.stamp.verilate: ./vsrc/$(MODULE).v ./csrc/$(MODULE).cpp
	@echo
	@echo "### VERILATING ###"
	verilator -Wall --trace --x-assign unique --x-initial unique -cc ./vsrc/$(MODULE).v --exe ./csrc/$(MODULE).cpp
	@touch .stamp.verilate

clean:
	rm -rf .stamp.*;
	rm -rf ./obj_dir
	rm -rf waveform.vcd


.PHONY: sim clean verilate build waves

include ../Makefile
