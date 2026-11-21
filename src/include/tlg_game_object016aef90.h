/* src/include/tlg_game_object016aef90.h: the class whose vtable is at 0x16aef90 and
 * whose complete destructor is 0x847290, a base of other game classes (game
 * region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AEF90_H
#define TLG_GAME_OBJECT016AEF90_H

#include "tlg_game_object016ae7e0.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16aef90
 * (config/vtables.derived.base.txt, stored by FUN_00846c90 FUN_00847290), derived from
 * Object016ae7e0 (tlg_game_object016ae7e0.h, 0x9c bytes of data), whose
 * fields from +0x9c are not traced.
 * Its own fields are traced only where its destructor FUN_00847290 tears them
 * down (the counted reference at +0xc0, the Names at +0x11c, +0x118, +0x110, +0x10c, +0x108, +0x104, +0x100, +0xa0); the rest are not traced. */
class Object016aef90 : public Object016ae7e0 /* derived name */
{
  public:
    Object016aef90(const Name &name); /* 0x846c90, its row named after it (D15) */
    virtual ~Object016aef90();

  private:
    u8 unknown9c[0x4];
    Name namea0; /* +0xa0: released by the destructor (`mov eax, [rbx+0xa0]; shl 5`) */
    u8 unknowna4[0x1c];
    /* +0xc0: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> heldc0;
    u8 unknownc8[0x38];
    Name name100; /* +0x100: released by the destructor (`mov eax, [rbx+0x100]; shl 5`) */
    Name name104; /* +0x104: released by the destructor (`mov eax, [rbx+0x104]; shl 5`) */
    Name name108; /* +0x108: released by the destructor (`mov eax, [rbx+0x108]; shl 5`) */
    Name name10c; /* +0x10c: released by the destructor (`mov eax, [rbx+0x10c]; shl 5`) */
    Name name110; /* +0x110: released by the destructor (`mov eax, [rbx+0x110]; shl 5`) */
    u8 unknown114[0x4];
    Name name118; /* +0x118: released by the destructor (`mov eax, [rbx+0x118]; shl 5`) */
    Name name11c; /* +0x11c: released by the destructor (`mov eax, [rbx+0x11c]; shl 5`) */
};

#endif
