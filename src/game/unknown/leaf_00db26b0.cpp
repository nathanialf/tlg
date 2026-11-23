/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_scriptcode.h"
#include "tlg_libc.h"

/* the names of the script's types, from the strings */
extern const char D_14b3a40[]; /* "object" */
extern const char D_15bd63d[]; /* "no value" */
extern const char D_15bd113[]; /* "nil" */
extern const char D_15bd646[]; /* "boolean" */
extern const char D_15bd663[]; /* "luserdata" */
extern const char D_15bc267[]; /* "number" */
extern const char D_14b2532[]; /* "string" */
extern const char D_15b9a9d[]; /* "table" */
extern const char D_15bd66d[]; /* "invalid function" */
extern const char D_15bd64e[]; /* "userdata" */
extern const char D_15bd657[]; /* "thread" */
extern const char D_15bd67e[]; /* "ifunction" */
extern const char D_15bd688[]; /* "cfunction" */
extern const char D_15bd65e[]; /* "ui64" */
extern const char D_14cb9c9[]; /* "struct" */

/* derived names: the built-in type of a name (FUN_00db3300 and three more
 * call it): -2 for "object", the type's number for the names of the types
 * from "no value" (-1) to "struct" (12), -1 for any other name */
int FUN_00db26b0(ScriptString016bb0c0 *name)
{
    const char *chars = name->chars;
    if (!strcmp(D_14b3a40, chars))
        return -2;
    if (!strcmp(D_15bd63d, chars))
        return -1;
    if (!strcmp(D_15bd113, chars))
        return 0;
    if (!strcmp(D_15bd646, chars))
        return 1;
    if (!strcmp(D_15bd663, chars))
        return 2;
    if (!strcmp(D_15bc267, chars))
        return 3;
    if (!strcmp(D_14b2532, chars))
        return 4;
    if (!strcmp(D_15b9a9d, chars))
        return 5;
    if (!strcmp(D_15bd66d, chars))
        return 6;
    if (!strcmp(D_15bd64e, chars))
        return 7;
    if (!strcmp(D_15bd657, chars))
        return 8;
    if (!strcmp(D_15bd67e, chars))
        return 9;
    if (!strcmp(D_15bd688, chars))
        return 10;
    if (!strcmp(D_15bd65e, chars))
        return 11;
    if (!strcmp(D_14cb9c9, chars))
        return 12;
    return -1;
}
