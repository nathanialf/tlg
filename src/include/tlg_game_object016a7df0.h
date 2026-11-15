/* src/include/tlg_game_object016a7df0.h: the class whose vtable is at
 * 0x16a7df0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A7DF0_H
#define TLG_GAME_OBJECT016A7DF0_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a7df0
 * (config/vtables.derived.base.txt, stored by FUN_002a9d20 FUN_002a9e40 FUN_002a9fc0), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced only where its destructor FUN_002a9e40 tears them down
 * (the Name at +0x24, the blocks at +0x60, +0x48, +0x30); the rest are not traced. 0x88 bytes (`mov edi, 0x88` before operator
 * new in its creator FUN_002a9bc0). */
class Object016a7df0 : public Object016b9108 /* derived name */
{
  public:
    Object016a7df0(const Name &name); /* FUN_002a9d20 */
    virtual ~Object016a7df0();

  private:
    Name
        name24; /* +0x24: emptied again by the constructor's body, released by the destructor (`mov eax, [rbx+0x24]; shl 5`) */
    void *unknown28; /* +0x28: null from the constructor's body; not traced */
    /* +0x30, +0x48, +0x60: arrays whose elements need no destructor: the
     * destructor only releases their blocks (`mov rax, [rbx+0x30]; ... cmp
     * ecx, 0xa`); the constructor clears each and takes its owner index from
     * the thread's heap */
    Array01343a80<u32> array30;
    Array01343a80<u32> array48;
    Array01343a80<u32> array60;
    void *unknown78; /* +0x78: null from the constructor's body; not traced */
    void *unknown80; /* +0x80: null from the constructor's body; not traced */
};

#endif
