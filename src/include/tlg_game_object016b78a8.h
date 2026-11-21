/* src/include/tlg_game_object016b78a8.h: the class whose vtable is at
 * 0x16b78a8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B78A8_H
#define TLG_GAME_OBJECT016B78A8_H

#include "tlg_types.h"
#include "tlg_game_array.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b78a8
 * (config/vtables.derived.base.txt; stored by FUN_00ae88e0), derived from
 * Object016b9108: counted references at +0x28 and +0x30, which its
 * destructor (0xbdcda0, its row named for it, D15) empties by
 * compare-and-swap, the first first, and an array at +0x38 whose elements
 * have no destructor (only its block released); the members are then
 * destroyed last to first before the base's destructor. The array's element
 * type and the other fields are not traced. */
class Object016b78a8 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b78a8();

  private:
    u8 unknown24[0x4];
    AtomicRef0045c470<Object016b9108> held28; /* +0x28 */
    AtomicRef0045c470<Object016b9108> held30; /* +0x30 */
    Array05943280<void *> unknown38;          /* +0x38 */
};

#endif
