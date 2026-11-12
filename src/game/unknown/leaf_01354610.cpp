/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_block.h"
#include "tlg_game_record00f4dab0.h"

/* derived names: the class of the vtable at 0x16cae70
 * (config/vtables.derived.base.txt; made by FUN_005073e0): owned blocks at
 * +0x10 and +0x58 and between them an Object0134f620 record, at
 * +0x28. Its complete destructor 0x1354610 releases the block at +0x58, tears
 * down the record, then releases the block at +0x10 as a tail call, and calls
 * no base: the three members destroyed, last first; the deleting one 0x13546c0 is
 * the compiler's. The other members are not traced. */
class Object016cae70 /* derived name */
{
  public:
    virtual ~Object016cae70();

  private:
    u8 unknown8[0x8];
    OwnedBlock05943280 block10; /* +0x10: owned block */
    u8 unknown18[0x10];
    Object0134f620 unknown28; /* +0x28 */
    u8 unknown38[0x20];
    OwnedBlock05943280 block58; /* +0x58: owned block */
};

// NONMATCHING: the deleting destructor 0x13546c0 calls this one (28 bytes) where the base inlines it
// (an inline-cost margin); this complete destructor is equal
Object016cae70::~Object016cae70() {}
