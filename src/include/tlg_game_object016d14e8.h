/* src/include/tlg_game_object016d14e8.h: the class whose vtable is at
 * 0x16d14e8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016D14E8_H
#define TLG_GAME_OBJECT016D14E8_H

#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16d14e8
 * (config/vtables.derived.base.txt, stored by its creator FUN_00c5f1d0,
 * leaf_00c5f1d0.cpp, and its destructor FUN_013a98d0), derived from
 * Object016b9108: its five slots are the two destructors and the base's
 * three. 0x50 bytes: eight Names (+0x24, +0x28, +0x30, +0x34 and four
 * from +0x3c), empty from the constructor, an int at +0x2c, 0 from it,
 * and an int at +0x38, 1 from it (16 bytes of zero, a 4-byte one, the 1,
 * 16 bytes of zero). The destructor is implicit: the complete one,
 * FUN_013a98a0, is a jump to the base-object one, FUN_013a98d0 (the Names
 * released last to first, then the root's destructor in line), and the
 * deleting one, FUN_013a98b0, calls it: its cost is over the inline limit
 * of 325 (the inline hint). The class has no key function, so the
 * creator's unit emits the vtable with them. */
class Object016d14e8 : public Object016b9108 /* derived name */
{
  public:
    Object016d14e8(const Name &name) : Object016b9108(name), unknown2c(0), unknown38(1) {}

  private:
    Name name24;   /* +0x24 */
    Name name28;   /* +0x28 */
    int unknown2c; /* +0x2c: 0 from the constructor */
    Name name30;   /* +0x30 */
    Name name34;   /* +0x34 */
    int unknown38; /* +0x38: 1 from the constructor */
    Name name3c;   /* +0x3c */
    Name name40;   /* +0x40 */
    Name name44;   /* +0x44 */
    Name name48;   /* +0x48 */
    u8 unknown4c[0x4];
};

#endif
