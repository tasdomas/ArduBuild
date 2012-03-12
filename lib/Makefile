# NOTE: Build divided into C and CPP parts because the C code doesn't build with the CPP compiler

CC=avr-gcc
CXX=avr-g++
AR=avr-ar

INC_DIRS := -I .

CFLAGS  := -Wall -Os
CFLAGS += $(CFLAGS_HW_CFG)
CFLAGS  += $(INC_DIRS)

CXXFLAGS := -Wall -Os
CXXFLAGS += $(CFLAGS_HW_CFG)
CXXFLAGS += $(INC_DIRS)

HDR     := binary.h HardwareSerial.h pins_arduino.h Print.h Stream.h WConstants.h wiring.h wiring_private.h WProgram.h WString.h
C_SRC   := pins_arduino.c wiring_analog.c wiring_digital.c wiring_shift.c wiring.c wiring_pulse.c WInterrupts.c
CPP_SRC := HardwareSerial.cpp Tone.cpp WString.cpp  Print.cpp  WMath.cpp

OBJ := $(C_SRC:.c=.o) $(CPP_SRC:.cpp=.o)

all: arduino

arduino: $(OBJ) $(C_SRC) $(CPP_SRC) $(HDR)
	$(AR) rcs libarduino.a $(OBJ)
cloc:
	@cloc ./*
clean:
	@rm -rfv *.o
	@rm -rfv *.a
