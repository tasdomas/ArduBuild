#ifndef __INDICATOR_H__

#define __INDICATOR_H__

#define RED1 1
#define RED2 L1 << 1
#define RED3 L1 << 2
#define RED4 L1 << 3
#define RED5 L1 << 4
#define GREEN L1 << 5
#define BAR1 L1 << 6
#define BAR2 L1 << 7
#define BAR3 L1 << 8
#define BAR4 L1 << 9
#define BAR5 L1 << 10
#define BAR6 L1 << 11
#define BAR7 L1 << 12
#define BAR8 L1 << 13
#define BAR9 L1 << 14
#define BAR10 L1 << 15

#define DATA_PIN 11
#define LATCH_PIN 12
#define CLOCK_PIN 13

void indicator_setup();
int indicator_set(unsigned int state);

#endif
