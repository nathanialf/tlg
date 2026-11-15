/* src/include/tlg_game_object016a9638.h: the class whose vtable is at
 * 0x16a9638 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A9638_H
#define TLG_GAME_OBJECT016A9638_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a9638
 * (config/vtables.derived.base.txt, stored by FUN_003f45f0 FUN_003f49a0), derived from
 * Object016b9108: its slots 2 to 4 are the base's, slots 5 to 9 its own (declared; their bodies are not written here). Its own fields
 * from +0x24 are traced only where its destructor FUN_003f49a0 tears them down
 * (the arrays of Names at +0x40, +0x28, the Names at +0x5c, +0x58); the constructor appends a Name to each array and sets the two
 * Names. 0x60 bytes (`mov edi, 0x60` before operator new in its creator
 * FUN_003f4490). */
class Object016a9638 : public Object016b9108 /* derived name */
{
  public:
    Object016a9638(const Name &name); /* FUN_003f45f0 */
    virtual ~Object016a9638();
    virtual void slot5(); /* derived name; FUN_003f4bf0, not traced */
    virtual void slot6(); /* derived name; FUN_003f4c00, not traced */
    virtual void slot7(); /* derived name; FUN_003f4c10, not traced */
    virtual void slot8(); /* derived name; FUN_000058a0, not traced */
    virtual void slot9(); /* derived name; FUN_003f60c0, not traced */

  private:
    u8 unknown24[0x4];
    /* +0x28: an array of Names (the block at +0x28, the count at +0x30): the destructor releases each
     * (`mov r12, [r14+0x28]; mov ecx, [r12+rbx*4]` ... `cmp ebx, eax; jb`), then the block */
    Array01343a80<Name> names28;
    /* +0x40: an array of Names (the block at +0x40, the count at +0x48): the destructor releases each
     * (`mov r12, [r14+0x40]; mov ecx, [r12+rbx*4]` ... `cmp ebx, eax; jb`), then the block */
    Array01343a80<Name> names40;
    Name name58; /* +0x58: released by the destructor (`mov eax, [rbx+0x58]; shl 5`) */
    Name name5c; /* +0x5c: released by the destructor (`mov eax, [rbx+0x5c]; shl 5`) */
};

#endif
