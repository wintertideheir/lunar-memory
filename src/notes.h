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
