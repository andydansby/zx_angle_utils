


float N_atan2(float yyy, float xxx)
{
    //https://developer.download.nvidia.com/cg/atan2.html
    float t0, t1, t3, t4;

    t3 = _ABS(xxx);
    t1 = _ABS(yyy);
    t0 = _MAX(t3, t1);
    t1 = _MIN(t3, t1);
    t3 = 1.0 / t0;
    t3 = t1 * t3;

    t4 = t3 * t3;
    t0 =         - 0.013480470;
    t0 = t0 * t4 + 0.057477314;
    t0 = t0 * t4 - 0.121239071;
    t0 = t0 * t4 + 0.195635925;
    t0 = t0 * t4 - 0.332994597;
    t0 = t0 * t4 + 0.999995630;
    t3 = t0 * t3;

    t3 = (_ABS(yyy) > _ABS(xxx)) ? _M_PI_2 - t3 : t3;
    //t3 = (xxx > 0) ?  _M_PI - t3 : t3;//slightly modified line
    t3 = (xxx < 0) ?  _M_PI - t3 : t3;
    t3 = (yyy < 0) ? -t3 : t3;

    return t3;
}

float N_atan(float xxx)
{
    return N_atan2(xxx, 1.0);
}






