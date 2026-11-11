/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_name.h"

/* derived names: FUN_0126c7f0 is this file's static initializer. Among its
 * objects are 1 list of names built from strings, each destroyed by the array
 * destructor the compiler writes for it (0x1270590, registered with
 * __cxa_atexit in that order). Only the lists are written. */

/* an entry of 8 bytes, the name first: the initializer stores the name
 * only, and the destructor releases the name only (the second word not
 * traced) */
struct Entry0126c7f0 { /* derived name */

    Entry0126c7f0(const Name &name) : name(name) {}

    Name name;    /* +0x0 */
    u32 unknown4; /* +0x4 */
};

extern const char D_15c9ed8[6];
extern const char D_15c9ede[7];
extern const char D_15c9ee5[6];

// NONMATCHING: the file's initializer (FUN_0126c7f0): only the lists are
// written; its other objects are not.
static Entry0126c7f0 D_5ad7cc0[] = {Name(D_15c9ed8), Name(D_15c9ede), Name(D_15c9ee5)};
