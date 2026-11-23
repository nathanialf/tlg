/* src/include/tlg_game_object016cc308.h: the class whose vtable is at
 * 0x16cc308 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CC308_H
#define TLG_GAME_OBJECT016CC308_H

#include "tlg_game_name.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cc308
 * (config/vtables.derived.base.txt, stored by its creator FUN_00879380,
 * leaf_00879380.cpp, and its destructor FUN_01373690), derived from
 * Object016b9108: its five slots are the two destructors and the base's
 * three. 0x50 bytes: four Names at +0x24, +0x28, +0x30 and +0x34, empty
 * from the constructor (two 8-byte stores), which then calls reset().
 * The destructor is implicit: the complete one, FUN_01373680, is a jump
 * to the base-object one, FUN_01373690 (the Names released last to first,
 * then the root's destructor in line), and the deleting one, FUN_013737e0,
 * calls it: its cost is over the inline limit. The class has no key
 * function, so the creator's unit emits the vtable with them. */
class Object016cc308 : public Object016b9108 /* derived name */
{
  public:
    Object016cc308(const Name &name) : Object016b9108(name)
    {
        reset();
    }

    /* FUN_01372870 (also called by FUN_00885840 and FUN_00886300): the
     * Names released in the order +0x24, +0x30, +0x34, +0x28, then the int
     * at +0x2c and the 24 bytes from +0x38 cleared */
    void reset() /* derived name */
    {
        name24.release();
        name30.release();
        name34.release();
        name28.release();
        unknown2c = 0;
        unknown38 = 0;
        unknown40 = 0;
        unknown48 = 0;
    }

  private:
    Name name24;     /* +0x24 */
    Name name28;     /* +0x28 */
    int unknown2c;   /* +0x2c: 0 from reset() */
    Name name30;     /* +0x30 */
    Name name34;     /* +0x34 */
    void *unknown38; /* +0x38: null from reset() */
    void *unknown40; /* +0x40: null from reset() */
    void *unknown48; /* +0x48: null from reset() */
};

#endif
