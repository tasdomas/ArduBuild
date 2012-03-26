export CFLAGS_HW_CFG := -mmcu=atmega328 -DF_CPU=16000000
export AVRDUDE_HW_CFG := -p atmega328p -c arduino -P/dev/ttyACM0
export ROOT_DIR := $(CURDIR)
export OUTDIR := $(ROOT_DIR)/output

.PHONY: lib

outdir:
	mkdir -p $(OUTDIR)

lib:
	$(MAKE) --directory='lib/'

blink: outdir
	$(MAKE) --directory='src/blink'

indicator: outdir
	$(MAKE) --directory='src/indicator'

upload:
	avrdude $(AVRDUDE_VERBOSITY) -C avrdude.conf -q -q $(AVRDUDE_HW_CFG) -D -Uflash:w:$(OUTDIR)/$(HEX).hex:i

clean:
	rm -f *.o
	rm -f *.elf
	rm -f *.hex
	rm -f *~
