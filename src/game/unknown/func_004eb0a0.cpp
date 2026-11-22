/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_004eb0a0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then, in declaration order, 28 names,
 * each registered with Name's destructor (0x1331800), and a list, destroyed
 * by the array destructor the compiler writes for it (0x4eb910). What reads
 * them is not traced. */

extern const char D_156fb5c[24];
extern const char D_156fb74[40];
extern const char D_156fb9c[41];
extern const char D_156fbc5[37];
extern const char D_156fbea[36];
extern const char D_156fc0e[39];
extern const char D_156fc35[37];
extern const char D_156fc5a[37];
extern const char D_156fc7f[38];
extern const char D_156fca5[10];
extern const char D_156fcaf[15];
extern const char D_156fcbe[18];
extern const char D_156fcd0[16];
extern const char D_156fce0[16];
extern const char D_156fcf0[17];
extern const char D_15701c3[12];
extern const char D_157057c[18];
extern const char D_157058e[31];
extern const char D_15705ad[31];
extern const char D_15706f8[7];
extern const char D_15abfbb[7];
extern const char D_15c627c[41];
extern const char D_15c62a5[40];
extern const char D_15cb21f[8];
extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

/* an entry of 8 bytes, the name first: the initializer stores the name
 * only, and the destructor releases the name only (the second word not
 * traced) */
struct Entry004eb0a0 { /* derived name */

    Entry004eb0a0(const Name &name) : name(name) {}

    template <size_t N> Entry004eb0a0(const char (&string)[N], bool add = true) : name(string, add)
    {
    }

    Name name;    /* +0x0 */
    u32 unknown4; /* +0x4 */
};

Name D_57d9660(D_15c627c);
Name D_57d9664(D_15c62a5);
Name D_57d9668(D_15cb5dd, false);
Name D_57d966c(D_15cb5e6, false);
Name D_57d9670;
Name D_57d9674(D_156fb5c, false);
Name D_57d9678(D_15cb21f);
Name D_57d967c(D_15cb5dd, false);
Name D_57d9680(D_15abfbb, false);
Name D_57d9684(D_157057c, false);
Name D_57d9560(D_157058e, false);
Name D_57d9564(D_15705ad, false);
Name D_57d94ec(D_15706f8, false);
Name D_57d94f0(D_15701c3, false);
Name D_57d9688(D_156fb74);
Name D_57d9500(D_156fb9c);
Name D_57d94f8(D_156fbc5);
Name D_57d9518(D_156fbea);
Name D_57d9514(D_156fc0e);
Name D_57d951c(D_156fc35);
Name D_57d9520(D_156fc5a);
Name D_57d968c(D_156fc7f);
Name D_57d94f4(D_156fca5);
Name D_57d9504(D_156fcaf);
Name D_57d9508(D_156fcbe);
Name D_57d950c(D_156fcd0);
Name D_57d9510(D_156fce0);
Name D_57d94fc(D_156fcf0);

static Entry004eb0a0 D_57d94a0[] = {D_57d9688, D_57d9500, D_57d94f8, D_57d9518,
                                    D_57d9514, D_57d951c, D_57d9520, D_57d968c};
