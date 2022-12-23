
//https://stackoverflow.com/questions/73216244/how-to-normalize-angle-radian-value-to-2pi


void aroundCompass (void)
{
    slomo();
    printf("\x16\x01\x02");
	printf ("Hello Around the Compass\n");

    slomo();
    for (angle = 0; angle < 361; angle ++)
    {
        radians = degree2radian(angle);
        radian2 = radians - M_PI;

        printf ("Angle= %d ", angle);
        printf ("Rad= %.2f ", radians);
        printf ("Rad2= %.2f\n", radian2);

    }

    slomo();
    printf ("Press a Key\n");
    in_pause(0);
}
