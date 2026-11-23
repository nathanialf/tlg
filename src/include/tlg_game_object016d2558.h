/* src/include/tlg_game_object016d2558.h: the class whose vtable is at
 * 0x16d2558 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016D2558_H
#define TLG_GAME_OBJECT016D2558_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object01343880.h"

/* derived names: the class whose vtable is at 0x16d2558
 * (config/vtables.derived.base.txt, stored by its creator FUN_00d64040,
 * leaf_00d64040.cpp, and its destructor FUN_013ba2b0), derived from
 * Object01343880: its nine slots are the two destructors and the base's
 * seven. 0x60 bytes: an empty Name at +0x34, an empty counted reference
 * at +0x38, 8 bytes of zero at +0x40 and a locked array at +0x48 (its
 * elements have no destructor; not traced), all from the constructor. The
 * complete destructor, FUN_013ba280, is a jump to the base-object one,
 * FUN_013ba2b0 (the array's block, the reference and the Name released
 * last to first, then the root's destructor in line), and the deleting
 * one, FUN_013ba290, calls it. The base-object destructor costs 280 at
 * the unit stage (the array's block given back through FUN_00ebf3f0,
 * tlg_game_array.h): implicit, it would carry the inline hint (limit 325)
 * and be inlined into both, so the destructor is declared in the class
 * body, which carries none (limit 225). The class has no key function, so
 * the creator's unit emits the vtable with them. */
class Object016d2558 : public Object01343880 /* derived name */
{
  public:
    Object016d2558(const Name &name) : Object01343880(name), unknown40(0) {}

    virtual ~Object016d2558() {}

  private:
    Name name34;                           /* +0x34 */
    Ref00503fb0<Object016b9108> unknown38; /* +0x38 */
    void *unknown40;                       /* +0x40: null from the constructor */
    Array01343a80<int> unknown48;          /* +0x48: the element not traced */
};

#endif
