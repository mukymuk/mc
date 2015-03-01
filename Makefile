TOOLCHAIN:=c:/ti/ccsv6/tools/compiler/c2000_6.2.11

OUTDIR=build/${CFG}
TARGET=mc.out

CC = ${TOOLCHAIN}/bin/cl2000.exe
LD = ${CC}

CMDS = F28027F.cmd

MKDIR := .

ARCH_FLAGS=-v28 -ml -mt -O2 -g --define=FLASH --diag_warning=225 --display_error_number
LDFLAGS=$(ARCH_FLAGS) -i"$(TOOLCHAIN)/lib" -z -m"$(OUTDIR)/$(basename $(TARGET)).map" --stack_size=0x200 --warn_sections --reread_libs --priority --disable_auto_rts --diag_suppress=16002 --rom_model -l"rts2800_ml.lib"
CFLAGS=$(ARCH_FLAGS) -i"$(TOOLCHAIN)/include"
INCS=-I.

SRCS := $(wildcard *.c)
SRCS := $(SRCS) $(wildcard *.asm)

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

$(OUTDIR)/$(TARGET): $(OBJS)
	$(LD) $(INCS) $(LDFLAGS) -e=code_start --output_file="$@" $(OBJS) $(CMDS)

depend:
	makedepend -f$(OUTDIR)/deps -Y$(TOOLCHAIN)/include -p$(OUTDIR)/ -- $(CFLAGS) -- $(SRCS)

$(OUTDIR)/deps:
	touch $(OUTDIR)/deps
	make depend CFG=$(CFG)

all:	$(OUTDIRS) $(OUTDIR)/$(TARGET) $(OUTDIR)/$(TARGET) $(OUTDIR)/deps
clean:
	rm -rf $(OUTDIR)
	make all


.DEFAULT_GOAL=all

include $(OUTDIR)/deps

