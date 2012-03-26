#include <WProgram.h>

#include "general.h"

#include "indicator.h"


void indicator_setup()
{
	pinMode(DATA_PIN, OUTPUT);
	pinMode(CLOCK_PIN, OUTPUT);
	pinMode(LATCH_PIN, OUTPUT);
}

int indicator_set(unsigned int state) {
	byte buf;

	digitalWrite(LATCH_PIN, LOW);

	buf = lowByte(state);
	shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, buf);
	buf = highByte(state);
	shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, buf);

	digitalWrite(LATCH_PIN, HIGH);
}