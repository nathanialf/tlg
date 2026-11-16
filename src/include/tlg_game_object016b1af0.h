/* src/include/tlg_game_object016b1af0.h: the class whose vtable is at
 * 0x16b1af0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B1AF0_H
#define TLG_GAME_OBJECT016B1AF0_H

#include "tlg_game_node.h"
#include "tlg_game_object01343880.h"

/* derived names: the class whose vtable is at 0x16b1af0
 * (config/vtables.derived.base.txt, stored by FUN_00a02870 FUN_00a033c0
 * FUN_00a034e0), derived from Object01343880: slots 5, 7 and 8 override
 * the base's (FUN_00a035f0, FUN_00a03660, FUN_00a03680; declared, their
 * bodies are not members yet). 0x60 bytes (`mov edi,
 * 0x60` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00a02870 sets them and its destructor FUN_00a033c0
 * tears them down. */
class Object016b1af0 : public Object01343880 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, 0 and 1.0 from
     * +0x34 in one `movabs`, two pointers cleared in one 16-byte store at
     * +0x40 (two pointers of one type, another than the reference's), `mov
     * qword [r15+0x50], 0` */
    Object016b1af0(const Name &name)
        : Object01343880(name), unknown34(0.0f), unknown38(1.0f), unknown40(0), unknown48(0)
    {
    }

    virtual ~Object016b1af0();
    /* slot 5, FUN_00a035f0: named as the base's slot is (an override
     * carries the base's name); not traced */
    virtual int FUN_000058a0();
    /* slot 7, FUN_00a03660: named as the base's slot is (an override
     * carries the base's name); not traced */
    virtual void FUN_001af750();
    /* slot 8, FUN_00a03680: named as the base's slot is (an override
     * carries the base's name); not traced */
    virtual void slot8();

  private:
    float unknown34; /* +0x34: zero from the constructor; not traced */
    float unknown38; /* +0x38: 1.0 from the constructor; not traced */
    void *unknown40; /* +0x40: null from the constructor; not traced */
    void *unknown48; /* +0x48: null from the constructor; not traced */
    /* +0x50: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Object016b9108> held50;
    u8 unknown58[0x8];
};

/* derived name: the complete destructor FUN_00a033c0: the body is empty; the
 * members are released, last first, then the base's destructor is inlined.
 * FUN_00a034e0, slot 1, is the deleting one and holds this one inlined.
 * Defined here, so the unit that creates the object (leaf_00a02870.cpp)
 * emits the vtable and both destructors. */
inline Object016b1af0::~Object016b1af0() {}

#endif
