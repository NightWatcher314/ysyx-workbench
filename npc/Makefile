TOPNAME = top
NXDC_FILES = constr/top.nxdc
INC_PATH ?=

VERILATOR = verilator
VERILATOR_CFLAGS += -MMD --build -cc  \
				-O3 --x-assign fast --x-initial fast --noassert

BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj_dir
BIN = $(BUILD_DIR)/$(TOPNAME)

default: $(BIN)

# constraint file
SRC_AUTO_BIND = $(abspath $(BUILD_DIR)/auto_bind.cpp)
$(SRC_AUTO_BIND): $(NXDC_FILES)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@

# project source
VSRCS = $(shell find $(abspath ./vsrc) -name "*.v")
CSRCS = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")
CSRCS += $(SRC_AUTO_BIND)

# rules for NVBoard
include $(NVBOARD_HOME)/scripts/nvboard.mk

# rules for verilator
INCFLAGS = $(addprefix -I, $(INC_PATH))
CXXFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\""

$(BUILD_DIR):
	$(shell mkdir -p $(BUILD_DIR))

$(BIN): $(VSRCS) $(CSRCS) $(NVBOARD_ARCHIVE)
	@echo	
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(TOPNAME) $^ \
		$(addprefix -CFLAGS , $(CXXFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
		--Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN))


all:clean $(BUILD_DIR) run


run: $(BIN)
	@echo
	@echo "### BOARD ###"
	$(call git_commit, "sim RTL")
	@$^

# waves: sim
# 	@echo
# 	@echo "### WAVES ###"
# 	gtkwave waveform.vcd

# sim: waveform.vcd
# 	$(call git_commit, "sim RTL")

# build: ./obj_dir/V$(MODULE)
# 	$(call git_commit, "build RTL")

# verilate: .stamp.verilate

# waveform.vcd: $(BIN)
# 	@echo
# 	@echo "### SIMULATING ###"
# 	@$(BIN) +verilator+rand+reset+2

# ./obj_dir/V$(MODULE): .stamp.verilate
# 	@echo
# 	@echo "### BUILDING SIM ###"
# 	make -C obj_dir -f V$(MODULE).mk V$(MODULE)

# .stamp.verilate: ./vsrc/$(MODULE).v ./csrc/$(MODULE).cpp
# 	@echo
# 	@echo "### VERILATING ###"
# 	verilator -Wall --trace --x-assign unique --x-initial unique -cc ./vsrc/$(MODULE).v --exe ./csrc/$(MODULE).cpp
# 	@touch .stamp.verilate

clean:
	rm -rf .stamp.*;
	rm -rf waveform.vcd
	rm -rf $(BUILD_DIR)


.PHONY: sim clean verilate build waves default run all

# rules for git
include ../Makefile
