/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_block.h"
#include "tlg_game_object0139b6b0.h"
#include "tlg_game_record00f4dab0.h"

/* derived names: the class of the vtable at 0x16b1ac8
 * (config/vtables.derived.base.txt; made by FUN_001bd010): the record
 * 0x134f620 tears down at +0x10, an owned block at +0x28, the record
 * 0x139b6b0 tears down at +0x40 and an owned block at +0x58. Its complete
 * destructor 0xa01c20 releases them from the last to the first, the first as
 * a tail call, and calls no base; the deleting one 0xa01cd0 is the
 * compiler's. The other members are not traced. */
class Object016b1ac8 /* derived name */
{
  public:
    virtual ~Object016b1ac8();

  private:
    u8 unknown8[0x8];
    Object0134f620 unknown10;   /* +0x10 */
    OwnedBlock05943280 block28; /* +0x28 */
    u8 unknown30[0x10];
    Object0139b6b0 unknown40;   /* +0x40 */
    OwnedBlock05943280 block58; /* +0x58 */
};

// NONMATCHING: the deleting destructor 0xa01cd0 calls this one (28 bytes) where the base inlines it
// (an inline-cost margin); this complete destructor is equal
Object016b1ac8::~Object016b1ac8() {}
