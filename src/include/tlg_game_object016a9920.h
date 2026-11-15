/* src/include/tlg_game_object016a9920.h: the class whose vtable is at
 * 0x16a9920 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A9920_H
#define TLG_GAME_OBJECT016A9920_H

#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"
#include "tlg_game_pair0057e850.h"

/* derived names: the class whose vtable is at 0x16a9920
 * (config/vtables.derived.base.txt, stored by FUN_004299b0 FUN_00429b20
 * FUN_00429be0), derived from Object016b9108. 0x48 bytes (`mov edi,
 * 0x48` before operator new in the creator). Its own fields are traced
 * where its creator FUN_004299b0 sets them and its destructor FUN_00429b20
 * tears them down. The destructor is the class's key function
 * (leaf_00429b20.cpp), so that unit emits the vtable and the
 * destructors. */
class Object016a9920 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the 16 bytes at +0x24
     * cleared in one store (`vmovdqu [r15+0x24], xmm0`: two ints, the name and
     * an int, a run of zero stores made one memset), 1.0 at +0x34, then the
     * body's 1.0 twice at +0x38 in one `movabs` that the 1.0 before it is not
     * part of: the two are one value of two floats, assigned whole */
    Object016a9920(const Name &name)
        : Object016b9108(name), unknown24(0), unknown28(0), unknown30(0), unknown34(1.0f)
    {
        unknown38 = Pair0057e850(1.0f, 1.0f);
    }

    virtual ~Object016a9920();

  private:
    int unknown24;          /* +0x24: zero from the constructor; not traced */
    int unknown28;          /* +0x28: zero from the constructor; not traced */
    Name name2c;            /* +0x2c: empty from the constructor, released by the destructor */
    int unknown30;          /* +0x30: zero from the constructor; not traced */
    float unknown34;        /* +0x34: 1.0 from the constructor; not traced */
    Pair0057e850 unknown38; /* +0x38: 1.0 twice from the constructor; not traced */
    u8 unknown40[0x8];
};

#endif
