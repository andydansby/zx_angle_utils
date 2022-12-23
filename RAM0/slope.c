
#define M_PI_       3.14159	// pi
#define M_PI_2_     1.57079	// pi / 2
#define M_2XPI     6.28318 // pi * 2
#define M_PI_4     12.56636 // pi * 4
#define degree2radian2(a) (a * 00.01745)
#define radian2degree2(a) (a * 57.29578)
#define ABS(N) ((N<0)?(-N):(N))
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

#include <stdio.h>//standard input output
#include <input.h>//used for detecting key inputs

extern void slomo (void);

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



