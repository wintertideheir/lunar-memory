#include <time.h>

struct Note
{
    time_t created;  // Date of creation
    char  *code;     // Code to run note as a null-terminated string.
    int    score;    // Score when note was last presented
    int    tags_len; // Number of tags
    char **tags;     // Tags associated with note
};
