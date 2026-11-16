/* src/include/tlg_game_object016b7a40.h: the class whose vtable is at
 * 0x16b7a40 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B7A40_H
#define TLG_GAME_OBJECT016B7A40_H

#include "tlg_game_node.h"
#include "tlg_game_object016c7fb0.h"

/* derived names: the class whose vtable is at 0x16b7a40
 * (config/vtables.derived.base.txt, stored by FUN_00be4a80 FUN_00be54b0
 * FUN_00be5560), derived from Object016c7fb0. 0xe8 bytes (`mov edi,
 * 0xe8` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00be4a80 sets them and its destructor FUN_00be54b0
 * tears them down. The destructor is the class's key function
 * (leaf_00be54b0.cpp), so that unit emits the vtable and the
 * destructors. */
class Object016b7a40 : public Object016c7fb0 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, `mov qword [rbx+0xd8], 0`
     * (the reference) after the vptr */
    Object016b7a40(const Name &name) : Object016c7fb0(name) {}

    virtual ~Object016b7a40();

  private:
    /* +0xd8: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Object016b9108> heldd8;
    u8 unknowne0[0x8];
};

#endif
