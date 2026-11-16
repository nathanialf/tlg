/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_object016c3380.h"
#include "tlg_game_vector.h"

/* derived names: FUN_012b95f0 is this file's static initializer. It builds
 * the vector constants of tlg_game_vector.h into the file's own copies
 * (config/header_statics.base.txt), then 2 names from strings, in this order,
 * each registered with Name's destructor (0x1331800). Not written: it then
 * enters the object at 0x5ad9270 in the list FUN_00cb5760 heads, under the
 * name at 0x15ca43f with the table of five named functions at 0x16c3410
 * ("ModuleInitialize" to "BhvModuleInitialize"), its destructor
 * FUN_00cb57b0 registered last (a tail call). */

extern const char D_15cb5dd[9];
extern const char D_15cb5e6[13];

Name D_5ad93c0(D_15cb5dd, false);
Name D_5ad93c4(D_15cb5e6, false);

/* derived name: the name the object is made under (14 characters) */
extern const char D_15ca43f[15];

/* derived name: the complete constructor (called by the creator
 * FUN_012b4050): Object00c1b7f0's and the part's constructors inlined, the
 * vptr, the fields after the part, then the name set and the pointers
 * after it cleared */
Object016c3380::Object016c3380(const Name &name)
    : Object00c1b7f0(name), unknown194(), unknown1c4(false)
{
    active1d0 = 0;
    unknown1d4 = 0;
    unknown1c8 = -1;
    name1c0 = Name(D_15ca43f, false);
    registry = 0;
    unknown1f0 = 0;
    unknown1f8 = 0;
}
