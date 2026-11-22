/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00a93480 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt). Then, in declaration order, 11 names
 * from strings, each registered with Name's destructor (0x1331800), and 5
 * lists, each destroyed by the array destructor the compiler writes for it
 * (0xa948e0, 0xa94ac0, 0xa94ca0, 0xa94da0, 0xa94e10). What reads them is not
 * traced. */

// NONMATCHING: the file's initializer (FUN_00a93480) is equal in bytes, but it
// registers the 10-name list's destructor (0xa94da0), a loop in the base that
// the build unrolls (596 bytes against 99), so no row places it.

extern const char D_15a6457[10];
extern const char D_15a6461[28];
extern const char D_15a647d[39];
extern const char D_15a64a4[27];
extern const char D_15a64bf[27];
extern const char D_15a64da[27];
extern const char D_15a64f5[27];
extern const char D_15a6510[19];
extern const char D_15a6523[6];
extern const char D_15a6529[14];
extern const char D_15a6537[14];
extern const char D_15a6545[25];
extern const char D_15a655e[25];
extern const char D_15a6577[25];
extern const char D_15a6590[25];
extern const char D_15a65a9[25];
extern const char D_15a65c2[25];
extern const char D_15a65db[13];
extern const char D_15a66a8[15];
extern const char D_15a66d2[15];
extern const char D_15a66e1[27];
extern const char D_15a66fc[15];
extern const char D_15a670b[27];
extern const char D_15a6726[15];
extern const char D_15a6751[12];
extern const char D_15a675d[21];
extern const char D_15a6782[22];
extern const char D_15a67a8[21];
extern const char D_15a67cd[22];
extern const char D_15c8db4[7];
extern const char D_15ca367[8];
extern const char D_15cafd4[11];
extern const char D_15cb026[11];
extern const char D_15cb078[11];
extern const char D_15cb0c5[11];
extern const char D_15cb216[9];
extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_5829880(D_15cb5dd, false);
Name D_5829884(D_15cb5e6, false);
Name D_58296fc;
Name D_58296f8(D_15ca367, false);
Name D_58296c0(D_15a6457, false);
Name D_5829888(D_15a6461, false);
Name D_582988c(D_15a647d, false);

static Name D_5829730[] = {Name(D_15a675d, false), Name(D_15a64a4, false), Name(D_15a6782, false),
                           Name(D_15a64bf, false), Name(D_15a67a8, false), Name(D_15a64da, false),
                           Name(D_15a67cd, false), Name(D_15a64f5, false)};

/* a vector whose address FUN_00a927d0 and FUN_00a92990 hand on (0xa927ea,
 * 0xa929c4); external until those functions are in this file */
Vector4 D_5829700(0.0f, 0.0f, 0.0f, 0.0f);

Name D_58296c4(D_15a6510, false);
Name D_5829694(D_15c8db4, false);
Name D_5829698(D_15a6523, false);

static Name D_58296a0[] = {Name(D_15a6529, false), Name(D_15a6537, false), Name(D_15a6545, false),
                           Name(D_15a655e, false), Name(D_15a6577, false), Name(D_15a6590, false),
                           Name(D_15a65a9, false), Name(D_15a65c2, false)};

static Name D_5829710[] = {Name(D_15a66e1, false), Name(D_15a66fc, false), Name(D_15a670b, false),
                           Name(D_15a6726, false)};

Name D_5829720;

static Name D_58296d0[] = {Name(D_15cb026, false), Name(D_15a66fc, false), Name(D_15cafd4, false),
                           Name(D_15a6726, false), Name(D_15cb0c5, false), Name(D_15a66a8, false),
                           Name(D_15cb078, false), Name(D_15a66d2, false), Name(D_15a65db, false),
                           Name(D_15a6751, false)};

static Name D_5829724[] = {Name(D_15cb216, false), Name(D_15ca367, false), Name(D_15cb078, false)};
