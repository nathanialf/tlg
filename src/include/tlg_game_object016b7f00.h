/* src/include/tlg_game_object016b7f00.h: the class whose vtable is at
 * 0x16b7f00 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B7F00_H
#define TLG_GAME_OBJECT016B7F00_H

#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b7f00
 * (config/vtables.derived.base.txt; stored by FUN_00c18d90), derived from
 * Object016b9108, its destructor 0xc19090 (its row named for it, D15):
 * Names at +0x2c and +0x30, a counted reference at +0x38
 * that its destructor's body empties by compare-and-swap, and counted
 * references at +0x40 and +0x48, the members then destroyed last to first
 * before the base's destructor runs. FUN_00c193a0, slot 1, is the deleting
 * destructor. The other fields are not traced. */
class Object016b7f00 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b7f00();

  private:
    u8 unknown24[0x8];
    Name unknown2c;                           /* +0x2c */
    Name unknown30;                           /* +0x30 */
    AtomicRef0045c470<Object016b9108> held38; /* +0x38 */
    Ref00503fb0<Object016b9108> unknown40;    /* +0x40 */
    Ref00503fb0<Object016b9108> unknown48;    /* +0x48 */
};

#endif
