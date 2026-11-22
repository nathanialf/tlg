/* src/include/tlg_game_object016a7a50.h: the class whose vtable is at 0x16a7a50
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A7A50_H
#define TLG_GAME_OBJECT016A7A50_H

#include "tlg_game_array.h"
#include "tlg_game_name.h"
#include "tlg_game_object016aed28.h"

/* derived names: the class whose vtable is at 0x16a7a50
 * (config/vtables.derived.base.txt, stored by FUN_00297190 FUN_00297320), 0x5e0 bytes
 * (`mov edi, 0x5e0` before operator new in its creator FUN_00297030),
 * derived from Object016aed28 (tlg_game_object016aed28.h). Its constructor
 * FUN_00297190 is not written; its fields are traced where its destructor
 * FUN_00297320 tears them down: three arrays of names and a name (the array
 * at +0x580 emptied by FUN_00296f80, "Ai2ResetStaticVolSensor"'s visitor).
 * The destructor is the key function: leaf_00297320.cpp emits the vtable. */
class Object016a7a50 : public Object016aed28 /* derived name */
{
  public:
    Object016a7a50(const Name &name); /* FUN_00297190 */
    virtual ~Object016a7a50();

    Array05943280<Name> names580; /* +0x580 */
    Name name598;                 /* +0x598 */

  private:
    u8 unknown59c[0xc];

  public:
    Array05943280<Name> names5a8; /* +0x5a8 */
    Array05943280<Name> names5c0; /* +0x5c0 */

  private:
    u8 unknown5d8[0x8];
};

#endif
