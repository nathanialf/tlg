/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00ad6110 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt). Then, in declaration order, 4 names from
 * strings, each registered with Name's destructor (0x1331800), and a list,
 * destroyed by the array destructor the compiler writes for it (0xad6460).
 * What reads them is not traced. */

/* an entry of 8 bytes, the name first: the initializer stores the name
 * only, and the destructor releases the name only (the second word not
 * traced) */
struct Entry00ad6110 { /* derived name */

    template <size_t N> Entry00ad6110(const char (&string)[N], bool add = true) : name(string, add)
    {
    }

    Name name;    /* +0x0 */
    u32 unknown4; /* +0x4 */
};

extern const char D_15a8cda[33];
extern const char D_15a8cfb[33];
extern const char D_15a8d1c[13];
extern const char D_15a8d29[18];
extern const char D_15a8d3b[17];
extern const char D_15a8d4c[12];
extern const char D_15a8d58[17];
extern const char D_15a8d69[16];
extern const char D_15c8db4[7];
extern const char D_15cb414[7];

Name D_582cf54(D_15a8cda, false);
Name D_582cf58(D_15a8cfb, false);
Name D_582d090(D_15cb414, false);
Name D_582d094(D_15c8db4, false);

static Entry00ad6110 D_582d0a0[] = {{D_15c8db4, false}, {D_15a8d1c, false}, {D_15a8d29, false},
                                    {D_15a8d3b, false}, {D_15a8d4c, false}, {D_15a8d58, false},
                                    {D_15a8d69, false}};
