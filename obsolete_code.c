
//https://gamedev.net/forums/topic/385087-2d-ball-deflection-mini-golf-game/385087/
void reflection1 (void)
{
    slomo();

    printf("\x16\x01\x02");
	printf ("Hello Reflection\n");

    printf ("Enter Incoming Ray Angle ");
    scanf("%d", &incomingRay);
    printf ("\nIncoming Ray = %d \n",incomingRay);

    printf ("Enter Surface Angle ");
    scanf("%d", &surfaceAngle);
    printf ("\nSurface Angle = %d \n",surfaceAngle);

    //ball.angle = surface.angle - ( ball.angle - surface.angle )
    reflection = surfaceAngle - ( incomingRay - surfaceAngle );

    printf ("\nReflection = %d \n",reflection);

    slomo();
    printf ("Press a Key\n");
    in_pause(0);
}
/////////////////////////////////////////////////////

void reflection3 (void)
{
    float f_reflection1 = 0;
    float f_reflection2 = 0;
    float f_ray = 0;
    float f_surface = 0;
    float f_reflection = 0;
    int incomingRay = 0;
    int surfaceAngle = 0;
    int reflection = 0;

    slomo();

    printf("\x16\x01\x02");
	printf ("Hello Reflection\n");

    printf ("Enter Incoming Ray Angle ");
    scanf("%d", &incomingRay);
    printf ("\nIncoming Ray = %d \n",incomingRay);

    //convert ray to radians
    f_ray = (float) incomingRay;
    //printf ("\nf_ray = %f \n",f_ray);
    f_ray = degree2radian2 (f_ray); //OK
    printf ("convert to RAD f_ray = %f \n\n",f_ray);
    /////////////////////////////////////////////////////
    printf ("Enter Surface Angle ");
    scanf("%d", &surfaceAngle);
    printf ("\nSurface Angle = %d \n",surfaceAngle);

    //convert surface to radians
    f_surface = (float) surfaceAngle;
    //printf ("\nf_surface = %f \n",f_surface);
    f_surface = degree2radian2 (f_surface); //OK
    printf ("convert to RAD f_surface = %f \n\n",f_surface);
    /////////////////////////////////////////////////////


    //f_reflection2 = fmod (f_reflection1, M_2XPI);


    //https://gamedev.net/forums/topic/385087-2d-ball-deflection-mini-golf-game/385087/
    //ball.angle = surface.angle - ( ball.angle - surface.angle )
    //f_reflection2 = f_surface - (f_ray - f_surface);
    //printf ("f_reflection2 = %f \n",f_reflection2);

    //https://stackoverflow.com/questions/5830791/find-radians-reflection-angle

    f_reflection1 = normalize(f_reflection2,  0, M_2XPI );
    printf ("Normalize Reflection = %f \n",f_reflection1);

    f_reflection1 = radian2degree2 (f_reflection2);
    reflection = (int) f_reflection1;

    printf ("\nReflection = %f \n",f_reflection1);
    slomo();
    printf ("Press a Key\n");
    in_pause(0);
}
/////////////////////////////////////////////////////

void reflection2 (void)
{
    float f_reflection1 = 0;
    float f_reflection2 = 0;

    int incomingRay = 0;
    int surfaceAngle = 0;
    int reflection = 0;

    slomo();

    printf("\x16\x01\x02");
	printf ("Hello Reflection\n");

    printf ("Enter Incoming Ray Angle ");
    scanf("%d", &incomingRay);
    printf ("\nIncoming Ray = %d \n",incomingRay);

    printf ("Enter Surface Angle ");
    scanf("%d", &surfaceAngle);
    printf ("\nSurface Angle = %d \n",surfaceAngle);

    reflection = surfaceAngle - ( incomingRay - surfaceAngle );

    f_reflection1 = (float) reflection;

    f_reflection2 = reflection % 360;

    if (f_reflection2 < 0)
    {
        f_reflection2 += 360.0;
    }

    reflection = (int) f_reflection2;

    printf ("\nReflection = %d \n",reflection);

    slomo();
    printf ("Press a Key\n");
    in_pause(0);
}

/////////////////////////////////////////////////////


