/* src/include/tlg_game_object016cbf30.h: the class whose vtable is at
 * 0x16cbf30 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CBF30_H
#define TLG_GAME_OBJECT016CBF30_H

#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cbf30
 * (config/vtables.derived.base.txt, stored by FUN_008064f0 FUN_0136f420
 * FUN_0136f4e0), derived from Object016b9108. 0x28 bytes (`mov edi,
 * 0x28` before operator new in the creator). Its own fields are traced
 * where its creator FUN_008064f0 sets them and its destructor FUN_0136f420
 * tears them down. */
class Object016cbf30 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, `mov dword [r15+0x24], 0` */
    Object016cbf30(const Name &name) : Object016b9108(name) {}

    virtual ~Object016cbf30();

  private:
    Name name24; /* +0x24: empty from the constructor, released by the destructor */
};

/* derived name: the complete destructor FUN_0136f420: the body is empty; the
 * members are released, last first, then the base's destructor is inlined.
 * FUN_0136f4e0, slot 1, is the deleting one and holds this one inlined.
 * Defined here, so the unit that creates the object (leaf_008064f0.cpp)
 * emits the vtable and both destructors. */
inline Object016cbf30::~Object016cbf30() {}

#endif
