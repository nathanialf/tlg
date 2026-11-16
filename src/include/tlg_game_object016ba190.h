/* src/include/tlg_game_object016ba190.h: the class whose vtable is at
 * 0x16ba190 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016BA190_H
#define TLG_GAME_OBJECT016BA190_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16ba190
 * (config/vtables.derived.base.txt, stored by FUN_00d23490 FUN_00d237d0),
 * derived from Object016b9108 (its constructor calls Object016b9108's with
 * the name). Its objects come from a pool of 0x108-byte blocks, not from
 * operator new (FUN_00d1fb50). The fields are not traced. */
class Object016ba190 : public Object016b9108 /* derived name */
{
  public:
    Object016ba190(const Name &name); /* FUN_00d23490 */
    virtual ~Object016ba190();
};

/* derived name: takes a block from the class's pool under the pool's own
 * spin lock (0x5948194), growing the pool by an allocation of count times
 * size plus 0x10 bytes when it is empty; the block's next link is at +0x100 */
void *FUN_00d1fb50();

#endif
