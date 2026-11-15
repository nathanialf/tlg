/* src/include/tlg_game_object016b1e60.h: the class whose vtable is at
 * 0x16b1e60 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B1E60_H
#define TLG_GAME_OBJECT016B1E60_H

#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b1e60
 * (config/vtables.derived.base.txt, stored by FUN_00a315b0 FUN_00a31720
 * FUN_00a31870), derived from Object016b9108. 0x40 bytes (`mov edi,
 * 0x40` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00a315b0 sets them and its destructor FUN_00a31720
 * tears them down. The destructor is the class's key function
 * (leaf_00a31720.cpp), so that unit emits the vtable: defined inline it stays a
 * function of its own that the vtable's two destructors call. */
class Object016b1e60 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, `mov qword [r15+0x24],
     * 0x1e` (30 and the first name), `mov dword, 0` at +0x2c, +0x34 and +0x38
     * (the other names); +0x30 is not written */
    Object016b1e60(const Name &name) : Object016b9108(name), unknown24(30) {}

    virtual ~Object016b1e60();

  private:
    int unknown24; /* +0x24: 30 from the constructor; not traced */
    Name name28;   /* +0x28: empty from the constructor, released by the destructor */
    Name name2c;   /* +0x2c: empty from the constructor, released by the destructor */
    int unknown30; /* +0x30: not written by the constructor; not traced */
    Name name34;   /* +0x34: empty from the constructor, released by the destructor */
    Name name38;   /* +0x38: empty from the constructor, released by the destructor */
};

#endif
