/* src/include/tlg_game_object016aa140.h: the class whose vtable is at
 * 0x16aa140 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AA140_H
#define TLG_GAME_OBJECT016AA140_H

#include "tlg_game_node.h"
#include "tlg_game_object016aa0d0.h"

/* derived names: the class whose vtable is at 0x16aa140
 * (config/vtables.derived.base.txt, stored by FUN_004b0570 FUN_004b0b10
 * FUN_004b0d40), derived from Object016aa0d0. 0x90 bytes (`mov edi,
 * 0x90` before operator new in the creator). Its own fields are traced
 * where its creator FUN_004b0570 sets them and its destructor FUN_004b0b10
 * tears them down. The destructor is the class's key function
 * (leaf_004b0b10.cpp), so that unit emits the vtable and the
 * destructors. */
class Object016aa140 : public Object016aa0d0 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, `mov dword [rbx+0x60], 0`,
     * `mov byte [rbx+0x64], 0`, the four references cleared in one 32-byte
     * store */
    Object016aa140(const Name &name) : Object016aa0d0(name), unknown60(0), unknown64(false) {}

    virtual ~Object016aa140();

  private:
    int unknown60;  /* +0x60: zero from the constructor; not traced */
    bool unknown64; /* +0x64: false from the constructor; not traced */
    /* +0x68: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Object016b9108> held68;
    /* +0x70: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Object016b9108> held70;
    /* +0x78: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Object016b9108> held78;
    /* +0x80: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Object016b9108> held80;
    u8 unknown88[0x8];
};

#endif
