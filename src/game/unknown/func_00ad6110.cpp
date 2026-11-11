/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_name.h"

/* derived names: FUN_00ad6110 is this file's static initializer. Among its
 * objects are 1 list of names built from strings, each destroyed by the array
 * destructor the compiler writes for it (0xad6460, registered with
 * __cxa_atexit in that order). Only the lists are written. */

/* an entry of 8 bytes, the name first: the initializer stores the name
 * only, and the destructor releases the name only (the second word not
 * traced) */
struct Entry00ad6110 { /* derived name */

    Entry00ad6110(const Name &name) : name(name) {}

    Name name;    /* +0x0 */
    u32 unknown4; /* +0x4 */
};

extern const char D_15a8d1c[13];
extern const char D_15a8d29[18];
extern const char D_15a8d3b[17];
extern const char D_15a8d4c[12];
extern const char D_15a8d58[17];
extern const char D_15a8d69[16];
extern const char D_15c8db4[7];

// NONMATCHING: the file's initializer (FUN_00ad6110): only the lists are
// written; its other objects are not.
static Entry00ad6110 D_582d0a0[] = {
    Name(D_15c8db4, false), Name(D_15a8d1c, false), Name(D_15a8d29, false), Name(D_15a8d3b, false),
    Name(D_15a8d4c, false), Name(D_15a8d58, false), Name(D_15a8d69, false)};
