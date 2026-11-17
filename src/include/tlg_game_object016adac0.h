/* src/include/tlg_game_object016adac0.h: the class whose vtable is at 0x16adac0
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016ADAC0_H
#define TLG_GAME_OBJECT016ADAC0_H

#include "tlg_game_collection00214e10.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object00774560.h"

/* derived names: the class whose vtable is at 0x16adac0
 * (config/vtables.derived.base.txt, stored by FUN_0079dac0 FUN_0079dbc0), 0x420 bytes
 * (`mov edi, 0x420` before operator new in its creator FUN_0079d960),
 * derived from Object00774560 (its constructor 0x79dac0 first calls 0x774370, that
 * class's constructor). Its constructor is not written; the fields are the ones its destructor
 * releases (leaf_0079ec40.cpp). */
class Object016adac0 : public Object00774560 /* derived name */
{
  public:
    Object016adac0(const Name &name); /* 0x79dac0, its row named after it (D15) */
    virtual ~Object016adac0();
    virtual void slot9(); /* FUN_0079ec40 */

  private:
    Name namefc;               /* +0xfc */
    Object00214e10 unknown100; /* +0x100 */
    AtomicRef0045c470<Object016b9108> unknown3c0;
    AtomicRef0045c470<State00774760> unknown3c8;
    AtomicRef0045c470<Object016b9108> unknown3d0;
    int unknown3d8;      /* +0x3d8: zero from slot 9 */
    u8 unknown3dc[0x44]; /* to the 0x420 bytes the creator FUN_0079d960 allocates */
};

#endif
