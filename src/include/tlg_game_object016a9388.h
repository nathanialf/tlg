/* src/include/tlg_game_object016a9388.h: the class whose vtable is at
 * 0x16a9388 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A9388_H
#define TLG_GAME_OBJECT016A9388_H

#include "tlg_game_array.h"
#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a9388
 * (config/vtables.derived.base.txt, stored by FUN_003ecd10 FUN_003ed000), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced only where its destructor FUN_003ed000 tears them down
 * (the arrays of Names at +0x60, +0x48); the rest are not traced. */
class Object016a9388 : public Object016b9108 /* derived name */
{
  public:
    Object016a9388(const Name &name); /* FUN_003ecd10 */
    virtual ~Object016a9388();

  private:
    u8 unknown24[0x24];
    /* +0x48: an array of Names (the block at +0x48, the count at +0x50): the destructor releases each
     * (`mov r12, [r14+0x48]; mov ecx, [r12+rbx*4]` ... `cmp ebx, eax; jb`), then the block */
    Array05943280<Name> names48;
    /* +0x60: an array of Names (the block at +0x60, the count at +0x68): the destructor releases each
     * (`mov r12, [r14+0x60]; mov ecx, [r12+rbx*4]` ... `cmp ebx, eax; jb`), then the block */
    Array05943280<Name> names60;
    u8 unknown78[0x68]; /* the rest of the 0xe0 bytes the creator allocates; not traced */
};

#endif
