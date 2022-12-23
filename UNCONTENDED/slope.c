
/*
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

    t3 = (ABS(yyy) > ABS(xxx)) ? M_PI_2 - t3 : t3;
    ///t3 = (xxx > 0) ?  M_PI - t3 : t3;//slightly modified line
    t3 = (xxx < 0) ?  M_PI - t3 : t3;
    t3 = (yyy < 0) ? -t3 : t3;

    return t3;
}
float N_atan(float xxx)
{
    return atan2(xxx, 1.0);
}*/

void slopeCalculation (void)
{
    int x1,x2,y1,y2;
    //float output;
    float xxx = 0;
    float yyy = 0;
    float zzz = 0;
    float slope_angle = 0;
    float slope_RAD1 = 0;

    slomo();

    printf("\x16\x01\x02");
	printf ("Hello Slope\n");

    printf ("Enter X1 ");
    scanf("%d", &x1);
    printf ("Enter Y1 ");
    scanf("%d", &y1);
    printf ("Enter X2 ");
    scanf("%d", &x2);
    printf ("Enter Y2 ");
    scanf("%d", &y2);
    printf ("\nX1 = %d Y1 = %d X2 = %d Y2 = %d\n",x1,y1,x2,y2 );

    xxx = (float)(x2 - x1);
    if (xxx == 0)
    {
        xxx = .01;
    }

    yyy = (float)(y2 - y1);
    if (yyy == 0)
    {
        yyy = .01;
    }

    //194   100   194   65
    //slope_RAD1 = N_atan2(yyy,xxx);
    //slope_angle = radian2degree(slope_RAD1);
    //printf ("## slope_angle = %.2f\n",slope_angle);

    zzz = -1 + (yyy / xxx);

    //slope_RAD1 = N_atan(zzz);     //179.98
    //slope_RAD1 = 1-N_atan(zzz);   //-122.69

    slope_RAD1 = atan(zzz);       //-89.98
    //slope_RAD1 = -1.0 + atan(zzz);     //-147.28
    //slope_RAD1 = tan(zzz);          //15.56
    //slope_RAD1 = 1.0-tan(zzz);


    slope_angle = radian2degree(slope_RAD1);
    printf ("## slope_angle = %.2f\n",slope_angle);




    slomo();
    printf ("Press a Key\n");
    in_pause(0);
}



