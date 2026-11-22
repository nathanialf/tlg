/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00404aa0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt). Then, in declaration order, 11 names
 * from strings, each registered with Name's destructor (0x1331800), and a
 * list, destroyed by the array destructor the compiler writes for it
 * (0x404ed0). What reads them is not traced. */

/* an entry of 8 bytes, the name first: the initializer stores the name
 * only, and the destructor releases the name only (the second word not
 * traced) */
struct Entry00404aa0 { /* derived name */

    template <size_t N> Entry00404aa0(const char (&string)[N], bool add = true) : name(string, add)
    {
    }

    Name name;    /* +0x0 */
    u32 unknown4; /* +0x4 */
};

extern const char D_1569442[10];
extern const char D_156944c[10];
extern const char D_1569456[10];
extern const char D_1569460[12];
extern const char D_156946c[11];
extern const char D_1569477[16];
extern const char D_15910d7[20];
extern const char D_15c627c[41];
extern const char D_15c62a5[40];
extern const char D_15ca5c5[15];
extern const char D_15ca64f[15];
extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_57d3780(D_15cb5dd, false);
Name D_57d3784(D_15cb5e6, false);
Name D_57d3788(D_15c627c);
Name D_57d378c(D_15c62a5);
Name D_57d3608(D_15910d7);
Name D_57d35fc(D_1569442);
Name D_57d3600(D_156944c);
Name D_57d3604(D_1569456);

static Entry00404aa0 D_57d3650[] = {D_15ca5c5, D_15ca64f};

Name D_57d362c(D_1569460, false);
Name D_57d3634(D_156946c, false);
Name D_57d3630(D_1569477, false);
