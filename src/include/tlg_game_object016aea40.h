/* src/include/tlg_game_object016aea40.h: the class whose vtable is at
 * 0x16aea40 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AEA40_H
#define TLG_GAME_OBJECT016AEA40_H

#include "tlg_types.h"
#include "tlg_math.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b85e0.h"

/* derived names: the class whose vtable is at 0x16aea40
 * (config/vtables.derived.base.txt, stored by its creator FUN_00821ea0, where
 * its constructor is inlined, and by its complete destructor 0x822190, its row
 * named for it, D15), derived from Object016b85e0 (the creator calls that
 * class's constructor 0xc55320 first). It holds a counted reference at +0x240,
 * null from the constructor (`mov qword [r15+0x240], 0` after the vptr in
 * the creator, before the derived vptr in its derived classes' creators) and
 * released by the destructor before the base's destructor. 0x250 bytes (`mov
 * edi, 0x250` before operator new in the creator): the base's 16-byte rows
 * (`vmovaps [rbx+0x70]` in 0xc55320) align the class, so a derived class's
 * first field is at +0x248, in the tail (leaf_00670840.cpp). The destructor
 * is not written, so nothing here emits the vtable. */
class Object016aea40 : public Object016b85e0 /* derived name */
{
  public:
    Object016aea40(const Name &name) : Object016b85e0(name) {}

    virtual ~Object016aea40();

  private:
    u8 unknown8[0x68];
    Float4A unknown70; /* +0x70: the base's; not traced */
    u8 unknown80[0x1c0];
    Ref00503fb0<Object016b9108> held240; /* +0x240 */
};

#endif
