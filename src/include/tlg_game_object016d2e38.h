/* src/include/tlg_game_object016d2e38.h: the class whose vtable is at
 * 0x16d2e38 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016D2E38_H
#define TLG_GAME_OBJECT016D2E38_H

#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object01343880.h"

/* derived names: the class whose vtable is at 0x16d2e38
 * (config/vtables.derived.base.txt, stored by its creator FUN_00e647d0,
 * leaf_00e647d0.cpp, and its destructor FUN_013c9e70), derived from
 * Object01343880: its nine slots are the two destructors and the base's
 * seven. 0x58 bytes: two pairs of a counted reference and a Name, at
 * +0x38 and +0x40, +0x48 and +0x50, empty from the constructor (an 8-byte
 * and a 4-byte store each). The destructor is implicit: the complete one,
 * FUN_013c9e60, is a jump to the base-object one, FUN_013c9e70 (the Names
 * and references released last to first, then the root's destructor in
 * line), and the deleting one, FUN_013ca070, calls it: its cost is over
 * the inline limit of 325 (the inline hint). The class has no key
 * function, so the creator's unit emits the vtable with them. */
class Object016d2e38 : public Object01343880 /* derived name */
{
  public:
    Object016d2e38(const Name &name) : Object01343880(name) {}

  private:
    Ref00503fb0<Object016b9108> unknown38; /* +0x38 */
    Name name40;                           /* +0x40 */
    u8 unknown44[0x4];
    Ref00503fb0<Object016b9108> unknown48; /* +0x48 */
    Name name50;                           /* +0x50 */
    u8 unknown54[0x4];
};

#endif
