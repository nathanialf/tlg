/* src/include/tlg_game_object016b2388.h: the class whose vtable is at
 * 0x16b2388 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B2388_H
#define TLG_GAME_OBJECT016B2388_H

#include "tlg_game_block.h"
#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b2388
 * (config/vtables.derived.base.txt, stored by FUN_00a773b0 FUN_00a77570), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced only where its destructor FUN_00a77570 tears them down
 * (the Names at +0x9c, +0x98, +0x94, the blocks at +0x128, +0x110); the rest are not traced. */
class Object016b2388 : public Object016b9108 /* derived name */
{
  public:
    Object016b2388(const Name &name); /* FUN_00a773b0 */
    virtual ~Object016b2388();

  private:
    u8 unknown24[0x70];
    Name name94; /* +0x94: released by the destructor (`mov eax, [rbx+0x94]; shl 5`) */
    Name name98; /* +0x98: released by the destructor (`mov eax, [rbx+0x98]; shl 5`) */
    Name name9c; /* +0x9c: released by the destructor (`mov eax, [rbx+0x9c]; shl 5`) */
    u8 unknowna0[0x70];
    /* +0x110: an owned block, released by the destructor (`mov rax, [rbx+0x110]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block110;
    u8 unknown118[0x10];
    /* +0x128: an owned block, released by the destructor (`mov rax, [rbx+0x128]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block128;
    u8 unknown130[0x10]; /* the rest of the 0x140 bytes the creator allocates; not traced */
};

#endif
