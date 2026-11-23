/* src/include/tlg_game_object016cdff0.h: the class whose vtable is at
 * 0x16cdff0 (config/vtables.derived.base.txt), the global at 0x5824208 of
 * FUN_00a01a80's unit (func_00a01a80.cpp) (game region; docs/TARGETS.md).
 * Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CDFF0_H
#define TLG_GAME_OBJECT016CDFF0_H

#include "tlg_types.h"
#include "tlg_game_namelist.h"

/* derived names: the ints at +0x8 and +0xc and the list's count at +0x10,
 * a non-polymorphic base class: FUN_00a01a80 stores them (0, 4 and 0,
 * 0xa01a99 to 0xa01aad) apart and ahead of the class's vptr, the entries
 * after it (the loop at 0xa01bf0); as the class's own members after the
 * vptr the count's store is scheduled after the vptr's, and as members of
 * the base with the entries the first two are joined into one 8-byte store.
 * FUN_013883d0's append reads the count at +0x10 and the entries at +0x14 of
 * every such list. What the two ints hold is not traced. */
struct Base016cdff0 /* derived name */
{
    Base016cdff0() : unknown8(0), unknownc(4), count(0) {}

    int unknown8;   /* +0x8 */
    int unknownc;   /* +0xc */
    unsigned count; /* +0x10 */
};

/* derived names: a list of 1024 named values from +0x14, its count in the
 * base at +0x10; its slot 2 is FUN_013883d0's append. The destructor
 * (leaf_01388570.cpp) is the class's key function; it releases the names
 * from the last entry down. */
class Object016cdff0 : public Base016cdff0 /* derived name */
{
  public:
    virtual ~Object016cdff0();

  private:
    NamedValue013883d0 entries[1024]; /* +0x14 */
};

#endif
