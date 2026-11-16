/* src/include/tlg_game_object016be220.h: the class whose vtable is at
 * 0x16be220 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016BE220_H
#define TLG_GAME_OBJECT016BE220_H

#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16be220
 * (config/vtables.derived.base.txt, stored by FUN_00e94b50 FUN_00e94cb0
 * FUN_00e94e50), derived from Object016b9108. 0x40 bytes (`mov edi,
 * 0x40` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00e94b50 sets them and its destructor FUN_00e94cb0
 * tears them down. The destructor is the class's key function
 * (leaf_00e94cb0.cpp), so that unit emits the vtable: defined inline it stays a
 * function of its own that the vtable's two destructors call. */
class Object016be220 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the 28 bytes from +0x24 to
     * the object's end cleared by two 16-byte stores that overlap (`vmovdqu
     * [r15+0x30], xmm0; vmovdqu [r15+0x24], xmm0`): three ints and the two
     * references, a run of zero stores the compiler made one 28-byte memset */
    Object016be220(const Name &name)
        : Object016b9108(name), unknown24(0), unknown28(0), unknown2c(0)
    {
    }

    virtual ~Object016be220();

  private:
    int unknown24; /* +0x24: zero from the constructor; not traced */
    int unknown28; /* +0x28: zero from the constructor; not traced */
    int unknown2c; /* +0x2c: zero from the constructor; not traced */
    /* +0x30: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Object016b9108> held30;
    /* +0x38: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Object016b9108> held38;
};

#endif
