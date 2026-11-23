/* src/include/tlg_game_object016ae838.h: the class whose vtable is at
 * 0x16ae838, derived from Object016ae7e0 (game region; docs/TARGETS.md).
 * Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AE838_H
#define TLG_GAME_OBJECT016AE838_H

#include "tlg_game_name.h"
#include "tlg_game_object016ae7e0.h"

/* derived names: the class of the vtable at 0x16ae838
 * (config/vtables.derived.base.txt; made by FUN_00818ea0), derived from the
 * class whose destructor is 0x818d10 (leaf_00846b00.cpp): two Names at +0x9c
 * and +0xa0. Its complete destructor 0x8190a0 (leaf_008190a0.cpp) releases
 * +0xa0, then +0x9c, then runs the base's as a tail call; the deleting one
 * 0x819140 is the compiler's. Slot 2 is FUN_00cb66f0. The other members are
 * not traced. */
class Object016ae838 : public Object016ae7e0 /* derived name */
{
  public:
    virtual ~Object016ae838();

  private:
    Name unknown9c; /* +0x9c */
    Name unknowna0; /* +0xa0 */
};

/* derived names: the class of the vtable at 0x16b4e18
 * (config/vtables.derived.base.txt), made by the factory FUN_00b1b9f0 (0xb0
 * bytes), derived from Object016ae838: slots 7 and 8 are its own (0xb1bd30,
 * 0xb1bd40), the rest Object016ae838's. Its destructor's body is empty; its
 * complete destructor 0xb1bbf0 holds Object016ae838's inlined (the base's
 * vptr store, its two names, then 0x818d10 as a tail call). */
class Object016b4e18 : public Object016ae838 /* derived name */
{
  public:
    virtual ~Object016b4e18();
};

#endif
