### HW config ####

# Arduino MEGA 1280
#CFLAGS_HW_CFG := -mmcu=atmega1280 -DF_CPU=16000000
#AVRDUDE_HW_CFG := -p m1280 -c stk500v1 -P/dev/ttyUSB0 -b57600

# Arduino MEGA 2560
CFLAGS_HW_CFG := -mmcu=atmega328 -DF_CPU=16000000
AVRDUDE_HW_CFG := -p atmega328p -c arduino -P/dev/ttyACM0

CC=avr-g++
CPP=avr-g++
AR=avr-ar
LD=avr-ld
OBJCOPY=avr-objcopy

LIBDIR=$(ROOT_DIR)/lib
OUTDIR=$(ROOT_DIR)/output
CFLAGS_ELF_OUTPUT=$(CFLAGS_HW_CFG) -Wall -Os -L $(LIBDIR)
CFLAGS=-c $(CFLAGS_HW_CFG) -Wall -Os -I $(LIBDIR)
AVRDUDE_VERBOSITY=
STRIP=avr-strip

SRC := main.c indicator.c
INC :=

OBJ := $(SRC:.c=.o)

all: example

example: example.hex

example.hex: example.elf
	@cp example.elf example_unstripped.elf
	$(STRIP) -s example.elf
	$(OBJCOPY) -O ihex -R .eeprom example.elf $(OUTDIR)/example.hex

example.elf: $(OBJ) $(SRC) $(INC)
	$(CC) $(CFLAGS_ELF_OUTPUT) *.o -o example.elf -larduino

upload: example
	avrdude $(AVRDUDE_VERBOSITY) -C avrdude.conf -q -q $(AVRDUDE_HW_CFG) -D -Uflash:w:example.hex:i

clean:
	rm -f *.o
	rm -f *.elf
	rm -f *.hex
	rm -f *~
