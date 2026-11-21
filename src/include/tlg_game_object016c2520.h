/* src/include/tlg_game_object016c2520.h: the class whose vtable is at
 * 0x016c2520 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016C2520_H
#define TLG_GAME_OBJECT016C2520_H

#include "tlg_game_node.h"
#include "tlg_game_object00c1b7f0.h"

/* derived names: the class whose vtable is at 0x016c2520
 * (config/vtables.derived.base.txt, stored by FUN_0124bff0), over
 * Object00c1b7f0 and Object013cd320: its destructor FUN_0124c400 calls
 * 0x13cd320 and ends in a jump to 0xc1b7f0. Its creator FUN_0124be90 takes the
 * first type of the pair at 0x5ad7af0. Traced only where
 * FUN_0124e170 reads it. */
class Object016c2520 : public Object00c1b7f0, public Object013cd320 /* derived name */
{
  public:
    virtual ~Object016c2520();

  private:
    u8 unknown194[0x24]; /* +0x194: in the tail padding of Object013cd320; not traced */

  public:
    AtomicRef0045c470<Object016b9108> owner; /* +0x1b8: the owner, a counted reference */
};

#endif
