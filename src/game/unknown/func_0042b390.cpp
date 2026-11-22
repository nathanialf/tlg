/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_0042b390 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then, in declaration order, 6 lists,
 * each destroyed by the array destructor the compiler writes for it (0x42c310,
 * 0x42c380, 0x42c3f0, 0x42c460, 0x42c560, 0x42c5d0). What reads them is not
 * traced. */

// NONMATCHING: the file's initializer (FUN_0042b390) is equal in bytes, but it
// registers the destructors of its three 11-name lists (0x42c310, 0x42c380,
// 0x42c3f0), loops in the base that the build unrolls (655 bytes against 99),
// so no row places it.

extern const char D_156ac0e[184];
extern const char D_156acc6[24];
extern const char D_156acde[20];
extern const char D_156acf2[20];
extern const char D_156d61b[29];
extern const char D_15a6523[6];
extern const char D_15b7c67[8];
extern const char D_15c8db4[7];

/* an entry of 8 bytes, the name first: the initializer stores the name
 * only, and the destructor releases the name only (the second word not
 * traced) */
struct Entry0042b390 { /* derived name */

    Entry0042b390(const Name &name) : name(name) {}

    template <size_t N> Entry0042b390(const char (&string)[N], bool add = true) : name(string, add)
    {
    }

    Name name;    /* +0x0 */
    u32 unknown4; /* +0x4 */
};

static Name D_57d4680[] = {Name(D_156ac0e, false), Name(D_156ac0e, false), Name(D_156ac0e, false),
                           Name(D_156ac0e, false), Name(D_156ac0e, false), Name(D_156ac0e, false),
                           Name(D_156ac0e, false), Name(D_15c8db4, false), Name(D_15a6523, false),
                           Name(D_15c8db4, false), Name(D_15c8db4, false)};

static Name D_57d46b0[] = {Name(D_15c8db4, false),
                           Name(D_15c8db4, false),
                           Name(D_15c8db4, false),
                           Name(D_15c8db4, false),
                           Name(D_15c8db4, false),
                           Name(D_15c8db4, false),
                           Name(D_15c8db4, false),
                           Name(),
                           Name(),
                           Name(),
                           Name()};

static Name D_57d46e0[] = {
    Name(), Name(), Name(D_156d61b, false), Name(), Name(), Name(), Name(), Name(), Name(),
    Name(), Name()};

static Entry0042b390 D_57d4870[] = {
    {D_15b7c67, false}, {D_156acc6, false}, {D_156acde, false}, {D_156acf2, false}};

static Name D_57d4710[] = {
    Name(D_156acc6, false), Name(D_156acc6, false), Name(D_156acde, false), Name(D_156acde, false),
    Name(D_156acc6, false), Name(D_156acc6, false), Name(D_156acde, false), Name(D_156acde, false),
    Name(D_156acc6, false), Name(D_156acc6, false), Name(D_156acc6, false), Name(D_156acc6, false),
    Name(D_156acc6, false), Name(D_156acc6, false), Name(D_156acde, false), Name(D_156acde, false),
    Name(D_156acc6, false), Name(D_156acc6, false), Name(D_156acde, false), Name(D_156acde, false),
    Name(D_156acc6, false), Name(D_156acc6, false), Name(D_156acde, false), Name(D_156acde, false),
    Name(D_156acc6, false), Name(D_156acc6, false), Name(D_156acde, false), Name(D_156acde, false),
    Name(D_156acc6, false), Name(D_156acc6, false), Name(D_156acde, false), Name(D_156acde, false),
    Name(D_156acc6, false), Name(D_156acc6, false), Name(D_156acc6, false), Name(D_156acc6, false),
    Name(D_156acf2, false), Name(D_156acf2, false), Name(D_156acf2, false), Name(D_156acf2, false),
    Name(D_156acf2, false), Name(D_156acf2, false), Name(D_156acf2, false), Name(D_156acf2, false)};

static Name D_57d47c0[] = {
    Name(D_156acc6, false), Name(D_156acc6, false), Name(D_156acde, false), Name(D_156acde, false),
    Name(D_156acc6, false), Name(D_156acc6, false), Name(D_156acde, false), Name(D_156acde, false),
    Name(D_156acc6, false), Name(D_156acc6, false), Name(D_156acc6, false), Name(D_156acc6, false),
    Name(D_156acc6, false), Name(D_156acc6, false), Name(D_156acde, false), Name(D_156acde, false),
    Name(D_156acc6, false), Name(D_156acc6, false), Name(D_156acde, false), Name(D_156acde, false),
    Name(D_156acc6, false), Name(D_156acc6, false), Name(D_156acde, false), Name(D_156acde, false),
    Name(D_156acc6, false), Name(D_156acc6, false), Name(D_156acde, false), Name(D_156acde, false),
    Name(D_156acc6, false), Name(D_156acc6, false), Name(D_156acde, false), Name(D_156acde, false),
    Name(D_156acc6, false), Name(D_156acc6, false), Name(D_156acc6, false), Name(D_156acc6, false),
    Name(D_156acf2, false), Name(D_156acf2, false), Name(D_156acf2, false), Name(D_156acf2, false),
    Name(D_156acf2, false), Name(D_156acf2, false), Name(D_156acf2, false), Name(D_156acf2, false)};
