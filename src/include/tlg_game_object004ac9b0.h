/* src/include/tlg_game_object004ac9b0.h: an object holding one counted
 * reference (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT004AC9B0_H
#define TLG_GAME_OBJECT004AC9B0_H

#include "tlg_game_node.h"

/* derived names: an 8-byte object that holds one counted reference another
 * thread may replace. Its destructor (each of its four callers frees the
 * object right after: 0x4ab054, 0x4ac6b3, 0x4ac933, 0x4ad713) empties the
 * reference by compare-and-swap; then the member's own destructor finds it
 * empty or drops what another thread put there since. */
class Object004ac9b0 /* derived name */
{
  public:
    ~Object004ac9b0();

  private:
    AtomicRef0045c470<Object016b9108> held; /* +0x0 */
};

#endif
