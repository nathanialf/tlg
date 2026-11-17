/* src/include/tlg_game_object016a87b8.h: the class whose vtable is at
 * 0x16a87b8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A87B8_H
#define TLG_GAME_OBJECT016A87B8_H

#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_object016aeab0.h"

/* derived names: the class whose vtable is at 0x16a87b8
 * (config/vtables.derived.base.txt, stored by its constructor 0x344670, its
 * row named for it, D15, and by its destructors 0x134d440 and 0x134d4b0),
 * derived from Object016aeab0 (the constructor inlines that class's: the
 * ymm clear from +0x238 and the 3 at +0x248). 0x2a0 bytes (`mov edi, 0x2a0`
 * before operator new in its creator FUN_00344510). -1 at +0x258 from
 * Object016aeab0's constructor with a value; the heap block it owns at +0x260 is released by the
 * destructor (leaf_0134d440.cpp, the class's key function). The constructor
 * is not written; the other members are not traced. */
class Object016a87b8 : public Object016aeab0 /* derived name */
{
  public:
    Object016a87b8(const Name &name); /* 0x344670 */
    virtual ~Object016a87b8();

  private:
    u8 unknown25c[0x4];
    void *block260; /* +0x260 */
    u8 unknown268[0x38];
};

#endif
