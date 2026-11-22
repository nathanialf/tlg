/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00421aa0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt). Then, in declaration order, 32 names
 * from strings, each registered with Name's destructor (0x1331800), and 5
 * lists, each destroyed by the array destructor the compiler writes for it
 * (0x422b90, 0x422c90, 0x422d50, 0x422da0, 0x422e10). What reads them is not
 * traced. */

/* an entry of 8 bytes, the name first: the initializer stores the name
 * only, and the destructor releases the name only (the second word not
 * traced) */
struct Entry00421aa0 { /* derived name */

    template <size_t N> Entry00421aa0(const char (&string)[N], bool add = true) : name(string, add)
    {
    }

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
extern const char D_156a1d8[15];
extern const char D_156a1e7[15];
extern const char D_156a1f6[19];
extern const char D_156a209[17];
extern const char D_156a21a[17];
extern const char D_156a22b[19];
extern const char D_156a23e[37];
extern const char D_156a263[44];
extern const char D_156a28f[16];
extern const char D_156a29f[39];
extern const char D_156a2c6[38];
extern const char D_156a2ec[13];
extern const char D_156a2f9[37];
extern const char D_156a31e[44];
extern const char D_156a34a[17];
extern const char D_156a35b[19];
extern const char D_156a36e[20];
extern const char D_156a382[11];
extern const char D_156a38d[12];
extern const char D_156a399[30];
extern const char D_156a3b7[34];
extern const char D_156a3d9[30];
extern const char D_156a3f7[34];
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
extern const char D_156a58f[40];
extern const char D_1597f15[62];
extern const char D_159bc31[38];
extern const char D_15a6f3f[13];
extern const char D_15c627c[41];
extern const char D_15c62a5[40];
extern const char D_15c8db4[7];
extern const char D_15ca420[7];
extern const char D_15cb254[8];
extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_57d3f44(D_15cb5dd, false);
Name D_57d3f58(D_15cb5e6, false);
Name D_57d3f5c(D_15c627c);
Name D_57d3f54(D_15c62a5);
Name D_57d4260(D_15ca420, false);
Name D_57d3f50(D_15a6f3f);

static Name D_57d4080[] = {Name(D_156a15c), Name(D_156a16f), Name(D_156a185), Name(D_156a195)};

static Entry00421aa0 D_57d4090[] = {D_156a1ac, D_156a10e, D_156a1be};

static Name D_57d4070[] = {Name(D_156a1cf)};

Name D_57d4264(D_156a1d8);
Name D_57d4268(D_156a1e7);
Name D_57d426c(D_156a1f6);
Name D_57d4270(D_156a209);
Name D_57d4274(D_156a21a);
Name D_57d3f48(D_156a22b);
Name D_57d3f4c(D_156a23e);
Name D_57d3f40(D_156a263);
Name D_57d3f64(D_156a28f);
Name D_57d3f68(D_156a29f);
Name D_57d3f60(D_156a2c6);
Name D_57d3f70(D_156a2ec);
Name D_57d3f74(D_156a2f9);
Name D_57d3f6c(D_156a31e);
Name D_57d4164(D_15cb254);
Name D_57d4168(D_156a34a);
Name D_57d4278(D_156a35b);
Name D_57d427c(D_156a36e);
Name D_57d415c(D_156a382);
Name D_57d4160(D_156a38d);
Name D_57d3f78(D_156a399);
Name D_57d3f80(D_156a3b7);
Name D_57d3f7c(D_156a3d9);
Name D_57d3f84(D_156a3f7);

static Name D_57d3f90[] = {Name(D_156a419), Name(D_156a424), Name(D_156a42f), Name(D_156a43a),
                           Name(D_156a445), Name(D_156a450), Name(D_156a45b), Name(D_156a466),
                           Name(D_156a471), Name(D_156a47c), Name(D_156a487), Name(D_156a492),
                           Name(D_156a49d), Name(D_156a4a8), Name(D_156a4b3), Name(D_156a4be),
                           Name(D_156a4c9), Name(D_156a4d4), Name(D_156a4df), Name(D_156a4ea),
                           Name(D_156a4f5), Name(D_156a500), Name(D_156a50b), Name(D_156a516),
                           Name(D_156a521), Name(D_156a52d), Name(D_156a53f), Name(D_156a551),
                           Name(D_156a561), Name(D_156a571), Name(D_156a580)};

static Entry00421aa0 D_57d4010[] = {D_15c8db4, D_1597f15};

Name D_57d40a4(D_156a58f, false);
Name D_57d406c(D_159bc31, false);
