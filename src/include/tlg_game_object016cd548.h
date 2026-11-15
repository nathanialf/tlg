/* src/include/tlg_game_object016cd548.h: the class whose vtable is at
 * 0x16cd548 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CD548_H
#define TLG_GAME_OBJECT016CD548_H

#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"
#include "tlg_game_pair0057e850.h"

/* derived names: the class whose vtable is at 0x16cd548
 * (config/vtables.derived.base.txt, stored by FUN_009b3260 FUN_01387100
 * FUN_013871c0), derived from Object016b9108. 0x38 bytes (`mov edi,
 * 0x38` before operator new in the creator). Its own fields are traced
 * where its creator FUN_009b3260 sets them and its destructor FUN_01387100
 * tears them down. The destructor is the class's key function
 * (leaf_01387100.cpp), so that unit emits the vtable and the
 * destructors. */
class Object016cd548 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the name, 0.1 at +0x28,
     * then the body's 0 and 20.0 at +0x2c in one `movabs` that the 0.1 before
     * it is not part of (one value of two floats, assigned whole) and `mov dword
     * [r15+0x34], 0` after it */
    Object016cd548(const Name &name) : Object016b9108(name), unknown28(0.1f)
    {
        unknown2c = Pair0057e850(0.0f, 20.0f);
        unknown34 = 0;
    }

    virtual ~Object016cd548();

  private:
    Name name24;            /* +0x24: empty from the constructor, released by the destructor */
    float unknown28;        /* +0x28: 0.1 from the constructor; not traced */
    Pair0057e850 unknown2c; /* +0x2c: 0 and 20.0 from the constructor; not traced */
    int unknown34;          /* +0x34: zero from the constructor; not traced */
};

#endif
