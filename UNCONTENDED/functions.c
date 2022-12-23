

void slomo (void)
{
    for (temp1 = 0; temp1 < 20000; temp1++)
    {
    }
}

//http://lab.polygonal.de/2007/07/18/fast-and-accurate-sinecosine-approximation/
//good from -PI to PI
float _mikeSIN (float xx)
{
    # define M_PI_DIV4      1.273   //4/PI
    # define M_PI_POW_DIV4  0.405   //-4/(PI*PI)
    const float B = M_PI_DIV4;
    const float C = M_PI_POW_DIV4;
    float sin, BCalc, CCalc;
    //float powX = xx * xx;

    if (xx < -3.14)
        xx += 6.28;
    else
    if (xx > 3.14)
        xx-=6.28;

    CCalc = C * xx * xx;
    BCalc = B * xx;

    if (xx < 0)
        sin = BCalc + CCalc;
    else
        sin = BCalc - CCalc;

    return sin;
}

float _mikeCOS (float xx)
{
    return _mikeSIN(1.57 - xx);
}
