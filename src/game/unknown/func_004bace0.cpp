/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_name.h"

/* derived names: FUN_004bace0 is this file's static initializer. Among its
 * objects are 2 lists of names built from strings, each destroyed by the array
 * destructor the compiler writes for it (0x4bb760, 0x4bb820, registered with
 * __cxa_atexit in that order). Only the lists are written. */

/* an entry of 8 bytes, the name first: the initializer stores the name
 * only, and the destructor releases the name only (the second word not
 * traced) */
struct Entry004bace0 { /* derived name */

    Entry004bace0(const Name &name) : name(name) {}

    Name name;    /* +0x0 */
    u32 unknown4; /* +0x4 */
};

extern const char D_156f395[16];
extern const char D_156f3a5[22];
extern const char D_156f3bb[7];
extern const char D_156f3c2[15];
extern const char D_156f3d1[14];
extern const char D_156f3df[19];
extern const char D_156f3f2[20];
extern const char D_156f406[17];
extern const char D_156f417[19];

// NONMATCHING: the file's initializer (FUN_004bace0): only the lists are
// written; its other objects are not.
static Entry004bace0 D_57d8558[] = {Name(D_156f395, false), Name(D_156f3a5, false),
                                    Name(D_156f3bb, false)};
static Entry004bace0 D_57d8570[] = {Name(D_156f3c2, false), Name(D_156f3d1, false),
                                    Name(D_156f3df, false), Name(D_156f3f2, false),
                                    Name(D_156f406, false), Name(D_156f417, false)};
