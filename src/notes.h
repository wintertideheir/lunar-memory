#include <time.h>

struct Note
{
    /* When the code was last updated. */
    time_t updated;
    /* The last two times the note was presented. */
    time_t presented[2];

    char *code;

    /* The category of the note. Subcategories are seperated by periods
     * and read from left to right.
     */
    char* category;

    /* The score calculated when the last note was presented.
     * Must be between 0f and 1f.
     */
    float score;
};

/* An improved forgetting curve (called the Ebbinghaus curve in Lunar
 * Memory) describing how a particular kind of memory failiure,
 * transience, relates to time.
 *
 * Parameters:
 *     * time, a unitless meausure of how long time has passed since
 *       the last review. In practice it has units of days. Must be
 *       between 0f and FLT_MAX (see float.h).
 *     * alpha, a unitless free parameter. Must be non-zero and
 *       positive.
 *
 * Returns:
 *     A number between 1f and 0f that predicts what percent of
 *     information is retained after a given length of time. The return
 *     value can be reinterpreted as the chance for any randomly
 *     selected fragment of information being remembered after the
 *     given length of time.
 */
float ebbinghaus_curve(float time, float alpha);

/* Calculate the coefficient for a Ebbinghaus curve given a score and
 * time.
 *
 * Parameters:
 *     * score, a given score between 1f and 0f.
 *     * time, the non-zero length of time between when the note was
 *       last shown and when the score was recorded.
 *
 * Returns:
 *     The coefficient alpha for the Ebbinghaus curve that corresponds
 *     to the given score and time.
 */
float ebbinghaus_curve_coefficient(float score, float time);
