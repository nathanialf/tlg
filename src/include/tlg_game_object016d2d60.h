/* src/include/tlg_game_object016d2d60.h: the class whose vtable is at
 * 0x16d2d60 (config/vtables.derived.base.txt, stored by FUN_00e538f0
 * FUN_013c9a40); leaf_00e538f0.cpp defines its constructor. Every name here
 * is derived. */
#ifndef TLG_GAME_OBJECT016D2D60_H
#define TLG_GAME_OBJECT016D2D60_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: derived from Object016b9108: its five slots are the two
 * destructors and the base's three. 0x98 bytes (`mov edi, 0x98` in its
 * factory FUN_00e53790): from the constructor, 1, 0, 1 and 3 from +0x24
 * (one 16-byte store), 0 at +0x34, the sizes 1920 by 1080 twice, two zeros
 * and 1920 by 1080 again from +0x38 (one 32-byte store), 1 at +0x58 and
 * +0x5c, an empty Name at +0x60, 0 at +0x64 and +0x68, 1 at +0x6c, a locked
 * array of Names at +0x70 and four Names from +0x88, the last three set in
 * the constructor's body. The destructor is implicit: the complete one,
 * FUN_013c9a10, is a jump to the base-object one, FUN_013c9a40 (the Names
 * and the array released last to first, then the root's destructor in
 * line), and the deleting one, FUN_013c9a20, calls it: its cost is over the
 * inline limit of 325 (the inline hint). The class has no key function, so
 * the constructor's unit emits the vtable with them. */
class Object016d2d60 : public Object016b9108 /* derived name */
{
  public:
    Object016d2d60(const Name &name); /* FUN_00e538f0 */

  private:
    int unknown24;               /* +0x24: 1 from the constructor */
    int unknown28;               /* +0x28: 0 from the constructor */
    int unknown2c;               /* +0x2c: 1 from the constructor */
    int unknown30;               /* +0x30: 3 from the constructor */
    int unknown34;               /* +0x34: 0 from the constructor */
    int width38;                 /* +0x38: 1920 from the constructor */
    int height3c;                /* +0x3c: 1080 from the constructor */
    int width40;                 /* +0x40: 1920 from the constructor */
    int height44;                /* +0x44: 1080 from the constructor */
    int unknown48;               /* +0x48: 0 from the constructor */
    int unknown4c;               /* +0x4c: 0 from the constructor */
    int width50;                 /* +0x50: 1920 from the constructor */
    int height54;                /* +0x54: 1080 from the constructor */
    int unknown58;               /* +0x58: 1 from the constructor */
    int unknown5c;               /* +0x5c: 1 from the constructor */
    Name name60;                 /* +0x60 */
    int unknown64;               /* +0x64: 0 from the constructor */
    int unknown68;               /* +0x68: 0 from the constructor */
    int unknown6c;               /* +0x6c: 1 from the constructor */
    Array01343a80<Name> names70; /* +0x70 */
    Name name88;                 /* +0x88 */
    Name name8c;                 /* +0x8c: "trico", looked up without adding it */
    Name name90;                 /* +0x90: "data_trico" */
    Name name94;                 /* +0x94: "data_trico" */
};

#endif
