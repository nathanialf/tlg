/* src/include/tlg_game_object016b6c20.h: the class whose vtable is at
 * 0x16b6c20 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B6C20_H
#define TLG_GAME_OBJECT016B6C20_H

#include "tlg_math.h"
#include "tlg_game_node.h"
#include "tlg_game_object01343880.h"

/* derived names: the class whose vtable is at 0x16b6c20
 * (config/vtables.derived.base.txt, stored by FUN_00b766d0 FUN_00b76da0
 * FUN_00b76ec0), derived from Object01343880: slots 5, 7 and 8 override
 * the base's (FUN_00b76fd0, FUN_00b77320, FUN_00b77340), slots 9 to 12 are
 * its own (FUN_00b77040, FUN_00b77050, FUN_00b77080, FUN_00b772a0; declared,
 * their bodies are not members yet). 0x70 bytes (`mov edi,
 * 0x70` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00b766d0 sets them and its destructor FUN_00b76da0
 * tears them down. */
class Object016b6c20 : public Object01343880 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, `mov dword
     * [r15+0x34], 0`, `mov qword [r15+0x60], 0`, `mov dword [r15+0x68], 0` */
    Object016b6c20(const Name &name) : Object01343880(name), unknown34(0), unknown68(0) {}

    virtual ~Object016b6c20();
    /* slot 5, FUN_00b76fd0: named as the base's slot is (an override
     * carries the base's name); not traced */
    virtual int FUN_000058a0();
    /* slot 7, FUN_00b77320: named as the base's slot is (an override
     * carries the base's name); not traced */
    virtual void FUN_001af750();
    /* slot 8, FUN_00b77340: named as the base's slot is (an override
     * carries the base's name); not traced */
    virtual void slot8();
    virtual void slot9();  /* derived name; FUN_00b77040, not traced */
    virtual void slot10(); /* derived name; FUN_00b77050, not traced */
    virtual void slot11(); /* derived name; FUN_00b77080, not traced */
    /* slot 12, FUN_00b772a0: the component FUN_009f5540 finds in the node
     * into +0x60, then, when it holds its ints at +0x58 and +0xb0, the two
     * rows at +0x40 and +0x50 and the node's at +0x120 and +0x140 handed to
     * FUN_00ce2a80 with it */
    virtual void slot12(); /* derived name */

  private:
    int unknown34; /* +0x34: zero from the constructor; not traced */
    u8 unknown38[0x8];
    Float4A unknown40; /* +0x40: slot 12 hands its address on */
    Float4A unknown50; /* +0x50: slot 12 hands its address on */
    /* +0x60: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Object016b9108> held60;
    int unknown68; /* +0x68: zero from the constructor; not traced */
};

/* derived name: the complete destructor FUN_00b76da0: the body is empty; the
 * members are released, last first, then the base's destructor is inlined.
 * FUN_00b76ec0, slot 1, is the deleting one and holds this one inlined.
 * Defined here, so the unit that creates the object (leaf_00b766d0.cpp)
 * emits the vtable and both destructors. */
inline Object016b6c20::~Object016b6c20() {}

#endif
