/* src/include/tlg_game_object016cba70.h: the class whose vtable is at
 * 0x16cba70 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CBA70_H
#define TLG_GAME_OBJECT016CBA70_H

#include "tlg_game_base016cbbf8.h"
#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cba70
 * (config/vtables.derived.base.txt, stored by FUN_007a2a80 FUN_0136c600 FUN_0136c6d0), derived from
 * Object016b9108: its slots 2 to 4 are the base's; Base016cba70 (tlg_game_base016cbbf8.h) is its
 * second base, at +0x24. Its own fields
 * from +0x24 are traced only where its destructor FUN_0136c600 tears them down
 * (the Name at +0x9c); the rest are not traced.
 * The destructor is implicit: FUN_0136c600 and the deleting
 * FUN_0136c6d0 sit in the stretch of inline functions (from 0x1340000)
 * while the constructor is out of line, so the class has no key function
 * and the unit that constructs it (leaf_007a2a80.cpp) emits the vtable
 * with both. */
class Object016cba70 : public Object016b9108, public Base016cba70 /* derived name */
{
  public:
    /* inlined in the creator FUN_007a2a80: the bases (Base016cba70's fields before the vptr), the vptr, the empty name */
    Object016cba70(const Name &name) : Object016b9108(name) {}

  private:
    Name name9c; /* +0x9c: released by the destructor (`mov eax, [rbx+0x9c]; shl 5`) */
};

#endif
