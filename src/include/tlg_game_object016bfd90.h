/* src/include/tlg_game_object016bfd90.h: the class whose vtable is at
 * 0x016bfd90 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016BFD90_H
#define TLG_GAME_OBJECT016BFD90_H

#include "tlg_game_node.h"
#include "tlg_game_object00c1b7f0.h"

/* derived names: the class whose vtable is at 0x016bfd90
 * (config/vtables.derived.base.txt, stored by FUN_00f86720), over
 * Object00c1b7f0 and Object013cd320: its destructor FUN_00f86a70 calls
 * 0x13cd320 and ends in a jump to 0xc1b7f0. Its creator FUN_00f865c0 takes the
 * first type of the pair at 0x5acedc0. Traced only where
 * FUN_00f8c430 reads it. */
class Object016bfd90 : public Object00c1b7f0, public Object013cd320 /* derived name */
{
  public:
    virtual ~Object016bfd90();

  private:
    u8 unknown194[0x24]; /* +0x194: in the tail padding of Object013cd320; not traced */

  public:
    AtomicRef0045c470<Object016b9108> owner; /* +0x1b8: the owner, a counted reference */
};

#endif
