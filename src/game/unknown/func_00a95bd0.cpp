/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00a95bd0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then its names, each registered with
 * Name's destructor (0x1331800), and 3 lists of names, each destroyed by
 * the array destructor the compiler writes for it, in this order. What
 * reads the lists is not traced. The lists are external: 0x225923 and
 * 0x3fde14 read them from other units. Not claimed: an array destructor over
 * an external object has no module symbol the gate can prove. */

extern const char D_15a668d[27];
extern const char D_15a66a8[15];
extern const char D_15a66b7[27];
extern const char D_15a66d2[15];
extern const char D_15a66e1[27];
extern const char D_15a66fc[15];
extern const char D_15a670b[27];
extern const char D_15a6726[15];
extern const char D_15a6735[28];
extern const char D_15a6751[12];
extern const char D_15a675d[21];
extern const char D_15a6772[16];
extern const char D_15a6782[22];
extern const char D_15a6798[16];
extern const char D_15a67a8[21];
extern const char D_15a67bd[16];
extern const char D_15a67cd[22];
extern const char D_15a67e3[16];
extern const char D_15a67f3[24];
extern const char D_15a680b[26];
extern const char D_15a6825[23];
extern const char D_15a683c[23];
extern const char D_15a6853[22];
extern const char D_15a6869[24];
extern const char D_15a6881[21];
extern const char D_15a6896[32];
extern const char D_15a68b6[22];
extern const char D_15a68cc[22];
extern const char D_15a68e2[23];
extern const char D_15a68f9[37];
extern const char D_15a691e[37];
extern const char D_15a6943[39];
extern const char D_15a696a[39];
extern const char D_15a6991[36];
extern const char D_15a69b5[36];
extern const char D_15a69d9[36];
extern const char D_15a69fd[36];
extern const char D_15a6a21[35];
extern const char D_15a6a44[35];
extern const char D_15a6a67[37];
extern const char D_15a6a8c[37];
extern const char D_15a6ab1[34];
extern const char D_15a6ad3[34];
extern const char D_15a6af5[45];
extern const char D_15a6b22[45];
extern const char D_15a6b4f[35];
extern const char D_15a6b72[35];
extern const char D_15a6b95[35];
extern const char D_15a6bb8[35];
extern const char D_15a6bdb[36];
extern const char D_15a6bff[36];

Name D_5829b00;
Name D_58298c0[] = {Name(D_15a668d, false), Name(D_15a66a8, false), Name(D_15a66b7, false),
                    Name(D_15a66d2, false), Name(D_15a66e1, false), Name(D_15a66fc, false),
                    Name(D_15a670b, false), Name(D_15a6726, false), Name(D_15a6735, false),
                    Name(D_15a6751, false), Name(D_15a675d, false), Name(D_15a6772, false),
                    Name(D_15a6782, false), Name(D_15a6798, false), Name(D_15a67a8, false),
                    Name(D_15a67bd, false), Name(D_15a67cd, false), Name(D_15a67e3, false)};
// NONMATCHING: this list's array destructor (FUN_00a96710) is a loop over its 11 names in
// the base, where the build unrolls it (655 bytes; the 9-name lists of func_00abd0f0.cpp
// are unrolled in both); the initializer (FUN_00a95bd0) differs in register assignment
// only (r14 and r15 exchanged around two of the lists' strings).
Name D_58299a0[] = {Name(D_15a67f3, false), Name(D_15a680b, false), Name(D_15a6825, false),
                    Name(D_15a683c, false), Name(D_15a6853, false), Name(D_15a6869, false),
                    Name(D_15a6881, false), Name(D_15a6896, false), Name(D_15a68b6, false),
                    Name(D_15a68cc, false), Name(D_15a68e2, false)};
Name D_5829910[] = {
    Name(D_15a67f3, false), Name(D_15a68f9, false), Name(D_15a691e, false), Name(D_15a680b, false),
    Name(D_15a6943, false), Name(D_15a696a, false), Name(D_15a6825, false), Name(D_15a6991, false),
    Name(D_15a69b5, false), Name(D_15a683c, false), Name(D_15a69d9, false), Name(D_15a69fd, false),
    Name(D_15a6853, false), Name(D_15a6a21, false), Name(D_15a6a44, false), Name(D_15a6869, false),
    Name(D_15a6a67, false), Name(D_15a6a8c, false), Name(D_15a6881, false), Name(D_15a6ab1, false),
    Name(D_15a6ad3, false), Name(D_15a6896, false), Name(D_15a6af5, false), Name(D_15a6b22, false),
    Name(D_15a68b6, false), Name(D_15a6b4f, false), Name(D_15a6b72, false), Name(D_15a68cc, false),
    Name(D_15a6b95, false), Name(D_15a6bb8, false), Name(D_15a68e2, false), Name(D_15a6bdb, false),
    Name(D_15a6bff, false)};
