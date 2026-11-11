/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_name.h"

/* derived names: FUN_004bc940 is this file's static initializer. Among its
 * objects are 1 list of names built from strings, each destroyed by the array
 * destructor the compiler writes for it (0x4bcb80, registered with
 * __cxa_atexit in that order). Only the lists are written. */

/* a value and its name, 8 bytes */
struct Valued004bc940 { /* derived name */
    int value;          /* +0x0 */
    Name name;          /* +0x4 */
};

extern const char D_156f4ab[14];
extern const char D_156f4b9[12];
extern const char D_15b953a[5];
extern const char D_15bd10e[5];

// NONMATCHING: the file's initializer (FUN_004bc940): only the lists are
// written; its other objects are not.
static Valued004bc940 D_57d8730[] = {{0, Name(D_15bd10e, false)},
                                     {1, Name(D_156f4ab, false)},
                                     {2, Name(D_156f4b9, false)},
                                     {3, Name(D_15b953a, false)}};
