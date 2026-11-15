/* src/include/tlg_game_object016b7058.h: the class whose vtable is at
 * 0x16b7058 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B7058_H
#define TLG_GAME_OBJECT016B7058_H

#include "tlg_game_node.h"
#include "tlg_game_object01343880.h"

/* derived names: the class whose vtable is at 0x16b7058
 * (config/vtables.derived.base.txt, stored by FUN_00b85c60 FUN_00b866d0
 * FUN_00b86850), derived from Object01343880: slots 5, 7 and 8 override
 * the base's (FUN_00b86870, FUN_00b87d60, FUN_00b87d80; declared, their
 * bodies are not members yet). 0x48 bytes (`mov edi,
 * 0x48` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00b85c60 sets them and its destructor FUN_00b866d0
 * tears them down. The destructor is the class's key function
 * (leaf_00b866d0.cpp), so that unit emits the vtable: defined inline it stays a
 * function of its own that the vtable's two destructors call. */
class Object016b7058 : public Object01343880 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, 16 bytes cleared at +0x38
     * in one store (the reference and the two names) */
    Object016b7058(const Name &name) : Object01343880(name) {}

    virtual ~Object016b7058();
    /* slot 5, FUN_00b86870: named as the base's slot is (an override
     * carries the base's name); not traced */
    virtual int FUN_000058a0();
    /* slot 7, FUN_00b87d60: named as the base's slot is (an override
     * carries the base's name); not traced */
    virtual void FUN_001af750();
    /* slot 8, FUN_00b87d80: named as the base's slot is (an override
     * carries the base's name); not traced */
    virtual void slot8();

  private:
    int unknown34; /* +0x34: not written by the constructor; not traced */
    /* +0x38: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Node00503fb0> held38;
    Name name40; /* +0x40: empty from the constructor, released by the destructor */
    Name name44; /* +0x44: empty from the constructor, released by the destructor */
};

#endif
