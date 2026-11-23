/* src/include/tlg_game_object016cdff0.h: the class whose vtable is at
 * 0x16cdff0 (config/vtables.derived.base.txt), the global at 0x5824208 of
 * FUN_00a01a80's unit (func_00a01a80.cpp) (game region; docs/TARGETS.md).
 * Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CDFF0_H
#define TLG_GAME_OBJECT016CDFF0_H

#include "tlg_types.h"
#include "tlg_game_namelist.h"

/* derived names: a list of 1024 named values from +0x14, its count at
 * +0x10, held in a NamedValueList013883d0; its slot 2 is FUN_013883d0's
 * append. The constructor clears the int at +0x8 and sets the one at +0xc
 * to 4 (0xa01a99, 0xa01aa3); what they hold is not traced. The destructor
 * (leaf_01388570.cpp) is the class's key function. */
class Object016cdff0 /* derived name */
{
  public:
    Object016cdff0() : unknown8(0), unknownc(4) {}

    virtual ~Object016cdff0();

  private:
    int unknown8;                      /* +0x8 */
    int unknownc;                      /* +0xc */
    NamedValueList013883d0<1024> list; /* +0x10 */
};

#endif
