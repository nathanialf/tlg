/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_name.h"

/* derived names: FUN_00404aa0 is this file's static initializer. Among its
 * objects are 1 list of names built from strings, each destroyed by the array
 * destructor the compiler writes for it (0x404ed0, registered with
 * __cxa_atexit in that order). Only the lists are written. */

/* an entry of 8 bytes, the name first: the initializer stores the name
 * only, and the destructor releases the name only (the second word not
 * traced) */
struct Entry00404aa0 { /* derived name */

    Entry00404aa0(const Name &name) : name(name) {}

    Name name;    /* +0x0 */
    u32 unknown4; /* +0x4 */
};

extern const char D_15ca5c5[15];
extern const char D_15ca64f[15];

// NONMATCHING: the file's initializer (FUN_00404aa0): only the lists are
// written; its other objects are not.
static Entry00404aa0 D_57d3650[] = {Name(D_15ca5c5), Name(D_15ca64f)};
