/* src/include/tlg_game_object016ad868.h: the class whose vtable is at 0x16ad868
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AD868_H
#define TLG_GAME_OBJECT016AD868_H

#include "tlg_game_object00774560.h"
#include "tlg_game_name.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16ad868 (config/vtables.derived.base.txt, stored by its constructor
 * FUN_00799900): it stores the vtable, releases its Name at +0xfc, then
 * tail-calls its base's destructor (0x774560). FUN_00799a70, slot 1, is the
 * deleting one. The destructor is the class's key function, so leaf_00799a10.cpp
 * emits the vtable. The other members are not traced. */
class Object016ad868 : public Object00774560 /* derived name */
{
  public:
    Object016ad868(const Name &name); /* 0x799900, its row named after it (D15) */
    virtual ~Object016ad868();

  private:
    Name namefc; /* +0xfc */
    u8 unknown100
        [0x60]; /* to the 0x160 bytes the creator FUN_007997a0 allocates (`mov edi, 0x160`) */
};

#endif
