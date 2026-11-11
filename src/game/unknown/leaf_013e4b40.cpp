/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_block.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16d4b78 (config/vtables.derived.base.txt, stored by its constructor
 * FUN_00f96270): it stores the vtable and destroys its members in reverse
 * order, the Object013e4510 at +0x30 (its destructor 0x13e4510, the row named
 * for it, D15) and then the heap block it owns at +0x18 (tlg_game_block.h).
 * It has no base. FUN_013e4bb0, slot 1, is the deleting one. The destructor
 * is the class's key function, so this file emits the vtable. The other
 * members are not traced. */
class Object013e4510 /* derived name */
{
  public:
    virtual ~Object013e4510();
};

class Object016d4b78 /* derived name */
{
  public:
    virtual ~Object016d4b78();

  private:
    u8 unknown8[0x10];
    OwnedBlock05943280 block18; /* +0x18 */
    u8 unknown20[0x10];
    Object013e4510 unknown30; /* +0x30 */
};

Object016d4b78::~Object016d4b78() {}
