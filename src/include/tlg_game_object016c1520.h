/* src/include/tlg_game_object016c1520.h: the class whose vtable is at
 * 0x016c1520 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016C1520_H
#define TLG_GAME_OBJECT016C1520_H

#include "tlg_game_node.h"
#include "tlg_game_object00c1b7f0.h"

/* derived names: the class whose vtable is at 0x016c1520
 * (config/vtables.derived.base.txt, stored by FUN_010d9730), over
 * Object00c1b7f0 and Object013cd320: its destructor FUN_010db160 calls
 * 0x13cd320 and ends in a jump to 0xc1b7f0. Its creator FUN_010d55c0 takes the
 * first type of the pair at 0x5ad1ef8. Traced only where
 * FUN_010ea4b0 reads it. */
class Object016c1520 : public Object00c1b7f0, public Object013cd320 /* derived name */
{
  public:
    virtual ~Object016c1520();

  private:
    u8 unknown194[0x24]; /* +0x194: in the tail padding of Object013cd320; not traced */

  public:
    AtomicRef0045c470<Object016b9108> owner; /* +0x1b8: the owner, a counted reference */
};

#endif
