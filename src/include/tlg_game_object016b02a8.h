/* src/include/tlg_game_object016b02a8.h: the class whose vtable is at
 * 0x16b02a8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B02A8_H
#define TLG_GAME_OBJECT016B02A8_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b02a8
 * (config/vtables.derived.base.txt, stored by FUN_008c2140 FUN_008c22e0
 * FUN_008c2440), derived from Object016b9108. 0x48 bytes (`mov edi,
 * 0x48` before operator new in the creator). Its own fields are traced
 * where its creator FUN_008c2140 sets them and its destructor FUN_008c22e0
 * tears them down. The destructor is the class's key function
 * (leaf_008c22e0.cpp), so that unit emits the vtable and the
 * destructors. */
class Object016b02a8 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the name at +0x24, the
     * array of Names at +0x30 (`vmovdqu [r15+0x30], xmm0`) with its owner index
     * from the thread's heap and its lock, then the body's `mov dword
     * [r15+0x28], 0` and bit 0 of the base's flags at +0x16 set */
    Object016b02a8(const Name &name) : Object016b9108(name)
    {
        unknown28 = 0;
        flags16 |= 1;
    }

    virtual ~Object016b02a8();

  private:
    Name name24;   /* +0x24: empty from the constructor, released by the destructor */
    int unknown28; /* +0x28: zero from the constructor; not traced */
    u8 unknown2c[0x4];
    Array01343a80<Name> names30; /* +0x30: an array of Names, each released by the destructor */
};

#endif
