/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_name.h"

/* derived names: FUN_008a82f0 is this file's static initializer. Among its
 * objects are 3 lists of names built from strings, each destroyed by the array
 * destructor the compiler writes for it (0x8aec00, 0x8aed30, 0x8aee30, registered with
 * __cxa_atexit in that order). Only the lists are written. */

/* an entry of 8 bytes, the name first: the initializer stores the name
 * only, and the destructor releases the name only (the second word not
 * traced) */
struct Entry008a82f0 { /* derived name */

    Entry008a82f0(const Name &name) : name(name) {}

    Name name;    /* +0x0 */
    u32 unknown4; /* +0x4 */
};

extern const char D_159bb29[8];
extern const char D_159bb31[7];
extern const char D_159bb38[10];
extern const char D_159bb42[11];
extern const char D_159bb4d[10];
extern const char D_159bb57[9];
extern const char D_159bb60[12];
extern const char D_159bb6c[14];
extern const char D_15a41e2[5];
extern const char D_15a41e7[5];
extern const char D_15a41ec[5];
extern const char D_15c7a8a[5];
extern const char D_15c94db[5];

// NONMATCHING: the file's initializer (FUN_008a82f0): only the lists are
// written; its other objects are not.
static Entry008a82f0 D_581e760[] = {Name(D_159bb29), Name(D_159bb31), Name(D_159bb38),
                                    Name(D_159bb42), Name(D_159bb4d)};
static Name D_581e790[] = {Name(D_15c7a8a), Name(D_159bb57), Name(D_159bb60), Name(D_159bb6c)};
static Entry008a82f0 D_581f010[] = {Name(D_15a41e2), Name(D_15c94db), Name(D_15a41e7),
                                    Name(D_15a41ec)};
