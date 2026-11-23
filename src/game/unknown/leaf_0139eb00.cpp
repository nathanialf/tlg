/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_libc.h"

/* derived names: replaces the characters from start up to end of a text
 * in a buffer of 1024 bytes with another text (called by FUN_00bec050):
 * a longer text moves the rest up first, and is refused where the result
 * would not fit; a shorter one is copied in and the rest, its terminator
 * with it, moved down after it */
// NONMATCHING: register assignment from the entry: the base keeps start in
// r13 and spills the text's pointer ([rbp-0x30]), the build keeps the text
// in r13 and spills start; the blocks, the tests and the growth loop are the
// base's
void FUN_0139eb00(char *buffer, int start, int end, const char *text) /* derived name */
{
    int length = strlen(text);
    int growth = length - (end - start);
    if (growth > 0) {
        unsigned size = strlen(buffer);
        if (size + growth + 1 > 1023)
            return;
        char *moved = buffer + (start + length - end);
        for (int i = size; i >= end; --i)
            moved[i] = buffer[i];
    } else if (growth < 0) {
        int size = strlen(buffer);
        strncpy(buffer + start, text, length);
        char *moved = buffer + (start + length - end);
        for (int i = end; i <= size; ++i)
            moved[i] = buffer[i];
        return;
    }
    strncpy(buffer + start, text, length);
}
