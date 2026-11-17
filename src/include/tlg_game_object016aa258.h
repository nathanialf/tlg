/* src/include/tlg_game_object016aa258.h: the class whose vtable is at
 * 0x16aa258 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AA258_H
#define TLG_GAME_OBJECT016AA258_H

#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_array01343a80.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16aa258
 * (config/vtables.derived.base.txt, stored by its creator FUN_004b51d0, where
 * its constructor is inlined after Object016b9108's), derived from Object016b9108. 0x98 bytes
 * (`mov edi, 0x98` before operator new in the creator). Its fields are traced only where the creator sets them; its destructor is not written, so nothing here emits the vtable. */
class Object016aa258 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the array at
     * +0x28 (its owner index from the thread's heap, its lock free), the 49
     * bytes from +0x40 cleared (two overlapping `vmovups` of ymm0 at +0x51 and
     * +0x40), null at +0x78 and +0x80, -1.0 at +0x88 and 0 from +0x8c */
    Object016aa258(const Name &name)
        : Object016b9108(name), unknown40(), unknown70(false), unknown78(0), unknown80(0),
          unknown88(-1.0f), unknown8c(0), unknown90(0), unknown94(0)
    {
    }

    virtual ~Object016aa258();

  private:
    u8 unknown24[0x4];
    Array01343a80<void *> array28; /* +0x28: empty from the constructor; its elements not traced */
    void *unknown40[6];            /* +0x40: null from the constructor; not traced */
    bool unknown70;                /* +0x70: false from the constructor */
    u8 unknown71[0x7];
    void *unknown78; /* +0x78: null from the constructor; not traced */
    void *unknown80; /* +0x80: null from the constructor; not traced */
    float unknown88; /* +0x88: -1.0 from the constructor */
    int unknown8c;   /* +0x8c: 0 from the constructor */
    int unknown90;   /* +0x90: 0 from the constructor */
    int unknown94;   /* +0x94: 0 from the constructor */
};

#endif
