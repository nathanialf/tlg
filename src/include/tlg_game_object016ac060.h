/* src/include/tlg_game_object016ac060.h: the class whose vtable is at 0x16ac060
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AC060_H
#define TLG_GAME_OBJECT016AC060_H

#include "tlg_game_object016b9108.h"
#include "tlg_game_name.h"

/* derived names: the class whose vtable is at 0x16ac060
 * (config/vtables.derived.base.txt, stored by FUN_0066dcc0 FUN_0066e340), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced only where its destructor FUN_0066e340 tears them down
 * (the Names at +0x420, +0x2a8, +0x2a0, +0x218, +0x100); the rest are not traced. */
class Object016ac060 : public Object016b9108 /* derived name */
{
  public:
    Object016ac060(const Name &name); /* 0x66dcc0, its row named after it (D15) */
    virtual ~Object016ac060();

  private:
    u8 unknown24[0xdc];
    Name name100; /* +0x100: released by the destructor (`mov eax, [rbx+0x100]; shl 5`) */
    u8 unknown104[0x114];
    Name name218; /* +0x218: released by the destructor (`mov eax, [rbx+0x218]; shl 5`) */
    u8 unknown21c[0x84];
    Name name2a0; /* +0x2a0: released by the destructor (`mov eax, [rbx+0x2a0]; shl 5`) */
    u8 unknown2a4[0x4];
    Name name2a8; /* +0x2a8: released by the destructor (`mov eax, [rbx+0x2a8]; shl 5`) */
    u8 unknown2ac[0x174];
    Name name420; /* +0x420: released by the destructor (`mov eax, [rbx+0x420]; shl 5`) */
    u8 unknown424
        [0xdc]; /* to the 0x500 bytes the creator FUN_006572b0 allocates (`mov edi, 0x500`) */
};

#endif
