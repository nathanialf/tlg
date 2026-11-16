/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_object013cd320_inline.h"
#include "tlg_game_object016c1bf8.h"
#include "tlg_game_vector.h"

/* derived names: FUN_011f70a0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 2 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). Not written: it then
 * enters the object at 0x5ad7430 in the list FUN_00cb5760 heads, under the
 * name at 0x15c8e00 with the table of named functions at 0x16c1c80, its
 * destructor FUN_00cb57b0 registered last (a tail call). */

extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_5ad7580(D_15cb5dd, false);
Name D_5ad7584(D_15cb5e6, false);

/* derived name: the name the object is made under (11 characters) */
extern const char D_15c8e00[12];

/* derived name: the complete constructor (called by the creator
 * FUN_011edbd0): Object00c1b7f0's and the part's constructors inlined, the
 * vptr, the members, then the ints and the name set and the pointers
 * after it cleared */
Object016c1bf8::Object016c1bf8(const Name &name)
    : Object00c1b7f0(name), unknown194(), unknown1c4(false)
{
    active1d0 = 0;
    unknown1d4 = 0;
    unknown1c8 = -1;
    name1c0 = Name(D_15c8e00, false);
    registry = 0;
    unknown1f0 = 0;
    unknown1f8 = 0;
}
