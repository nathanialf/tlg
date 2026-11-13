/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_object0134f620.h"
#include "tlg_game_object00c55550.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16b8488 (config/vtables.derived.base.txt; stored by its constructors
 * FUN_007d9220 and on): it stores the vtable, runs FUN_00c2a490 and then
 * 0x134f620 (the record's destructor, leaf_006e0a80.cpp's) on its member at
 * +0x238, and its base's destructor FUN_00c55550 as a tail call.
 * FUN_00c29c40, slot 1, is the deleting one. The destructor is the class's key
 * function, so this file emits the vtable. */
void FUN_00c2a490(Object0134f620 *self); /* derived name */

class Object00c29c00 : public Object00c55550 /* derived name */
{
  public:
    virtual ~Object00c29c00();

  private:
    u8 unknown8[0x230];
    Object0134f620 unknown238; /* +0x238 */
};

Object00c29c00::~Object00c29c00()
{
    FUN_00c2a490(&unknown238);
}
