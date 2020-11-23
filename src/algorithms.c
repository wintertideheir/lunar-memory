#include <math.h>
#include <float.h>

float ebbinghaus_curve(float time,
                       float alpha)
{
    return 1f / ((alpha * logf(time + 1f)) + 1f);
}

float ebbinghaus_curve_coefficient(float score,
                                   float time)
{
    // Prevent a division by zero error 
    float score_adjusted = (score == 0) ? FLT_EPSILON : score;

    return ((1 / score_adjusted) - 1) / logf(time + 1f);
}
