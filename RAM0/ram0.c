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

# define M_PI_     3.14159	// pi
# define N_PI       -3.14159 //negative PI
# define M_PI_2_M   1.57079	// pi / 2
# define M_2XPI     6.28318 // pi * 2
# define M_PI_4_M   12.56636 // pi * 4
#define degree2radian2(a) (a * 00.01745)
#define radian2degree2(a) (a * 57.29578)
#define ABS(N) ((N<0)?(-N):(N))



#include <stdlib.h>//standard library
#include <stdio.h>//standard input output
#include <input.h>//used for detecting key inputs
#include <math.h>
#include <input.h>//used for detecting key inputs


static void naked_placement_in_RAM0(void) __naked
{
__asm
    SECTION BANK_00
__endasm;
}

#define degree2radian(a) (a * 0.0174)
#define radian2degree(a) (a * 57.2957)
#define ABS(N) ((N<0)?(-N):(N))
#define M_PI_2_     1.57079	// pi / 2
#define M_PI_		3.14159	// pi
#define M_PI_3     6.28318
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))


#include "externs.h"
#include "variables.h"
#include "ram0.h"

extern void slomo (void);
//extern void in_pause (a);

// do not have main() here at all since
// we are just compiling to object files
// you will get a RET inserted automatically


// Normalizes any number to an arbitrary range
// by assuming the range wraps around when going below min or above max
float normalize(float value, float start, float end)
{
  float width       = end - start;   //
  float offsetValue = value - start;   // value relative to 0

  return ( offsetValue - ( floor( offsetValue / width ) * width ) ) + start ;
  // + start to reset back to start of original range
}

float N_atan2(float yyy, float xxx)
{
    //https://developer.download.nvidia.com/cg/atan2.html
    float t0, t1, t3, t4;

    t3 = ABS(xxx);
    t1 = ABS(yyy);
    t0 = MAX(t3, t1);
    t1 = MIN(t3, t1);
    t3 = 1.0 / t0;
    t3 = t1 * t3;

    t4 = t3 * t3;
    t0 =         - 0.013480470;
    t0 = t0 * t4 + 0.057477314;
    t0 = t0 * t4 - 0.121239071;
    t0 = t0 * t4 + 0.195635925;
    t0 = t0 * t4 - 0.332994597;
    t0 = t0 * t4 + 0.999995630;
    t3 = t0 * t3;

    t3 = (ABS(yyy) > ABS(xxx)) ? M_PI_2_ - t3 : t3;
    ///t3 = (xxx > 0) ?  M_PI_ - t3 : t3;//slightly modified line
    t3 = (xxx < 0) ?  M_PI_ - t3 : t3;
    t3 = (yyy < 0) ? -t3 : t3;

    return t3;
}

float N_atan(float xxx)
{
    return N_atan2(xxx, 1.0);
}


void slopeCalculation (void)
{
    int x1,x2,y1,y2;
    //float output;
    float xx = 0;
    float yy = 0;
    float slope_angle = 0;

    float slope_RAD1 = 0;
    float slope_RAD2 = 0;
    float f_degree = 0;
    int degree = 0;

    slomo();

    printf("\x16\x01\x02");
	printf ("Hello Slope\n");
	printf ("Try 96 196 112 180 == 45\n");

    printf ("Enter X1 ");
    scanf("%d", &x1);
    printf ("Enter Y1 ");
    scanf("%d", &y1);
    printf ("Enter X2 ");
    scanf("%d", &x2);
    printf ("Enter Y2 ");
    scanf("%d", &y2);
    printf ("\nX1 = %d Y1 = %d X2 = %d Y2 = %d\n\n",x1,y1,x2,y2 );

    xx = (float)(x2 - x1);
    yy = (float)(y1 - y2);
    slope_RAD1 = N_atan2(yy,xx);

    slope_angle = N_atan2(yy, xx) * 180.0 / M_PI_;

    if (slope_angle < 0.0)
    {
        slope_angle += 360.0;
    }

    printf ("Nvidia ATAN2 slope_RAD = %.4f\n",slope_RAD1);
    printf ("OUTPUT ATAN2 degree = %.4f\n", slope_angle);


    slomo();
    printf ("Press a Key\n");
    in_pause(0);
}



//must have blank line at end
