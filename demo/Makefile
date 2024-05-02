BUILD_DIR ?= /home/sharmine/Documents/thesis/litex/litex/soc/software/demo/build/tul_pynq_z2


include $(BUILD_DIR)/software/include/generated/variables.mak
include $(SOC_DIRECTORY)/software/common.mak

OBJECTS   = donut.o helloc.o crt0.o main.o gcmtest.o gcm.o aes.o print.o stats.o asmtest.o
ifdef WITH_CXX
	OBJECTS += hellocpp.o
	CFLAGS += -DWITH_CXX
endif

#-------------------------------------------------------------------------------------------
# Control flag variable
# Set CFLAG_OPTION variable based on the chosen Test Case 
#
# CFLAG_OPTION | Test Case definition
#      1       | T1: Base code: XOR and Shift operations
#      2       | T2: Karatsuba multiplication (mul) and multiplication reduction (rdx)
#      3       | T3: Karatsuba mul and shift rdx 
#      4       | T4: Karatsuba mul with mulclh and mulcl and multiplication rdx
#      5       | T5: Karatsuba mul with mulclh and mulcl and shift rdx
#      6       | T6: Karatsuba mul and rdx with mulclh and mulcl
#      7       | T7: Karatsuba mul with mulclh and mulcl and immediate rdx mulclhi and mulcli
#-------------------------------------------------------------------------------------------

CFLAG_OPTION ?= 7

# Define flags based on CFLAG_OPTION (Do not modify)
ifeq ($(CFLAG_OPTION),1)
    CFLAGS += -DGF_MUL_ENABLED
endif
ifeq ($(CFLAG_OPTION),2)
    CFLAGS += -DGF_MUL_KARATSUBA_ENABLED
    CFLAGS += -DMUL_REDUCTION
endif
ifeq ($(CFLAG_OPTION),3)
    CFLAGS += -DGF_MUL_KARATSUBA_ENABLED
    CFLAGS += -DSHIFT_REDUCTION
endif
ifeq ($(CFLAG_OPTION),4)
    CFLAGS += -DKARATSUBA_CUSTINSTR_ENABLED
    CFLAGS += -DMUL_REDUCTION
endif
ifeq ($(CFLAG_OPTION),5)
    CFLAGS += -DKARATSUBA_CUSTINSTR_ENABLED
    CFLAGS += -DSHIFT_REDUCTION
endif
ifeq ($(CFLAG_OPTION),6)
    CFLAGS += -DKARATSUBA_CUSTINSTR_ENABLED
    CFLAGS += -DMUL_INS_REDUCTION
endif
ifeq ($(CFLAG_OPTION),7)
    CFLAGS += -DKARATSUBA_CUSTINSTR_ENABLED
    CFLAGS += -DMUL_IMM_REDUCTION
endif
#-------------------------------------------------------------------------------------------


all: demo.bin
	$(PYTHON) -m litex.soc.software.memusage demo.elf $(BUILD_DIR)/software/include/generated/regions.ld $(TRIPLE)


%.bin: %.elf
	$(OBJCOPY) -O binary $< $@
ifneq ($(OS),Windows_NT)
	chmod -x $@
endif

vpath %.a $(PACKAGES:%=../%)

demo.elf: $(OBJECTS)
	$(CC) $(LDFLAGS) -Wl,--no-warn-rwx-segment -T linker.ld -N -o $@ \
		$(OBJECTS) \
		$(PACKAGES:%=-L$(BUILD_DIR)/software/%) \
		-Wl,--whole-archive \
		-Wl,--gc-sections \
		-Wl,-Map,$@.map \
		$(LIBS:lib%=-l%)

ifneq ($(OS),Windows_NT)
	chmod -x $@
endif

# pull in dependency info for *existing* .o files
-include $(OBJECTS:.o=.d)

donut.o: CFLAGS   += -w

VPATH = $(BIOS_DIRECTORY):$(BIOS_DIRECTORY)/cmds:$(CPU_DIRECTORY)


%.o: %.cpp
	$(compilexx)

%.o: %.c
	$(compile)

%.o: %.S
	$(assemble)

clean:
	$(RM) $(OBJECTS) demo.elf demo.bin .*~ *~

.PHONY: all clean
