/* src/include/tlg_game_object016cd4a0.h: the class whose vtable is at
 * 0x16cd4a0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CD4A0_H
#define TLG_GAME_OBJECT016CD4A0_H

#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cd4a0
 * (config/vtables.derived.base.txt, stored by FUN_00995680 FUN_01383410
 * FUN_013834d0), derived from Object016b9108. 0x30 bytes (`mov edi,
 * 0x30` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00995680 sets them and its destructor FUN_01383410
 * tears them down. */
class Object016cd4a0 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, `movabs rdx,
     * 0xbf80000000000000` stored at +0x24: the name and -1.0 */
    Object016cd4a0(const Name &name) : Object016b9108(name), unknown28(-1.0f) {}

    virtual ~Object016cd4a0();

  private:
    Name name24;     /* +0x24: empty from the constructor, released by the destructor */
    float unknown28; /* +0x28: -1.0 from the constructor; not traced */
};

/* derived name: the complete destructor FUN_01383410: the body is empty; the
 * members are released, last first, then the base's destructor is inlined.
 * FUN_013834d0, slot 1, is the deleting one and holds this one inlined.
 * Defined here, so the unit that creates the object (leaf_00995680.cpp)
 * emits the vtable and both destructors. */
inline Object016cd4a0::~Object016cd4a0() {}

#endif
