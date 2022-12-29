
static void  naked_placement_in_RAM0_a(void) __naked
{
    __asm
        SECTION BANK_00
    __endasm;
}

/*float scaleNumbers (float input, float inputLow, float inputHigh, float outputLow, float outputHigh)
{
    float slope1 =  (outputHigh - outputLow) / (inputHigh - inputLow);
    return outputLow + slope1 * (input - inputLow);
}*/
//https://stackoverflow.com/questions/5731863/mapping-a-numeric-range-onto-another
void scaleNumbers (void)
{
    char string[32];

    float input = 0;

    float inputLow = 0;
    float inputHigh = 0;

    float outputLow = 0;
    float outputHigh = 0;

    float slope1 = 0;
    float answer = 0;

    slomo();
    printf("\x16\x01\x02");
	printf ("Hello Number Scale\n");

    printf ("Enter input Range Low  ");
    scanf("%s", &string);
    inputLow = atof(string);
    printf ("\n");

    printf ("Enter input Range High ");
    scanf("%s", &string);
    inputHigh = atof(string);
    printf ("\n");

    printf ("Enter input Number ");
    scanf("%s", &string);
    input = atof(string);
    printf ("\n");

    printf ("Enter output Range Low ");
    scanf("%s", &string);
    outputLow = atof(string);
    printf ("\n");

    printf ("Enter output Range High ");
    scanf("%s", &string);
    outputHigh = atof(string);
    printf ("\n");

    slope1 =  (outputHigh - outputLow) / (inputHigh - inputLow);

    answer = outputLow + slope1 * (input - inputLow);

    printf ("Answer = %.4f\n\n", answer);

    slomo();
    printf ("Press a Key\n");
    in_pause(0);
}

///////////////////////////////////////////////

static void  naked_placement_in_RAM0_b(void) __naked
{
    __asm
        SECTION BANK_00
    __endasm;
}
// Normalizes any number to an arbitrary range
// by assuming the range wraps around when going below min or above max
void normalize(void)
{
    char string[32];
    float input = 0;
    float inputLow = 0;
    float inputHigh = 0;
    float width = 0;
    float offsetValue = 0;
    float answer = 0;

    slomo();
    printf("\x16\x01\x02");
	printf ("Hello Normalize\n\n");

	printf ("Enter input Number ");
    scanf("%s", &string);
    input = atof(string);
    printf ("\n");

    printf ("Enter Start Number ");
    scanf("%s", &string);
    inputLow = atof(string);
    printf ("\n");

    printf ("Enter End Number ");
    scanf("%s", &string);
    inputHigh = atof(string);
    printf ("\n\n");


    width = inputHigh - inputLow;   //float width = end - start;


    //float offsetValue = value - start;   // value relative to 0
    offsetValue = input - inputLow;   // value relative to 0

    //return ( offsetValue - ( floor( offsetValue / width ) * width ) ) + start ;
    // + start to reset back to start of original range
    answer = ( offsetValue - ( floor( offsetValue / width ) * width ) ) + inputLow;

    printf ("Answer = %.4f\n\n", answer);

    slomo();
    printf ("Press a Key\n");
    in_pause(0);
}






