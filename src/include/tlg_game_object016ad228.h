/* src/include/tlg_game_object016ad228.h: the class whose vtable is at 0x16ad228
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AD228_H
#define TLG_GAME_OBJECT016AD228_H

#include "tlg_game_collection00214e10.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object00774560.h"

/* derived names: the class whose vtable is at 0x16ad228
 * (config/vtables.derived.base.txt, stored by FUN_007795c0 FUN_007796c0), 0x3f0 bytes
 * (`mov edi, 0x3f0` before operator new in its creator FUN_00779460),
 * derived from Object00774560 (its constructor 0x7795c0 first calls 0x774370, that
 * class's constructor). Its constructor is not written; the fields are the ones its destructor
 * releases (leaf_007796c0.cpp). */
class Object016ad228 : public Object00774560 /* derived name */
{
  public:
    Object016ad228(const Name &name); /* 0x7795c0, its row named after it (D15) */
    virtual ~Object016ad228();

  private:
    Name namefc; /* +0xfc */
    u8 unknown100[0x10];
    Ref00503fb0<Object016b9108> unknown110; /* +0x110 */
    u8 unknown118[0x8];
    Object00214e10 unknown120; /* +0x120 */
    u8 unknown3e0[0x10];       /* to the 0x3f0 bytes the creator FUN_00779460 allocates */
};

#endif
