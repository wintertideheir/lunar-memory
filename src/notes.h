#include <time.h>

/* The maximum score possible for a note. Because the maxiumum reaction
 * time of a human is around 0.2 seconds, the maximum score is it's
 * inverse, 5 per second.
 */
#define MAX_SCORE 5.0f

struct Note
{
    time_t last_updated;
    char *code;

    /* The category of the note. Subcategories are seperated by periods
     * and read from left to right.
     */
    char* category;

    /* The score calculated and time of recording when the last note
     * was presented. The score is by default defined as the the
     * inverse of the time it takes to process the note. Notes may
     * choose other methods of assigning scores. The score should
     * always be between 0 and MAX_SCORE.
     */
    time_t score_time;
    float score;

    /* Each note is tagged with tags_len strings. These tags provide
     * simple, additional information, like the type of note, what
     * collection it came from, or it's revision status.
     */
    int tags_len;
    char **tags;
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
