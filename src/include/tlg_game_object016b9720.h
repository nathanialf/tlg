/* src/include/tlg_game_object016b9720.h: the class whose vtable is at
 * 0x16b9720 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B9720_H
#define TLG_GAME_OBJECT016B9720_H

#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"
#include "tlg_game_pair0057e850.h"

/* derived name: the class between Object016b9108 and Object016b9720: its
 * constructor, inlined, clears the 16 bytes at +0x28 BEFORE the derived
 * class's vptr store (`vmovdqu [r15+0x28], xmm0` at 0xced8af, the vptr
 * stored after it); its own vptr store is dead. Two pointers; not traced. */
class Base016b9720 : public Object016b9108 /* derived name */
{
  public:
    Base016b9720(const Name &name) : Object016b9108(name), unknown28(0), unknown30(0) {}

  private:
    void *unknown28; /* +0x28: null from the constructor; not traced */
    void *unknown30; /* +0x30: null from the constructor; not traced */
};

struct Peer016b9720; /* derived name: leaf_00cee190.cpp */

/* derived names: the class whose vtable is at 0x16b9720
 * (config/vtables.derived.base.txt, stored by FUN_00ced790 FUN_00cee190
 * FUN_00cee240), derived from Base016b9720. 0x50 bytes (`mov edi, 0x50`
 * before operator new in the creator). Its own fields are traced where its
 * creator FUN_00ced790 sets them and its destructor FUN_00cee190 reads them
 * (the linked object at +0x38). The destructor is the class's key function
 * (leaf_00cee190.cpp), so that unit emits the vtable and the destructors. */
class Object016b9720 : public Base016b9720 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, `mov
     * qword [r15+0x38], 0`, 0.5 at +0x40, then the body's 0.5 and 0 at +0x44
     * in one `mov qword [r15+0x44], 0x3f000000` that the 0.5 before it is not
     * part of: the two are one value of two floats, assigned whole */
    Object016b9720(const Name &name) : Base016b9720(name), peer38(0), unknown40(0.5f)
    {
        unknown44 = Pair0057e850(0.5f, 0.0f);
    }

    virtual ~Object016b9720();

  private:
    friend struct Peer016b9720;

    Peer016b9720 *peer38;   /* +0x38: detached by the destructor */
    float unknown40;        /* +0x40: 0.5 from the constructor; not traced */
    Pair0057e850 unknown44; /* +0x44: 0.5 and 0 from the constructor; not traced */
    u8 unknown4c[0x4];
};

#endif
