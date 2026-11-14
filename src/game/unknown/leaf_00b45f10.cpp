/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_object0139b6b0.h"
#include "tlg_game_name.h"
#include "tlg_game_object0134f620.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16b6138 (config/vtables.derived.base.txt, stored by its constructor
 * FUN_00b45e50): it stores the vtable, runs the class's FUN_00b45f80 on the
 * object, then 0x139b6b0 on its member at +0x28 and 0x134f620 on the
 * one at +0x10 (each an array of tlg_game_object0139b6b0.h, as
 * leaf_00b45590.cpp), then releases its Name at +0xc. It has no base.
 * FUN_00b461f0, slot 1, is the deleting one (the Name's clear dead before
 * operator delete). The destructor is the class's key function, so this file
 * emits the vtable. The other members are not traced. */
class Object016b6138 /* derived name */
{
  public:
    virtual ~Object016b6138();
    void FUN_00b45f80(); /* derived name */

  private:
    u8 unknown8[4];
    Name nameC;               /* +0xc */
    Object0134f620 unknown10; /* +0x10 */
    Object0139b6b0 unknown28; /* +0x28 */
};

Object016b6138::~Object016b6138()
{
    FUN_00b45f80();
}
