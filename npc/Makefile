MODULE=chip

all:
	@echo "Write this Makefile by your self."

.PHONY: sim
sim: clean ./obj_dir/V$(MODULE)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo
	@echo "### SIMULATING ###"
	@./obj_dir/V$(MODULE) +verilator+rand+reset+2
	
.PHONY:waves
waves: sim
	@echo
	@echo "### WAVES ###"
	gtkwave waveform.vcd

./obj_dir/V$(MODULE): .stamp.verilate
	@echo
	@echo "### BUILDING SIM ###"
	make -C obj_dir -f V$(MODULE).mk V$(MODULE)

.stamp.verilate: ./vsrc/$(MODULE).v ./csrc/$(MODULE).cpp
	@echo
	@echo "### VERILATING ###"
	verilator -Wall --trace --x-assign unique --x-initial unique -cc ./vsrc/$(MODULE).v --exe ./csrc/$(MODULE).cpp
	@touch .stamp.verilate

.PHONY:clean
clean:
	rm -rf .stamp.*;
	rm -rf ./obj_dir
	rm -rf waveform.vcd

include ../Makefile