void reflection3 (void)
{
    float f_reflection1 = 0;
    float f_reflection2 = 0;
    float f_ray = 0;
    float f_surface = 0;
    float f_reflection = 0;
    int incomingRay = 0;
    int surfaceAngle = 0;
    int reflection = 0;

    slomo();

    printf("\x16\x01\x02");
	printf ("Hello Reflection\n");

    printf ("Enter Incoming Ray Angle ");
    scanf("%d", &incomingRay);
    printf ("\nIncoming Ray = %d \n",incomingRay);

    printf ("Enter Surface Angle ");
    scanf("%d", &surfaceAngle);
    printf ("\nSurface Angle = %d \n",surfaceAngle);

    //convert ray to radians
    f_ray = (float) incomingRay;
    f_ray = degree2radian2 (f_ray);

    //convert surface to radians
    f_surface = (float) surfaceAngle;
    f_surface = degree2radian2 (f_surface);

    f_reflection1 = f_surface - (f_ray - f_surface);

    f_reflection2 = fmod (f_reflection1, M_PI_3_M);

    if (f_reflection2 < 0)
    {
        f_reflection2 += M_PI_M;
    }

    f_reflection1 = radian2degree2 (f_reflection2);

    reflection = (int) f_reflection1;

    printf ("\nReflection = %d \n",reflection);

    slomo();
    printf ("Press a Key\n");
    in_pause(0);
}

/////////////////////////////////////////////////////

void reflection6 (void)//try to work in degrees
{
    int incomingRay = 0;
    int surfaceAngle = 0;
    int reflection1 = 0;
    int reflection2 = 0;
    int oppositeAngle = 0;
    int difference = 0;

    slomo();

    printf("\x16\x01\x02");
	printf ("Hello Reflection\n");
	printf ("Enter Surface Angle ");
    scanf("%d", &surfaceAngle);
    printf ("\nSurface Angle = %d \n",surfaceAngle);

    ////////////
    //calculate opposite angle
    if (surfaceAngle < 180)
    {//if you use <= 180 opposite angle will be 360
        oppositeAngle = surfaceAngle + 180;//good
    }
    if (surfaceAngle >= 180)
    {///if you use >= 180 opposite angle will be 0
        oppositeAngle = surfaceAngle - 180;//good
    }
    printf ("oppositeAngle = %d \n\n",oppositeAngle);
    ////////////
    // opposite angles seem good
    ////////////

    printf ("Enter Incoming Ray Angle ");
    scanf("%d", &incomingRay);
    printf ("\nIncoming Ray = %d \n",incomingRay);

    difference = ABS (incomingRay - surfaceAngle);
    printf ("difference = %d \n\n",difference);

	if (difference <= 180)
    {
        reflection1 = oppositeAngle - difference;
        printf ("ZOINKS \n");
    }

    if (difference > 180)
    {
        reflection1 = surfaceAngle + difference;
        printf ("WTF \n");
    }

    //special case coming at the edge
    //leave for last check
    if (incomingRay == surfaceAngle)
    {
        reflection1 = surfaceAngle;
    }
    if (incomingRay == oppositeAngle)
    {
        reflection1 = oppositeAngle;
    }

    printf ("## reflection1 = %d \n\n",reflection1);

    slomo();
    printf ("Press a Key\n");
    in_pause(0);
}

/////////////////////////////////////////////////////

//i.e. using 180 instead of 0, it will introduce a wrong angle
// issue found, if you use opposite angle as surface
void reflection4 (void)//try to work in degrees
{
    float f_reflection1 = 0;
    float f_reflection2 = 0;

    int incomingRay = 0;
    int surfaceAngle = 0;
    int reflection1 = 0;
    int reflection2 = 0;
    int oppositeAngle = 0;
    int difference = 0;

    slomo();

    printf("\x16\x01\x02");
	printf ("Hello Reflection\n");

	printf ("Enter Surface Angle ");
    scanf("%d", &surfaceAngle);
    printf ("\nSurface Angle = %d \n",surfaceAngle);

	if (surfaceAngle < 180)
    {
        oppositeAngle = surfaceAngle + 180;
    }
    if (surfaceAngle > 180)
    {
        oppositeAngle = surfaceAngle - 180;
    }
    printf ("oppositeAngle = %d \n\n",oppositeAngle);
    ////////////

    printf ("Enter Incoming Ray Angle ");
    scanf("%d", &incomingRay);
    printf ("\nIncoming Ray = %d \n",incomingRay);
    ////////////

    difference = ABS (incomingRay - surfaceAngle);
    printf ("difference = %d \n\n",difference);

    reflection1 = oppositeAngle - (difference);
    printf ("## reflection1 = %d \n\n",reflection1);

    if (reflection1 > 360)
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

    printf ("Reflection formula = %d \n",reflection2);

    f_reflection1 = (float) reflection1;

    f_reflection2 = reflection1 % 360;

    if (f_reflection2 < 0)
    {
        f_reflection2 += 360.0;
    }

    reflection1 = (int) f_reflection2;

    printf ("\nReflection = %d \n",reflection1);

    slomo();
    printf ("Press a Key\n");
    in_pause(0);
}

/////////////////////////////////////////////////////


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







