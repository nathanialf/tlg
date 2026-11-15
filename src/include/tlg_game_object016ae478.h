/* src/include/tlg_game_object016ae478.h: the class whose vtable is at
 * 0x16ae478 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AE478_H
#define TLG_GAME_OBJECT016AE478_H

#include "tlg_game_node.h"
#include "tlg_game_object01343880.h"

/* derived names: the class whose vtable is at 0x16ae478
 * (config/vtables.derived.base.txt, stored by FUN_00810b60 FUN_00810ce0
 * FUN_00811380), derived from Object01343880: slot 7 overrides the
 * base's (FUN_00811730; declared, its body is not a member yet). 0x98 bytes (`mov edi,
 * 0x98` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00810b60 sets them and its destructor FUN_00810ce0
 * tears them down. The destructor is the class's key function
 * (leaf_00810ce0.cpp), so that unit emits the vtable: defined inline it stays a
 * function of its own that the vtable's two destructors call. */
class Object016ae478 : public Object01343880 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the 96 bytes from +0x38 to
     * the object's end cleared by three 32-byte stores, the last one first:
     * the twelve references, a run of zero stores the compiler made one memset */
    Object016ae478(const Name &name) : Object01343880(name) {}

    virtual ~Object016ae478();
    /* slot 7, FUN_00811730: named as the base's slot is (an override
     * carries the base's name); not traced */
    virtual void FUN_001af750();

  private:
    /* +0x38: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Node00503fb0> held38;
    /* +0x40: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Node00503fb0> held40;
    /* +0x48: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Node00503fb0> held48;
    /* +0x50: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Node00503fb0> held50;
    /* +0x58: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Node00503fb0> held58;
    /* +0x60: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Node00503fb0> held60;
    /* +0x68: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Node00503fb0> held68;
    /* +0x70: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Node00503fb0> held70;
    /* +0x78: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Node00503fb0> held78;
    /* +0x80: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Node00503fb0> held80;
    /* +0x88: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Node00503fb0> held88;
    /* +0x90: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Node00503fb0> held90;
};

#endif
