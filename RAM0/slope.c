
//#include <stdio.h>//standard input output
//#include <input.h>//used for detecting key inputs

extern void slomo (void);
extern float N_atan2(float yyy, float xxx);
extern float N_atan(float xxx);


static void naked_placement_in_RAM0_c(void) __naked
{
    __asm
        SECTION BANK_00
    __endasm;
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
	printf ("Hello Slope\n\n");

	printf ("The purpose of slope is to calculate\n");
	printf ("the angle of two points in Cartesian\n");
	printf ("space.  You will need the start and \n");
	printf ("end of each pixel. X and Y.\n\n");

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

    slope_angle = N_atan2(yy, xx) * 180.0 / _M_PI;

    if (slope_angle < 0.0)
    {
        slope_angle += 360.0;
    }

    printf ("Nvidia ATAN2 slope_RAD = %.4f\n",slope_RAD1);
    printf ("OUTPUT ATAN2 degree = %.4f\n", slope_angle);


    slomo();
    printf ("Press a Key\n");
    in_pause(0);

    return;
}



/*void slopeCalculation (void)
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
*/




