/* src/include/tlg_game_object013ef2e0.h: the class whose vtable is at
 * 0x16d51b8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT013EF2E0_H
#define TLG_GAME_OBJECT013EF2E0_H

#include "tlg_types.h"
#include "tlg_game_block.h"

/* derived names: the class whose vtable is at 0x16d51b8
 * (config/vtables.derived.base.txt); its complete destructor FUN_013ef2e0
 * (leaf_013ef2e0.cpp) stores the vtable and releases the block the pointer
 * at +0x18 holds (tlg_game_block.h); the class whose destructor is
 * 0x1006120 holds one at +0x308 and has it inlined (`mov [r14+0x308],
 * vtable` and the block at +0x320). The other members are not traced. */
class Object013ef2e0 /* derived name */
{
  public:
    virtual ~Object013ef2e0();

  private:
    u8 unknown8[0x10];
    void *unknown18; /* +0x18: owned block */
};

#endif
