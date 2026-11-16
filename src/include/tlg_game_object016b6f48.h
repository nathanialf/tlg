/* src/include/tlg_game_object016b6f48.h: the class whose vtable is at
 * 0x16b6f48 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B6F48_H
#define TLG_GAME_OBJECT016B6F48_H

#include "tlg_game_node.h"
#include "tlg_game_object01343880.h"

/* derived names: the class whose vtable is at 0x16b6f48
 * (config/vtables.derived.base.txt, stored by FUN_00b828e0 FUN_00b838e0
 * FUN_00b83a80), derived from Object01343880: slots 5, 7 and 8 override
 * the base's (FUN_00b83aa0, FUN_00b83d10, FUN_00b83d30; declared, their
 * bodies are not members yet). 0x60 bytes (`mov edi,
 * 0x60` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00b828e0 sets them and its destructor FUN_00b838e0
 * tears them down. The destructor is the class's key function
 * (leaf_00b838e0.cpp), so that unit emits the vtable and the
 * destructors. */
class Object016b6f48 : public Object01343880 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, `mov dword [r15+0x34], 0`,
     * the four floats at +0x38 from the constants at 0x1541d10 (1, 1, 1, 0) in
     * one store, `mov dword [r15+0x48], 0`, the two references cleared in one
     * store; the base's pointer and int cleared before the vptr store */
    Object016b6f48(const Name &name)
        : Object01343880(name), unknown34(0), unknown38(1.0f), unknown3c(1.0f), unknown40(1.0f),
          unknown44(0.0f), unknown48(0)
    {
    }

    virtual ~Object016b6f48();
    /* slot 5, FUN_00b83aa0: named as the base's slot is (an override
     * carries the base's name); not traced */
    virtual int FUN_000058a0();
    /* slot 7, FUN_00b83d10: named as the base's slot is (an override
     * carries the base's name); not traced */
    virtual void FUN_001af750();
    /* slot 8, FUN_00b83d30: named as the base's slot is (an override
     * carries the base's name); not traced */
    virtual void slot8();

  private:
    int unknown34;   /* +0x34: zero from the constructor; not traced */
    float unknown38; /* +0x38: 1.0 from the constructor; not traced */
    float unknown3c; /* +0x3c: 1.0 from the constructor; not traced */
    float unknown40; /* +0x40: 1.0 from the constructor; not traced */
    float unknown44; /* +0x44: zero from the constructor; not traced */
    int unknown48;   /* +0x48: zero from the constructor; not traced */
    u8 unknown4c[0x4];
    /* +0x50: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Object016b9108> held50;
    /* +0x58: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Object016b9108> held58;
};

#endif
