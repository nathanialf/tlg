/* src/include/tlg_game_object016acb20.h: the class whose vtable is at 0x16acb20
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016ACB20_H
#define TLG_GAME_OBJECT016ACB20_H

#include "tlg_game_collection00214e10.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object00774560.h"

/* derived names: the class whose vtable is at 0x16acb20
 * (config/vtables.derived.base.txt, stored by its constructor FUN_007658a0,
 * not written, and its destructor FUN_007659d0, leaf_00766e50.cpp), derived
 * from Object00774560: a Name at +0xfc, an Object00214e10 at +0x100, two
 * references at +0x3c0 and +0x3c8 and an int at +0x3d0 (the destructor
 * releases the members last first) */
class Object016acb20 : public Object00774560 /* derived name */
{
  public:
    Object016acb20(const Name &name); /* 0x7658a0, its row named after it (D15) */
    virtual ~Object016acb20();
    virtual void slot9();                    /* FUN_00766c90 */
    virtual void slot14(Pose0077bac0 *pose); /* FUN_00766e50 */

  private:
    Name namefc;               /* +0xfc */
    Object00214e10 unknown100; /* +0x100: run by slot 14, reset by slot 9 */
    /* +0x3c0, +0x3c8: references slot 9 empties, the second to the body's
     * kind of state (its int at +0x60 given bit 0 first) */
    AtomicRef0045c470<Object016b9108> unknown3c0;
    AtomicRef0045c470<State00774760> unknown3c8;
    int unknown3d0; /* +0x3d0: zero from slot 9 */
    u8 unknown3d4
        [0x7c]; /* to the 0x450 bytes the creator FUN_00765740 allocates (`mov edi, 0x450`) */
};

#endif
