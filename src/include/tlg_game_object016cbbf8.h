/* src/include/tlg_game_object016cbbf8.h: the class whose vtable is at
 * 0x16cbbf8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CBBF8_H
#define TLG_GAME_OBJECT016CBBF8_H

#include "tlg_game_base016cbbf8.h"
#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cbbf8
 * (config/vtables.derived.base.txt, stored by FUN_007adaa0 FUN_0136df20 FUN_0136dfe0), derived from
 * Object016b9108: its slots 2 to 4 are the base's; Base016cbbf8 (tlg_game_base016cbbf8.h) is its
 * second base, at +0x24. Its own fields
 * from +0x24 are traced only where its destructor FUN_0136df20 tears them down
 * (the Name at +0x40); the rest are not traced.
 * The destructor is implicit: FUN_0136df20 and the deleting
 * FUN_0136dfe0 sit in the stretch of inline functions (from 0x1340000)
 * while the constructor is out of line, so the class has no key function
 * and the unit that constructs it (leaf_007adaa0.cpp) emits the vtable
 * with both. */
class Object016cbbf8 : public Object016b9108, public Base016cbbf8 /* derived name */
{
  public:
    /* inlined in the creator FUN_007adaa0: the bases (Base016cbbf8's fields before the vptr), the vptr, the empty name */
    Object016cbbf8(const Name &name) : Object016b9108(name) {}

  private:
    Name name40;       /* +0x40: released by the destructor (`mov eax, [rbx+0x40]; shl 5`) */
    u8 unknown44[0xc]; /* the rest of the 0x50 bytes the creator allocates; not traced */
};

#endif
