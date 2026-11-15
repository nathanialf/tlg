/* src/include/tlg_game_object016ccdf0.h: the class whose vtable is at
 * 0x16ccdf0, the base of the class at 0x16b1208 (game region;
 * docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CCDF0_H
#define TLG_GAME_OBJECT016CCDF0_H

#include "tlg_types.h"
#include "tlg_game_object01343880.h"
#include "tlg_game_object016ccdd0.h"

/* derived names: the class whose vtable is at 0x16ccdf0
 * (config/vtables.derived.base.txt, stored by FUN_00967d40 FUN_00967e80
 * FUN_0137f420 FUN_0137f500), derived from Object01343880
 * (tlg_game_object01343880.h: slots 5 to 8 are that class's). Its own
 * fields are traced only where its destructor FUN_0137f420 tears them down:
 * the Object016ccdd0 at +0x38, whose vptr the destructor stores at +0x38 (0x16ccde0) before it
 * releases that member's block at +0x40. */
class Object016ccdf0 : public Object01343880 /* derived name */
{
  public:
    virtual ~Object016ccdf0();

  private:
    Object016ccdd0 member38; /* +0x38: destroyed by the destructor */
};

/* derived name: the complete destructor (slot 0 of 0x16ccdf0, FUN_0137f420):
 * the body is empty; the member at +0x38 is destroyed (its destructor
 * FUN_0137e9a0 inlined: its vptr store, the block at +0x40, the count at
 * +0x4c), then the base's destructor is inlined (its vptr store, then the two
 * names). FUN_0137f500, slot 1, is the deleting one. Defined here, inline:
 * the destructor of the derived class at 0x16b1208 (FUN_00967d40) holds this
 * body, and the deleting destructor holds it too; the class's vtable and
 * its two destructors are emitted by the unit that stores the vtable
 * (leaf_00967d40.cpp, the rows' unit). */
inline Object016ccdf0::~Object016ccdf0() {}

#endif
