/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_object0134f620.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16ac720 (config/vtables.derived.base.txt; stored also by FUN_006e0770):
 * it stores the vtable, runs 0x134f620, the destructor of its member at
 * +0x238 (which frees the pointers in the array at +0x0 of that member counted
 * by the int at +0x8), written as a free function on that record, and runs
 * its base's destructor FUN_00c55550 as a tail call. FUN_006e0ab0, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */

class Object00c55550 /* derived name */
{
  public:
    virtual ~Object00c55550();
};

class Object006e0a80 : public Object00c55550 /* derived name */
{
  public:
    virtual ~Object006e0a80();

  private:
    u8 unknown8[0x230];
    Object0134f620 unknown238; /* +0x238 */
};

Object006e0a80::~Object006e0a80() {}
