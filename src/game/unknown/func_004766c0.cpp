/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_004766c0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then, in declaration order, 6 lists,
 * each destroyed by the array destructor the compiler writes for it (0x477570,
 * 0x4775e0, 0x477650, 0x477870, 0x4778e0, 0x477950). What reads them is not
 * traced. */

// NONMATCHING: the file's initializer (FUN_004766c0): the register assignment
// after the first registration (rbx and r14 exchanged, 0x4768f7); it also
// registers the destructors of two 11-name lists (0x477570, 0x4775e0), loops
// in the base that the build unrolls (655 bytes against 99).

extern const char D_156d60e[13];
extern const char D_156d61b[29];
extern const char D_156d638[8];
extern const char D_156d640[17];
extern const char D_156d651[13];
extern const char D_156d65e[15];
extern const char D_156d66d[14];
extern const char D_156d67b[14];
extern const char D_156d689[19];
extern const char D_156d69c[18];
extern const char D_15b7c67[8];

static Name D_57d6290[] = {Name(D_156d60e, false),
                           Name(D_156d60e, false),
                           Name(D_156d60e, false),
                           Name(D_156d60e, false),
                           Name(D_156d60e, false),
                           Name(D_156d60e, false),
                           Name(D_156d60e, false),
                           Name(),
                           Name(),
                           Name(),
                           Name()};

static Name D_57d62c0[] = {
    Name(), Name(), Name(D_156d61b, false), Name(), Name(), Name(), Name(), Name(), Name(),
    Name(), Name()};

static Name D_57d6500[] = {Name(D_15b7c67, false), Name(D_156d638, false), Name(D_156d640, false),
                           Name(D_156d651, false), Name(D_156d65e, false), Name(D_156d66d, false),
                           Name(D_156d67b, false), Name(D_156d689, false), Name(D_156d69c, false)};

static Name D_57d62f0[] = {Name(D_156d638, false),
                           Name(D_156d67b, false),
                           Name(D_156d689, false),
                           Name(D_156d69c, false),
                           Name(D_156d640, false),
                           Name(D_156d67b, false),
                           Name(D_156d689, false),
                           Name(D_156d69c, false),
                           Name(D_156d66d, false),
                           Name(D_156d66d, false),
                           Name(D_156d69c, false),
                           Name(D_156d69c, false),
                           Name(D_156d640, false),
                           Name(D_156d640, false),
                           Name(D_156d689, false),
                           Name(D_156d69c, false),
                           Name(D_156d651, false),
                           Name(D_156d67b, false),
                           Name(D_156d689, false),
                           Name(D_156d69c, false),
                           Name(D_156d65e, false),
                           Name(D_156d67b, false),
                           Name(D_156d689, false),
                           Name(D_156d69c, false),
                           Name(D_156d640, false),
                           Name(),
                           Name(D_156d689, false),
                           Name(D_156d69c, false),
                           Name(),
                           Name(),
                           Name(),
                           Name(),
                           Name(),
                           Name(),
                           Name(),
                           Name(),
                           Name(),
                           Name(),
                           Name(),
                           Name(),
                           Name(),
                           Name(),
                           Name(),
                           Name()};

static Name D_57d63a0[] = {Name(D_156d67b, false),
                           Name(D_156d67b, false),
                           Name(D_156d689, false),
                           Name(D_156d69c, false),
                           Name(D_156d67b, false),
                           Name(D_156d67b, false),
                           Name(D_156d689, false),
                           Name(D_156d69c, false),
                           Name(D_156d66d, false),
                           Name(D_156d66d, false),
                           Name(D_156d69c, false),
                           Name(D_156d69c, false),
                           Name(D_156d640, false),
                           Name(D_156d640, false),
                           Name(D_156d689, false),
                           Name(D_156d69c, false),
                           Name(D_156d67b, false),
                           Name(D_156d67b, false),
                           Name(D_156d689, false),
                           Name(D_156d69c, false),
                           Name(D_156d67b, false),
                           Name(D_156d67b, false),
                           Name(D_156d689, false),
                           Name(D_156d69c, false),
                           Name(D_156d689, false),
                           Name(),
                           Name(D_156d689, false),
                           Name(D_156d69c, false),
                           Name(),
                           Name(),
                           Name(),
                           Name(),
                           Name(),
                           Name(),
                           Name(),
                           Name(),
                           Name(),
                           Name(),
                           Name(),
                           Name(),
                           Name(),
                           Name(),
                           Name(),
                           Name()};

static Name D_57d6450[] = {Name(D_156d67b, false),
                           Name(D_156d67b, false),
                           Name(D_156d689, false),
                           Name(D_156d69c, false),
                           Name(D_156d67b, false),
                           Name(D_156d67b, false),
                           Name(D_156d689, false),
                           Name(D_156d69c, false),
                           Name(D_156d66d, false),
                           Name(D_156d66d, false),
                           Name(D_156d69c, false),
                           Name(D_156d69c, false),
                           Name(D_156d640, false),
                           Name(D_156d640, false),
                           Name(D_156d689, false),
                           Name(D_156d69c, false),
                           Name(D_156d67b, false),
                           Name(D_156d67b, false),
                           Name(D_156d689, false),
                           Name(D_156d69c, false),
                           Name(D_156d67b, false),
                           Name(D_156d67b, false),
                           Name(D_156d689, false),
                           Name(D_156d69c, false),
                           Name(D_156d689, false),
                           Name(),
                           Name(D_156d689, false),
                           Name(D_156d69c, false),
                           Name(),
                           Name(),
                           Name(),
                           Name(),
                           Name(),
                           Name(),
                           Name(),
                           Name(),
                           Name(),
                           Name(),
                           Name(),
                           Name(),
                           Name(),
                           Name(),
                           Name(),
                           Name()};
