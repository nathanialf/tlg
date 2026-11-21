/* src/include/tlg_game_object016d3e10.h: the class whose vtable is at 0x16d3e10
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016D3E10_H
#define TLG_GAME_OBJECT016D3E10_H

#include "tlg_game_object016b9108.h"
#include "tlg_game_node.h"

/* derived names: a holder of one counted reference at +0x8, exchanged: the
 * class whose vtable is at 0x16d3e10 (its destructor 0x13d8e40 stores it).
 * The class at 0x16d3df0 holds one at its +0x10 (its creator FUN_013d93b0
 * empties the reference by compare-and-swap right after the stores). */
class Object016d3e10 /* derived name */
{
  public:
    virtual ~Object016d3e10();

    /* the reference emptied by compare-and-swap (`xor ecx, ecx; lock
     * cmpxchg qword [r14], rcx` in a loop at 0x13d8e60) */
    void reset() /* derived name */
    {
        held8.clear();
    }

  private:
    AtomicRef0045c470<Object016b9108> held8; /* +0x8 */
};

#endif
