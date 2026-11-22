/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00212f10 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then a list of 8 entries named from
 * strings, destroyed by the array destructor the compiler writes for it
 * (0x214710). The list is file-local: FUN_0020e2a0 compares a name with each
 * entry in turn and keeps the position. */

/* an entry of 8 bytes, the name first: the initializer stores the name
 * only, and the destructor releases the name only (the second word not
 * traced) */
struct Entry00212f10 { /* derived name */

    template <size_t N> Entry00212f10(const char (&string)[N]) : name(string) {}

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

static Entry00212f10 D_57ca0e0[] = {D_15c7a8a, D_15a8f79, D_155fa0c, D_155fa1c,
                                    D_156983a, D_155fa26, D_155fa30, D_155fa3d};
