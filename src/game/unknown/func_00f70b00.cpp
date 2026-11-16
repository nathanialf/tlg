/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_object016bfb28.h"
#include "tlg_game_vector.h"

/* derived names: FUN_00f70b00 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 2 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). */

extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_5acec10(D_15cb5dd, false);
Name D_5acec14(D_15cb5e6, false);

/* derived name: the name the object is made under (9 characters) */
extern const char D_15c5469[10];

/* derived name: the complete constructor (called by the creator
 * FUN_00f6f0c0): Object00c1b7f0's and the part's constructors inlined, the
 * vptr, the fields after the part, then the name set and the pointers
 * after it cleared */
Object016bfb28::Object016bfb28(const Name &name)
    : Object00c1b7f0(name), unknown194(), unknown1d8(0), unknown1dc(1), unknown1e0(1.0f)
{
    unknown1e8 = false;
    unknown1ec = -1;
    unknown1f0 = -1;
    active1f4 = 0;
    unknown1f8 = 0;
    name1e4 = Name(D_15c5469, false);
    registry = 0;
    unknown218 = 0;
    unknown220 = 0;
}
