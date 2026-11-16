/* src/include/tlg_game_object016b8e48.h: the class whose vtable is at
 * 0x16b8e48 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B8E48_H
#define TLG_GAME_OBJECT016B8E48_H

#include "tlg_game_node.h"
#include "tlg_game_object01343880.h"

/* derived names: the class whose vtable is at 0x16b8e48
 * (config/vtables.derived.base.txt, stored by FUN_00cab0b0 FUN_013ad180
 * FUN_013ad2a0), derived from Object01343880: slot 7 is its own
 * (FUN_00cabe40, leaf_00cabe40.cpp), the other slots the base's.
 * 0x48 bytes (`mov edi, 0x48` before operator new in the creator). Its own
 * fields are traced where its creator FUN_00cab0b0 sets them and its
 * destructor FUN_013ad180 tears them down. */
class Object016b8e48 : public Object01343880 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, `mov
     * dword [r15+0x34], 1`, 25.0 twice from +0x38, `mov qword [r15+0x40], 0` */
    Object016b8e48(const Name &name)
        : Object01343880(name), unknown34(1), unknown38(25.0f), unknown3c(25.0f)
    {
    }

    virtual ~Object016b8e48();

    /* slot 7, FUN_00cabe40: named as the base's slot is (an override
     * carries the base's name) */
    virtual void FUN_001af750();

  private:
    int unknown34;   /* +0x34: 1 from the constructor; not traced */
    float unknown38; /* +0x38: 25.0 from the constructor; not traced */
    float unknown3c; /* +0x3c: 25.0 from the constructor; not traced */
    /* +0x40: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Object016b9108> held40;
};

/* derived name: the complete destructor FUN_013ad180: the body is empty; the
 * reference is released, then the base's destructor is inlined.
 * FUN_013ad2a0, slot 1, is the deleting one and holds this one inlined.
 * Defined here, so the unit that creates the object (leaf_00cab0b0.cpp)
 * emits the vtable and both destructors. */
inline Object016b8e48::~Object016b8e48() {}

#endif
