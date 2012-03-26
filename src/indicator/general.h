#ifndef _GENERAL_H_
#define _GENERAL_H_

#include <stdio.h> /* fundamental data type definitions */

/* Define fundamental datatypes for type naming consistency */
typedef uint8_t bool_t;
typedef void void_t;

/* Define constants */

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE !FALSE
#endif

#ifndef LOW
#define LOW 0
#endif

#ifndef HIGH
#define HIGH 1
#endif


#endif /* _GENERAL_H_ */
