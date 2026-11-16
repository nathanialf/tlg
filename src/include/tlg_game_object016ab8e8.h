/* src/include/tlg_game_object016ab8e8.h: the class whose vtable is at 0x16ab8e8
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AB8E8_H
#define TLG_GAME_OBJECT016AB8E8_H

#include "tlg_game_object016b9108.h"
#include "tlg_game_object0134f620.h"
#include "tlg_game_block.h"
#include "tlg_game_array.h"
#include "tlg_game_name.h"

/* derived names: the class whose vtable is at 0x16ab8e8
 * (config/vtables.derived.base.txt, stored by FUN_005a65d0 FUN_005a6ce0), derived from
 * Object016b9108: its slots 2 to 4 are the base's, slots 5 to 6 its own (declared; their bodies are not written here). Its own fields
 * from +0x24 are traced only where its destructor FUN_005a6ce0 tears them down
 * (the array of Names at +0x30, the block at +0x48, the record at +0x68); the rest are not traced.
 * The creator FUN_005a6470 allocates 0x80 bytes (`mov edi, 0x80` before operator new). */
class Object016ab8e8 : public Object016b9108 /* derived name */
{
  public:
    Object016ab8e8(const Name &name); /* FUN_005a65d0, its row named after it (D15) */
    virtual ~Object016ab8e8();
    virtual void slot5(); /* derived name; FUN_001af750, not traced */
    virtual void slot6(); /* derived name; FUN_00c1b350, not traced */

  private:
    u8 unknown24[0xc];
    /* +0x30: an array of Names (the block at +0x30, the count at +0x38): the destructor releases each
     * (`mov r12, [r14+0x30]; mov ecx, [r12+rbx*4]` ... `cmp ebx, eax; jb`), then the block */
    Array05943280<Name> names30;
    /* +0x48: an owned block, released by the destructor (`mov rax, [rbx+0x48]; ... cmp ecx, 0xa`) */
    OwnedBlock05943280 block48;
    u8 unknown50[0x18];
    /* +0x68: torn down by the destructor (`lea rdi, [rbx+0x68]; call 0x134f620`) */
    Object0134f620 record68;
};

#endif
