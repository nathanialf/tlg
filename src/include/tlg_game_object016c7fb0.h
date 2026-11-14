/* src/include/tlg_game_object016c7fb0.h: the class whose vtable is at 0x16c7fb0 and
 * whose complete destructor is 0xbe1980, a base of other game classes (game
 * region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016C7FB0_H
#define TLG_GAME_OBJECT016C7FB0_H

#include "tlg_game_object016b9108.h"
#include "tlg_game_object0134f620.h"
#include "tlg_game_block.h"
#include "tlg_game_array.h"
#include "tlg_game_name.h"

/* derived names: the class whose vtable is at 0x16c7fb0
 * (config/vtables.derived.base.txt, stored by FUN_00be1980 FUN_00be4000 FUN_00be4a80), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced only where its destructor FUN_00be1980 tears them down
 * (the arrays of Names at +0xc0, +0xa8, the Name at +0x24, the blocks at +0x70, +0x58, the record at +0x28); the rest are not traced. */
class Object016c7fb0 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016c7fb0();

  private:
    Name name24; /* +0x24: released by the destructor (`mov eax, [rbx+0x24]; shl 5`) */
    /* +0x28: torn down by the destructor (`lea rdi, [rbx+0x28]; call 0x134f620`) */
    Object0134f620 record28;
    u8 unknown40[0x18];
    /* +0x58: an owned block, released by the destructor (`mov rax, [rbx+0x58]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block58;
    u8 unknown60[0x10];
    /* +0x70: an owned block, released by the destructor (`mov rax, [rbx+0x70]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block70;
    u8 unknown78[0x30];
    /* +0xa8: an array of Names (the block at +0xa8, the count at +0xb0): the destructor releases each
     * (`mov r12, [r14+0xa8]; mov ecx, [r12+rbx*4]` ... `cmp ebx, eax; jb`), then the block */
    Array05943280<Name> namesa8;
    /* +0xc0: an array of Names (the block at +0xc0, the count at +0xc8): the destructor releases each
     * (`mov r12, [r14+0xc0]; mov ecx, [r12+rbx*4]` ... `cmp ebx, eax; jb`), then the block */
    Array05943280<Name> namesc0;
};

#endif
