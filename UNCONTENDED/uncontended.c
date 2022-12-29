// using sdcc_iy 1.99c

#pragma scanf  %f

//Using advise from Stefan
//moved Stack pointer from $BFFF to $C000 as
//Stack automatically decrements before useage
// see zpragma.inc in Uncontended

#include "define.h"

#include <arch/zx.h>
#include <stdlib.h>//standard library
#include <stdio.h>//standard input output
#include <input.h>//used for detecting key inputs
#include <math.h>


#include <intrinsic.h>//temp to place labels
//powerful troubleshooting tool
    //intrinsic_label(border_start);
    //intrinsic_label(border_end);


#include "externs.h"    //references to asm functions
#include "variables.h"

#include "functions.c"

#include "degrees2radian.c"
#include "radian2degrees.c"

void main ()
{
    //new
    //SETUP_IM2();// set up for the interrupt MODE 2
    // this will point the I register to IM2 Vector

    zx_cls(PAPER_WHITE);
    printf("\x16\x01\x02");

    while (1)
    {

        routineChoice = 0;
        printf ("1 Slope Calculation\n");
        printf ("2 Degrees to Radian\n");
        printf ("3 Radians to Degrees\n");
        printf ("4 Reflection\n");
        printf ("5 Wrap Around PI\n");
        printf ("6 Wrap Around Double PI\n");
        printf ("9 Around the Compass *LONG*\n");

        printf ("enter choice ");

        scanf("%d", &routineChoice);
        //routineChoice = 1;

        zx_cls(PAPER_WHITE);

        switch (routineChoice)
        {
            /*case 0:
            {
                //do nothing
                break;
            }*/
            case 1:
            {
                slopeCalculation();
                break;
            }
            case 2:
            {
                degrees2Radians();
                break;
            }
            case 3:
            {
                radians2Degrees();
                break;
            }
            case 4:
            {
                reflection5 ();
                break;
            }
            case 5:
            {
                wrapAroundPI2();
                break;
            }
            case 6:
            {
                wrapAroundPI();
                break;
            }
            case 7:
            {
                wrapAroundPI();
                break;
            }
            case 8:
            {
                wrapAroundPI();
                break;
            }
            case 9:
            {
                aroundCompass();
                break;
            }
        }

        //printf("\x16\x01\x02");
        //printf ("press enter ");
        //scanf("%s", input);

        in_pause(0);
        printf ("press enter ");
        zx_cls(PAPER_WHITE);
        printf("\x16\x01\x02");

    }


}

// must have blank line at end
