/* src/include/tlg_game_object016d6b08.h: the class whose vtable is at
 * 0x16d6b08, a base of game classes (game region; docs/TARGETS.md). Every name
 * here is derived. */
#ifndef TLG_GAME_OBJECT016D6B08_H
#define TLG_GAME_OBJECT016D6B08_H

#include "tlg_types.h"
#include "tlg_game_block.h"
#include "tlg_game_name.h"

/* derived names: the class of the vtable at 0x16d6b08
 * (config/vtables.derived.base.txt; made by FUN_0122be10): an owned block at
 * +0x18 and a Name at +0x30. Its complete destructor 0x147e900 releases the
 * Name, then the block; the deleting one 0x147e9a0 is the compiler's
 * (leaf_0147e900.cpp, the key function's file). Slot 2 is FUN_0147bac0, slot 3
 * FUN_001af750 (declared; their bodies are not written). The other members
 * are not traced. */
class Object016d6b08 /* derived name */
{
  public:
    virtual ~Object016d6b08();
    virtual void slot2(); /* derived name; FUN_0147bac0, not traced */
    virtual void slot3(); /* derived name; FUN_001af750, not traced */

  private:
    u8 unknown8[0x10];
    OwnedBlock05943280 unknown18; /* +0x18 */
    u8 unknown20[0x10];
    Name unknown30; /* +0x30 */
};

#endif
