#include <time.h>

/* The maximum score possible for a note. Because the maxiumum reaction
 * time of a human is around 0.2 seconds, the maximum score is it's
 * inverse, 5 per second.
 */
#define MAX_SCORE 5.0f

struct Note
{
    /* Code to run the note and when it was created. The code ought to
     * be written in Lunar Memory's variant of LuaTeX, and verified
     * correct before being embodied in a note.
     */
    const time_t code_time;
    const char *code;

    /* The category of the note, given by an alphabetic identifier.
     * Categories may be composed of subcategories, in which case the
     * identifiers are concatenated with periods.
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

    /* Each note is tagged with tag_lens strings. These tags provide
     * simple, additional information, like the type of note, what
     * collection it came from, or it's revision status.
     */
    int tags_len;
    char **tags;
};
