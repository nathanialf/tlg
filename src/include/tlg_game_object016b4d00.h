/* src/include/tlg_game_object016b4d00.h: the class whose vtable is at 0x16b4d00
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B4D00_H
#define TLG_GAME_OBJECT016B4D00_H

#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b4d00
 * (config/vtables.derived.base.txt): its destructor 0x1392440 stores the
 * vtable, releases the counted reference at +0x48, then the name at +0x38,
 * and runs no base's. The classes whose destructors call it (0x1392620 and
 * the classes FUN_00b14040 makes) derive from it. The other fields are not
 * traced. */
class Object016b4d00 /* derived name */
{
  public:
    virtual ~Object016b4d00();

  private:
    u8 unknown8[0x30];
    Name name38; /* +0x38 */
    u8 unknown3c[0xc];
    Ref00503fb0<Object016b9108> held48; /* +0x48 */
};

#endif
