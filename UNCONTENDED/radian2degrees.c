
void radians2Degrees (void)
{

    slomo();
    printf("\x16\x01\x02");
	printf ("Hello Radian to Degrees \n\n");
	printf ("Converts Radians to Degrees \n\n");

    printf ("Enter Radian \n");
    scanf("%s", &string);

    radians = atof(string);
    printf ("\nRadians = %f ",radians);

    radian2 = radian2degree(radians);

    printf ("Degrees = %f \n",radian2);

    slomo();
    printf ("Press a Key\n");
    in_pause(0);
}


