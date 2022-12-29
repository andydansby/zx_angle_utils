
static void  naked_placement_in_RAM0_h(void) __naked
{
    __asm
        SECTION BANK_00
    __endasm;
}


//https://stackoverflow.com/questions/73216244/how-to-normalize-angle-radian-value-to-2pi


void aroundCompass (void)
{
    float radians;
    float radian2;
    int angle;


    slomo();
    printf("\x16\x01\x02");
	printf ("Hello Around the Compass\n");

    slomo();
    for (angle = 0; angle < 361; angle ++)
    {
        radians = _degree2radian(angle);
        radian2 = radians - _M_PI;

        printf ("Angle= %d ", angle);
        printf ("Rad= %.2f ", radians);
        printf ("Rad2= %.2f\n", radian2);

    }

    slomo();
    printf ("Press a Key\n");
    in_pause(0);
}
