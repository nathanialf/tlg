/* src/include/tlg_game_object016ce038.h: the class whose vtable is at
 * 0x16ce038 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CE038_H
#define TLG_GAME_OBJECT016CE038_H

#include "tlg_types.h"
#include "tlg_game_object01367090.h"
#include "tlg_game_object016a7620.h"

/* derived names: the class of the vtable at 0x16ce038
 * (config/vtables.derived.base.txt; stored by FUN_00a036a0 and by its
 * destructor 0x1388680, leaf_01388680.cpp): a message of three names
 * (Object016a7620's, whose vptr the destructor stores once its own member is
 * gone) with a pair of counted references at +0x20 that the destructor runs
 * FUN_01367090 on. The rest of the object is not traced. */
class Object016ce038 : public Object016a7620 /* derived name */
{
  public:
    virtual ~Object016ce038();

  private:
    u8 unknown18[0x8];
    Object01367090 unknown20; /* +0x20 */
};

#endif
