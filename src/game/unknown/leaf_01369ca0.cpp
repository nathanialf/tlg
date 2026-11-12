/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_block.h"
#include "tlg_game_record00f4dab0.h"

/* derived names: the class of the vtable at 0x16cb760
 * (config/vtables.derived.base.txt; made by FUN_00704230): owned blocks at
 * +0x10 and +0x48 and between them an Object0134f620 record, at
 * +0x28. Its complete destructor 0x1369ca0 releases the block at +0x48, tears
 * down the record, then releases the block at +0x10 as a tail call, and calls
 * no base: the three members destroyed, last first; the deleting one 0x1369d50 is
 * the compiler's. The other members are not traced. */
class Object016cb760 /* derived name */
{
  public:
    virtual ~Object016cb760();

  private:
    u8 unknown8[0x8];
    OwnedBlock05943280 block10; /* +0x10: owned block */
    u8 unknown18[0x10];
    Object0134f620 unknown28; /* +0x28 */
    u8 unknown38[0x10];
    OwnedBlock05943280 block48; /* +0x48: owned block */
};

// NONMATCHING: the deleting destructor 0x1369d50 calls this one (28 bytes) where the base inlines it
// (an inline-cost margin); this complete destructor is equal
Object016cb760::~Object016cb760() {}
