/* src/include/tlg_game_object016a85a8.h: the class whose vtable is at
 * 0x16a85a8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A85A8_H
#define TLG_GAME_OBJECT016A85A8_H

#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a85a8
 * (config/vtables.derived.base.txt, stored by FUN_00324dd0 FUN_00324f50
 * FUN_00325040), derived from Object016b9108. 0x48 bytes (`mov edi,
 * 0x48` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00324dd0 sets them and its destructor FUN_00324f50
 * tears them down. */
class Object016a85a8 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, `mov dword, 0` at +0x24,
     * +0x28 and +0x2c (an int and the two names), the four floats at +0x30 from
     * the constants at 0x1528d80 (30, 0, 10, 60), 30.0 at +0x40 */
    Object016a85a8(const Name &name)
        : Object016b9108(name), unknown24(0), unknown30(30.0f), unknown34(0.0f), unknown38(10.0f),
          unknown3c(60.0f), unknown40(30.0f)
    {
    }

    virtual ~Object016a85a8();

  private:
    int unknown24;   /* +0x24: zero from the constructor; not traced */
    Name name28;     /* +0x28: empty from the constructor, released by the destructor */
    Name name2c;     /* +0x2c: empty from the constructor, released by the destructor */
    float unknown30; /* +0x30: 30.0 from the constructor; not traced */
    float unknown34; /* +0x34: zero from the constructor; not traced */
    float unknown38; /* +0x38: 10.0 from the constructor; not traced */
    float unknown3c; /* +0x3c: 60.0 from the constructor; not traced */
    float unknown40; /* +0x40: 30.0 from the constructor; not traced */
};

/* derived name: the complete destructor FUN_00324f50: the body is empty; the
 * members are released, last first, then the base's destructor is inlined.
 * FUN_00325040, slot 1, is the deleting one and holds this one inlined.
 * Defined here, so the unit that creates the object (leaf_00324dd0.cpp)
 * emits the vtable and both destructors. */
inline Object016a85a8::~Object016a85a8() {}

#endif
