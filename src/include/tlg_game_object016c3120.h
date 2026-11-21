/* src/include/tlg_game_object016c3120.h: the class whose vtable is at
 * 0x016c3120 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016C3120_H
#define TLG_GAME_OBJECT016C3120_H

#include "tlg_game_node.h"
#include "tlg_game_object00c1b7f0.h"

/* derived names: the class whose vtable is at 0x016c3120
 * (config/vtables.derived.base.txt, stored by FUN_0129ea30), over
 * Object00c1b7f0 and Object013cd320: its destructor FUN_0129f5b0 calls
 * 0x13cd320 and ends in a jump to 0xc1b7f0. Its creator FUN_0129e8d0 takes the
 * first type of the pair at 0x5ad88a8. Traced only where
 * FUN_012a4ea0 reads it. */
class Object016c3120 : public Object00c1b7f0, public Object013cd320 /* derived name */
{
  public:
    virtual ~Object016c3120();

  private:
    u8 unknown194[0x24]; /* +0x194: in the tail padding of Object013cd320; not traced */

  public:
    AtomicRef0045c470<Object016b9108> owner; /* +0x1b8: the owner, a counted reference */
};

#endif
