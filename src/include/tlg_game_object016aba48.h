/* src/include/tlg_game_object016aba48.h: the class whose vtable is at
 * 0x16aba48 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016ABA48_H
#define TLG_GAME_OBJECT016ABA48_H

#include "tlg_game_node.h"
#include "tlg_game_object016cb168.h"

/* derived names: the class whose vtable is at 0x16aba48
 * (config/vtables.derived.base.txt, stored by FUN_005aaa70 FUN_005ab240
 * FUN_005ab2e0), derived from Object016cb168. 0x58 bytes (`mov edi,
 * 0x58` before operator new in the creator). Its own fields are traced
 * where its creator FUN_005aaa70 sets them and its destructor FUN_005ab240
 * tears them down. The destructor is the class's key function
 * (leaf_005ab240.cpp), so that unit emits the vtable and the
 * destructors. */
class Object016aba48 : public Object016cb168 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, `mov dword [r15+0x40], 0`,
     * -1.0 at +0x44 and +0x48, `mov qword [r15+0x4c], 0` (two ints: the pair
     * the code generator merges is the last two of one type) */
    Object016aba48(const Name &name)
        : Object016cb168(name), unknown40(0), unknown44(-1.0f), unknown48(-1.0f), unknown4c(0),
          unknown50(0)
    {
    }

    virtual ~Object016aba48();

  private:
    int unknown40;   /* +0x40: zero from the constructor; not traced */
    float unknown44; /* +0x44: -1.0 from the constructor; not traced */
    float unknown48; /* +0x48: -1.0 from the constructor; not traced */
    int unknown4c;   /* +0x4c: zero from the constructor; not traced */
    int unknown50;   /* +0x50: zero from the constructor; not traced */
    u8 unknown54[0x4];
};

#endif
