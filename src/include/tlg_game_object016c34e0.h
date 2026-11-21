/* src/include/tlg_game_object016c34e0.h: the class whose vtable is at
 * 0x016c34e0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016C34E0_H
#define TLG_GAME_OBJECT016C34E0_H

#include "tlg_game_node.h"
#include "tlg_game_object00c1b7f0.h"

/* derived names: the class whose vtable is at 0x016c34e0
 * (config/vtables.derived.base.txt, stored by FUN_012d2630), over
 * Object00c1b7f0 and Object013cd320: its destructor FUN_012d32a0 calls
 * 0x13cd320 and ends in a jump to 0xc1b7f0. Its creator FUN_012cfd00 takes the
 * first type of the pair at 0x5ad98e8. Traced only where
 * FUN_012da460 reads it. */
class Object016c34e0 : public Object00c1b7f0, public Object013cd320 /* derived name */
{
  public:
    virtual ~Object016c34e0();

  private:
    u8 unknown194[0x24]; /* +0x194: in the tail padding of Object013cd320; not traced */

  public:
    AtomicRef0045c470<Object016b9108> owner; /* +0x1b8: the owner, a counted reference */
};

#endif
