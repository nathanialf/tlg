/* src/include/tlg_game_object016b2388.h: the class whose vtable is at
 * 0x16b2388 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B2388_H
#define TLG_GAME_OBJECT016B2388_H

#include <stdlib.h>

#include "tlg_game_array01343a80.h"
#include "tlg_math.h"
#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b2388
 * (config/vtables.derived.base.txt, stored by FUN_00a773b0 FUN_00a77570), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields from +0x24
 * are traced where its constructor FUN_00a773b0 sets them and its destructor
 * FUN_00a77570 tears them down (the Names at +0x9c, +0x98, +0x94, the arrays
 * at +0x128, +0x110). 0x140 bytes. */
class Object016b2388 : public Object016b9108 /* derived name */
{
  public:
    Object016b2388(const Name &name); /* FUN_00a773b0 */
    virtual ~Object016b2388();

  private:
    u8 unknown24[0xc];
    /* +0x30: 25 words cleared together by the constructor (`vmovups ymm` at
     * +0x70, +0x50, +0x30 and `mov dword [+0x90], 0`: one memset); not traced */
    u32 unknown30[0x19];
    Name name94;   /* +0x94: released by the destructor (`mov eax, [rbx+0x94]; shl 5`) */
    Name name98;   /* +0x98: released by the destructor (`mov eax, [rbx+0x98]; shl 5`) */
    Name name9c;   /* +0x9c: released by the destructor (`mov eax, [rbx+0x9c]; shl 5`) */
    int unknowna0; /* +0xa0: zero from the constructor; not traced */
    int unknowna4; /* +0xa4: zero from the constructor; not traced */
    int unknowna8; /* +0xa8: zero from the constructor; not traced */
    int unknownac; /* +0xac: zero from the constructor; not traced */
    int unknownb0; /* +0xb0: zero from the constructor; not traced */
    int unknownb4; /* +0xb4: zero from the constructor; not traced */
    int unknownb8; /* +0xb8: zero from the constructor; not traced */
    int unknownbc; /* +0xbc: zero from the constructor; not traced */
    int unknownc0; /* +0xc0: zero from the constructor; not traced */
    u8 unknownc4[0xc];
    Float4A unknownd0; /* +0xd0: zero from the constructor (one aligned store); not traced */
    int unknowne0;     /* +0xe0: zero from the constructor; not traced */
    u8 unknowne4[0xc];
    int unknownf0;  /* +0xf0: zero from the constructor; not traced */
    int unknownf4;  /* +0xf4: zero from the constructor; not traced */
    int unknownf8;  /* +0xf8: zero from the constructor; not traced */
    int unknownfc;  /* +0xfc: zero from the constructor; not traced */
    int unknown100; /* +0x100: zero from the constructor; not traced */
    int unknown104; /* +0x104: zero from the constructor; not traced */
    int unknown108; /* +0x108: zero from the constructor; not traced */
    int unknown10c; /* +0x10c: zero from the constructor; not traced */
    /* +0x110: an array whose elements need no destructor, with its lock
     * (the word at +0x124): the destructor releases only its block (`mov
     * rax, [rbx+0x110]; ... cmp ecx, 0xa`) */
    Array01343a80<u32> array110;
    /* +0x128: the same kind of array (its lock at +0x13c) */
    Array01343a80<u32> array128;
};

#endif
