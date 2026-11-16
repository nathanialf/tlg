/* src/include/tlg_game_object016d3ad0.h: the class of the vtable at
 * 0x16d3ad0 and the class of 0x16ca148 derived from it, read from the bytes
 * of their destructors. Every name here is derived. */
#ifndef TLG_GAME_OBJECT016D3AD0_H
#define TLG_GAME_OBJECT016D3AD0_H

#include "tlg_game_block.h"
#include "tlg_game_name.h"
#include "tlg_simd.h"

/* derived names: the class of the vtable at 0x16d3ad0
 * (config/vtables.derived.base.txt; made by FUN_00f59e00): an owned block at
 * +0x18 and a Name at +0x30. Its complete destructor 0x13d65a0 releases the
 * Name, then the block; the deleting one 0x13d6640 is the compiler's. Slot 2
 * is FUN_013d4610. The other members are not traced. Its destructor
 * is inline here: the base's (in the linkonce stretch) is inlined into the
 * derived destructors of other units. */
class Object016d3ad0 /* derived name */
{
  public:
    virtual ~Object016d3ad0() {}

  private:
    u8 unknown8[0x10];
    OwnedBlock05943280 unknown18; /* +0x18 */
    u8 unknown20[0x10];
    Name unknown30; /* +0x30 */
};

/* derived names: the class of the vtable at 0x16ca148
 * (config/vtables.derived.base.txt; made by FUN_00f59e00): a vector at
 * +0x110, an int at +0x124 and an owned block at +0x128 after its base's
 * members. Slot 2, FUN_00f66fd0, is its key function: the vtable and the
 * implicit destructor are emitted with it, the complete one 0xf66e00
 * releasing the block, then running its base's (inlined), the deleting one
 * 0xf66ef0 the complete one inlined (the implicit destructor carries the
 * inline hint). The other members are not traced. */
class Object016ca148 : public Object016d3ad0 /* derived name */
{
  public:
    virtual void slot2(); /* derived name: FUN_00f66fd0 */

  private:
    u8 unknown38[0xd8];
    Vec4 unknown110; /* +0x110: cleared by slot 2 */
    u8 unknown120[4];
    int unknown124;                /* +0x124: cleared by slot 2 */
    OwnedBlock05943280 unknown128; /* +0x128 */
};

#endif
