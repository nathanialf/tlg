/* src/include/tlg_game_object016d51e0.h: the class whose vtable is at
 * 0x16d51e0 and the class at 0x16c0bc0 built on it (game region;
 * docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016D51E0_H
#define TLG_GAME_OBJECT016D51E0_H

#include "tlg_types.h"
#include "tlg_game_block.h"
#include "tlg_game_name.h"

/* derived names: the class of the vtable at 0x16d51e0
 * (config/vtables.derived.base.txt; made by FUN_01006780): an owned block at
 * +0x18 and a Name at +0x30. Its complete destructor 0x13ef1a0 releases the
 * Name, then the block; the deleting one 0x13ef240 is the compiler's. Slot 2
 * is FUN_013ed810. The other members are not traced. */
class Object016d51e0 /* derived name */
{
  public:
    virtual ~Object016d51e0();

  private:
    u8 unknown8[0x10];
    OwnedBlock05943280 unknown18; /* +0x18 */
    u8 unknown20[0x10];
    Name unknown30; /* +0x30 */
};

#endif
