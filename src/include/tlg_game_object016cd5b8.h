/* src/include/tlg_game_object016cd5b8.h: the class whose vtable is at
 * 0x16cd5b8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CD5B8_H
#define TLG_GAME_OBJECT016CD5B8_H

#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cd5b8
 * (config/vtables.derived.base.txt, stored by FUN_009b3570 FUN_01386e00
 * FUN_01386ec0), derived from Object016b9108. 0x48 bytes (`mov edi,
 * 0x48` before operator new in the creator). Its own fields are traced
 * where its creator FUN_009b3570 sets them and its destructor FUN_01386e00
 * tears them down. The destructor is the class's key function
 * (leaf_01386e00.cpp), so that unit emits the vtable and the
 * destructors. */
class Object016cd5b8 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, `mov dword` stores from
     * +0x24: the name, 0.1, 0, 50.0, 0, 60.0 (floats and ints alternating: four
     * 4-byte fields of one type would be one vector store), then `mov qword
     * [r15+0x3c], 0` and `mov dword [r15+0x44], 0` */
    Object016cd5b8(const Name &name)
        : Object016b9108(name), unknown28(0.1f), unknown2c(0), unknown30(50.0f), unknown34(0),
          unknown38(60.0f), unknown3c(0), unknown40(0), unknown44(0)
    {
    }

    virtual ~Object016cd5b8();

  private:
    Name name24;     /* +0x24: empty from the constructor, released by the destructor */
    float unknown28; /* +0x28: 0.1 from the constructor; not traced */
    int unknown2c;   /* +0x2c: zero from the constructor; not traced */
    float unknown30; /* +0x30: 50.0 from the constructor; not traced */
    int unknown34;   /* +0x34: zero from the constructor; not traced */
    float unknown38; /* +0x38: 60.0 from the constructor; not traced */
    int unknown3c;   /* +0x3c: zero from the constructor; not traced */
    int unknown40;   /* +0x40: zero from the constructor; not traced */
    int unknown44;   /* +0x44: zero from the constructor; not traced */
};

#endif
