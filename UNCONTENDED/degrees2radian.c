void degrees2Radians (void)
{

    slomo();

    printf("\x16\x01\x02");
	printf ("Hello Degrees to Radian\n");

    printf ("Enter Degrees ");
    scanf("%d", &degrees);

    printf ("\nDegrees = %d ",degrees);
    radian = degree2radian (degrees);
    printf ("Radians = %f \n",radian);

    slomo();
    printf ("Press a Key\n");
    in_pause(0);

}

