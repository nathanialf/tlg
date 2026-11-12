/* src/include/tlg_game_object016ccdf0.h: the class whose vtable is at
 * 0x16ccdf0, the base of the class at 0x16b1208 (game region;
 * docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CCDF0_H
#define TLG_GAME_OBJECT016CCDF0_H

#include "tlg_types.h"
#include "tlg_game_object016b9108.h"
#include "tlg_game_object016ccdd0.h"

/* derived names: the class whose vtable is at 0x16ccdf0
 * (config/vtables.derived.base.txt, stored by FUN_00967d40 FUN_00967e80
 * FUN_0137f420 FUN_0137f500), derived from Object016b9108: its slots 2 to 4
 * are the base's, slots 5 to 8 its own (declared; their bodies are not
 * written). Its own fields from +0x24 are traced only where its destructor
 * FUN_0137f420 (leaf_0137f420.cpp) tears them down: the Object016ccdd0 at
 * +0x38, whose vptr the destructor stores at +0x38 (0x16ccde0) before it
 * releases that member's block at +0x40. */
class Object016ccdf0 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016ccdf0();
    virtual void slot5(); /* derived name; FUN_000058a0, not traced */
    virtual void slot6(); /* derived name; FUN_01343880, not traced */
    virtual void slot7(); /* derived name; 0x1af750 */
    virtual void slot8(); /* derived name; 0x1af750 */

  private:
    u8 unknown24[0x14];
    Object016ccdd0 member38; /* +0x38: destroyed by the destructor */
};

#endif
