/* src/include/tlg_game_object016cd580.h: the class whose vtable is at
 * 0x16cd580 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CD580_H
#define TLG_GAME_OBJECT016CD580_H

#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cd580
 * (config/vtables.derived.base.txt, stored by FUN_009b33e0 FUN_01386f80
 * FUN_01387040), derived from Object016b9108. 0x48 bytes (`mov edi,
 * 0x48` before operator new in the creator). Its own fields are traced
 * where its creator FUN_009b33e0 sets them and its destructor FUN_01386f80
 * tears them down.
 * The destructor is implicit: FUN_01386f80 and the deleting
 * FUN_01387040 sit in the stretch of inline functions (from 0x1340000)
 * while the constructor is out of line, so the class has no key function
 * and the unit that constructs it (leaf_009b33e0.cpp) emits the vtable
 * with both. */
class Object016cd580 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, `mov dword` stores from
     * +0x24: the name, 0.1, 0, 0.024, 0, 1.0 (floats and ints
     * alternating: four 4-byte fields of one type would be one vector store), then `mov qword [r15+0x3c], 0`
     * and `mov dword [r15+0x44], 0` */
    Object016cd580(const Name &name)
        : Object016b9108(name), unknown28(0.1f), unknown2c(0), unknown30(0.024f), unknown34(0),
          unknown38(1.0f), unknown3c(0), unknown40(0), unknown44(0)
    {
    }

  private:
    Name name24;     /* +0x24: empty from the constructor, released by the destructor */
    float unknown28; /* +0x28: 0.1 from the constructor; not traced */
    int unknown2c;   /* +0x2c: zero from the constructor; not traced */
    float unknown30; /* +0x30: 0.024 from the constructor; not traced */
    int unknown34;   /* +0x34: zero from the constructor; not traced */
    float unknown38; /* +0x38: 1.0 from the constructor; not traced */
    int unknown3c;   /* +0x3c: zero from the constructor; not traced */
    int unknown40;   /* +0x40: zero from the constructor; not traced */
    int unknown44;   /* +0x44: zero from the constructor; not traced */
};

#endif
