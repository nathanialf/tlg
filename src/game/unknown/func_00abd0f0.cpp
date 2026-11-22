/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00abd0f0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then the empty name at 0x582ae00 and a
 * name from a string, each registered with Name's destructor (0x1331800),
 * then 21 lists of names, each ended by a copy of the empty name and
 * destroyed by the array destructor the compiler writes for it (0xabdc70 to
 * 0xabebc0, registered in that order). The lists are file-local: their
 * addresses sit in the unit's table at 0x16b2e70 (from 0x16b2f18, read at
 * 0xabcd3f); what reads them is not traced. */

extern const char D_14cb8e5[2];
extern const char D_15a7844[23];
extern const char D_15a785b[25];
extern const char D_15a7874[27];
extern const char D_15a788f[30];
extern const char D_15a78ad[30];
extern const char D_15a78cb[30];
extern const char D_15a78e9[30];
extern const char D_15a7907[28];
extern const char D_15a7923[28];
extern const char D_15a793f[28];
extern const char D_15a795b[28];
extern const char D_15a7977[31];
extern const char D_15a7996[31];
extern const char D_15a79b5[31];
extern const char D_15a79d4[31];
extern const char D_15a79f3[29];
extern const char D_15a7a10[29];
extern const char D_15a7a2d[29];
extern const char D_15a7a4a[29];
extern const char D_15a7a67[21];
extern const char D_15a7a7c[16];
extern const char D_15a7a8c[28];
extern const char D_15a7aa8[20];
extern const char D_15a7abc[18];
extern const char D_15a7ace[21];
extern const char D_15a7ae3[21];
extern const char D_15a7f48[15];
extern const char D_15a7f60[8];
extern const char D_15a8290[15];
extern const char D_15a829f[17];
extern const char D_15a82b0[19];
extern const char D_15a82c3[13];
extern const char D_15a82d0[13];
extern const char D_15a82dd[15];
extern const char D_15a82ec[22];
extern const char D_15a8302[24];
extern const char D_15a831a[26];
extern const char D_15a8a6c[13];

Name D_582ae00;
Name D_582accc(D_14cb8e5, false);

static Name D_582ae04[] = {Name(D_15a8290, false), D_582ae00};
static Name D_582ae0c[] = {Name(D_15a829f, false), D_582ae00};
static Name D_582ae14[] = {Name(D_15a82b0, false), D_582ae00};
static Name D_582ae1c[] = {Name(D_15a82c3, false), D_582ae00};
static Name D_582ae24[] = {Name(D_15a82d0, false), D_582ae00};
static Name D_582ae2c[] = {Name(D_15a82dd, false), D_582ae00};
static Name D_582ae40[] = {Name(D_15a82ec, false), Name(D_15a7844, false), Name(D_15a8a6c, false),
                           D_582ae00};
static Name D_582ae50[] = {Name(D_15a8302, false), Name(D_15a785b, false), Name(D_15a8a6c, false),
                           D_582ae00};
static Name D_582ae60[] = {Name(D_15a831a, false), Name(D_15a7874, false), Name(D_15a8a6c, false),
                           D_582ae00};
static Name D_582ae70[] = {Name(D_15a788f, false), Name(D_15a78ad, false), Name(D_15a78cb, false),
                           Name(D_15a78e9, false), Name(D_15a7907, false), Name(D_15a7923, false),
                           Name(D_15a793f, false), Name(D_15a795b, false), D_582ae00};
static Name D_582aea0[] = {Name(D_15a7977, false), Name(D_15a7996, false), Name(D_15a79b5, false),
                           Name(D_15a79d4, false), Name(D_15a79f3, false), Name(D_15a7a10, false),
                           Name(D_15a7a2d, false), Name(D_15a7a4a, false), D_582ae00};
static Name D_582aec4[] = {Name(D_15a7a67, false), Name(D_15a7a7c, false), D_582ae00};
static Name D_582aed0[] = {Name(D_15a7a8c, false), D_582ae00};
static Name D_582aed8[] = {Name(D_15a7aa8, false), Name(D_15a7abc, false), D_582ae00};
static Name D_582aee4[] = {Name(D_15a7f60, false), Name(D_15a7f48, false), D_582ae00};
static Name D_582aef0[] = {D_582ae00};
static Name D_582aef4[] = {Name(D_15a7ace, false), D_582ae00};
static Name D_582aefc[] = {Name(D_15a7ae3, false), D_582ae00};
static Name D_582af04[] = {D_582accc, D_582ae00};
static Name D_582af0c[] = {D_582accc, D_582ae00};
static Name D_582af14[] = {D_582ae00};
