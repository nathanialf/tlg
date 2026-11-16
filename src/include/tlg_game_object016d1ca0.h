/* src/include/tlg_game_object016d1ca0.h: the class whose vtable is at
 * 0x16d1ca0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016D1CA0_H
#define TLG_GAME_OBJECT016D1CA0_H

#include "tlg_game_node.h"
#include "tlg_game_object00ced570.h"

/* derived names: the class whose vtable is at 0x16d1ca0
 * (config/vtables.derived.base.txt, stored by FUN_00cd6540 FUN_013af460
 * FUN_013af510), derived from Object00ced570. 0x70 bytes (`mov edi,
 * 0x70` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00cd6540 sets them and its destructor FUN_013af460
 * tears them down. The destructor is the class's key function
 * (leaf_013af460.cpp), so that unit emits the vtable and the
 * destructors. */
class Object016d1ca0 : public Object00ced570 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, `mov qword [r15+0x68], 0`
     * (the reference), then the body's 7, -1, 1 and 32 at +0x50 in one store
     * from the constants at 0x1544e00 (the base's four ints) and 1 at +0x60; the
     * base's fields set before the vptr store */
    Object016d1ca0(const Name &name) : Object00ced570(name)
    {
        unknown50 = 7;
        unknown54 = -1;
        unknown58 = 1;
        unknown5c = 32;
        unknown60 = 1;
    }

    virtual ~Object016d1ca0();

  private:
    int unknown60; /* +0x60: 1 from the constructor; not traced */
    u8 unknown64[0x4];
    /* +0x68: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Object016b9108> held68;
};

#endif
