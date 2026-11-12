/* src/include/tlg_game_object016ccdd0.h: the class whose vtable is at
 * 0x16ccdd0, a member of the class at 0x16ccdf0 (game region;
 * docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CCDD0_H
#define TLG_GAME_OBJECT016CCDD0_H

#include "tlg_types.h"

/* derived names: the class whose vtable is at 0x16ccdd0
 * (config/vtables.derived.base.txt, two slots; stored by its constructor
 * FUN_00961bf0): its destructor (FUN_0137e9a0, leaf_0137e9a0.cpp) releases
 * the heap block at +0x8 when it holds one and clears the pointer and the
 * count at +0x14. The class has no base. The other members are not traced.
 * Object016ccdf0 (tlg_game_object016ccdf0.h) holds one at +0x38. */
class Object016ccdd0 /* derived name */
{
  public:
    virtual ~Object016ccdd0();

  private:
    void *block8; /* +0x8 */
    u8 unknown10[0x4];
    int count14; /* +0x14 */
};

#endif
