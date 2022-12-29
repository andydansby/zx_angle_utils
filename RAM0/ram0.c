// using sdcc80 1.99c

// assembly files are in ram0Z.asm as
// indicated by ramMain.lst

// this has been pushed to zpragma.inc
//#pragma output CRT_ORG_CODE = 49152

//be sure to bank to this slot if you
//plan on using other banks

//we are just putting functions here

//PLACE ASSEMBLY VARIABLES HERE
//HAVE AT LEAST ONE VARIABLE DEFINED AS AN ASM VARIABLE

//if this is before any custom headers
//it will set everything below it to be
//in the correct memory slot

static void naked_placement_in_RAM0(void) __naked
{
__asm
    SECTION BANK_00
__endasm;
}

#include <stdlib.h>//standard library
#include <stdio.h>//standard input output
#include <input.h>//used for detecting key inputs
#include <math.h>
#include <input.h>//used for detecting key inputs



//#define degree2radian(a) (a * 0.0174)
//#define radian2degree(a) (a * 57.2957)
#define _ABS(N) ((N<0)?(-N):(N))
#define _M_PI_2     1.57079	// pi / 2
#define _M_PI		3.14159	// pi
#define _M_PI_3     6.28318
#define _MAX(x, y) (((x) > (y)) ? (x) : (y))
#define _MIN(x, y) (((x) < (y)) ? (x) : (y))
#define _degree2radian(a) (a * 0.0174)


#include "externs.h"
#include "normalize.c"  //a & b
#include "fastTrig.c"
#include "slope.c"      //c
//#include "ram0.h"
#include "wrap_around_PI.c" //e
#include "reflection.c"     //g
#include "aroundCompass.c"  //h

extern void slomo (void);
//extern void in_pause (a);

// do not have main() here at all since
// we are just compiling to object files
// you will get a RET inserted automatically




//must have blank line at end
