/* src/include/tlg_game_object016d3ef8.h: the class whose vtable is at
 * 0x16d3ef8, a base of game classes (game region; docs/TARGETS.md). Every name
 * here is derived. */
#ifndef TLG_GAME_OBJECT016D3EF8_H
#define TLG_GAME_OBJECT016D3EF8_H

#include "tlg_types.h"
#include "tlg_game_block.h"
#include "tlg_game_name.h"

/* derived names: the class of the vtable at 0x16d3ef8
 * (config/vtables.derived.base.txt; made by FUN_00f9ab50): an owned block at
 * +0x18 and a Name at +0x30. Its complete destructor 0x13e3c00 releases the
 * Name, then the block; the deleting one 0x13e3ca0 is the compiler's
 * (leaf_013e3c00.cpp, the key function's file). Slot 2 is FUN_013dfda0, slot 3
 * FUN_001af750 (declared; their bodies are not written). The other members
 * are not traced. */
class Object016d3ef8 /* derived name */
{
  public:
    virtual ~Object016d3ef8();
    virtual void slot2(); /* derived name; FUN_013dfda0, not traced */
    virtual void slot3(); /* derived name; FUN_001af750, not traced */

  private:
    u8 unknown8[0x10];
    OwnedBlock05943280 unknown18; /* +0x18 */
    u8 unknown20[0x10];
    Name unknown30; /* +0x30 */
};

#endif
