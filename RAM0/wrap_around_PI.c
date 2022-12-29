//https://stackoverflow.com/questions/73216244/how-to-normalize-angle-radian-value-to-2pi

static void  naked_placement_in_RAM0_e(void) __naked
{
    __asm
        SECTION BANK_00
    __endasm;
}
//if floating point number exceeds or is less than PI,wrap around the other side
void wrapAroundPI (void)
{
    char string[32];
    float radians = 0.0;
    float radian2 = 0.0;

    slomo();

    printf("\x16\x01\x02");
	printf ("Hello Wrap Around Double PI\n");
	printf ("If you exceed over 6.28\n");
	printf ("Wraps around to 0 + remainder\n");

    printf ("Enter Radian ");
    scanf("%s", &string);
    radians = atof(string);

    radian2 = radians - 2 * M_PI * floor(radians / (2 * M_PI));

    printf ("\nWrap around radian = %f \n",radian2);

    slomo();
    printf ("Press a Key\n");
    in_pause(0);

}

static void  naked_placement_in_RAM0_f(void) __naked
{
    __asm
        SECTION BANK_00
    __endasm;
}

void wrapAroundPI2 (void)
{
    char string[32];
    float radians = 0.0;
    float radian2 = 0.0;

    slomo();

    printf("\x16\x01\x02");
	printf ("Hello Wrap Around PI\n");
	printf ("If you exceed over 3.14\n");
	printf ("Wraps around to 0 + remainder\n");

    printf ("Enter Radian ");
    scanf("%s", &string);
    radians = atof(string);

    radian2 = radians - 2 * M_PI_2 * floor(radians / (2 * M_PI_2));

    printf ("\nWrap around radian = %f \n",radian2);

    slomo();
    printf ("Press a Key\n");
    in_pause(0);

}
