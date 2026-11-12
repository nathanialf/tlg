/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_block.h"
#include "tlg_game_record00f4dab0.h"

/* derived names: the member FUN_0139b6b0 tears down (leaf_00b45590.cpp's:
 * the reference-counted pointers in the 16-byte entries of the array at +0x0
 * counted by the int at +0x8) */
struct Object0139b6b0 /* derived name */
{
    void *unknown0; /* +0x0 */
    int unknown8;   /* +0x8 */
};

void FUN_0139b6b0(Object0139b6b0 *self); /* derived name */

/* derived names: the class of the vtable at 0x16b1ac8
 * (config/vtables.derived.base.txt; made by FUN_001bd010): the record
 * FUN_0134f620 tears down at +0x10, an owned block at +0x28, the record
 * FUN_0139b6b0 tears down at +0x40 and an owned block at +0x58. Its complete
 * destructor 0xa01c20 releases them from the last to the first, the first as
 * a tail call, and calls no base; the deleting one 0xa01cd0 is the
 * compiler's. The other members are not traced. */
class Object016b1ac8 /* derived name */
{
  public:
    virtual ~Object016b1ac8();

  private:
    u8 unknown8[0x8];
    Object0134f620 unknown10; /* +0x10 */
    u8 unknown20[0x8];
    void *block28; /* +0x28: owned block */
    u8 unknown30[0x10];
    Object0139b6b0 unknown40; /* +0x40 */
    u8 unknown50[0x8];
    void *block58; /* +0x58: owned block */
};

// NONMATCHING: the deleting destructor 0xa01cd0 calls this one (28 bytes) where the base inlines it
// (an inline-cost margin); this complete destructor is equal
Object016b1ac8::~Object016b1ac8()
{
    releaseBlock(block58);
    FUN_0139b6b0(&unknown40);
    releaseBlock(block28);
    FUN_0134f620(&unknown10);
}
