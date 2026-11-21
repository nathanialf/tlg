/* src/include/tlg_game_object016cebe8.h: the class whose vtable is at
 * 0x16cebe8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CEBE8_H
#define TLG_GAME_OBJECT016CEBE8_H

#include "tlg_game_node.h"
#include "tlg_game_object016b8450.h"

/* derived names: the class whose vtable is at 0x16cebe8
 * (config/vtables.derived.base.txt, stored by FUN_00b0c790 FUN_0138f9c0
 * FUN_0138fa70), derived from Object016b8450. 0xa0 bytes (`mov edi,
 * 0xa0` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00b0c790 sets them and its destructor FUN_0138f9c0
 * tears them down. The destructor is the class's key function
 * (leaf_0138f9c0.cpp), so that unit emits the vtable and the
 * destructors. */
class Object016cebe8 : public Object016b8450 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, `mov dword [rbx+0x94], 0`,
     * `mov qword [rbx+0x98], 0` (the reference); the base's fields set before
     * the vptr store */
    Object016cebe8(const Name &name) : Object016b8450(name), unknown94(0) {}

    virtual ~Object016cebe8();

  private:
    int unknown94; /* +0x94: zero from the constructor; not traced */
    /* +0x98: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Object016b9108> held98;
};

#endif
