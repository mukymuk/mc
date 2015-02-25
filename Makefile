TOOLCHAIN:=c:/ti/ccsv6/tools/compiler/c2000_6.2.11

BSP=launchxl-f28027
HAL=f2802x
OUTDIR=build/${CFG}
TARGET=mc.out
LINKER_SCRIPT=F28027F.cmd

CC = ${TOOLCHAIN}/bin/cl2000.exe
LD = ${CC}

MKDIR := .

ARCH_FLAGS=-v28 -ml -mt -O2 -g --define=FLASH --diag_warning=225 --display_error_number
LDFLAGS=$(ARCH_FLAGS) -i"$(TOOLCHAIN)/lib" -z -m"$(OUTDIR)/$(basename $(TARGET)).map" --stack_size=0x200 --warn_sections --reread_libs --priority --disable_auto_rts --diag_suppress=16002 --rom_model -l"rts2800_ml.lib"
CFLAGS=$(ARCH_FLAGS) -i"$(TOOLCHAIN)/include"
INCS=-I.

SRCS := $(wildcard *.c)
SRCS := $(SRCS) $(wildcard *.asm)

#include hal/sources

OUTDIRS=$(addprefix $(OUTDIR)/, $(MKDIR))

$(OUTDIR)/%.bin: $(OUTDIR)/%.out
	$(OBJCOPY) -O binary $< $@  

$(OUTDIR)/%.o: %.asm
	$(CC) $(CFLAGS) $(INCS) --output_file="$@" -c $<

$(OUTDIR)/%.o: %.c
	$(CC) $(CFLAGS) $(INCS) --output_file="$@" -c $<

$(OUTDIRS):
	@mkdir -p $(OUTDIRS)

OBJS := $(SRCS:.c=.o)
OBJS := $(OBJS:.asm=.o)
OBJS := $(addprefix ./$(OUTDIR)/,$(OBJS))




$(OUTDIR)/$(TARGET): $(OBJS) $(LINKER_SCRIPT)
	$(LD) $(LDFLAGS) --output_file="$@" $(OBJS) $(LINKER_SCRIPT)

all:	$(OUTDIRS) $(OUTDIR)/$(TARGET) $(OUTDIR)/$(TARGET)
clean:
	rm -rf $(OUTDIR)
	make all

.DEFAULT_GOAL=all

