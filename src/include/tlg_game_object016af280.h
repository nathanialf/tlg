/* src/include/tlg_game_object016af280.h: the class whose vtable is at 0x16af280
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AF280_H
#define TLG_GAME_OBJECT016AF280_H

#include "tlg_types.h"
#include "tlg_math.h"
#include "tlg_game_name.h"
#include "tlg_game_object01343880.h"

/* derived names: the class whose vtable is at 0x16af280
 * (config/vtables.derived.base.txt, stored by its creator FUN_00879700, where
 * its constructor is inlined, and by its complete destructor FUN_0087aeb0,
 * leaf_0087aeb0.cpp), derived from Object01343880. 0x60 bytes (`mov edi,
 * 0x60` before operator new in the creator). Its fields are traced only where
 * the creator sets them. */
class Object016af280 : public Object01343880 /* derived name */
{
  public:
    /* inlined in the creator: Object01343880's, the vptr, (0, 0, 0, 1) at
     * +0x40 (one 16-byte constant), zero at +0x50 */
    Object016af280(const Name &name)
        : Object01343880(name), unknown40(0.0f, 0.0f, 0.0f, 1.0f), unknown50(0)
    {
    }

    virtual ~Object016af280();

  private:
    u8 unknown34[0xc];
    Float4 unknown40; /* +0x40: (0, 0, 0, 1) from the constructor; not traced */
    int unknown50;    /* +0x50: 0 from the constructor */
    u8 unknown54[0xc];
};

#endif
