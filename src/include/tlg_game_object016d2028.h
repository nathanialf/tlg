/* src/include/tlg_game_object016d2028.h: the class whose vtable is at
 * 0x16d2028 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016D2028_H
#define TLG_GAME_OBJECT016D2028_H

#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object00cf7fb0.h"

/* derived names: the class whose vtable is at 0x16d2028
 * (config/vtables.derived.base.txt, stored by its creator FUN_00cfba50,
 * leaf_00cfba50.cpp, and its destructor FUN_013b38d0), derived from
 * Object00cf7fb0: its six slots are the two destructors and the base's
 * four. 0xe0 bytes: after the base's fields, three empty counted
 * references at +0xc8, +0xd0 and +0xd8 (a 16-byte and an 8-byte store).
 * The destructor is implicit: the complete one, FUN_013b38a0, is a jump
 * to the base-object one, FUN_013b38d0 (the references released last to
 * first, then a tail call of the base's destructor FUN_00cf7fb0), and the
 * deleting one, FUN_013b38b0, calls it: its cost is over the inline limit
 * of 325 (the inline hint). The class has no key function, so the
 * creator's unit emits the vtable with them. */
class Object016d2028 : public Object00cf7fb0 /* derived name */
{
  public:
    Object016d2028(const Name &name) : Object00cf7fb0(name, 5) {}

  private:
    Ref00503fb0<Object016b9108> unknownc8; /* +0xc8 */
    Ref00503fb0<Object016b9108> unknownd0; /* +0xd0 */
    Ref00503fb0<Object016b9108> unknownd8; /* +0xd8 */
};

#endif
