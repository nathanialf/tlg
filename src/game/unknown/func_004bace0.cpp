/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_004bace0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt). Then, in declaration order, 29 names
 * from strings, each registered with Name's destructor (0x1331800), and 2
 * lists, each destroyed by the array destructor the compiler writes for it
 * (0x4bb760, 0x4bb820). What reads them is not traced. */

/* an entry of 8 bytes, the name first: the initializer stores the name
 * only, and the destructor releases the name only (the second word not
 * traced) */
struct Entry004bace0 { /* derived name */

    template <size_t N> Entry004bace0(const char (&string)[N], bool add = true) : name(string, add)
    {
    }

    Name name;    /* +0x0 */
    u32 unknown4; /* +0x4 */
};

extern const char D_156f331[13];
extern const char D_156f33e[14];
extern const char D_156f34c[7];
extern const char D_156f353[9];
extern const char D_156f35c[9];
extern const char D_156f365[14];
extern const char D_156f373[7];
extern const char D_156f37a[17];
extern const char D_156f38b[10];
extern const char D_156f395[16];
extern const char D_156f3a5[22];
extern const char D_156f3bb[7];
extern const char D_156f3c2[15];
extern const char D_156f3d1[14];
extern const char D_156f3df[19];
extern const char D_156f3f2[20];
extern const char D_156f406[17];
extern const char D_156f417[19];
extern const char D_15942aa[25];
extern const char D_15942c3[25];
extern const char D_1596df9[7];
extern const char D_1598a9e[12];
extern const char D_1598b27[13];
extern const char D_159bc66[13];
extern const char D_15a7cc7[24];
extern const char D_15aba12[12];
extern const char D_15b1dea[7];
extern const char D_15c627c[41];
extern const char D_15c62a5[40];
extern const char D_15c8db4[7];
extern const char D_15cb078[11];
extern const char D_15cb083[13];
extern const char D_15cb0d0[13];
extern const char D_15cb254[8];
extern const char D_15cb266[10];
extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_57d86c0(D_15cb5dd, false);
Name D_57d86c4(D_15cb5e6, false);
Name D_57d86c8(D_15c627c);
Name D_57d86cc(D_15c62a5);
Name D_57d8500(D_15cb266, false);
Name D_57d8504(D_15cb254, false);
Name D_57d8508(D_15cb078, false);
Name D_57d850c(D_15cb083, false);
Name D_57d8510(D_15cb0d0, false);
Name D_57d85a4(D_156f331, false);
Name D_57d859c(D_156f33e, false);
Name D_57d8518(D_15c8db4, false);
Name D_57d8550(D_156f34c, false);
Name D_57d85a0(D_156f353, false);
Name D_57d85a8(D_156f35c, false);
Name D_57d85ac(D_15aba12, false);
Name D_57d85b0(D_1598b27, false);
Name D_57d851c(D_156f365, false);
Name D_57d8554(D_156f373, false);
Name D_57d856c(D_1596df9, false);
Name D_57d84f4(D_15942aa, false);
Name D_57d84fc(D_15942c3, false);
Name D_57d84f8;
Name D_57d86d0(D_15a7cc7, false);
Name D_57d86d4(D_156f37a, false);
Name D_57d86d8(D_156f38b, false);
Name D_57d86dc(D_1598a9e, false);
Name D_57d86e0(D_159bc66, false);
Name D_57d8514(D_15b1dea, false);

static Entry004bace0 D_57d8558[] = {{D_156f395, false}, {D_156f3a5, false}, {D_156f3bb, false}};

static Entry004bace0 D_57d8570[] = {{D_156f3c2, false}, {D_156f3d1, false}, {D_156f3df, false},
                                    {D_156f3f2, false}, {D_156f406, false}, {D_156f417, false}};
