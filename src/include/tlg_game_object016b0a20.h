/* src/include/tlg_game_object016b0a20.h: the class whose vtable is at
 * 0x16b0a20 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B0A20_H
#define TLG_GAME_OBJECT016B0A20_H

#include "tlg_game_node.h"
#include "tlg_game_object00ca38f0.h"

/* derived names: the class whose vtable is at 0x16b0a20
 * (config/vtables.derived.base.txt, stored by FUN_00900a40 FUN_00900bf0
 * FUN_00900ca0), derived from Object00ca38f0. 0x68 bytes (`mov edi,
 * 0x68` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00900a40 sets them and its destructor FUN_00900bf0
 * tears them down. The destructor is the class's key function
 * (leaf_00900bf0.cpp), so that unit emits the vtable and the
 * destructors. */
class Object016b0a20 : public Object00ca38f0 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, `mov qword [r15+0x58], 0`
     * (the reference), then 1.0 and 0 at +0x60 in one `mov qword [r15+0x60],
     * 0x3f800000` (two floats) */
    Object016b0a20(const Name &name) : Object00ca38f0(name), unknown60(1.0f), unknown64(0.0f) {}

    virtual ~Object016b0a20();

  private:
    u8 unknown8[0x50];
    /* +0x58: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Object016b9108> held58;
    float unknown60; /* +0x60: 1.0 from the constructor; not traced */
    float unknown64; /* +0x64: zero from the constructor; not traced */
};

#endif
