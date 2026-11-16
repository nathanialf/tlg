/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_object013cd320_inline.h"
#include "tlg_game_object016c3760.h"
#include "tlg_game_vector.h"

/* derived names: FUN_012fb710 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 2 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_5ada900(D_15cb5dd, false);
Name D_5ada904(D_15cb5e6, false);

/* derived name: the name the object is made under (20 characters) */
extern const char D_15cb5b6[21];

/* derived name: the complete constructor (called by the creator
 * FUN_012f9d60): Object00c1b7f0's and the part's constructors inlined, the
 * vptr, the members, then the ints and the name set and the pointers
 * after it cleared */
Object016c3760::Object016c3760(const Name &name)
    : Object00c1b7f0(name), unknown194(), unknown1c4(false)
{
    active1d0 = 0;
    unknown1d4 = 0;
    unknown1c8 = -1;
    name1c0 = Name(D_15cb5b6, false);
    registry = 0;
    unknown1f0 = 0;
    unknown1f8 = 0;
}
