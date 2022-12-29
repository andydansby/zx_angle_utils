
static void  naked_placement_in_RAM0_g(void) __naked
{
    __asm
        SECTION BANK_00
    __endasm;
}


/*
                90
             130   40
            180       0
             220   320
                270

                1.57
            2.26     .698
        3.14                0
            3.839     5.585
                4.712
*/

///////seems good

void reflection5 (void)
{
    int incomingRay = 0;
    int surfaceAngle = 0;
    int reflection1 = 0;
    int reflection2 = 0;
    int glancing = 0;
    int oppositeAngle = 0;
    int difference = 0;

    int temp = 0;

    slomo();

    printf("\x16\x01\x01");//printf("\x16\x01\x02");
	//printf ("Hello Reflection\n\n");


	printf ("The angle of Reflection is always equal to\n");
	printf ("the incidence angle in the opposite direction\n");
    printf ("of the surface. You will need\n");
    printf ("The angle of the surface and\n");
    printf ("The angle of the ray.\n");

    printf ("there will be 2 outputs\n");
    printf ("invert reflection is below the surface\n");
    printf ("reflection is above surface\n");
    printf ("The normal answer is Reflection\n\n");



	printf ("Enter Surface Angle ");
    scanf("%d", &surfaceAngle);


    ////////////
    //calculate opposite angle
    if (surfaceAngle < 180)
    {//if you use <= 180 opposite angle will be 360
        oppositeAngle = surfaceAngle + 180;//good
    }
    if (surfaceAngle >= 180)
    {//if you use >= 180 opposite angle will be 0
        oppositeAngle = surfaceAngle - 180;//good
    }
    ////////////
    // opposite angles seem good
    ////////////

    printf ("Enter Incoming Ray Angle ");
    scanf("%d", &incomingRay);


    printf ("\n\n");
    printf ("Surface Angle = %d oppositeAngle = %d\n",surfaceAngle, oppositeAngle);
    printf ("Inbound Ray   = %d",incomingRay);
    printf ("\n\n");


    ////////////
    // Reflection calculation
    ////////////
    reflection1 = surfaceAngle * 2 - incomingRay;

    if (reflection1 >= 360)
    {
        reflection2 = reflection1 - 360;
    }
    if (reflection1 < 0)
    {
        reflection2 = reflection1 + 360;
    }
    else
    {
        reflection2 = reflection1;
    }

    ////////////
    // on larger angles, bring back into range
    ////////////
    if (reflection2 > 360)
    {
        reflection2 -= 360;
        //reflection1 = reflection2;
    }

    if (reflection2 < 180)
    {
        //add
        temp = reflection2 + 180;
    }
    if (reflection2 > 180)
    {
        //subtract
        temp = reflection2 - 180;
    }
    reflection2 = temp;

    //calculate opposite RAY angle
    if (reflection2 < 180)
    {//if you use <= 180 opposite angle will be 360
        reflection1 = reflection2 + 180;//good
    }
    if (reflection2 >= 180)
    {//if you use >= 180 opposite angle will be 0
        reflection1 = reflection2 - 180;//good
    }

    //special case coming at the edge
    //leave for last check
    if (incomingRay == surfaceAngle)
    {
        reflection1 = surfaceAngle;
        reflection2 = surfaceAngle;
    }
    if (incomingRay == oppositeAngle)
    {
        reflection1 = oppositeAngle;
        reflection2 = oppositeAngle;
    }
    //special case coming at the edge
    //leave for last check

    printf ("## reflection = %d  ##",reflection2);
    printf ("\n");

    printf ("invert reflection = %d",reflection1);
    printf ("\n\n");
    slomo();
    printf ("Press a Key\n");
    in_pause(0);
}



/*
void reflection5 (void)
{
    int incomingRay = 0;
    int surfaceAngle = 0;
    int reflection1 = 0;
    int reflection2 = 0;
    int glancing = 0;
    int oppositeAngle = 0;
    int difference = 0;

    int temp = 0;

    slomo();

    printf("\x16\x01\x02");
	printf ("Hello Reflection\n");
	printf ("Enter Surface Angle ");
    scanf("%d", &surfaceAngle);


    ////////////
    //calculate opposite angle
    if (surfaceAngle < 180)
    {//if you use <= 180 opposite angle will be 360
        oppositeAngle = surfaceAngle + 180;//good
    }
    if (surfaceAngle >= 180)
    {//if you use >= 180 opposite angle will be 0
        oppositeAngle = surfaceAngle - 180;//good
    }
    ////////////
    // opposite angles seem good
    ////////////

    printf ("Enter Incoming Ray Angle ");
    scanf("%d", &incomingRay);


    printf ("\n\n");
    printf ("Surface Angle = %d oppositeAngle = %d\n",surfaceAngle, oppositeAngle);
    printf ("Inbound Ray = %d",surfaceAngle);
    printf ("\n\n");


    ////////////
    // Reflection calculation
    ////////////
    reflection1 = surfaceAngle * 2 - incomingRay;
    if (reflection1 >= 360)
    {
        reflection2 = reflection1 - 360;
    }
    if (reflection1 < 0)
    {
        reflection2 = reflection1 + 360;
    }
    else
    {
        reflection2 = reflection1;
    }

    ////////////
    // on larger angles, bring back into range
    ////////////
    if (reflection2 > 360)
    {
        reflection2 -= 360;
        reflection1 = reflection2;
    }
    //printf ("before adjust = %d reflection1 %d \n",reflection2, reflection1);

    if (reflection2 < 180)
    {
        //add
        temp = reflection2 + 180;
    }
    if (reflection2 > 180)
    {
        //subtract
        temp = reflection2 - 180;
    }
    reflection2 = temp;

    //printf ("adjust2 = %d \n",reflection2);

    //calculate opposite angle

    if (reflection2 < 180)
    {//if you use <= 180 opposite angle will be 360
        glancing = reflection2 + 180;//good
    }
    if (reflection2 >= 180)
    {//if you use >= 180 opposite angle will be 0
        glancing = reflection2 - 180;//good
    }
    printf ("glancing = %d \n\n",glancing);

    ////////////

    //special case coming at the edge
    //leave for last check
    if (incomingRay == surfaceAngle)
    {
        reflection2 = surfaceAngle;
    }
    if (incomingRay == oppositeAngle)
    {
        reflection2 = oppositeAngle;
    }
    //need to program edge cases as well
    printf ("## reflection1 = %d \n\n",reflection1);
    printf ("## reflection2 = %d \n\n",reflection2);
    slomo();
    printf ("Press a Key\n");
    in_pause(0);
}
*/



