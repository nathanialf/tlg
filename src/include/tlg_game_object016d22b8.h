/* src/include/tlg_game_object016d22b8.h: the class whose vtable is at
 * 0x16d22b8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016D22B8_H
#define TLG_GAME_OBJECT016D22B8_H

#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"
#include "tlg_game_pair0057e850.h"

/* derived names: the class whose vtable is at 0x16d22b8
 * (config/vtables.derived.base.txt, stored by FUN_00d48470 FUN_013b8d30 FUN_013b8e50), derived from
 * Object016b9108: its slots 2 to 4 are the base's.
 * Its own fields are traced only where its destructor FUN_013b8d30 tears them
 * down (the counted reference at +0x30); the rest are not traced.
 * The destructor is implicit: FUN_013b8d30 and the deleting
 * FUN_013b8e50 sit in the stretch of inline functions (from 0x1340000)
 * while the constructor is out of line, so the class has no key function
 * and the unit that constructs it (leaf_00d48310.cpp) emits the vtable
 * with both. */
class Object016d22b8 : public Object016b9108 /* derived name */
{
  public:
    Object016d22b8(const Name &name); /* FUN_00d48470 */

  private:
    float unknown24;        /* +0x24: 0.5 from the constructor; not traced */
    Pair0057e850 unknown28; /* +0x28: (0.5, 1.0) from the constructor; not traced */
    /* +0x30: a counted reference, set by the constructor (an exchange),
     * released by the destructor (the pointer cleared, `cmp dword [r+8],
     * 0xdeadc0de`, the count dropped) */
    AtomicRef0045c470<Object016b9108> held30;
};

#endif
