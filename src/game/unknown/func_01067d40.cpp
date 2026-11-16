/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_object016c1128.h"
#include "tlg_game_vector.h"

/* derived names: FUN_01067d40 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 11 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

extern const char D_15ca27a[9];
extern const char D_15ca283[10];
extern const char D_15ca28d[10];
extern const char D_15ca367[8];
extern const char D_15caff8[15];
extern const char D_15cb04a[15];
extern const char D_15cb21f[8];
extern const char D_15cb254[8];
extern const char D_15cb266[10];
extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_5ad0a40(D_15cb5dd, false);
Name D_5ad0a44(D_15cb5e6, false);
Name D_5ad08e0(D_15ca367, false);
Name D_5ad08e4(D_15ca27a, false);
Name D_5ad08e8(D_15ca283, false);
Name D_5ad08ec(D_15ca28d, false);
Name D_5ad08f0(D_15cb266, false);
Name D_5ad08f4(D_15cb04a, false);
Name D_5ad08f8(D_15caff8, false);
Name D_5ad08fc(D_15cb254, false);
Name D_5ad0900(D_15cb21f, false);

/* derived name: the name the object is made under (15 characters) */
extern const char D_15c6b1d[16];

/* derived name: the complete constructor (called by the factory
 * FUN_01064370): Object00c1b7f0's and the part's constructors inlined, the
 * vptr, the fields after the part, then the name set and the pointers
 * after it cleared */
// NONMATCHING: 140/143: MemCpyOpt's clear of +0x194 to +0x1c7 is inserted where its scan
// stops, at the load of VECTOR_W after the zero stored at +0x250; the base has the clear
// before that store (something ends the scan between the stores at +0x230 and +0x250).
Object016c1128::Object016c1128(const Name &name) : Object00c1b7f0(name), unknown194(), unknown1c0(0)
{
    unknown1c8 = false;
    unknown1cc = -1;
    unknown1d0 = -1;
    active1d4 = 0;
    unknown1d8 = 0;
    name1c4 = Name(D_15c6b1d, false);
    registry = 0;
    unknown1f8 = 0;
    unknown200 = 0;
}
