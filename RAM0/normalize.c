
static void  naked_placement_in_RAM0_a(void) __naked
{
    __asm
        SECTION BANK_00
    __endasm;
}

float scaleNumbers (float input, float inputLow, float inputHigh, float outputLow, float outputHigh)
{
    float slope1 =  (outputHigh - outputLow) / (inputHigh - inputLow);
    return outputLow + slope1 * (input - inputLow);
}


static void  naked_placement_in_RAM0_b(void) __naked
{
    __asm
        SECTION BANK_00
    __endasm;
}
// Normalizes any number to an arbitrary range
// by assuming the range wraps around when going below min or above max
float normalize(float value, float start, float end)
{
  float width       = end - start;   //
  float offsetValue = value - start;   // value relative to 0

  return ( offsetValue - ( floor( offsetValue / width ) * width ) ) + start ;
  // + start to reset back to start of original range
}






