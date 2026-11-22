/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_004dc9e0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then, in declaration order, 45 names,
 * each registered with Name's destructor (0x1331800), and a list, destroyed
 * by the array destructor the compiler writes for it (0x4df110). What reads
 * them is not traced. */

extern const char D_156f672[24];
extern const char D_156f68a[18];
extern const char D_156f69c[31];
extern const char D_156f6bb[31];
extern const char D_156f6da[26];
extern const char D_156f6f4[34];
extern const char D_156f716[34];
extern const char D_156f738[30];
extern const char D_156f756[36];
extern const char D_156f77a[40];
extern const char D_156f7a2[31];
extern const char D_156f7c1[33];
extern const char D_156f7e2[33];
extern const char D_156f803[30];
extern const char D_156f821[28];
extern const char D_156f83d[32];
extern const char D_156f85d[29];
extern const char D_156f87a[10];
extern const char D_156f884[12];
extern const char D_156f890[12];
extern const char D_156f89c[14];
extern const char D_156f8aa[20];
extern const char D_156f8be[9];
extern const char D_156f8c7[11];
extern const char D_156f8d2[11];
extern const char D_156f8dd[14];
extern const char D_156f8eb[13];
extern const char D_156f8f8[12];
extern const char D_156f904[21];
extern const char D_156f919[15];
extern const char D_156f928[34];
extern const char D_156f94a[34];
extern const char D_1570079[13];
extern const char D_15701c3[12];
extern const char D_15706f8[7];
extern const char D_15abfbb[7];
extern const char D_15c627c[41];
extern const char D_15c62a5[40];
extern const char D_15ca408[10];
extern const char D_15ca420[7];
extern const char D_15cb21f[8];
extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

/* an entry of 8 bytes, the name first: the initializer stores the name
 * only, and the destructor releases the name only (the second word not
 * traced) */
struct Entry004dc9e0 { /* derived name */

    Entry004dc9e0(const Name &name) : name(name) {}

    template <size_t N> Entry004dc9e0(const char (&string)[N], bool add = true) : name(string, add)
    {
    }

    Name name;    /* +0x0 */
    u32 unknown4; /* +0x4 */
};

Name D_57d9000(D_15c627c);
Name D_57d9004(D_15c62a5);
Name D_57d9008(D_15ca420, false);
Name D_57d900c(D_15cb5dd, false);
Name D_57d9010(D_15cb5e6, false);
Name D_57d9014;
Name D_57d9018(D_156f672, false);
Name D_57d901c(D_15ca408);
Name D_57d8f00(D_15cb21f);
Name D_57d9020(D_15cb5dd, false);
Name D_57d9024(D_15abfbb, false);
Name D_57d8e68(D_156f68a, false);
Name D_57d9028(D_156f69c, false);
Name D_57d902c(D_156f6bb, false);
Name D_57d8e6c(D_15706f8, false);
Name D_57d8e70(D_15701c3, false);
Name D_57d8ed8(D_156f6da);
Name D_57d9030(D_156f6f4);
Name D_57d9034(D_156f716);
Name D_57d8ed0(D_156f738);
Name D_57d8ed4(D_156f756);
Name D_57d8e9c(D_156f77a);
Name D_57d8ea8(D_156f7a2);
Name D_57d8ea0(D_156f7c1);
Name D_57d8ea4(D_156f7e2);
Name D_57d9038(D_156f803);
Name D_57d8ef8(D_156f821);
Name D_57d8ef0(D_156f83d);
Name D_57d8ef4(D_156f85d);
Name D_57d8e74(D_156f87a);
Name D_57d8e78(D_156f884);
Name D_57d8e7c(D_156f890);
Name D_57d8e80(D_156f89c);
Name D_57d8e84(D_156f8aa);
Name D_57d8e88(D_156f8be);
Name D_57d8e8c(D_156f8c7);
Name D_57d8e90(D_156f8d2);
Name D_57d8e5c(D_156f8dd);
Name D_57d8e94(D_156f8eb);
Name D_57d8e60(D_156f8f8);
Name D_57d8e98(D_156f904);
Name D_57d903c(D_1570079);
Name D_57d8efc(D_156f919);

static Entry004dc9e0 D_57d8e20[] = {D_57d9030, D_57d9034, D_57d8e9c, D_57d8ea8,
                                    D_57d8ea0, D_57d8ea4, D_57d9038, D_57d8ef8};

Name D_57d8e64(D_156f928);
Name D_57d9040(D_156f94a);
