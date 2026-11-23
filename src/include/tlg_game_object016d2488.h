/* src/include/tlg_game_object016d2488.h: the class whose vtable is at
 * 0x16d2488 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016D2488_H
#define TLG_GAME_OBJECT016D2488_H

#include "tlg_game_base016cbbf8.h"
#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16d2488
 * (config/vtables.derived.base.txt, stored by FUN_00d63aa0 FUN_013ba7c0 FUN_013ba880), derived from
 * Object016b9108: its slots 2 to 4 are the base's; Base016d2450 (tlg_game_base016cbbf8.h) is its
 * second base, at +0x24. Its own fields
 * from +0x24 are traced only where its destructor FUN_013ba7c0 tears them down
 * (the Name at +0x50); the rest are not traced.
 * The destructor is implicit: FUN_013ba7c0 and the deleting
 * FUN_013ba880 sit in the stretch of inline functions (from 0x1340000)
 * while the constructor is out of line, so the class has no key function
 * and the unit that constructs it (leaf_00d63aa0.cpp) emits the vtable
 * with both. */
class Object016d2488 : public Object016b9108, public Base016d2450 /* derived name */
{
  public:
    /* inlined in the creator FUN_00d63aa0: the bases (Base016d2450's fields before the vptr), the vptr, the empty name */
    Object016d2488(const Name &name) : Object016b9108(name) {}

  private:
    Name name50;       /* +0x50: released by the destructor (`mov eax, [rbx+0x50]; shl 5`) */
    u8 unknown54[0xc]; /* the rest of the 0x60 bytes the creator allocates; not traced */
};

#endif
