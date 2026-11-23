/* src/include/tlg_game_object016c70d0.h: the counted object whose vtable is
 * at 0x16c70d0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016C70D0_H
#define TLG_GAME_OBJECT016C70D0_H

#include "tlg_types.h"
#include "tlg_game_array01343a80.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16c70d0
 * (config/vtables.derived.base.txt), over the counted base (slot 2 is its
 * release, 0x69a0), 0x60 bytes (`mov edi, 0x60` before operator new in the
 * constructor of Object016aec40, FUN_0082fd70, and in FUN_013534f0): a
 * counted reference at +0x10, a locked array of counted references at +0x18
 * and two locked arrays at +0x30 and +0x48 whose elements have no
 * destructor. Its constructor, inlined at both sites, is the members' (each
 * array emptied, its owner the calling thread's heap, its lock made free:
 * 0x82fde4 to 0x82fe98); FUN_013534f0 value-initialises it (the 0x60 bytes
 * cleared first), so the constructor is implicit. Every function of the
 * class lies in the stretch of inline functions (the complete destructor
 * FUN_01345c70, the deleting one FUN_01345d90), so it declares no
 * destructor and the unit that constructs it emits the vtable and both: the
 * complete one costs 240 at the unit stage, under the hint's limit of 325,
 * and the deleting one holds it. The arrays' elements are not traced. */
class Object016c70d0 : public Counted00c14bc0 /* derived name */
{
  private:
    Ref00503fb0<Object016b9108> held10;                      /* +0x10 */
    Array01343a80<Ref00503fb0<Object016b9108>> references18; /* +0x18 */
    Array01343a80<u32> values30;                             /* +0x30 */
    Array01343a80<u32> values48;                             /* +0x48 */
};

#endif
