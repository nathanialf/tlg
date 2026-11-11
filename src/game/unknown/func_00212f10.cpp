/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_name.h"

/* derived names: FUN_00212f10 is this file's static initializer. Among its
 * objects are 1 list of names built from strings, each destroyed by the array
 * destructor the compiler writes for it (0x214710, registered with
 * __cxa_atexit in that order). Only the lists are written. */

/* an entry of 8 bytes, the name first: the initializer stores the name
 * only, and the destructor releases the name only (the second word not
 * traced) */
struct Entry00212f10 { /* derived name */

    Entry00212f10(const Name &name) : name(name) {}

    Name name;    /* +0x0 */
    u32 unknown4; /* +0x4 */
};

extern const char D_155fa0c[16];
extern const char D_155fa1c[10];
extern const char D_155fa26[10];
extern const char D_155fa30[13];
extern const char D_155fa3d[16];
extern const char D_156983a[4];
extern const char D_15a8f79[5];
extern const char D_15c7a8a[5];

// NONMATCHING: the file's initializer (FUN_00212f10): only the lists are
// written; its other objects are not.
static Entry00212f10 D_57ca0e0[] = {Name(D_15c7a8a), Name(D_15a8f79), Name(D_155fa0c),
                                    Name(D_155fa1c), Name(D_156983a), Name(D_155fa26),
                                    Name(D_155fa30), Name(D_155fa3d)};
