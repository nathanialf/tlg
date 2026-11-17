/* src/include/tlg_game_object016ad610.h: the class whose vtable is at 0x16ad610
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AD610_H
#define TLG_GAME_OBJECT016AD610_H

#include "tlg_game_collection00214e10.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object00774560.h"

/* derived names: the class whose vtable is at 0x16ad610
 * (config/vtables.derived.base.txt, stored by FUN_00790a00 FUN_00790cb0), 0x480 bytes
 * (`mov edi, 0x480` before operator new in its creator FUN_007908a0),
 * derived from Object00774560 (its constructor 0x790a00 first calls 0x774370, that
 * class's constructor). Its constructor is not written; the fields are the ones its destructor
 * releases (leaf_00790cb0.cpp). */
class Object016ad610 : public Object00774560 /* derived name */
{
  public:
    Object016ad610(const Name &name); /* 0x790a00, its row named after it (D15) */
    virtual ~Object016ad610();

  private:
    Name namefc; /* +0xfc */
    u8 unknown100[0x8];
    Ref00503fb0<Object016b9108> unknown108; /* +0x108 */
    u8 unknown110[0x38];
    Ref00503fb0<Object016b9108> unknown148; /* +0x148 */
    u8 unknown150[0x60];
    Object00214e10 unknown1b0; /* +0x1b0 */
    u8 unknown470[0x10];       /* to the 0x480 bytes the creator FUN_007908a0 allocates */
};

#endif
