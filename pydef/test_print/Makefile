SOURCES		=  test_print.c $(SIREN_LIB)/printf.c
OBJECTS		=  test_print.o $(SIREN_LIB)/printf.o

CC          = $(MSPGCC_ROOT)/msp430-elf-gcc
DEVICE		= msp430fr6989
GDB			= $(MSPGCC_ROOT)/msp430-elf-gdb

# GCC flags
CSTD_FLAGS			= -std=gnu11 -funsigned-char
DEBUG_FLAGS			= -g3 -ggdb -gdwarf-2 -DDEBUG
ERROR_FLAGS			= -Wall -Wextra -Wshadow -fmax-errors=5
NO_ERROR_FLAGS		= -Wno-unused-parameter -Wno-unknown-pragmas -Wno-unused-variable -Wno-type-limits -Wno-comment
LIB_INCLUDES		= -I $(MSPGCC_ROOT)/../include/ -I $(SIREN_LIB)/
MSP430_FLAGS		= -mmcu=$(DEVICE) -mhwmult=none -D__$(DEVICE)__ -DDEPRECATED -mlarge
REDUCE_SIZE_FLAGS	= -fdata-sections -ffunction-sections -finline-small-functions -O0
SIM_FLAGS			= -D__MSPSIM__

CFLAGS				= $(CSTD_FLAGS) $(DEBUG_FLAGS) $(ERROR_FLAGS) $(NO_ERROR_FLAGS) $(LIB_INCLUDES) $(MSP430_FLAGS) $(REDUCE_SIZE_FLAGS) $(SIM_FLAGS) -DDEBUG=$(DEBUG)

LFLAGS = -Wl,--gc-sections -Wl,--reduce-memory-overheads -Wl,--stats -Wl,--relax
LIBS = -L $(MSPGCC_ROOT)/../include/
DEBUG = -DDEBUG


all: compile

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

# Change -o to $(DEVICE) when we need multiple devices
compile: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LFLAGS) -o main.out $(LIBS)

install: all
	mspdebug tilib "prog main.out"

debug: all
	mspdebug tilib gdb &

gdb:
	msp430-elf-gdb -x ../tools/cmd.gdb

clean:
	rm -rf *.o
	rm -rf hardware_tests/*.o
	rm -f main.out
	rm -rf ../lib/*.o
