/* src/include/tlg_game_object016ab968.h: the class whose vtable is at
 * 0x16ab968 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AB968_H
#define TLG_GAME_OBJECT016AB968_H

#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16ab968
 * (config/vtables.derived.base.txt, stored by FUN_005a81d0 FUN_005aac20
 * FUN_005aace0), derived from Object016b9108. 0x30 bytes (`mov edi,
 * 0x30` before operator new in the creator). Its own fields are traced
 * where its creator FUN_005a81d0 sets them and its destructor FUN_005aac20
 * tears them down. */
class Object016ab968 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, `movabs rdx,
     * 0xbf80000000000000` stored at +0x24 (the name and -1.0), `mov dword
     * [r15+0x2c], 0x3f000000` (0.5) */
    Object016ab968(const Name &name) : Object016b9108(name), unknown28(-1.0f), unknown2c(0.5f) {}

    virtual ~Object016ab968();

  private:
    Name name24;     /* +0x24: empty from the constructor, released by the destructor */
    float unknown28; /* +0x28: -1.0 from the constructor; not traced */
    float unknown2c; /* +0x2c: 0.5 from the constructor; not traced */
};

/* derived name: the complete destructor FUN_005aac20: the body is empty; the
 * members are released, last first, then the base's destructor is inlined.
 * FUN_005aace0, slot 1, is the deleting one and holds this one inlined.
 * Defined here, so the unit that creates the object (leaf_005a81d0.cpp)
 * emits the vtable and both destructors. */
inline Object016ab968::~Object016ab968() {}

#endif
