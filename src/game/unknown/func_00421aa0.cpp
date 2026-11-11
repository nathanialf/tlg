/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_name.h"

/* derived names: FUN_00421aa0 is this file's static initializer. Among its
 * objects are 5 lists of names built from strings, each destroyed by the array
 * destructor the compiler writes for it (0x422b90, 0x422c90, 0x422d50, 0x422da0, 0x422e10, registered with
 * __cxa_atexit in that order). Only the lists are written. */

/* an entry of 8 bytes, the name first: the initializer stores the name
 * only, and the destructor releases the name only (the second word not
 * traced) */
struct Entry00421aa0 { /* derived name */

    Entry00421aa0(const Name &name) : name(name) {}

    Name name;    /* +0x0 */
    u32 unknown4; /* +0x4 */
};

extern const char D_156a10e[15];
extern const char D_156a15c[19];
extern const char D_156a16f[22];
extern const char D_156a185[16];
extern const char D_156a195[23];
extern const char D_156a1ac[18];
extern const char D_156a1be[17];
extern const char D_156a1cf[9];
extern const char D_156a419[11];
extern const char D_156a424[11];
extern const char D_156a42f[11];
extern const char D_156a43a[11];
extern const char D_156a445[11];
extern const char D_156a450[11];
extern const char D_156a45b[11];
extern const char D_156a466[11];
extern const char D_156a471[11];
extern const char D_156a47c[11];
extern const char D_156a487[11];
extern const char D_156a492[11];
extern const char D_156a49d[11];
extern const char D_156a4a8[11];
extern const char D_156a4b3[11];
extern const char D_156a4be[11];
extern const char D_156a4c9[11];
extern const char D_156a4d4[11];
extern const char D_156a4df[11];
extern const char D_156a4ea[11];
extern const char D_156a4f5[11];
extern const char D_156a500[11];
extern const char D_156a50b[11];
extern const char D_156a516[11];
extern const char D_156a521[12];
extern const char D_156a52d[18];
extern const char D_156a53f[18];
extern const char D_156a551[16];
extern const char D_156a561[16];
extern const char D_156a571[15];
extern const char D_156a580[15];
extern const char D_1597f15[62];
extern const char D_15c8db4[7];

// NONMATCHING: the file's initializer (FUN_00421aa0): only the lists are
// written; its other objects are not.
static Name D_57d4080[] = {Name(D_156a15c), Name(D_156a16f), Name(D_156a185), Name(D_156a195)};
static Entry00421aa0 D_57d4090[] = {Name(D_156a1ac), Name(D_156a10e), Name(D_156a1be)};
static Name D_57d4070[] = {Name(D_156a1cf)};
static Name D_57d3f90[] = {Name(D_156a419), Name(D_156a424), Name(D_156a42f), Name(D_156a43a),
                           Name(D_156a445), Name(D_156a450), Name(D_156a45b), Name(D_156a466),
                           Name(D_156a471), Name(D_156a47c), Name(D_156a487), Name(D_156a492),
                           Name(D_156a49d), Name(D_156a4a8), Name(D_156a4b3), Name(D_156a4be),
                           Name(D_156a4c9), Name(D_156a4d4), Name(D_156a4df), Name(D_156a4ea),
                           Name(D_156a4f5), Name(D_156a500), Name(D_156a50b), Name(D_156a516),
                           Name(D_156a521), Name(D_156a52d), Name(D_156a53f), Name(D_156a551),
                           Name(D_156a561), Name(D_156a571), Name(D_156a580)};
static Entry00421aa0 D_57d4010[] = {Name(D_15c8db4), Name(D_1597f15)};
