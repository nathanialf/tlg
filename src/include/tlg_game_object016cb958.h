/* src/include/tlg_game_object016cb958.h: the class whose vtable is at
 * 0x16cb958 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CB958_H
#define TLG_GAME_OBJECT016CB958_H

#include "tlg_game_base016cbbf8.h"
#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cb958
 * (config/vtables.derived.base.txt, stored by FUN_007a2150 FUN_0136c1e0 FUN_0136c2a0), derived from
 * Object016b9108: its slots 2 to 4 are the base's; Base016cb958 (tlg_game_base016cbbf8.h) is its
 * second base, at +0x24. Its own fields
 * from +0x24 are traced only where its destructor FUN_0136c1e0 tears them down
 * (the Name at +0x74); the rest are not traced. */
class Object016cb958 : public Object016b9108, public Base016cb958 /* derived name */
{
  public:
    /* inlined in the creator FUN_007a2150: the bases (Base016cb958's fields before the vptr), the vptr, the empty name */
    Object016cb958(const Name &name) : Object016b9108(name) {}

    virtual ~Object016cb958();

  private:
    Name name74;       /* +0x74: released by the destructor (`mov eax, [rbx+0x74]; shl 5`) */
    u8 unknown78[0x8]; /* the rest of the 0x80 bytes the creator allocates; not traced */
};

#endif
