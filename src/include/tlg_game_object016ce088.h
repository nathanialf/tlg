/* src/include/tlg_game_object016ce088.h: the class whose vtable is at
 * 0x16ce088 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CE088_H
#define TLG_GAME_OBJECT016CE088_H

#include "tlg_types.h"
#include "tlg_game_object01367090.h"
#include "tlg_game_object016a7620.h"

/* derived names: the class of the vtable at 0x16ce088
 * (config/vtables.derived.base.txt; stored by FUN_00a04750 and by its
 * destructor 0x1388780, leaf_01388780.cpp): a message of three names
 * (Object016a7620's, whose vptr the destructor stores once its own member is
 * gone) with a pair of counted references at +0x20 that the destructor runs
 * FUN_01367090 on. The rest of the object is not traced. */
class Object016ce088 : public Object016a7620 /* derived name */
{
  public:
    virtual ~Object016ce088();

  private:
    u8 unknown18[0x8];
    Object01367090 unknown20; /* +0x20 */
};

#endif
