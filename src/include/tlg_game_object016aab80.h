/* src/include/tlg_game_object016aab80.h: the class whose vtable is at
 * 0x16aab80 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AAB80_H
#define TLG_GAME_OBJECT016AAB80_H

#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_array01343a80.h"
#include "tlg_game_object01343880.h"

/* derived names: the class whose vtable is at 0x16aab80
 * (config/vtables.derived.base.txt, stored by its creator FUN_00503960, where
 * its constructor is inlined after Object01343880's), derived from Object01343880. 0x90 bytes
 * (`mov edi, 0x90` before operator new in the creator). Its fields are traced only where the creator sets them; its destructor is not written, so nothing here emits the vtable. */
class Object016aab80 : public Object01343880 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the 32 bytes
     * from +0x38 cleared, 0 at +0x58 and +0x60, the array at +0x68 (its
     * owner index from the thread's heap, its lock free), null at +0x80 and 0
     * at +0x88 */
    Object016aab80(const Name &name)
        : Object01343880(name), unknown38(), unknown58(0), unknown60(0), unknown80(0), unknown88(0)
    {
    }

    virtual ~Object016aab80();

  private:
    void *unknown38[4]; /* +0x38: null from the constructor; not traced */
    int unknown58;      /* +0x58: 0 from the constructor */
    u8 unknown5c[0x4];
    void *unknown60;               /* +0x60: null from the constructor; not traced */
    Array01343a80<void *> array68; /* +0x68: empty from the constructor; its elements not traced */
    void *unknown80;               /* +0x80: null from the constructor; not traced */
    int unknown88;                 /* +0x88: 0 from the constructor */
    u8 unknown8c[0x4];
};

#endif
