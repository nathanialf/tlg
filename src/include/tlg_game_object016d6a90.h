/* src/include/tlg_game_object016d6a90.h: the class of the vtable at
 * 0x16d6a90 and the class of 0x16ca810 derived from it, read from the bytes
 * of their destructors (the same shapes as tlg_game_object016d3ad0.h's two
 * classes). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016D6A90_H
#define TLG_GAME_OBJECT016D6A90_H

#include "tlg_game_block.h"
#include "tlg_game_name.h"
#include "tlg_simd.h"

/* derived names: the class of the vtable at 0x16d6a90
 * (config/vtables.derived.base.txt; made by FUN_0121a680): an owned block at
 * +0x18 and a Name at +0x30. Its complete destructor 0x147a4d0 releases the
 * Name, then the block; the deleting one 0x147a570 is the compiler's. Slot 2
 * is FUN_01478b40. The other members are not traced. Its destructor is
 * inline here: the base's (in the linkonce stretch) is inlined into the
 * derived destructors. */
class Object016d6a90 /* derived name */
{
  public:
    virtual ~Object016d6a90() {}

  private:
    u8 unknown8[0x10];
    OwnedBlock05943280 unknown18; /* +0x18 */
    u8 unknown20[0x10];
    Name unknown30; /* +0x30 */
};

/* derived names: the class of the vtable at 0x16ca810
 * (config/vtables.derived.base.txt; made by FUN_0121a680): a vector at
 * +0x110, an int at +0x124 and an owned block at +0x128 after its base's
 * members. Slot 2, FUN_01223180, is its key function: the vtable and the
 * implicit destructor are emitted with it, the complete one 0x1222fb0
 * releasing the block, then running its base's (inlined), the deleting one
 * 0x12230a0 the complete one inlined. Slot 4 is pure (__cxa_pure_virtual).
 * The other members are not traced. */
class Object016ca810 : public Object016d6a90 /* derived name */
{
  public:
    virtual void slot2(); /* derived name: FUN_01223180 */
    /* derived name: pure here; each class derived from this one gives its
     * own */
    virtual void slot4() = 0;

  private:
    u8 unknown38[0xd8];
    Vec4 unknown110; /* +0x110: cleared by slot 2 */
    u8 unknown120[4];
    int unknown124;                /* +0x124: cleared by slot 2 */
    OwnedBlock05943280 unknown128; /* +0x128 */
};

#endif
