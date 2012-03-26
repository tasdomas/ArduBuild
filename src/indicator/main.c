#include <WProgram.h>
#include "general.h"
#include "indicator.h"

#define NR_OF_DELAY_ENTRIES 23 /* delay values that form a value loop */
static const int16_t delay_us[] = { 20000, 18000, 16000, 14000, 12000, 10000, 8000,
				    6000,  4000,  2000,  1000,  1000,  1000, 1000,
				    2000,  4000, 6000,   8000, 10000, 12000, 14000,
				    16000, 18000 };
#define NR_OF_OUTPUT_PINS 4
static const uint8_t output_pin[] = {2,3,4,5};
static int16_t value[] = {0,0,0,0};
static int16_t i=0;
static uint8_t delay_index = 7; /* begin with fast fading */
static uint16_t loop_counter = 0;

void delay_execution(int16_t delay_us)
{
	/* Use delay() as a fallback for too large values that delayMicroseconds() cannot handle */
	if (delay_us < 16000) {
		delayMicroseconds(delay_us);
	} else {
		delay(delay_us / 1000);
	}
}

void setup()
{
	indicator_setup();
}

void loop()
{
	static unsigned int wrout = 1;
	if (wrout != 1 << 15) {
		wrout = wrout << 1;
	} else {
		wrout = 1;
	}
	indicator_set(wrout);
	delay(500);
}

int main(void)
{
	init(); /* Arduino initializations */
	setup();
	while (TRUE) { loop(); }
	return 0;
}

/* This function should never be called, but a link dependency exists */
extern "C" void_t __cxa_pure_virtual(void)
{
	while(TRUE) {}
}
