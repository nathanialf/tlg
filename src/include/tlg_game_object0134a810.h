/* src/include/tlg_game_object0134a810.h: the class whose vtable is at
 * 0x16c7328, a member of game classes (game region; docs/TARGETS.md). Every
 * name here is derived. */
#ifndef TLG_GAME_OBJECT0134A810_H
#define TLG_GAME_OBJECT0134A810_H

#include "tlg_types.h"

/* derived names: the class whose vtable is at 0x16c7328
 * (config/vtables.derived.base.txt): its complete destructor 0x134a810
 * (leaf_0134a810.cpp, the key function's file) stores the vtable and
 * releases the block the pointer at +0x68 holds (tlg_game_block.h); the
 * deleting one is the compiler's. The other members are not traced. */
class Object0134a810 /* derived name */
{
  public:
    virtual ~Object0134a810();

  private:
    u8 unknown8[0x60];
    void *unknown68; /* +0x68: owned block */
};

#endif
