/* src/include/tlg_game_object016d15b0.h: the class whose vtable is at
 * 0x16d15b0, a base of game classes (game region; docs/TARGETS.md). Every
 * name here is derived. */
#ifndef TLG_GAME_OBJECT016D15B0_H
#define TLG_GAME_OBJECT016D15B0_H

#include "tlg_game_block.h"
#include "tlg_game_object00d30550.h"

/* derived names: the class of the vtable at 0x16d15b0
 * (config/vtables.derived.base.txt; made by FUN_00c688c0), derived from
 * Object00d30550 (its destructor 0xd30550, its row named for it, D15;
 * leaf_013a9fb0.cpp): owned blocks at +0x70 and +0x88. Its destructor is
 * the members' and is declared inline below: the base's deleting destructor
 * 0x13a9f00 and the destructors of the classes at 0x16bac50 and 0x16bad98
 * over it (leaf_00d81bf0.cpp, leaf_00d86290.cpp) inline it, and the
 * complete destructor 0x13a9e60 (the vtable's slot 0, emitted with the
 * vtable where a unit uses it) releases the block at +0x88, then the one
 * at +0x70, then runs the base's as a tail call. The other members are not
 * traced. */
class Object016d15b0 : public Object00d30550 /* derived name */
{
  public:
    virtual ~Object016d15b0();

  private:
    u8 unknown8[0x68];
    OwnedBlock05943280 unknown70; /* +0x70 */
    u8 unknown78[0x10];
    OwnedBlock05943280 unknown88; /* +0x88 */
};

inline Object016d15b0::~Object016d15b0() {}

#endif
