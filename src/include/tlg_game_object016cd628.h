/* src/include/tlg_game_object016cd628.h: the class whose vtable is at
 * 0x16cd628 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CD628_H
#define TLG_GAME_OBJECT016CD628_H

#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"
#include "tlg_game_pair0057e850.h"

/* derived names: the class whose vtable is at 0x16cd628
 * (config/vtables.derived.base.txt, stored by FUN_009b3960 FUN_01386a80
 * FUN_01386b40), derived from Object016b9108. 0x58 bytes (`mov edi,
 * 0x58` before operator new in the creator). Its own fields are traced
 * where its creator FUN_009b3960 sets them and its destructor FUN_01386a80
 * tears them down.
 * The destructor is implicit: FUN_01386a80 and the deleting
 * FUN_01386b40 sit in the stretch of inline functions (from 0x1340000)
 * while the constructor is out of line, so the class has no key function
 * and the unit that constructs it (leaf_009b3960.cpp) emits the vtable
 * with both. */
class Object016cd628 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, `mov dword` stores from
     * +0x24: the name, 0.1, 0, 1, 2.0, 0, 0.5, 0, 0.2, then the body's 0 and
     * 10.0 at +0x48 in one `movabs` that the 0.2 before it is not part of (one
     * value of two floats, assigned whole) and `mov dword [r15+0x50], 0` */
    Object016cd628(const Name &name)
        : Object016b9108(name), unknown28(0.1f), unknown2c(0), unknown30(1), unknown34(2.0f),
          unknown38(0), unknown3c(0.5f), unknown40(0), unknown44(0.2f)
    {
        unknown48 = Pair0057e850(0.0f, 10.0f);
        unknown50 = 0;
    }

  private:
    Name name24;            /* +0x24: empty from the constructor, released by the destructor */
    float unknown28;        /* +0x28: 0.1 from the constructor; not traced */
    int unknown2c;          /* +0x2c: zero from the constructor; not traced */
    int unknown30;          /* +0x30: 1 from the constructor; not traced */
    float unknown34;        /* +0x34: 2.0 from the constructor; not traced */
    int unknown38;          /* +0x38: zero from the constructor; not traced */
    float unknown3c;        /* +0x3c: 0.5 from the constructor; not traced */
    int unknown40;          /* +0x40: zero from the constructor; not traced */
    float unknown44;        /* +0x44: 0.2 from the constructor; not traced */
    Pair0057e850 unknown48; /* +0x48: 0 and 10.0 from the constructor; not traced */
    int unknown50;          /* +0x50: zero from the constructor; not traced */
    u8 unknown54[0x4];
};

#endif
