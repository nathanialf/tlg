/* src/include/tlg_game_object016b9c70.h: the class whose vtable is at
 * 0x16b9c70 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B9C70_H
#define TLG_GAME_OBJECT016B9C70_H

#include "tlg_game_node.h"
#include "tlg_game_object00cf7fb0.h"

/* derived names: the class whose vtable is at 0x16b9c70
 * (config/vtables.derived.base.txt, stored by FUN_00cfc3e0 FUN_013b3740 FUN_013b37f0), derived from
 * Object00cf7fb0 (the class whose destructor is 0xcf7fb0): the base's slots and fields are not traced,
 * so the bytes below the first member here are the base's or this class's.
 * Its own fields are traced only where its destructor FUN_013b3740 tears them
 * down (the counted reference at +0xc8); the rest are not traced. */
class Object016b9c70 : public Object00cf7fb0 /* derived name */
{
  public:
    /* inlined in the creator FUN_00cfc3e0: Object00cf7fb0's constructor with 6, the
     * vptr, the members empty */
    Object016b9c70(const Name &name) : Object00cf7fb0(name, 6), unknownd0(0), unknownd4(0) {}

    virtual ~Object016b9c70();

  private:
    /* +0xc8: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> heldc8;
    int unknownd0; /* +0xd0: zero from the constructor; not traced */
    int unknownd4; /* +0xd4: zero from the constructor; not traced */
    u8 unknownd8[0x8];
};

#endif
