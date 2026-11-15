/* src/include/tlg_game_object016b7c98.h: the class whose vtable is at
 * 0x16b7c98 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B7C98_H
#define TLG_GAME_OBJECT016B7C98_H

#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b7c98
 * (config/vtables.derived.base.txt, stored by FUN_00bedb40 FUN_00beec30
 * FUN_00beed20), derived from Object016b9108. 0x40 bytes (`mov edi,
 * 0x40` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00bedb40 sets them and its destructor FUN_00beec30
 * tears them down. */
class Object016b7c98 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, `mov dword [r15+0x24], 0`,
     * -1.0 at +0x28, the 16 bytes at +0x2c in one store (-1, 0 and the two
     * names: four 4-byte fields of one type, the vector made by `vmovd`) */
    Object016b7c98(const Name &name)
        : Object016b9108(name), unknown24(0), unknown28(-1.0f), unknown2c(-1), unknown30(0)
    {
    }

    virtual ~Object016b7c98();

  private:
    int unknown24;   /* +0x24: zero from the constructor; not traced */
    float unknown28; /* +0x28: -1.0 from the constructor; not traced */
    int unknown2c;   /* +0x2c: -1 from the constructor; not traced */
    int unknown30;   /* +0x30: zero from the constructor; not traced */
    Name name34;     /* +0x34: empty from the constructor, released by the destructor */
    Name name38;     /* +0x38: empty from the constructor, released by the destructor */
};

/* derived name: the complete destructor FUN_00beec30: the body is empty; the
 * members are released, last first, then the base's destructor is inlined.
 * FUN_00beed20, slot 1, is the deleting one and holds this one inlined.
 * Defined here, so the unit that creates the object (leaf_00bedb40.cpp)
 * emits the vtable and both destructors. */
inline Object016b7c98::~Object016b7c98() {}

#endif
