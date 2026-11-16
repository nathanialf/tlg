/* src/include/tlg_game_object016aa290.h: the class whose vtable is at
 * 0x16aa290 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AA290_H
#define TLG_GAME_OBJECT016AA290_H

#include "tlg_game_node.h"
#include "tlg_game_object016aa0d0.h"

/* derived names: the class whose vtable is at 0x16aa290
 * (config/vtables.derived.base.txt, stored by FUN_004b60b0 FUN_004b6250
 * FUN_004b6380), derived from Object016aa0d0. 0x80 bytes (`mov edi,
 * 0x80` before operator new in the creator). Its own fields are traced
 * where its creator FUN_004b60b0 sets them and its destructor FUN_004b6250
 * tears them down. The destructor is the class's key function
 * (leaf_004b6250.cpp), so that unit emits the vtable and the
 * destructors. */
class Object016aa290 : public Object016aa0d0 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the 32 bytes from +0x60
     * cleared in one store (four ints and the two references, a run of zero
     * stores made one memset) */
    Object016aa290(const Name &name)
        : Object016aa0d0(name), unknown60(0), unknown64(0), unknown68(0), unknown6c(0)
    {
    }

    virtual ~Object016aa290();

  private:
    int unknown60; /* +0x60: zero from the constructor; not traced */
    int unknown64; /* +0x64: zero from the constructor; not traced */
    int unknown68; /* +0x68: zero from the constructor; not traced */
    int unknown6c; /* +0x6c: zero from the constructor; not traced */
    /* +0x70: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Object016b9108> held70;
    /* +0x78: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Object016b9108> held78;
};

#endif
